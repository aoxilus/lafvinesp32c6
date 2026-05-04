#include <LovyanGFX.hpp>
#include <WiFi.h>

// ================== PIN DEFINITIONS FOR YOUR BOARD ==================
#define TFT_MOSI  6
#define TFT_SCLK  7
#define TFT_CS    14
#define TFT_DC    15
#define TFT_RST   21
#define TFT_BL    22
// ===================================================================

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
      cfg.dummy_read_bits  = 8;
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
  delay(500);

  // Turn on backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.init();
  tft.setRotation(1);        // Try 0, 1, 2, 3 if the image is rotated
  tft.setBrightness(200);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(TFT_CYAN);
  tft.setCursor(20, 30);
  tft.println("WiFi Scanner");

  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(20, 70);
  tft.println("ESP32-C6 + 1.47\" LCD");
  tft.println("SD Card Ready");
  tft.println("Scanning networks...");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("\n=== SYSTEM READY ===");
  Serial.println("LCD should now be showing text.");
  Serial.println("WiFi scanning started.");
}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(5, 10);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.println(" Scanning...");

  int n = WiFi.scanNetworks(false, true);

  tft.setTextColor(TFT_CYAN);
  tft.setTextSize(1);
  tft.setCursor(5, 45);
  tft.printf("Found: %d networks\n\n", n);

  for (int i = 0; i < min(n, 9); i++) {
    tft.setCursor(5, 75 + i*18);
    String ssid = WiFi.SSID(i);
    if (ssid.length() > 15) ssid = ssid.substring(0,13) + "..";

    tft.setTextColor(TFT_GREEN);
    tft.print(ssid);
    tft.setTextColor(TFT_WHITE);
    tft.printf(" %d", WiFi.RSSI(i));
    tft.setTextColor(TFT_ORANGE);
    tft.printf(" Ch%d", WiFi.channel(i));
  }

  tft.setCursor(5, 270);
  tft.setTextColor(TFT_DARKGREY);
  tft.println("Next scan in 8s");

  Serial.printf("Scan complete - %d networks found\n", n);
  delay(8000);
}
