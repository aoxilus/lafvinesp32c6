// Arkanoid guacamole edition: la bola es el carozo, tu paddle es la palita que rescata tostadas.

#include <LovyanGFX.hpp>

// "Red del hueso al mundo": SPI y amigos (sin esto el aguacate no sale del molcajete).
#define TFT_MOSI  6
#define TFT_SCLK  7
#define TFT_CS    14
#define TFT_DC    15
#define TFT_RST   21
#define TFT_BL    22
#define BOOT_BTN  9

// Cristal util ~172x320 (doc LAFVIN). Chip ST7789: RAM horizontal tipica 240; si dibujas "ancho 240" el vidrio solo muestra ~172px -> cortas columnas 1 y 5 a la mitad.
#define TFT_RAM_W 240
#define DISP_W    172
#define DISP_H    320
#define TFT_OFFSET_X ((TFT_RAM_W - DISP_W) / 2)  // 34: centrar ventana visible en la RAM (ajusta +/-2 si ves franja)
#define TFT_OFFSET_Y 0

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789  _panel_instance;
  lgfx::Bus_SPI       _bus_instance;
public:
  LGFX(void) {
    auto bus_cfg = _bus_instance.config();
    bus_cfg.spi_host = SPI2_HOST;
    bus_cfg.freq_write = 40000000;
    bus_cfg.pin_sclk = TFT_SCLK;
    bus_cfg.pin_mosi = TFT_MOSI;
    bus_cfg.pin_miso = -1;
    bus_cfg.pin_dc   = TFT_DC;
    _bus_instance.config(bus_cfg);
    _panel_instance.setBus(&_bus_instance);

    auto panel_cfg = _panel_instance.config();
    panel_cfg.pin_cs     = TFT_CS;
    panel_cfg.pin_rst    = TFT_RST;
    panel_cfg.memory_width  = TFT_RAM_W;
    panel_cfg.memory_height = DISP_H;
    panel_cfg.panel_width   = DISP_W;
    panel_cfg.panel_height  = DISP_H;
    panel_cfg.offset_x     = TFT_OFFSET_X;
    panel_cfg.offset_y     = TFT_OFFSET_Y;
    panel_cfg.offset_rotation = 0;
    panel_cfg.dummy_read_pixel = 8;
    panel_cfg.dummy_read_bits  = 8;
    panel_cfg.invert = true;
    _panel_instance.config(panel_cfg);
    setPanel(&_panel_instance);
  }
};

LGFX tft;

static const int COLS = 5;
static const int ROWS = 10;

bool bricks[ROWS][COLS];           // ¿Siguen enteros o ya son solo recuerdos en el bowl?
uint16_t brickColors[ROWS][COLS];  // Madurez por fila: del verde al "ya está para guacamole".

static const uint16_t palette[] = {
  TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_GREEN, TFT_CYAN,
  TFT_MAGENTA, TFT_BLUE, TFT_PINK, TFT_GOLD, TFT_SKYBLUE
};
static const int paletteN = sizeof(palette) / sizeof(palette[0]);

int W = DISP_W;
int H = DISP_H;

int paddleX = 0;
const int paddleW = 40;
const int paddleH = 7;

int ballX = 0, ballY = 0;
int ballDX = 2, ballDY = -3;
const int ballR = 4;
int ballHue = 0;

int marginX = 4;
int topY = 8;
int brickH = 10;
int gap = 2;
int brickW = 0;
int paddleY = 0;

void nextBallColor() {
  ballHue = (ballHue + 1) % paletteN;  // Rotación de cultivos: otro tono de "aguacatero".
}

void layoutPlayfield() {
  W = tft.width();
  H = tft.height();
  // Si el driver devolviera ancho de RAM (240), el layout ocuparia mas que el cristal y cortaria los lados.
  if (W > DISP_W) W = DISP_W;
  if (H > DISP_H) H = DISP_H;

  marginX = 4;
  topY = 8;
  int innerW = W - 2 * marginX;
  brickW = (innerW - (COLS - 1) * gap) / COLS;
  if (brickW < 8) brickW = 8;

  // La palita vive abajo, como quien defiende el mango del suelo.
  paddleY = H - 14 - paddleH;
  if (paddleY < H / 2) paddleY = H / 2;

  int maxBrickBottom = paddleY - 28;
  int maxBrickH = maxBrickBottom - topY - (ROWS - 1) * gap;
  brickH = maxBrickH / ROWS;
  if (brickH < 8) brickH = 8;
  if (brickH > 14) brickH = 14;
}

void resetBricks() {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      bricks[r][c] = true;
      brickColors[r][c] = palette[(r + c) % paletteN];  // Huerto nuevo: todos los frutos en pie.
    }
  }
}

