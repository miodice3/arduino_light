#include "env_variables.h"  

#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiMulti.h>
#include <WiFiUdp.h>
#include <WiFiScan.h>
#include <ETH.h>
#include <WiFiClient.h>
#include <WiFiSTA.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiGeneric.h>

void join_wifi_network(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi Network: " + String(ssid));
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print('.');
      delay(1000);
    }
    Serial.println(WiFi.localIP());
}

void re_join_network_if_needed(){
    if (WiFi.status() != WL_CONNECTED) {
        int i = 0;
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, pass);
        Serial.println("Attempting reconnect to WiFi Network: " + String(ssid));
        while (WiFi.status() != WL_CONNECTED) {
            i = i + 1;
            delay(1000);
                if (i >= 15) {
                re_join_network_if_needed();
            }
        }
        Serial.println("Reconnected to WiFi Network: " + String(ssid));
        Serial.println(WiFi.localIP());
    }
}
