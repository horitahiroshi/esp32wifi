
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
  while(ssid == ""){
    Serial.println("Please enter WiFi name:");
    if(SerialBT.available()){
      ssid = SerialBT.readStringUntil('\n');
    }
  }
  while(password == ""){
    Serial.println("Please enter WiFi password:");
    if(SerialBT.available()){
      password = SerialBT.readStringUntil('\n');
    }
  }

  Serial.println(ssid);
  Serial.println(password);

  WiFi.begin(ssid, password);

  int counter = 6;
  while (WiFi.status() != WL_CONNECTED || counter >= 0){
    delay(500);
    Serial.println("Connecting to WiFi ...");
    counter--;
  }

  Serial.println("Connected to the WiFi network.");
}

void loop() {
  if(!WiFi_connected){
    setWiFi();
    delay(20);
  }
  Serial.println("WiFi connected for sure!");
  delay(1000);
}