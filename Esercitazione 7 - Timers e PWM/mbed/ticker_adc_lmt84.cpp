#include "mbed.h"

// Define Ticker
Ticker adc_timer;
// Define Timer for debouncing
Timer debounce; 
// Define Timer for timeout
Timeout adc_restart_timeout;
// Define button-input
InterruptIn button(USER_BUTTON);
// Analog input- LMT84
AnalogIn lmt84(A1);

// Variables
float raw_in, lmt84_mv, temp;
volatile bool b_pressed = false;
volatile bool adc_read_flag = false;

void lmt84_read(){
    adc_read_flag = true;
}

void button_pressed_callback(){
    if (debounce.read_ms()>200){
        b_pressed = true;
    }
    debounce.reset(); // Reset Timer
}

int main(){
    printf("*****START*****\n");
    
    __enable_irq();
    
    // ADC/Timer Interrupt - 500 ms
    adc_timer.attach(&lmt84_read, 0.5);

    debounce.start(); // Start Debouncing-Timer
    button.fall(&button_pressed_callback); // Button rising-edge interrupt

    while(1) {
        if(adc_read_flag){
            // Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
            raw_in = lmt84.read(); 
            // Converts value in the 0V-3.3V range
            lmt84_mv = raw_in * 3300; 
            // Convert mV to temperature
            temp = (1035 - lmt84_mv)/5.50f;
            // Display values
            printf("measure : %f -> %.0f mV \n", raw_in, lmt84_mv);
            printf("temperature : %f °C\n", temp);
            // Reset flag
            adc_read_flag = false;
        }
        if(b_pressed){
            printf("STOP ADC Read!\n");
            adc_timer.detach(); // ADC stop          
            HAL_Delay(4000); // Wait for Other Operations
            printf("Restart ADC Read!\n");
            adc_timer.attach(&lmt84_read, 0.5); // ADC restart
            b_pressed = false;
        }else{
            __WFI(); // Wait-For-Interrupt          
        }
    }
}