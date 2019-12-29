#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define TurnOffTimeout 10000000
int buttonPins[] = {4, 5, 12, 13, 14, 15, 16};
int ID = -1;
long Time = 0;
IPAddress myIP, servIP;
bool states[7], oldstates[7], isWorking = true;
WiFiClient client;
/*
 * Обозначения и соответствующие номера портов
 * D1 5
 * D2 4
 * D3 0    Нельзя использовать при запуске
 * D4 2    Нельзя использовать при запуске (LED_BUILTIN)
 * D0 16   При использовании INPUT_PULLUP требуется дополнительный резистор от + к контакту-приёмнику esp
           При замыкании на +, esp не запускается в режиме прошивки
 * D5 14
 * D6 12
 * D7 13
 * D8 15   При использовании INPUT_PULLUP требуется допоолнительный резистор от + к контакту-приёмнику esp
 */
void WiFiBegin() {
  WiFi.begin("1", "12345678"); // aASDd456aaSADL<VLA4456
}

void setup() {
  //Disable AP
  WiFi.softAPdisconnect(true);
  for(int i = 0; i < sizeof(buttonPins) / sizeof(const int); i++)
    pinMode(buttonPins[i], INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(0, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);
  WiFiBegin();
}

void loop() {
  if(digitalRead(buttonPins[0]) == LOW) {
    if (Time) {
      if ((micros() - Time) > TurnOffTimeout) {
        isWorking = !isWorking;
        Time = 0;
        if (!isWorking) {
          Serial.println("Tuned off");
          if (WiFi.status() == WL_CONNECTED) {
            WiFi.disconnect();
          }
          ID = -1;
          digitalWrite(LED_BUILTIN, HIGH);
        } else {
          WiFiBegin();
        }
      }
      Serial.println((micros() - Time));
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
      Serial.println("Couldn't connect to WiFi.");
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    } else {
      myIP = WiFi.localIP();
      servIP = IPAddress(myIP[0], myIP[1], myIP[2], 1);
      if (!client.connected()) {
        client.connect(servIP, 6000);
        Serial.print("Connection to ");
        Serial.print(servIP);
        Serial.println(" Failed");
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      } else {
        if (ID == -1) {
          client.print("-1");
          Serial.print("Waiting for responce");
          while(client.available() == 0 && WiFi.status() == WL_CONNECTED && client.connected() && digitalRead(buttonPins[0]) != LOW) {
            Serial.print(".");
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            delay(1000);
          }
          while(client.available()) {
            String responce = client.readStringUntil('\r');
            ID = responce.toInt();
            while(client.available()) {
              responce = client.read();
            }
          }
        } else {
          digitalWrite(LED_BUILTIN, HIGH);
        }
        
        int i;
        static char request[4] = {0};
        request += ID;
  
        if(digitalRead(buttonPins[0]) == LOW)
          request += "|0";
      
        for(i = 1; i < sizeof(buttonPins) / sizeof(const int); i++) {
          states[i] = digitalRead(buttonPins[i]);
          if ( (states[i] == LOW) && (oldstates[i] != LOW) ) {
            request += "|";
            request += i;
          }
          oldstates[i] = states[i];
        }
        if ( (request[request.length() - 1] != '0') && (request.indexOf('|') != -1) )
          client.print(request);
        //Serial.println(request);
      }
    }
    delay(100);
  } else {
    delay(1000);
  }
}
