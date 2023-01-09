//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Redmi Note 10 Pro"  // Replace with your network credentials
#define STAPSK  "varsha"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int A,B,C,D;

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);  
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);  
  pinMode(8, OUTPUT);  
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  //U=digitalRead(2);
  //V=digitalRead(4);
  //W=digitalRead(6);
W= (!A&&B&&D) || (!A&&B&&C) || (A&&!B&&!C);
X= (!A&&!B&&D) || (!A&&!B&&C) || (!A&&B&&!C&&!D) || (A&&!B&&!C&&D);
Y= (!A&&!C&&!D) || (!A&&C&&D) || (A&&!B&&!C&&!D);
Z= (!A&&!D) || (A&&!B&&!C&&!D);
a= (!W&&X&&!Y&&!Z);
b= (!W&&X&&!Y&&Z) || (!W&&X&&Y&&!Z) || (W&&X&&!Y&&!Z);
c= (W&&X&&!Y&&!Z);
d= (!W&&X&&!Y&&!Z) || (!W&&X&&Y&&Z) || (W&&!X&&Y&&!Z);
e= (!W&&Y&&Z) || (!W&&X&&!Y) || (W&&!X&&!Y&&Z);
f= (!W&&Y&&Z);
g= (!W&&X&&Y&&Z) || (W&&X&&!Y&&!Z);
  digitalWrite(2, a); //LSB
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g);

}

