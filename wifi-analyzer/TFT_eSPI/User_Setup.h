// User_Setup.h for UeeKKoo / LAFVIN-style ESP32-C6-1.47" ST7789 LCD
// Pins from Waveshare/Spotpear docs for this exact board

#define USER_SETUP_ID 0xC647

// Define the width and height in pixels
#define TFT_WIDTH  172
#define TFT_HEIGHT 320

// ST7789 driver
#define ST7789_DRIVER

// ESP32-C6 SPI pins for this board
#define TFT_MOSI 6
#define TFT_SCLK 7
#define TFT_CS   14   // Chip select control pin
#define TFT_DC   15   // Data Command control pin
#define TFT_RST  21   // Reset pin (could be -1 if connected to ESP32 EN)
#define TFT_BL   22   // Backlight control pin (PWM capable)

// Optional touch support (if your board has it - many variants do via GT911 or similar)
#define TOUCH_CS -1   // Set to pin if you have touch

// Font and color depth
#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48

#define SMOOTH_FONT

// SPI frequency
#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000

// Backlight
#define TFT_INVERSION_ON
#define TFT_RGB_ORDER TFT_BGR
