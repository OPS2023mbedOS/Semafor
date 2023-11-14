#include "car.h"
#include <chrono>
void car(uint32_t color, int parking_time, int outside_time){
    while (true) {
        parking_lots.acquire();

        mutex_lots.lock();

        int i = freeSpace.top();
        freeSpace.pop();
        mutex_lots.unlock();
        
        drawOnDisplay(i, color);
        ThisThread::sleep_for(std::chrono::milliseconds(parking_time));

        mutex_lots.lock();
        freeSpace.push(i);
        mutex_lots.unlock();
        drawOnDisplay(i, LCD_COLOR_BLACK);

        parking_lots.release();
        
        ThisThread::sleep_for(std::chrono::milliseconds(outside_time));
        
    }
}

void drawOnDisplay(int i, uint32_t color){
        mutex_display.lock();
        BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
        BSP_LCD_SetTextColor(color);
        switch(i){
            case 0:{
                BSP_LCD_FillRect(1, 1, 108, 108);
                break;
            }
            case 3:{
                BSP_LCD_FillRect(110,110, 108, 108);
                break;
            }
            case 1:{
                BSP_LCD_FillRect(1, 110, 108, 108);
                break;
            }
            case 2:{
                BSP_LCD_FillRect(110, 1, 108, 108);
                break;
            }
        }
        mutex_display.unlock();
}