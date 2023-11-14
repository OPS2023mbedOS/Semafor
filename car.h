#pragma once
#include "stm32746g_discovery_lcd.h"
#include "mbed.h"
#include "globals.h"
#include <cstdint>



void car(uint32_t color, int parking_time, int outside_time);
void drawOnDisplay(int i, uint32_t color);