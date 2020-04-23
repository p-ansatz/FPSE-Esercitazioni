#include "mbed.h"

// Define Analog Output
AnalogOut out(PA_4);

int main(){
    float out_val;
    while(1) {
        for(out_val = 0.0f; out_val < 1.0f; out_val += 0.1f) {
            out.write(out_val);   // Set the output voltage, specified as a percentage
            HAL_Delay(5);          // Wait 5ms
        }
    }
}
