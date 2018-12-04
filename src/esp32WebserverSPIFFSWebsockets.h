#ifndef __ESP32WEBSERVERSPIFFSWEBSOCKETS__
#define __ESP32WEBSERVERSPIFFSWEBSOCKETS__

#include "Arduino.h"

#include <WiFi.h>
#include <WebSocketsServer.h>
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

typedef enum {
  wifi_init_fail, 
  spiffs_init_fail, 
  server_init_fail, 
  websockets_init_fail,
}EErrCodes;

class Esp32WebserverSPIFFS {
  private:
    const char *mSsid;
    const char *mPass;
    uint16_t mServerPort = 80;
    uint16_t mWebsocketsPort = 81;
    
    AsyncWebServer *mServer;
    WebSocketsServer *mWebSocket;

    bool initWifi();
    bool initWebsockets();
    bool initSPIFFS();
    bool initAP();
    bool initServer();
  
  public:  
    Esp32WebserverSPIFFS(const char *aSsid, const char *aPass);
    EErrCodes init();
    void loop();
};

#endif
