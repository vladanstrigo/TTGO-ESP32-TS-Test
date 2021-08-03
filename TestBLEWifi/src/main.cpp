#include <Arduino.h>
#include "BLEDevice.h"
#include "BLE2902.h"

#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char* ssid = "ESP32 VLADAN WIFI";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

WebServer server(80);


HardwareSerial commSerial(0);

BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
int sensorvalue = 0;

std::string format(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char smallBuffer[1024];
    int size = vsnprintf(smallBuffer, sizeof smallBuffer, format, args);
    va_end(args);

    if (size < sizeof smallBuffer) 
        return std::string(smallBuffer);

    char buffer[size  + 1]; /* maybe malloc if it's too big */

    va_start(args, format);
    vsnprintf(buffer, sizeof buffer, format, args);
    va_end(args);
    return std::string(buffer);
}

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };
    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void handle_OnConnect() {
  commSerial.println("ON CONNECT!!!");
  server.send(200, "text/html", "ON CONNECT HTML OUTPUT!!!\n"); 
}
void handle_OnHello() {
  commSerial.println("ON HELLO!!!");
  server.send(200, "text/html", "HELLO WORLD HTML OUTPUT!!!\n"); 
}

void setup() {
	commSerial.begin(115200, SERIAL_8N1, 0, 1);
	commSerial.println("Starting TTGO TS BLEWifiTest - BLE");

    commSerial.begin(115200);
    pinMode(5, OUTPUT);      // set the LED pin mode

    delay(10);

    BLEDevice::init("ESP32 VLADAN");
    BLEServer* pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());
		
    BLEService* pService = pServer->createService("91bad492-b950-4226-aa2b-4ede9fa42f59");

    pCharacteristic = pService->createCharacteristic(
        BLEUUID("0d563a58-196a-48ce-ace2-dfec78acc814"),
        BLECharacteristic::PROPERTY_BROADCAST | BLECharacteristic::PROPERTY_READ  |
        BLECharacteristic::PROPERTY_NOTIFY    | BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_INDICATE
    );

    BLE2902* p2902Descriptor = new BLE2902();
    p2902Descriptor->setNotifications(true);
    pCharacteristic->addDescriptor(p2902Descriptor);

    pService->start();

    BLEAdvertising* pAdvertising = pServer->getAdvertising();
    pAdvertising->addServiceUUID(BLEUUID(pService->getUUID()));
    pAdvertising->start();

    WiFi.softAP(ssid, password);
    delay(100);
  
    server.on("/", handle_OnConnect);
    server.on("/hello", handle_OnHello);
    server.begin();
}

void loop() 
{
    server.handleClient();

    if (deviceConnected) {
        sensorvalue += 1;
        pCharacteristic->setValue(format("BLE value: %d", sensorvalue));
        pCharacteristic->notify();
        commSerial.println("Sent value : " + String(sensorvalue));
    }
    else {
        commSerial.println("Not yet connected!");
    }
    delay(1000);
}