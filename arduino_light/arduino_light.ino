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


#include "env_variables.h"

void setup() {
    Serial.begin(9600);
    Serial.println("Connecting to:");
    Serial.println(ssid);
    Serial.println(pass);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print('.');
      delay(1000);
    }
//    Serial.println(WiFi.localIP());
    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
