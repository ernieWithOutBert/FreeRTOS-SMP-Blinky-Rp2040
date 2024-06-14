#include "main.h"
#include "stdio.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"

/* The queue used by the queue send and queue receive tasks. */
static QueueHandle_t xQueue0To1 = NULL;
static QueueHandle_t xQueue1To0 = NULL;

int main(void)
{
    bool initValue = false;

    multicore_reset_core1();
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    xQueue0To1 = xQueueCreate(10, sizeof(bool));
    xQueue1To0 = xQueueCreate(10, sizeof(bool));
    init_BlinkyCore0(xQueue0To1, xQueue1To0);
    init_BlinkyCore1(xQueue1To0, xQueue0To1);
    // Provide a inital value for the LED Flag
    if (pdTRUE == xQueueSend(xQueue0To1, (void *)&(initValue), 0))
    {
        vTaskStartScheduler();
    };
    /* should never reach here */
    panic_unsupported();
}
