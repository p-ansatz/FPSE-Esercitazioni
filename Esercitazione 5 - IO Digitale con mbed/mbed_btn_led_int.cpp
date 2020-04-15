#include "mbed.h"            

// Define Interrupt Inputs
InterruptIn btn_1(PA_10);
InterruptIn btn_2(PC_2);

// Define output 
DigitalOut led_1(LED1);
DigitalOut led_2(PB_10);

// Define ISR - btn_1
void btn_1_callback(){
    led_1 = !led_1;    
}

// Define ISR - btn_2
void btn_2_callback(){
    led_2 = !led_2;    
}

int main(){
    __enable_irq();
    
    // Callback on Rising Edge
    btn_1.rise(&btn_1_callback);
    btn_2.rise(&btn_2_callback);
    
    // Change Priority
    NVIC_SetPriority(EXTI15_10_IRQn, 1);

    while(1){
        __WFI(); // Wait-For-Interrupt            
    }
}