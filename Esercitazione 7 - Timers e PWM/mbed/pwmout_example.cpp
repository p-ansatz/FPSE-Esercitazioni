#include "mbed.h"

PwmOut PWM(PA_8);

int main() {
    PWM.period(0.0022); // set PWM period to 1/400Hz
    PWM.write(0.5);    // set duty cycle to 50%
    while(1){
        ;
    }
}