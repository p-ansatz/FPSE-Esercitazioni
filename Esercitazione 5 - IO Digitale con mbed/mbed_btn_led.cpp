#include "mbed.h"            

DigitalOut internal_led(LED1);  
DigitalIn internal_btn(USER_BUTTON);

DigitalOut external_led(PB_10);
DigitalIn external_btn(PA_10);


int main() {
    while(1) {
        if(internal_btn == 0){
            internal_led = 1; // INTERNAL LED ON
        }else
            internal_led = 0; // INTERNAL LED OFF
            
        if(external_btn == 0){
            external_led = 1; // PB_10 HIGH
        }else{
            external_led = 0; // PB_10 LOW
        }
        
    }
}
