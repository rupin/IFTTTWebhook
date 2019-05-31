#include <WiFi.h>
#include "IFTTTWebhook.h"

#define WIFI_SSID "YOUR SSID HERE"
#define	WIFI_PASSWORD "YOUR PASSWORD HERE"

#define IFTTT_API_KEY "YOUR IFTTT KEY HERE"
#define IFTTT_EVENT_NAME "YOUR WEBHOOK EVENT HERE"

void setup() {
  Serial.begin(115200);
  Serial.println("RUNNING");
  
  WiFi.mode(WIFI_STA);
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

  IFTTTWebhook wh(IFTTT_API_KEY, IFTTT_EVENT_NAME);
  wh.trigger();
  //wh.trigger("1");
  //wh.trigger("1", "2");
  //wh.trigger("1", "2", "3");
}

void loop() {
}
