#include"mbed.h"

// Define Ticker
Ticker time_up; 
// Define Led
DigitalOut led(LED1);

void led_switch_ISR(){
    led = !led;
}

int main(){
    time_up.attach(&led_switch_ISR, 0.2);
    while(1){ 
        ;
    }
}