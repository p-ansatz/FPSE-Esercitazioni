#include "mbed.h"

// Define the frequencies for the basic notes
# define DO     0.0038221 // 1 / 261.63Hz
# define MI     0.0030337 // 1 / 329.63Hz
# define SOL    0.0025510 // 1 / 392Hz
# define SI     0.0020247 // 1 / 493.88Hz

// Define the "beat length"
# define pause     500 // 500 ms

// Define Speaker PWM-Output
PwmOut Speaker(A0);

int main() {
    while(1){
        Speaker.period(DO);
        Speaker.write(0.5);
        HAL_Delay(pause);

        Speaker.period(MI);
        Speaker.write(0.5);
        HAL_Delay(pause);

        Speaker.period(SOL);
        Speaker.write(0.5);
        HAL_Delay(pause);

        Speaker.period(SI);
        Speaker.write(0.5);
        HAL_Delay(pause);

        Speaker.write(0); // Duty-Cycle 0 For Silence
        HAL_Delay(pause);
    }
}