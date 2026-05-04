# lafvinesp32c6

Proyectos para la placa **LAFVIN / UeeKKoo ESP32-C6** con pantalla **ST7789 172x320** (1.47"). Documentación oficial: [Tutorial Arduino LAFVIN ESP32-C6 LCD](https://lafvin-esp32-c6-147lcd.readthedocs.io/en/latest/Tutorial/2.arduino.html).

## Contenido

| Carpeta / archivo | Descripción |
|-------------------|-------------|
| `arkanoid/` | Juego tipo Arkanoid con **LovyanGFX** (Arduino IDE). Control con botón **BOOT** (GPIO 9). |
| `wifi-analyzer/` | Proyecto **PlatformIO** (Arduino framework) para pruebas TFT / WiFi; dependencias en `platformio.ini`. |
| `*.ino` (raíz) | Sketches sueltos de prueba (pantalla, backlight, etc.). |

## Arkanoid

1. Instala la librería **LovyanGFX** en Arduino IDE.
2. Abre `arkanoid/arkanoid.ino`.
3. Placa: **ESP32C6 Dev Module** (o equivalente), puerto COM correcto, **Upload**.

`ARKANOID.md` es una copia del mismo código que `arkanoid.ino` (para copiar/pegar).

## wifi-analyzer (PlatformIO)

```bash
cd wifi-analyzer
pio run
```

Se ignoran carpetas de build (`.pio/`) en Git; al clonar, PlatformIO vuelve a descargar librerías.

## Licencia

Código del repositorio: uso personal / educativo salvo que se indique otra cosa en archivos concretos.
