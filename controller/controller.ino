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
 * D0 16
 * D5 14
 * D6 12
 * D7 13
 * D8 15
 */

int *ipFromStr(String strIP) {
  int *Parts = (int*) malloc(sizeof(int) * 4);
  for (int i = 0; i < 4; i++)
    Parts[i] = 0;
  int Part = 0;
  for ( int i=0; i<strIP.length(); i++ )
  {
    char c = strIP[i];
    if ( c == '.' )
    {
      Part++;
      continue;
    }
    Parts[Part] *= 10;
    Parts[Part] += c - '0';
  }
  return Parts;
}
void setup() {
  //Disable AP
  WiFi.softAPdisconnect(true);
  for(int i = 0; i < sizeof(buttonPins) / sizeof(const int); i++)
    pinMode(buttonPins[i], INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(0, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  if(digitalRead(buttonPins[0]) == HIGH) {
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
      WiFi.begin("QTcpServer", "aASDd456aaSADL<VLA4456");
      if(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Couldn't connect to WiFi.");
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      } else {
        myIP = WiFi.localIP();
        //Serial.println(myIP);
        String temp = myIP.toString();
        temp = temp.substring(0, temp.lastIndexOf('.') + 1);
        temp += '1';
        int *ipArr = ipFromStr(temp);
        servIP = IPAddress(ipArr[0], ipArr[1], ipArr[2], ipArr[3]);
        delete[]ipArr;
        Serial.println(servIP.toString());
        if (!client.connected()) {
          client.connect(servIP, 6000);
          Serial.println("Connection Failed");
          digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        } else {
          if (ID == -1) {
            client.print("-1");
            Serial.print("Waiting for responce");
            if(client.available() == 0) {
              Serial.print(".");
              digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
              delay(500);
            } else {
              while(client.available()) {
                String responce = client.readStringUntil('\r');
                ID = responce.toInt();
                while(client.available()) {
                  responce = client.read();
                }
              }
            }
          } else {
            digitalWrite(LED_BUILTIN, HIGH);
          }
          
          int i;
          String request = "" + ID;
    
          if(digitalRead(buttonPins[0]) == HIGH)
            request += "|0";
        
          for(i = 1; i < sizeof(buttonPins) / sizeof(const int); i++) {
            states[i] = digitalRead(buttonPins[i]);
            if ( (states[i] == HIGH) && (oldstates[i] != HIGH) ) {
              request += "|";
              request += i;
            }
            oldstates[i] = states[i];
          }
          if ( (request[request.length() - 1] == '0') || (request.length() == 1) )
            request = "";
          //Serial.println(request);
          client.print(request);
        }
      }
    }
    delay(100);
  } else {
    delay(1000);
  }
}
