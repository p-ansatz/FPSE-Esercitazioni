#include "mbed.h"            

//Define input bus
BusIn buttons(USER_BUTTON, PA_10);

//Define output bus
BusOut leds(PB_10, LED1);

int main() {
    while(1) {
        if(buttons == 0x01){         // PA_10 Pressed
            leds = 0x03;             // All Led ON
        }else if(buttons == 0x02){   // USER_BUTTON Pressed
            leds = 0x00;             // All Led OFF
        }
    }
}
