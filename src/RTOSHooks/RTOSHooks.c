#include "RTOSIncludes.h"

void vApplicationTickHook(void)
{
}

void vApplicationMallocFailedHook(void)
{
    configASSERT((volatile void *)NULL);
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    /* Run time stack overflow checking is performed if
       configconfigCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
       function is called if a stack overflow is detected.  pxCurrentTCB can be
       inspected in the debugger if the task name passed into this function is
       corrupt. */
    configASSERT((volatile void *)NULL);
    for (;;)
        ;
}

void vApplicationIdleHook(void)
{
    volatile size_t xFreeStackSpace;

    /* The idle task hook is enabled by setting configUSE_IDLE_HOOK to 1 in
       FreeRTOSConfig.h.

       This function is called on each cycle of the idle task.  In this case it
       does nothing useful, other than report the amount of FreeRTOS heap that
       remains unallocated. */
    xFreeStackSpace = xPortGetFreeHeapSize();

    if (xFreeStackSpace > 100)
    {
        /* By now, the kernel has allocated everything it is going to, so
           if there is a lot of heap remaining unallocated then
           the value of configTOTAL_HEAP_SIZE in FreeRTOSConfig.h can be
           reduced accordingly. */
    }
    (void)xFreeStackSpace;
}