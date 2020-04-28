#include "mbed.h"

// Define Output
DigitalOut output(PA_5); 
// Define Timers
Timer timer; 

void task(void){
    // Toggle output
    output = !output;
}

int main() {
    timer.start(); // Start timer counting
    while(1) {
        if (timer.read_ms() >= 200){
            task();
            timer.reset(); // Reset timer
        }
    }
}