# 🧪 test

Esta carpeta junta los archivos de prueba y diagnóstico del board **LAFVIN / UeeKKoo ESP32-C6 1.47" LCD**.

## Por qué importan

Antes de confiar en un juego o en una app más grande, conviene validar piezas pequeñas:

- 🔌 que la placa aparezca por USB / COM,
- 💡 que el backlight encienda,
- 🖥️ que la pantalla responda,
- 📶 que WiFi escanee,
- 🧰 que haya scripts rápidos para detectar problemas sin abrir el IDE.

Aquí quedan agrupados esos archivos para que el repo se vea más ordenado.

## Archivos

### `check-esp32.ps1`

Script de PowerShell para listar puertos COM y dispositivos USB relacionados con ESP32.  
Sirve para detectar si la placa entra en modo bootloader o si Windows la está viendo.

### `monitor-esp32.ps1`

Monitor en vivo para repetir la detección de la placa cada pocos segundos.  
Útil cuando estás probando combinaciones de **BOOT + RESET**.

### `test_backlight.ino`

Prueba mínima para verificar que el pin del backlight funciona.  
Si esto falla, no vale la pena depurar la UI todavía.

### `full_lcd_test.ino`

Prueba de pantalla + WiFi con **LovyanGFX**.  
Ayuda a validar pines, inicialización del ST7789, texto en pantalla y escaneo básico de redes.

### `sketch_may3a.ino`

Otro sketch temprano de WiFi + LCD usado durante la etapa de experimentación.  
Se guarda como referencia de trabajo para comparar configuraciones que sí compilaron o que mostraron algo útil en pantalla.
