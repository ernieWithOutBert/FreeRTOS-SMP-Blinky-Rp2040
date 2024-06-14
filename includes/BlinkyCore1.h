#ifndef BLINKYCORE1_H_INCLUDED
#define BLINKYCORE1_H_INCLUDED
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

    void init_BlinkyCore1(QueueHandle_t sendQueue, QueueHandle_t receiveQueue);

#ifdef __cplusplus
}
#endif
#endif