void resetBall() {
  ballX = W / 2;
  ballY = paddleY - 24;
  ballDX = (random(0, 2) ? 2 : -2);
  ballDY = -3;
  nextBallColor();  // Carozo relanzado: va con outfit nuevo.
}

void clampBall() {
  int minX = ballR;
  int maxX = W - 1 - ballR;
  int minY = ballR;
  int maxY = H - 1 - ballR;
  if (ballX < minX) ballX = minX;
  if (ballX > maxX) ballX = maxX;
  if (ballY < minY) ballY = minY;
  if (ballY > maxY) ballY = maxY;
}

void setup() {
  pinMode(BOOT_BTN, INPUT_PULLUP);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);  // Luz: sin esto el aguacate está en la bolsa oscura del súper.

  tft.init();
  tft.setRotation(0);
  tft.setBrightness(200);

  layoutPlayfield();

  paddleX = (W - paddleW) / 2;
  resetBricks();
  resetBall();
}

void loop() {
  const int spd = 6;
  // BOOT: empujas la palita a la izquierda; sueltas y corre a la derecha (aguacate que no coopera).
  if (digitalRead(BOOT_BTN) == LOW) {
    paddleX -= spd;
  } else {
    paddleX += spd;
  }
  if (paddleX < 0) paddleX = 0;
  if (paddleX > W - paddleW) paddleX = W - paddleW;

  ballX += ballDX;
  ballY += ballDY;

  // Rebote en paredes: el carozo no perfora la cáscara del LCD.
  if (ballX - ballR <= 0) {
    ballX = ballR;
    ballDX = -ballDX;
    nextBallColor();
  } else if (ballX + ballR >= W - 1) {
    ballX = W - 1 - ballR;
    ballDX = -ballDX;
    nextBallColor();
  }

  if (ballY - ballR <= 0) {
    ballY = ballR;
    ballDY = -ballDY;
    nextBallColor();
  }

  // Aterrizaje en la palita: si cae bien, no hay guacamole en el piso.
  if (ballY + ballR >= paddleY &&
      ballY - ballR <= paddleY + paddleH &&
      ballX + ballR >= paddleX &&
      ballX - ballR <= paddleX + paddleW) {
    ballY = paddleY - ballR - 1;
    ballDY = -abs(ballDY);
    ballDX += (ballX - (paddleX + paddleW / 2)) / 5;
    if (ballDX > 5) ballDX = 5;
    if (ballDX < -5) ballDX = -5;
    nextBallColor();
  }

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (!bricks[r][c]) continue;
      int bx = marginX + c * (brickW + gap);
      int by = topY + r * (brickH + gap);
      int bw = brickW;
      int bh = brickH;
      if (bx + bw > W) bw = W - bx;
      if (by + bh > H) bh = H - by;
      if (bw <= 0 || bh <= 0) continue;

      if (ballX + ballR > bx && ballX - ballR < bx + bw &&
          ballY + ballR > by && ballY - ballR < by + bh) {
        bricks[r][c] = false;  // ¡Splat! Ese aguacate ya es dip.
        ballDY = -ballDY;
        nextBallColor();
      }
    }
  }

  bool any = false;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (bricks[r][c]) {
        any = true;
        break;
      }
    }
    if (any) break;
  }

  // Se cayó al vacío o limpiaste el árbol: nueva pala de mercado.
  if (ballY - ballR > H - 2 || !any) {
    layoutPlayfield();
    resetBricks();
    resetBall();
    paddleX = (W - paddleW) / 2;
  }

  clampBall();

  tft.fillScreen(TFT_BLACK);

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (!bricks[r][c]) continue;
      int bx = marginX + c * (brickW + gap);
      int by = topY + r * (brickH + gap);
      int bw = brickW;
      int bh = brickH;
      if (bx < 0 || by < 0) continue;
      if (bx + bw > W) bw = W - bx;
      if (by + bh > H) bh = H - by;
      if (bw > 0 && bh > 0) {
        tft.fillRect(bx, by, bw, bh, brickColors[r][c]);
      }
    }
  }

  int px = paddleX;
  int pw = paddleW;
  if (px + pw > W) pw = W - px;
  if (pw > 0 && paddleY + paddleH <= H) {
    tft.fillRoundRect(px, paddleY, pw, paddleH, 2, TFT_WHITE);  // Palita blanca: no dejes que escape el verde.
  }

  if (ballX >= ballR && ballX < W - ballR && ballY >= ballR && ballY < H - ballR) {
    tft.fillCircle(ballX, ballY, ballR, palette[ballHue % paletteN]);  // El carozo polícromo.
  }

  delay(33);  // ~30 FPS: maduración frame a frame.
}
