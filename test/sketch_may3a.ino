#include <LovyanGFX.hpp>
#include <WiFi.h>

// Pin definitions for UeeKKoo ESP32-C6-1.47" LCD
#define TFT_MOSI  6
#define TFT_SCLK  7
#define TFT_CS    14
#define TFT_DC    15
#define TFT_RST   21
#define TFT_BL    22

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789  _panel_instance;
  lgfx::Bus_SPI       _bus_instance;
public:
  LGFX(void) {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = SPI2_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = 40000000;
      cfg.freq_read  = 16000000;
      cfg.spi_3wire  = false;
      cfg.use_lock   = true;
      cfg.dma_channel = 1;
      cfg.pin_sclk = TFT_SCLK;
      cfg.pin_mosi = TFT_MOSI;
      cfg.pin_miso = -1;
      cfg.pin_dc   = TFT_DC;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }
    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs     = TFT_CS;
      cfg.pin_rst    = TFT_RST;
      cfg.pin_busy   = -1;
      cfg.memory_width  = 172;
      cfg.memory_height = 320;
      cfg.panel_width   = 172;
      cfg.panel_height  = 320;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits  = 8;           // Fixed: was dummy_read_byte
      cfg.readable = true;
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;
      _panel_instance.config(cfg);
    }
    setPanel(&_panel_instance);
  }
};

LGFX tft;

void setup() {
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);           // Try values 0,1,2,3 if screen is upside down or mirrored
  tft.setBrightness(180);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(TFT_CYAN);
  tft.setCursor(15, 25);
  tft.println("WiFi Scanner");

  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(15, 55);
  tft.println("ESP32-C6 1.47\" LCD");
  tft.println("Ready - Scanning...");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println("LCD + WiFi Scanner initialized successfully!");
}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(5, 8);
  tft.setTextColor(TFT_YELLOW);
  tft.println(" Scanning WiFi...");

  int n = WiFi.scanNetworks(false, true);

  tft.setTextColor(TFT_CYAN);
  tft.setCursor(5, 35);
  tft.printf("Found: %d networks\n\n", n);

  for (int i = 0; i < min(n, 8); i++) {
    tft.setCursor(5, 65 + i*22);
    String ssid = WiFi.SSID(i);
    if (ssid.length() > 14) ssid = ssid.substring(0, 12) + "..";

    tft.setTextColor(TFT_GREEN);
    tft.print(ssid);
    tft.setTextColor(TFT_WHITE);
    tft.printf(" %d", WiFi.RSSI(i));
    tft.setTextColor(TFT_ORANGE);
    tft.printf(" Ch%d", WiFi.channel(i));
  }

  tft.setCursor(5, 265);
  tft.setTextColor(TFT_DARKGREY);
  tft.println("Next scan in 8 seconds");

  Serial.printf("Scan #%d - Found %d networks\n", millis()/8000, n);
  delay(8000);
}
