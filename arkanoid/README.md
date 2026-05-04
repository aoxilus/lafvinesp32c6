# 🥑 Arkanoid

Mini Arkanoid para la placa **LAFVIN / UeeKKoo ESP32-C6 1.47" LCD** con pantalla **ST7789**.

## 🇬🇧 English

### What it does

- 👾 Draws a **5 x 10** brick field.
- 🌈 The ball changes color when it bounces or breaks bricks.
- 🕹️ Uses the **BOOT** button (`GPIO 9`) to move the paddle:
  - hold = left
  - release = right
- 🖥️ Uses **240 RAM width**, **172x320 visible area**, and `offset_x = 34`.

### Files

- `arkanoid.ino` → main Arduino IDE sketch.
- `ARKANOID.md` → same source, easy to copy/paste.

### Libraries / dependencies

- **LovyanGFX**

Install in Arduino IDE:

1. Open **Library Manager**.
2. Search for **LovyanGFX**.
3. Install it.

### How to run

1. Open `arkanoid.ino` in Arduino IDE.
2. Select **ESP32C6 Dev Module**.
3. Select the correct **COM** port.
4. Upload the sketch ▶️

### Display note

Official LAFVIN docs point to **172x320**, but the **ST7789** often exposes **240 RAM columns**.  
That is why this sketch uses:

- `memory_width = 240`
- `panel_width = 172`
- `offset_x = 34`

If you see a strip or shifted image, tweak `TFT_OFFSET_X`.

### Video

- 📺 YouTube demo: [Watch here](https://www.youtube.com/watch?v=qAq44lFisYs)

## 🇪🇸 Español

### Qué hace

- 🎮 Dibuja un campo de **5 x 10** ladrillos.
- 🌈 La bola cambia de color al rebotar o romper ladrillos.
- 🕹️ Usa el botón **BOOT** (`GPIO 9`) para mover la paleta:
  - mantener = izquierda
  - soltar = derecha
- 🖥️ Configura la pantalla con **RAM 240**, **visible 172x320** y `offset_x = 34`.

### Archivos

- `arkanoid.ino` → sketch principal para Arduino IDE.
- `ARKANOID.md` → copia del mismo código para copiar/pegar fácil.

### Librerías / dependencias

- **LovyanGFX**

Instalación en Arduino IDE:

1. Abre **Gestor de librerías**.
2. Busca **LovyanGFX**.
3. Instálala.

### Cómo correrlo

1. Abre `arkanoid.ino` en Arduino IDE.
2. Selecciona la placa **ESP32C6 Dev Module**.
3. Selecciona el puerto **COM** correcto.
4. Sube el sketch ▶️

### Nota de pantalla

La documentación de LAFVIN apunta a **172x320**, pero el **ST7789** suele exponer **240 columnas de RAM**.  
Por eso este sketch usa:

- `memory_width = 240`
- `panel_width = 172`
- `offset_x = 34`

Si ves una franja o la imagen corrida, ajusta `TFT_OFFSET_X`.

### Video

- 📺 Demo en YouTube: [Ver aquí](https://www.youtube.com/watch?v=qAq44lFisYs)
