# 📡 wifi-analyzer

Pruebas de WiFi, pantalla y firmware para la placa **LAFVIN / UeeKKoo ESP32-C6 1.47" LCD**.

## 🇬🇧 English

### What is in this folder?

#### `src/main.cpp`

A simple **Arduino + PlatformIO** sketch to confirm:

- build works,
- upload works,
- serial output works.

Right now it prints messages over serial and acts as test firmware.

#### `main/main.c`

An **ESP-IDF** serial WiFi scan example:

- initializes NVS,
- starts WiFi in station mode,
- scans networks,
- prints SSID / RSSI / channel / auth to the console.

This file is useful as reference, but the current `platformio.ini` is configured for **Arduino**, so the main build in this folder uses `src/main.cpp`.

### Libraries / dependencies

These are declared in `platformio.ini`:

- **TFT_eSPI**
- **SD**

It also uses:

- **Arduino framework** for the main PlatformIO environment.
- **ESP-IDF APIs** in `main/main.c` (`esp_wifi`, `esp_event`, `nvs_flash`, etc.), which come from Espressif's SDK.

### How to build

#### PlatformIO

```bash
cd wifi-analyzer
pio run
```

#### Serial monitor

```bash
pio device monitor -b 115200
```

### Important files

- `platformio.ini` → environment and dependencies.
- `User_Setup.h` → TFT_eSPI screen config.
- `TFT_eSPI/User_Setup.h` → another setup copy for tests.
- `src/main.cpp` → current Arduino firmware.
- `main/main.c` → ESP-IDF WiFi scan example.

### Video

- 📺 YouTube demo: [Watch here](https://www.youtube.com/watch?v=qAq44lFisYs)

## 🇪🇸 Español

### Qué hay en esta carpeta

#### `src/main.cpp`

Sketch **Arduino + PlatformIO** muy simple para comprobar que:

- la compilación funciona,
- el upload funciona,
- el puerto serie responde.

Ahora mismo imprime mensajes por serial y sirve como firmware de prueba.

#### `main/main.c`

Ejemplo **ESP-IDF** de escaneo WiFi por serial:

- inicializa NVS,
- arranca WiFi en modo estación,
- escanea redes,
- imprime SSID / RSSI / canal / auth por consola.

Este archivo es útil como referencia, pero el `platformio.ini` actual está configurado para **Arduino**, así que el build principal en esta carpeta usa `src/main.cpp`.

### Librerías / dependencias

En `platformio.ini` están declaradas estas dependencias:

- **TFT_eSPI**
- **SD**

Además usa:

- **Arduino framework** para el entorno principal de PlatformIO.
- **ESP-IDF APIs** en `main/main.c` (`esp_wifi`, `esp_event`, `nvs_flash`, etc.), que vienen del SDK de Espressif.

### Cómo compilar

#### PlatformIO

```bash
cd wifi-analyzer
pio run
```

#### Monitor serial

```bash
pio device monitor -b 115200
```

### Archivos importantes

- `platformio.ini` → entorno y dependencias.
- `User_Setup.h` → configuración de pantalla para TFT_eSPI.
- `TFT_eSPI/User_Setup.h` → otra copia de setup para pruebas.
- `src/main.cpp` → firmware Arduino actual.
- `main/main.c` → ejemplo ESP-IDF de escaneo WiFi.

### Video

- 📺 Demo en YouTube: [Ver aquí](https://www.youtube.com/watch?v=qAq44lFisYs)
