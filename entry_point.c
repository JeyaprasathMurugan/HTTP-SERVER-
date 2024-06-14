#include "nvs_flash.h"
#include "wifi_app.h"
#include "gpio_led.h"

TaskHandle_t led_task = NULL;

void led_toggle(void* args){

	    volatile uint32_t* set_value = (uint32_t*)GPIO_OUT_W1TS_REG;
		volatile uint32_t* clear_value = (uint32_t*)GPIO_OUT_W1TC_REG;
		volatile uint32_t* enable_value = (uint32_t*)GPIO_ENABLE_REG;

		*enable_value = 0x00000004;

		printf("printed\n");

		while(1){


		     /**set_value = 0x00000020;*/
		     *set_value = 0x00000004;
		     vTaskDelay(pdMS_TO_TICKS(100));

		     /**clear_value =0x00000020;*/
		     *clear_value =0x00000004;
		     vTaskDelay(pdMS_TO_TICKS(100));
		}



}


void app_main(void)
{
    // Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	// Start Wifi
	wifi_app_start();

xTaskCreatePinnedToCore(led_toggle,"hello",9086,NULL,3,&led_task,1);


}
