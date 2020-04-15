#include "mbed.h"            

//Define input bus
BusIn buttons(USER_BUTTON, PA_10);

//Define output bus
BusOut leds(PB_10, LED1);


int main(){
    leds.write(0x03); // LEDS ON

    while(1) {
        if(buttons == 0x01){ // PA_10 Pressed
            leds = ~leds.read(); // Toggle Leds
        }
        wait(0.2);
    }
}