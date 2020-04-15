#include "mbed.h"            

DigitalOut internal_led(LED1);  
DigitalIn internal_btn(USER_BUTTON);

int main() {
    while(1) {
        if(internal_btn == 0){
            internal_led = 1; // LED ON
        }else{
            internal_led = 0; // LED OFF
        }
    }
}
