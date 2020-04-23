#include "mbed.h"

// Define Analog Output
AnalogOut out(PA_4);

int main(){
    float out_val;
    while(1) {
        out = 0.0 / 3.3f; // Generate 0V
        wait(0.1);        // Wait 100ms
        out = 1.0 / 3.3f; // Generate 1V
        wait(0.1);        // Wait 1000ms
        out =2.0 / 3.3f;  // Generate 2V
        wait(0.1);        // Wait 100ms
        out = 3.0 / 3.3f; // Generate 3V
        wait(0.1);        // Wait 100ms
    }
}
