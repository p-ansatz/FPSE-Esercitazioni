#include "mbed.h"

AnalogIn analog_in(A1);

int main(){
    
    float meas_in;
    float meas_mv;
    float temp;

    while(1) {
        // Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_in = analog_in.read(); 
        // Converts value in the 0V-3.3V range
        meas_mv = meas_in * 3300; 
        // Convert mV to temperature
        temp = (1035 - meas_mv)/5.50f;
        // Display values
        printf("measure : %f -> %.0f mV \n", meas_in, meas_mv);
        printf("temperature : %f °C\n", temp);

        HAL_Delay(1000); 
        
        // Clear Lines
        printf("\033[1A");                
        printf("\033[1A"); 
    }
}