#ifndef BLINKYCORE0_H_INCLUDED
#define BLINKYCORE0_H_INCLUDED
#ifdef __cplusplus
extern "C"
{
#endif

    /************************************ INCLUDES ************************************/
#include "RTOSIncludes.h"
    /************************************ MACROS AND DEFINES  *************************/

    /************************************ TYPEDEFS ************************************/

    /************************************ EXPORTED VARIABLES **************************/

    /************************************ GLOBAL FUNCTION PROTOTYPES ******************/
    void init_BlinkyCore0(QueueHandle_t sendQueue, QueueHandle_t receiveQueue);

#ifdef __cplusplus
}
#endif
#endif