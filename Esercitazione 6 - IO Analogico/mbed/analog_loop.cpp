#include "mbed.h"

// Define Analog Output
AnalogOut out(PA_4);

// Define Analog Input
AnalogIn in(A0);

int main(){
    float out_val, in_val;
    while(1) {
        for(out_val = 0.0f; out_val < 1.1f; out_val += 0.1f) {
            // Set the output voltage, specified as a percentage
            out.write(out_val);
            // Read the input voltage, represented as a float in the range [0.0, 1.0]
            in_val = in.read();
            // Debug Print
            printf("(out:%.4f) || (in:%.4f) \n", out_val, in_val);
            wait(0.5);          // Wait 500ms
            printf("\033[1A");  // Clear Line
        }
    }
}
