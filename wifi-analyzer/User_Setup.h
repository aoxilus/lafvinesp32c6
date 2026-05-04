// User_Setup.h for UeeKKoo / LAFVIN ESP32-C6-1.47" LCD (ST7789)
// Place this file in: Documents/Arduino/libraries/TFT_eSPI/User_Setup.h
// (Replace the default one or create a new User_Setup_Select.h that includes this)

#define USER_SETUP_ID 0xC647

// Display type and size
#define ST7789_DRIVER
#define TFT_WIDTH  172
#define TFT_HEIGHT 320

// Pin definitions for your board
#define TFT_MOSI  6
#define TFT_SCLK  7
#define TFT_CS    14
#define TFT_DC    15
#define TFT_RST   21
#define TFT_BL    22   // Backlight

// Touch (disabled for now - enable if you have touch working)
#define TOUCH_CS -1

// Font and graphics options
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

// SPI settings
#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000

// Color order and inversion
#define TFT_INVERSION_ON
#define TFT_RGB_ORDER TFT_BGR
