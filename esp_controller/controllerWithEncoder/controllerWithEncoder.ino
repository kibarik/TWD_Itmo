#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <stdlib.h>

#define arrLen(arr) (sizeof(arr) / sizeof(arr[0]))
#define ENC_BUTTONS_COUNT 3
#define RED_LED_PIN 5
#define GREEN_LED_PIN 16

const int encButtonPins[] = {14, 13, 12};
const int zeroButtonPin = 4;
int ID = -1;
long Time = 0;
IPAddress myIP, servIP;
bool isWorking = true;
WiFiClient client;

struct {
  String ssid, password;
  byte servLastIPByte;
  long turnOffTimeout; // microseconds
} settings;

void setup() {
  //Disable AP
  WiFi.softAPdisconnect(true);

  settings.ssid = "1";                // The name of the WiFi network, where the Raspberry PI is located
  settings.password = "12345678";     // Password to WiFi network. i.e. aASDd456aaSADL<VLA4456
  settings.servLastIPByte = 1;        // The last number in ip of Raspberry PI. i.e. 192.168.1.<servLastIPByte>
  settings.turnOffTimeout = 10000000; // The time you need to hold the zero button to turn off the esp in microseconds

  for(int i = 0; i < arrLen(encButtonPins); i++)
    pinMode(encButtonPins[i], INPUT);
  pinMode(zeroButtonPin, INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  WiFi.begin(settings.ssid, settings.password);
}

void loop() {
  if(digitalRead(zeroButtonPin) == LOW) {
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
      delay(500);
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
          while(client.available() == 0 && WiFi.status() == WL_CONNECTED && client.connected() && digitalRead(zeroButtonPin) != LOW) {
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

        static char buttonsStates[ENC_BUTTONS_COUNT + 1] = {0};
        static byte oldstate = 0;
      
        for(int i = 0; i < ENC_BUTTONS_COUNT; i++)
          buttonsStates[i] = (int)!digitalRead(encButtonPins[i]) + '0';

        byte state = strtol(buttonsStates, NULL, 2);
        if (state && state != oldstate) {
        	String request = String(ID);
        	request.concat("|");
					if(!digitalRead(zeroButtonPin))
						request.concat("0|");
          request.concat(state);
          client.print(request);
        }

        oldstate = state;
      }
    }
    delay(100);
  } else {
    delay(1000);
  }
}
