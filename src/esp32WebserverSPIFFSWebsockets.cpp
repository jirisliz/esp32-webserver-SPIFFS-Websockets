#include "esp32WebserverSPIFFSWebsockets.h"

bool Esp32WebserverSPIFFS::initWifi(){
      if(mSsid == NULL || mPass == NULL)
      {
        Serial.println("initWifi Error has occurred.");
        return false;
      }
      
      // Connect to Wi-Fi
      WiFi.begin(mSsid, mPass);
      Serial.println("Connecting to WiFi..");
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.printf(".");
      }
      
      // Print ESP32 Local IP Address
      Serial.println("");
      Serial.println(WiFi.localIP());

      return true;
    }

    bool Esp32WebserverSPIFFS::initWebsockets(){
      //mWebSocket = new WebSocketsServer(mWebsocketsPort);

      return true;
    }

    bool Esp32WebserverSPIFFS::initSPIFFS(){
      // Init SPIFFS
      if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return false;
      }
      return true;
    }

    bool Esp32WebserverSPIFFS::initAP(){
      
    }

    bool Esp32WebserverSPIFFS::initServer(){
      mServer = new AsyncWebServer(mServerPort);
      
      // Route server index page
      mServer->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", String(), false);
      });

      // Route server style
      mServer->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/style.css", "text/css");
      });
      mServer->begin();

      return true;
    }

// Public
  
    Esp32WebserverSPIFFS::Esp32WebserverSPIFFS(const char *aSsid, const char *aPass){
      if(aSsid != NULL)mSsid = aSsid;
      else mSsid = NULL;
      if(aPass != NULL)mPass = aPass;
      else mPass = NULL;
      
    }

    EErrCodes Esp32WebserverSPIFFS::init(){
      
      Serial.printf("SSID: %s \n", mSsid);
      Serial.printf("PASS: %s \n", mPass);
      
      // Wifi init
      if(!initWifi())return wifi_init_fail;
      Serial.println("Wifi initialized.");

      // SPIFFS init
      if(!initSPIFFS())return spiffs_init_fail;
      Serial.println("SPIFFS initialized.");

      // Websockets init
      if(!initWebsockets())return websockets_init_fail;
      Serial.println("Websockets initialized.");

      // Server init
      if(!initServer())return server_init_fail;
      Serial.println("Server initialized.");
      
    }

    void Esp32WebserverSPIFFS::loop(){
      //mWebSocket->loop();
    }
