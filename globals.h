#include "mbed.h"
#define PARKING_LOTS 4
extern Mutex mutex_lots;
extern Mutex mutex_display;
extern Semaphore parking_lots;
extern uint32_t park[];