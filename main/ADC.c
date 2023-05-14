#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/adc.h"

void app_main(void)
{
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);

  adc2_config_channel_atten(ADC2_CHANNEL_0, ADC_ATTEN_DB_11);

  while (true)
  {
    int val1 = 0;
    int val2 = 0;

    val1 = adc1_get_raw(ADC1_CHANNEL_4);
    adc2_get_raw(ADC2_CHANNEL_0, ADC_WIDTH_BIT_12, &val2);

    printf("ADC1: %d - ADC2: %d - ADC1 T: %f - ADC2 T: %f \n", val1, val2, val1 * (3.3 / 4095), val2 * (3.3 / 4095));
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}
