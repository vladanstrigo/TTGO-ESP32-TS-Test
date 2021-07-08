#define ST7735_DRIVER

#define TFT_WIDTH  128
#define TFT_HEIGHT 160

#define INITR_GREENTAB2
// #define ST7735_GREENTAB

#define TFT_MISO    -1
#define TFT_MOSI    23
#define TFT_SCLK    5
#define TFT_CS      16  // Chip select control pin
#define TFT_DC      17  // Data Command control pin
#define TFT_RST     -1  // Reset pin (could connect to RST pin)
#define TFT_BL      27

#define LOAD_GLCD  // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2 // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4 // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6 // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7 // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:.
#define LOAD_FONT8 // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT

#define SPI_FREQUENCY  20000000 // Maximum to use SPIFFS

#define SUPPORT_TRANSACTIONS
