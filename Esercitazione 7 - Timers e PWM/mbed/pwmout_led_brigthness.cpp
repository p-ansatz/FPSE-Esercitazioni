#include "mbed.h"

// PWM Output on PA_5
PwmOut led(PA_5);

float brightness = 0.0;

int main() {
    while(1) {
        while(brightness <= 1.0){
            HAL_Delay(1);
            brightness += 0.001;
            led.write(brightness);
        }

        HAL_Delay(1000);
        
        while(brightness >= 0.0){
            HAL_Delay(1);
            brightness -= 0.001;
            led.write(brightness);
        }

        HAL_Delay(500);
    }    
}