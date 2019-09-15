#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

int buttonPins[] = {4, 5, 12, 13, 14, 15, 16};
int ID = -1;
bool states[7], oldstates[7];
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
void setup() {
  //Disable AP
  WiFi.softAPdisconnect(true);
  for(int i = 0; i < sizeof(buttonPins) / sizeof(const int); i++)
    pinMode(buttonPins[i], INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
  // Подключение к WiFi
  WiFi.begin("Keenetic-3981", "xXSBxSFu");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  if (!client.connected()) {
    client.connect("192.168.1.2", 6000);
    Serial.println("Connection Failed");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  } else {
    if (ID == -1) {
      client.print("-1");
      Serial.print("Waiting for responce");
      while(client.available() == 0) {
        Serial.print(".");
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        delay(500);
      }
      while(client.available()) {
        String responce = client.readStringUntil('\r');
        ID = responce.toInt();
        while(client.available()) {
          responce = client.read();
        }
      }
      Serial.println(ID);
    }
    
    int i;
    String request = "";
    request += ID;
  
    if(digitalRead(buttonPins[0]) == HIGH)
      request += "|0";
    for(int i = 1; i < sizeof(buttonPins) / sizeof(const int); i++) {
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
    
    if (i == (sizeof(buttonPins) / sizeof(const int)))
      digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(100);
}
