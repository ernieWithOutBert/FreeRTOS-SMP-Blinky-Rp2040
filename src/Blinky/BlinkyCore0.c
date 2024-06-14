#include "BlinkyCore0.h"
#include "pico/stdlib.h"

static QueueHandle_t sendToCore1;
static QueueHandle_t receiveFromCore1;
static TaskHandle_t taskHandle;

static void taskCore0(void *pvParameters)
{
    for (;;)
    {
        bool LEDState = false;

        if (pdTRUE == xQueueReceive(receiveFromCore1, &(LEDState), 0))
        {
            gpio_put(PICO_DEFAULT_LED_PIN, LEDState); // Write the LED from core0
            while (pdFALSE == xQueueSend(sendToCore1, (void *)&(LEDState), 0))
                ;
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void init_BlinkyCore0(QueueHandle_t sendQueue, QueueHandle_t receiveQueue)
{
    sendToCore1 = sendQueue;
    receiveFromCore1 = receiveQueue;
    xTaskCreateAffinitySet(taskCore0, "LED_Task_0", configMINIMAL_STACK_SIZE, NULL,
                           mainQUEUE_RECEIVE_TASK_PRIORITY, uxCoreAffinityMaskCore0,
                           &taskHandle);
    configASSERT(taskHandle);
}