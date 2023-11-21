#include "main.h"

Thread car1;
Thread car2;
Thread car3;
Thread car4;
Thread car5;
Thread car6;

Mutex mutex_lots;
Mutex mutex_display;
Semaphore parking_lots(4);
stack<int> freeSpace;


uint32_t park[4]; //funguje ale neuspokojí -> předělat na zásobník
// main() runs in its own thread in the OS
int main()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    
    for (int i = 0; i<4;i++){
        freeSpace.push(i);
    }


    car1.start([=]() {car(LCD_COLOR_BLUE, 2000, 4000); });

    car2.start([=]() {car(LCD_COLOR_RED, 1500, 4400); });
    car3.start([=]() {car(LCD_COLOR_GREEN, 2200, 3500); });
    car4.start([=]() {car(LCD_COLOR_MAGENTA, 1800, 5000); });
    car5.start([=]() {car(LCD_COLOR_YELLOW, 1000, 1000); });
    car6.start([=]() {car(LCD_COLOR_ORANGE, 3000, 1500); });
    while (true) {}
}

