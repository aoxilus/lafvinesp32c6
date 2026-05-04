# 📡 wifi-analyzer

Pruebas de WiFi, pantalla y firmware para la placa **LAFVIN / UeeKKoo ESP32-C6 1.47" LCD**.

## Qué hay en esta carpeta

### `src/main.cpp`

Sketch **Arduino + PlatformIO** muy simple para comprobar que:

- la compilación funciona,
- el upload funciona,
- el puerto serie responde.

Ahora mismo imprime mensajes por serial y sirve como firmware de prueba.

### `main/main.c`

Ejemplo **ESP-IDF** de escaneo WiFi por serial:

- inicializa NVS,
- arranca WiFi en modo estación,
- escanea redes,
- imprime SSID / RSSI / canal / auth por consola.

Este archivo es útil como referencia, pero el `platformio.ini` actual está configurado para **Arduino**, así que el build principal en esta carpeta usa `src/main.cpp`.

## Librerías / dependencias

En `platformio.ini` están declaradas estas dependencias:

- **TFT_eSPI**
- **SD**

Además usa:

- **Arduino framework** para el entorno principal de PlatformIO.
- **ESP-IDF APIs** en `main/main.c` (`esp_wifi`, `esp_event`, `nvs_flash`, etc.), que vienen del SDK de Espressif y no se instalan como librerías aparte en Arduino IDE.

## Cómo compilar

### PlatformIO

```bash
cd wifi-analyzer
pio run
```

### Monitor serial

```bash
pio device monitor -b 115200
```

## Archivos importantes

- `platformio.ini` → entorno y dependencias.
- `User_Setup.h` → configuración de pantalla para TFT_eSPI.
- `TFT_eSPI/User_Setup.h` → otra copia de setup para pruebas.
- `src/main.cpp` → firmware Arduino actual.
- `main/main.c` → ejemplo ESP-IDF de escaneo WiFi.
