
#include <Arduino.h>
#include "BluetoothSerial.h"
#include "WiFi.h"

BluetoothSerial SerialBT;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32BT");

}

bool WiFi_connected = false;

void setWiFi(){
  String ssid = "";
  String password = "";
  Serial.println("Let's set the WiFi connection!");
  Serial.println("Please enter WiFi name:");
  while(ssid == ""){
    ssid = SerialBT.readStringUntil('\n');
  }
  Serial.println(ssid);
  Serial.println(ssid.length());

  Serial.println("Please enter WiFi password:");
  while(password == ""){
    password = SerialBT.readStringUntil('\n');
  }
  Serial.println(password);
  Serial.println(password.length());

  WiFi.begin(ssid.substring(0,ssid.length()-1).c_str(), password.substring(0,password.length()-1).c_str());

  int counter = 20;
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting to WiFi ...");
    Serial.println(counter);
    counter--;
    if(counter <= 0){
      Serial.println("Timed out!");
      break;
    }
  }
  if(counter > 0){
    Serial.println("Connected to the WiFi network.");
    WiFi_connected = true;
  }
}

void loop() {
  if(!WiFi_connected){
    setWiFi();
    delay(20);
  } 
  else {
    Serial.println("WiFi connected for sure!");
  }
  delay(1000);
}