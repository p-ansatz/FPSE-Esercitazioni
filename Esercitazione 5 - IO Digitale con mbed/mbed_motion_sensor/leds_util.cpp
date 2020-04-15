#include "leds_util.h"

void led_blink(DigitalOut led){
    for(int i = 0; i < 5; i++){
        led.write(1);
        HAL_Delay(200);
        led.write(0);
        HAL_Delay(200);
    }
}
