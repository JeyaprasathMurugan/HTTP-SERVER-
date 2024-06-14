#include "gpio_led.h"
#include<freertos/FreeRTOS.h>
#include<stdlib.h>


void app_main(){

	volatile uint32_t* set_value = (uint32_t*)GPIO_OUT_W1TS_REG;
	volatile uint32_t* clear_value = (uint32_t*)GPIO_OUT_W1TC_REG;
	volatile uint32_t* enable_value = (uint32_t*)GPIO_ENABLE_REG;

	*enable_value = 0x00000024;

	printf("printed\n");

	while(1){


	     /**set_value = 0x00000020;*/
	     *set_value = 0x00000024;
	     vTaskDelay(pdMS_TO_TICKS(100));

	     /**clear_value =0x00000020;*/
	     *clear_value =0x00000024;
	     vTaskDelay(pdMS_TO_TICKS(100));
	}
}

