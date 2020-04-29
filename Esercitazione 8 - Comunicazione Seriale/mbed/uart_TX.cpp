#include "mbed.h"

/* UART */
Serial uart_com(PA_2, PA_3);  // PA_2: TX pin | PA_: RX_pin
// Parameters
#define BAUDRATE    115200
#define BITS        8 
#define PARITY      SerialBase::None
#define STOP_BITS   1
// Methods
void UART_Init(){
    uart_com.baud(BAUDRATE);
    uart_com.format(BITS, PARITY, STOP_BITS);
}
void clear_screen(){
    char clrscr[] = {0x1B, '[', '2' , 'J',0};
    uart_com.printf(clrscr);
}
void reset_screen(){
    char reset[] = {0x1B, '[' , 'H' , 0};
    uart_com.printf(reset);
}

/* ADC */
// Analog input- LMT84
AnalogIn lmt84(A0);
// Define Ticker
Ticker adc_timer;
// Variables
float raw_in, lmt84_mv, temp;
volatile bool adc_read_flag = false;
// ADC ticker-ISR
void lmt84_read(){
    adc_read_flag = true;
}

int main(){
    // UART Initialization
    UART_Init();
    clear_screen();
    reset_screen();

    // ADC/Timer Interrupt - 500 ms
    adc_timer.attach(&lmt84_read, 0.5);
    
    // Infinite Loop
    while(1) {
        if(adc_read_flag){
            // Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
            raw_in = lmt84.read(); 
            // Converts value in the 0V-3.3V range
            lmt84_mv = raw_in * 3300; 
            // Convert mV to temperature
            temp = (1035 - lmt84_mv)/5.50f;
            // UART Send values
            uart_com.printf("%.3f °C\n\r", temp);
            // Reset flag
            adc_read_flag = false;
        }
    }
}