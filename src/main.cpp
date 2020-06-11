#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "esp_bt.h"
#include "nvs_flash.h"
#include "esp_bt_device.h"
#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"
#include "esp_gatt_defs.h"
#include "esp_bt_main.h"
#include "esp_system.h"
#include "esp_gatt_common_api.h"
#include "esp_log.h"
#include "driver/uart.h"

#define SCAN_ALL_THE_TIME

int scanTime = 5; 

BLEScan* pBLEScan;
unsigned long lastMillis = 0;

void connect(){

  print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED){
 print(".");
  delay(1000);
  }
 
print("\nconnecting...");
  while (!client.connect("arduinoESP32")) {
  print(".");
  delay(1000);
  }

  println("\nconnected!");
  client.subscribe("/clientSub");
  }

  void messageReceived(String &topic, String &payload) {
  println("incoming: " + topic + " - " + payload);
  }
 

  class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
      void onResult(BLEAdvertisedDevice advertisedDevice){
       printf("Advertised Device: %s \n",advertisedDevice.toString().c_str());
    }
};





  
  while (WiFi.status() != WL_CONNECTED){
   delay(500);
   printt(".");
   }
  println("");
  println("WiFi connected");
  println("IP address: ");
  
  .println(WiFi.localIP());{
    client.begin("mqtt.eclipse.org", net);
    client.onMessage(messageReceived);
    connect();
    }
 
  println("Scanning...");
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); 
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); 
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);


void app_main(void) 
{
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  printt("Devices found: ");
  println(foundDevices.getCount());
  println("Scan done!");
  pBLEScan->clearResults(); 
  delay(2000);
  
client.loop();
 delay(10); 

if (!client.connected()){
  connect();
  }
  
if (millis() - lastMillis > 6000){
    lastMillis = millis();
    client.publish("/clientPub", "foundDevices.getCount()");
  }
}