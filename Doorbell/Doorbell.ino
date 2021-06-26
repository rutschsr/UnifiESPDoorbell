
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
// created with help from circuits4you.com NodeMCU ESP8266 Arduino WiFi Web Server LED on off control
//https://circuits4you.com/2018/02/05/esp8266-arduino-wifi-web-server-led-on-off-control/
//https://github.com/rutschsr/UnifiESPDoorbell
//---------------------------------------------------------------
//Our HTML webpage contents:
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>WiFi Doorbell Chime Ringer</h1><br>
Ciclk to Ring <a href="Front">Front Doorbell</a><br>
Ciclk to Ring <a href="Rear">Rear Doorbell</a><br>
<hr>
<a href="https://github.com/rutschsr/UnifiESPDoorbell">Github</a>
</center>
2021 June 11
<br>
Sam Rutschilling
<br>
v1.1
</body>
</html>
)=====";
//---------------------------------------------------------------
//On board LED Connected to GPIO2
//#define LED 2 
#define FrontDoor 1
#define RearDoor 3
#define WiLight 15
#define FrontDoor1 12
#define RearDoor1 14
#define WiLight1 2 

//SSID and Password of your WiFi router
const char* ssid = "SSID";
const char* password = "Password";

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80


void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleFront() { 
 
 digitalWrite(FrontDoor,HIGH); //LED is connected in reverse
 //server.send(200, "text/html", "LED is ON"); //Send ADC value only to client ajax request
 delay(150);
 digitalWrite(FrontDoor,LOW);
 handleRoot();
 
}

void handleRear() { 
 digitalWrite(RearDoor,HIGH);
 delay(150);
 digitalWrite(RearDoor,LOW);
 handleRoot();
}

void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);     //Connect to Wifi
  Serial.println("");

//Define Pins for 3 outputs
  pinMode(FrontDoor,OUTPUT);
  pinMode(RearDoor,OUTPUT);
  pinMode(WiLight,OUTPUT);
  pinMode(FrontDoor1,OUTPUT);
  pinMode(RearDoor1,OUTPUT);
  pinMode(WiLight1,OUTPUT);
  //Power on LED state off
  digitalWrite(FrontDoor,HIGH);
  digitalWrite(RearDoor,HIGH);
  digitalWrite(WiLight,HIGH);
  digitalWrite(FrontDoor1,HIGH);
  digitalWrite(RearDoor1,HIGH);
  digitalWrite(WiLight1,HIGH);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //If connection successful turn on LED
  digitalWrite(WiLight,HIGH);
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/Rear", handleRear);
  server.on("/Front", handleFront);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
  void(* resetFunc) (void) = 0;//declare reset function at address 0

void loop(void){
  server.handleClient(); //Handle client requests
  //handle Wifi Disconnects:
  if (WiFi.status() != WL_CONNECTED){
    resetFunc(); //Just Resets the device if Wifi Disconnects, then it can gracefully reconnect
  }
  
  }
  
