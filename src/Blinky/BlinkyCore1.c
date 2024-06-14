#include "BlinkyCore1.h"
#include "pico/stdlib.h"

static uint16_t ulCountOfItemsSentOnQueue = 0;
static QueueHandle_t sendToCore0;
static QueueHandle_t receiveFromCore0;
static TaskHandle_t taskHandle;

static void taskCore1(void *pvParameters)
{

    for (;;)
    {
        bool LEDState = false;

        if (pdTRUE == xQueueReceive(receiveFromCore0, &(LEDState), 0))
        {
            LEDState = !LEDState; // Toggle the LED State
            while (pdFALSE == xQueueSend(sendToCore0, (void *)&(LEDState), 0))
                ;
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void init_BlinkyCore1(QueueHandle_t sendQueue, QueueHandle_t receiveQueue)
{
    sendToCore0 = sendQueue;
    receiveFromCore0 = receiveQueue;
    xTaskCreateAffinitySet(taskCore1, "LED_Task_1", configMINIMAL_STACK_SIZE, NULL,
                           mainQUEUE_SEND_TASK_PRIORITY, uxCoreAffinityMaskCore1,
                           &taskHandle);
    configASSERT(taskHandle);
}