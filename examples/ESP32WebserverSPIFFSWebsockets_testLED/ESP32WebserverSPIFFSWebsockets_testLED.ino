#include <Arduino.h>
#include "heartBeat.h"
#include "esp32WebserverSPIFFSWebsockets.h"

#define USE_SERIAL Serial

const char* ssid     = "BioVendorIns";
const char* password = "H3sloB101NS#";

HeartBeat heart(LED_BUILTIN);
Esp32WebserverSPIFFS server(ssid, password);

void setup() {
  delay(2000); 
  
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  server.init();
  
}

void loop() {
  heart.run();
  //server.loop();
}
