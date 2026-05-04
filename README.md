# 🥑 lafvinesp32c6

**ESP32-C6 + 1.47" ST7789 (LAFVIN / UeeKKoo) — by [aoxilus](https://github.com/aoxilus)**  
*Guacamole dev kit energy: break bricks, not avocados.* 🎮

---

## 🇬🇧 English — Quick start (Arduino / Arkanoid)

1. 🧩 **Install [Arduino IDE](https://www.arduino.cc/en/software)** (2.x is fine).
2. 🔧 **Board support:** add the **ESP32** package in *Boards Manager* (Espressif). Select **ESP32C6 Dev Module** (or your equivalent).
3. 📚 **Library:** open *Library Manager* → install **LovyanGFX** (author: lovyan03).
4. 📂 **Open** this repo folder → open `arkanoid/arkanoid.ino`.
5. 🔌 **USB:** pick the right **COM port**, then **Upload** ▶️.

**Play:** use the **BOOT** button (GPIO `9`) — hold = paddle left, release = paddle right (as in the sketch).

---

## 🇪🇸 Español — Inicio rápido (Arduino / Arkanoid)

1. 🧩 **Instala [Arduino IDE](https://www.arduino.cc/en/software)**.
2. 🔧 **Placa:** en *Gestor de tarjetas* instala el paquete **ESP32** (Espressif). Elige **ESP32C6 Dev Module** (o la tuya).
3. 📚 **Librería:** *Gestor de librerías* → instala **LovyanGFX** (lovyan03).
4. 📂 **Abre** la carpeta del repo → abre `arkanoid/arkanoid.ino`.
5. 🔌 **USB:** elige el **puerto COM** correcto y pulsa **Subir** ▶️.

**Jugar:** botón **BOOT** (GPIO `9`) — mantener = paleta a la izquierda, soltar = a la derecha (según el sketch).

---

## 🖥️ Display notes (what we learned) / Notas de pantalla

| Topic | English | Español |
|--------|---------|---------|
| **Doc size** | LAFVIN lists **172×320** for this 1.47" panel (e.g. [Arduino tutorial / PNG size](https://lafvin-esp32-c6-147lcd.readthedocs.io/en/latest/Tutorial/2.arduino.html)). | LAFVIN documenta **172×320** para este panel 1.47" (p. ej. imágenes en el tutorial). |
| **ST7789 RAM** | The controller often has **240** columns of memory; the **visible glass** is still **~172** px wide. If you set “width 240” for *everything*, the first/last columns look **cut in half** — you must use **panel width 172** + **offset** in the driver, not a fake width. | El ST7789 suele tener **240** columnas de RAM; el **cristal** muestra **~172** px. Si usas ancho 240 para todo, la 1.ª y 5.ª columna se ven **a medias** → hay que usar **ancho de panel 172** + **offset** en el driver, no “inventar” píxeles. |
| **This repo (Arkanoid)** | `arkanoid.ino` uses `memory_width = 240`, `panel_width = 172`, `offset_x = 34` to **center** the 172px window in RAM. Tweak `TFT_OFFSET_X` ±1–2 if a strip looks off. | En `arkanoid.ino`: `memory_width = 240`, `panel_width = 172`, `offset_x = 34` para **centrar** la ventana. Ajusta `TFT_OFFSET_X` si ves franjas. |

`ARKANOID.md` = same source as `arkanoid.ino` (copy/paste friendly).

---

## 📁 Repo layout

| Path | What |
|------|------|
| `arkanoid/` | 🥑 **Arkanoid** (LovyanGFX) — main game sketch |
| `wifi-analyzer/` | PlatformIO + Arduino core (see `platformio.ini`) |
| `*.ino` (root) | Small display / test sketches |

**PlatformIO:** `cd wifi-analyzer` → `pio run` (`.pio/` is gitignored; libs re-download on first build).

---

## 🌐 Make this repo **public** on GitHub

Git can’t change visibility. In the browser: **Repository → Settings → General → Danger Zone → Change repository visibility → Public**.

---

## 📜 License

Educational / personal use unless another license appears in a specific file.

🥑 *¡Buena partida! / Happy hacking!*
