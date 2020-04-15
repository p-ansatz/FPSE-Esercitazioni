#include "mbed.h"            

DigitalOut internal_led(LED1);  

int main() {
    while(1) {
        internal_led = 1; // LED ON
        wait(0.5); // 500 ms
        internal_led = 0; // LED OFF
        wait(1.0); // 1 sec
    }
}
