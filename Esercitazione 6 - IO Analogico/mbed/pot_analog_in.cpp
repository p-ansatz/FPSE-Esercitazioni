#include "mbed.h"

// Define Analog Input
AnalogIn pot_in(A0);

int main(){
    float pot_val_f;
    uint16_t pot_val;
    while(1) {
        // Read the input voltage, represented as a float in the range [0.0, 1.0]
        pot_val_f = pot_in.read();
        // Read the input voltage, represented as an unsigned short in the range [0x0, 0xFFFF]
        pot_val = pot_in.read_u16();
        // Debug Print
        printf("(Float value: %.4f) || (Unsigned int value: %d)    \n", pot_val_f, pot_val);
        wait(0.5);          // Wait 500ms
        printf("\033[1A");  // Clear Line        
    }
}
