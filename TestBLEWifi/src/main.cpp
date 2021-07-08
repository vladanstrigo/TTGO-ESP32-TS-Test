#include <TFT_eSPI.h>
#include <Arduino.h>
#include "BLEDevice.h"
#include "mydatatypes.h"
#include <SPI.h>
#include <Wire.h>
// #include <LCD.h>

HardwareSerial commSerial(0);

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

void setup() {
	commSerial.begin(115200, SERIAL_8N1, 0, 1);
	commSerial.println("Starting TTGO TS BLEWifiTest");
	// lcdStartup();

  	tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(0, 0);

    if (TFT_BL > 0) {
        pinMode(TFT_BL, OUTPUT);
        digitalWrite(TFT_BL, HIGH);
    }

 	tft.fillScreen(TFT_BLACK);
    tft.setTextFont(2);
	tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString("BLA BLA!!!", 10, 10);
}

void loop() {
//   showMessage((char*)"Radiii");
}