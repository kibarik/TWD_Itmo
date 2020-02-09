#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#define arrLen(arr) (sizeof(arr) / sizeof(arr[0]))
#define BUTTONS_COUNT 7
#define RED_LED_PIN 14
#define GREEN_LED_PIN 16

const int buttonPins[] = {12, 13, 10, 2, 0, 4, 5};
int ID = -1;
long Time = 0;
IPAddress myIP, servIP;
bool isWorking = true;
WiFiClient client;

struct {
  String ssid, password;
  char *flashPassword;
  byte servLastIPByte;
  long turnOffTimeout; // microseconds
} settings;

void InitizlizeOTA();

void setup() {
  settings.ssid = "1";                  // The name of the WiFi network, where the Raspberry PI is located
  settings.password = "12345678";       // Password to WiFi network. i.e. aASDd456aaSADL<VLA4456
  settings.flashPassword = "456123789"; // Password which will be requested on flash
  settings.servLastIPByte = 1;          // The last number in ip of Raspberry PI. i.e. 192.168.1.<servLastIPByte>
  settings.turnOffTimeout = 10000000;   // The time you need to hold the zero button to turn off the esp in microseconds

  for(int i = 0; i < BUTTONS_COUNT; i++)
    pinMode(buttonPins[i], INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  InitializeOTA();
}

void loop() {
  ArduinoOTA.handle();

  if(digitalRead(buttonPins[0]) == LOW) {
    if (Time) {
      if ((micros() - Time) > settings.turnOffTimeout) {
        Time = 0;
        if (isWorking) {
          if (WiFi.status() == WL_CONNECTED) {
            WiFi.disconnect();
          }
          ID = -1;
          // Отключаем все светодиоды
          //digitalWrite(LED_BUILTIN, HIGH);
          digitalWrite(RED_LED_PIN, LOW); 
          digitalWrite(GREEN_LED_PIN, LOW);
        } else {
          WiFi.begin(settings.ssid, settings.password);
        }
        isWorking = !isWorking;
      }
    } else {
      Time = micros();
    }
  } else {
    Time = 0;
  }

  if (isWorking) {
    
    if (WiFi.status() != WL_CONNECTED) {
      // Подключение к WiFi
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
    } else {
      // Подключение к RaspberryPI
      myIP = WiFi.localIP();
      servIP = IPAddress(myIP[0], myIP[1], myIP[2], settings.servLastIPByte);
      if (!client.connected()) {
        client.connect(servIP, 6000);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
      } else { // Если уже подключен к RaspberryPI
        if (ID == -1) { // Если ещё не получил ID
          client.print("-1");
          digitalWrite(GREEN_LED_PIN, LOW);
          while(client.available() == 0 && WiFi.status() == WL_CONNECTED && client.connected() && digitalRead(buttonPins[0]) != LOW) {
            digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
            delay(2000);
          }
          while(client.available()) {
            String responce = client.readStringUntil('\r');
            ID = responce.toInt();
            while(client.available()) {
              responce = client.read();
            }
          }
        } else {
          digitalWrite(RED_LED_PIN, LOW);
          digitalWrite(GREEN_LED_PIN, HIGH);
        }
        
// Логика считывания с кнопок и отправки на RaspberryPI

        static bool buttonsStates[BUTTONS_COUNT] = {0};
        static bool oldStates[BUTTONS_COUNT] = {0};
        String request = String(ID);

        if(digitalRead(buttonPins[0]) == LOW)
          request += "|0";
      
        for(int i = 1; i < BUTTONS_COUNT; i++) {
          buttonsStates[i] = digitalRead(buttonPins[i]);
          if ( (buttonsStates[i] == LOW) && (oldStates[i] != LOW) ) {
            request += "|";
            request += i;
          }
          oldStates[i] = buttonsStates[i];
        }

        // TODO Поправить баг с отправкой нескольких нажатий в одном сообщении
        //request += '\0';
        if ( (request[request.length() - 1] != '0') && (request.indexOf('|') != -1) )
          client.print(request);
      }
    }
    delay(100);
  } else {
    delay(1000);
  }
}

void InitializeOTA() {
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(settings.ssid, settings.password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  ArduinoOTA.setPassword(settings.flashPassword);

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
