//lcd 128 x 160 px

#define LCDCONSTRUCTOR TFT_eSPI
LCDCONSTRUCTOR tft = TFT_eSPI();

#define SPRITECONSTRUCTOR TFT_eSprite
SPRITECONSTRUCTOR bar = TFT_eSprite(&tft);

void showMessage(char *message) {
    tft.println(message);  
}

void lcdStartup()
{
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(3, 5);

    if (TFT_BL > 0) {
        pinMode(TFT_BL, OUTPUT);
        digitalWrite(TFT_BL, HIGH);
    }  

    tft.println("Starting TTGO TS BleWifiTest");
}