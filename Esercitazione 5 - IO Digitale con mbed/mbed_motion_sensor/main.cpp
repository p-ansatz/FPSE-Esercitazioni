#include "mbed.h"            
#include "leds_util.h"

// Define Interrupt
InterruptIn m_sensor(PC_2);

// Define LED outputs
DigitalOut red_led(PA_10);
DigitalOut green_led(PB_3);

// Flag
int move_flag = 0;

void motion_callback(){
    green_led.write(0);
    move_flag = 1;
}

int main(){

    __enable_irq();

    m_sensor.rise(&motion_callback);

    while(1){
        if(move_flag){
            led_blink(red_led);
            move_flag = 0;
        }

        if(move_flag == 0){
            green_led.write(1);            
            __WFI();
        }
    }
}