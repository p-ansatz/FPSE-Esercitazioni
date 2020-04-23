#include "mbed.h"

#define R_S 10000
#define R25 10000
#define T0 25+273.15
#define B 3950

AnalogIn analog_in(A0);

int main(){
    
    float meas_in;
    double v_in;
    float temp;
    float R_thermistor;
    float S_H;

    while(1) {
        // Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_in = analog_in.read(); 
        // Converts value in the 0V-3.3V range (3.3V = 3300mV)
        v_in = (meas_in*3300);
        // Calculate Thermistor Resistance (using Voltage divider formula)
        R_thermistor = (R_S)/((3300/v_in)-1);
        // Steinhart-Hart
        S_H = 1.0/(T0) + (1.0/B)*log(R_thermistor/R25);
        S_H = 1/S_H;
        // Kelvin -> Celsius
        temp = S_H-273.15;
        // Display values
        printf("measure : %f -> %.0f mV \n", meas_in, v_in);
        printf("temperature : %f °C\n", temp);

        HAL_Delay(1000); 
    }
}