#include "mbed.h"

// Define Timout Object
Timeout response; 
// Define Button
DigitalIn button(USER_BUTTON);
// Define Leds
DigitalOut led1(LED1); // Internal

void blink_ISR(){ 
    led1 = 1;
    HAL_Delay(500);
    led1=0;
}

int main() {
    
    while(1) {
        if(button.read() == 0){        
            /* Attach blink_ISR function to response Timeout, to occur after 2 seconds*/
            response.attach(&blink_ISR, 2.0); 
        }
    }
}