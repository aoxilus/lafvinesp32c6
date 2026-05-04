# 🧪 test

Esta carpeta junta los archivos de prueba y diagnóstico del board **LAFVIN / UeeKKoo ESP32-C6 1.47" LCD**.

## 🇬🇧 English

### Why these matter

Before trusting a game or a bigger app, it helps to validate the small pieces first:

- 🔌 board shows up over USB / COM,
- 💡 backlight turns on,
- 🖥️ screen responds,
- 📶 WiFi scans,
- 🧰 helper scripts can diagnose issues fast.

These files are grouped here to keep the repo clean and arcade-neat 👾

### Files

#### `check-esp32.ps1`

A PowerShell script that lists COM ports and ESP32-related USB devices.  
Useful to detect whether the board enters bootloader mode or whether Windows is seeing it.

#### `monitor-esp32.ps1`

Live monitor that repeats board detection every few seconds.  
Useful while testing **BOOT + RESET** combinations.

#### `test_backlight.ino`

Minimal test to verify the backlight pin works.  
If this fails, there is no point debugging the UI yet.

#### `full_lcd_test.ino`

Display + WiFi test using **LovyanGFX**.  
Helps validate pins, ST7789 init, on-screen text, and basic network scanning.

#### `sketch_may3a.ino`

Another early WiFi + LCD sketch used during experimentation.  
Kept as a reference to compare setups that compiled or displayed something useful.

### Video

- 📺 YouTube demo: [Watch here](https://www.youtube.com/watch?v=qAq44lFisYs)

## 🇪🇸 Español

### Por qué importan

Antes de confiar en un juego o en una app más grande, conviene validar piezas pequeñas:

- 🔌 que la placa aparezca por USB / COM,
- 💡 que el backlight encienda,
- 🖥️ que la pantalla responda,
- 📶 que WiFi escanee,
- 🧰 que haya scripts rápidos para detectar problemas sin abrir el IDE.

Aquí quedan agrupados esos archivos para que el repo se vea más ordenado y con vibra arcade 👾

### Archivos

#### `check-esp32.ps1`

Script de PowerShell para listar puertos COM y dispositivos USB relacionados con ESP32.  
Sirve para detectar si la placa entra en modo bootloader o si Windows la está viendo.

#### `monitor-esp32.ps1`

Monitor en vivo para repetir la detección de la placa cada pocos segundos.  
Útil cuando estás probando combinaciones de **BOOT + RESET**.

#### `test_backlight.ino`

Prueba mínima para verificar que el pin del backlight funciona.  
Si esto falla, no vale la pena depurar la UI todavía.

#### `full_lcd_test.ino`

Prueba de pantalla + WiFi con **LovyanGFX**.  
Ayuda a validar pines, inicialización del ST7789, texto en pantalla y escaneo básico de redes.

#### `sketch_may3a.ino`

Otro sketch temprano de WiFi + LCD usado durante la etapa de experimentación.  
Se guarda como referencia de trabajo para comparar configuraciones que sí compilaron o que mostraron algo útil en pantalla.

### Video

- 📺 Demo en YouTube: [Ver aquí](https://www.youtube.com/watch?v=qAq44lFisYs)
