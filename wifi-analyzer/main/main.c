#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

static const char *TAG = "wifi-scanner";

static void wifi_scan_task(void *arg)
{
    ESP_LOGI(TAG, "Starting WiFi scan...");

    wifi_scan_config_t scan_config = {
        .ssid = NULL,
        .bssid = NULL,
        .channel = 0,
        .show_hidden = true,
        .scan_type = WIFI_SCAN_TYPE_ACTIVE,
        .scan_time = {
            .active = {
                .min = 100,
                .max = 300,
            }
        }
    };

    int scan_count = 0;
    while (1) {
        ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true));

        uint16_t ap_num = 0;
        ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));

        if (ap_num > 0) {
            wifi_ap_record_t *ap_info = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t) * ap_num);
            ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_num, ap_info));

            printf("\n=== WiFi Scan #%d - Found %d networks ===\n", ++scan_count, ap_num);
            for (int i = 0; i < ap_num; i++) {
                printf("%2d | %-25s | RSSI: %4d | Ch: %2d | Auth: %d\n",
                       i + 1,
                       ap_info[i].ssid,
                       ap_info[i].rssi,
                       ap_info[i].primary,
                       ap_info[i].authmode);
            }
            free(ap_info);
        } else {
            printf("\nScan #%d - No networks found\n", ++scan_count);
        }

        vTaskDelay(pdMS_TO_TICKS(8000)); // Scan every 8 seconds
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "ESP32-C6 WiFi Scanner starting...");

    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize WiFi
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    // Start the scanner task
    xTaskCreate(wifi_scan_task, "wifi_scan", 4096, NULL, 5, NULL);

    printf("\nESP32-C6 WiFi Scanner ready on COM10!\n");
    printf("Open Serial Monitor at 115200 baud to see results.\n");
}
