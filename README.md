# 🥑 lafvinesp32c6

**ESP32-C6 + 1.47" ST7789 projects by [aoxilus](https://github.com/aoxilus)**  
*In Mexico, avocado is luxury. So if we are spending luxury money, the pixels better line up.* 😄🥑👾

This repo is for the **LAFVIN / UeeKKoo ESP32-C6 1.47" LCD** board: game tests, display experiments, and WiFi stuff.

## 🇬🇧 English
### What is here?

- 🎮 `arkanoid/arkanoid.ino`: the main Arduino sketch.
- 🥑 `arkanoid/ARKANOID.md`: same code, easy to copy/paste.
- 📡 `wifi-analyzer/`: PlatformIO experiment folder.
- 🧪 `test/`: quick hardware tests and helper scripts.

### Arduino steps

1. 🧩 Install [Arduino IDE](https://www.arduino.cc/en/software).
2. 🔧 In **Boards Manager**, install **ESP32 by Espressif**.
3. 🛠️ Select board: **ESP32C6 Dev Module**.
4. 📚 In **Library Manager**, install **LovyanGFX**.
5. 📂 Open `arkanoid/arkanoid.ino`.
6. 🔌 Select your USB **COM** port.
7. ▶️ Click **Upload**.

### How to play

- 👈 Hold **BOOT** = paddle goes left.
- 👉 Release **BOOT** = paddle goes right.

### Video

- 📺 YouTube demo: [Watch here](https://www.youtube.com/watch?v=qAq44lFisYs)

### Display findings

- 📏 Official LAFVIN docs point to **172x320** for this screen: [Arduino tutorial](https://lafvin-esp32-c6-147lcd.readthedocs.io/en/latest/Tutorial/2.arduino.html).
- 🧠 The **ST7789** often behaves like it has **240 columns of RAM**, but the visible glass is still around **172 pixels wide**.
- ⚠️ If you force **240** as the visible width, the **first and last bricks look cut in half**.
- ✅ The current Arkanoid setup uses:
  - `memory_width = 240`
  - `panel_width = 172`
  - `offset_x = 34`
- 🔍 If the image still looks shifted, tweak `TFT_OFFSET_X` a little.

## 🇪🇸 Español
### ¿Qué hay aquí?

- 🎮 `arkanoid/arkanoid.ino`: el sketch principal de Arduino.
- 🥑 `arkanoid/ARKANOID.md`: el mismo código, fácil de copiar y pegar.
- 📡 `wifi-analyzer/`: carpeta de experimentos con PlatformIO.
- 🧪 `test/`: pruebas rápidas de hardware y scripts auxiliares.

### Pasos en Arduino

1. 🧩 Instala [Arduino IDE](https://www.arduino.cc/en/software).
2. 🔧 En **Gestor de tarjetas**, instala **ESP32 by Espressif**.
3. 🛠️ Elige la placa: **ESP32C6 Dev Module**.
4. 📚 En **Gestor de librerías**, instala **LovyanGFX**.
5. 📂 Abre `arkanoid/arkanoid.ino`.
6. 🔌 Elige el puerto **COM** correcto.
7. ▶️ Pulsa **Subir**.

### Cómo jugar

- 👈 Mantén **BOOT** = la paleta va a la izquierda.
- 👉 Suelta **BOOT** = la paleta va a la derecha.

### Video

- 📺 Demo en YouTube: [Ver aquí](https://www.youtube.com/watch?v=qAq44lFisYs)

### Hallazgos de la pantalla

- 📏 La documentación oficial de LAFVIN apunta a **172x320** para esta pantalla: [tutorial Arduino](https://lafvin-esp32-c6-147lcd.readthedocs.io/en/latest/Tutorial/2.arduino.html).
- 🧠 El **ST7789** muchas veces se comporta como si tuviera **240 columnas de RAM**, aunque el cristal visible siga siendo de unos **172 px**.
- ⚠️ Si fuerzas **240** como ancho visible, **el primer y el último bloque se ven partidos**.
- ✅ La configuración actual de Arkanoid usa:
  - `memory_width = 240`
  - `panel_width = 172`
  - `offset_x = 34`
- 🔍 Si la imagen todavía se ve corrida, ajusta un poco `TFT_OFFSET_X`.

## 📁 Notes / Notas

- `ARKANOID.md` and `arkanoid.ino` contain the same source.
- `wifi-analyzer/` uses PlatformIO. Build with `pio run`.
- `test/` stores the diagnostic sketches and PowerShell helpers that were used to bring up the board.

## 📜 License

This repo is shared under the **MIT License**.  
Code should be easier to share than avocado should be to afford. 🥑

Share and learn / Comparte y aprende 🎉🕹️👾
