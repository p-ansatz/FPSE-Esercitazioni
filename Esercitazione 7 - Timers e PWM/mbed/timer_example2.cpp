#include "mbed.h"

// Define Interrupt Inputs
InterruptIn button(USER_BUTTON); 
// Define Led Output
DigitalOut led(LED1); 
// Define Timer for debouncing
Timer debounce; 

void toggle_ISR() {
    if (debounce.read_ms()>200)
        led=!led; 
    debounce.reset(); // Reset Timer
}

int main() {
    __enable_irq();
    
    debounce.start(); // Start Timer
    button.fall(&toggle_ISR); // Callback on Falling Edge 
    __WFI(); // Wait-For-Interrupt    
    
    while(1){
        ; //keep Alive        
    }
}