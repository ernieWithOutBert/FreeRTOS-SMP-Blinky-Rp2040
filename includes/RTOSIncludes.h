#ifndef RTOSHOOKS_H_INCLUDED
#define RTOSHOOKS_H_INCLUDED
#ifdef __cplusplus
extern "C"
{
#endif

/************************************ INCLUDES ************************************/
#include "FreeRTOS.h"
#include "queue.h"  /* RTOS queue related API prototypes. */
#include "timers.h" /* Software timer related API prototypes. */
#include "task.h"   /* RTOS task related API prototypes. */

    /************************************ MACROS AND DEFINES  *************************/
#define uxCoreAffinityMaskCore0 ((UBaseType_t)0b01)
#define uxCoreAffinityMaskCore1 ((UBaseType_t)0b10)
#define mainQUEUE_RECEIVE_TASK_PRIORITY (tskIDLE_PRIORITY + 2)
#define mainQUEUE_SEND_TASK_PRIORITY (tskIDLE_PRIORITY + 1)
#define mainQUEUE_SEND_PERIOD_MS pdMS_TO_TICKS(200)
#define mainSOFTWARE_TIMER_PERIOD_MS pdMS_TO_TICKS(1000)
#define mainQUEUE_LENGTH (1)
    /************************************ TYPEDEFS ************************************/

    /************************************ EXPORTED VARIABLES **************************/

    /************************************ GLOBAL FUNCTION PROTOTYPES ******************/

    void vApplicationTickHook(void);
    void vApplicationMallocFailedHook(void);
    void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);
    void vApplicationIdleHook(void);

#ifdef __cplusplus
}
#endif
#endif
