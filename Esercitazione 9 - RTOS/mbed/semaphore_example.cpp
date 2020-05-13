#include "mbed.h"
#include "rtos.h"

// Define Serial Communication interface
Serial uart_com(PA_2, PA_3);  // PA_2: TX pin | PA_: RX_pin
// Parameters
#define BAUDRATE    115200
#define BITS        8 
#define PARITY      SerialBase::None
#define STOP_BITS   1

// Methods
void clear_screen(){
    char clrscr[] = {0x1B, '[', '2' , 'J',0};
    uart_com.printf(clrscr);
}
void UART_init(){
    uart_com.baud(BAUDRATE);
    uart_com.format(BITS, PARITY, STOP_BITS);
    clear_screen();
}

// Define Threads and Semaphore
Thread thread1, thread2, thread3, thread4;
Semaphore sema(2); // Counting Semaphore - 2 token

// Thread!
void communication_thread(const char *data) {
    while (true) {
        sema.acquire();
        uart_com.printf("%s\n", data);
        osDelay(2000);
        sema.release();
    }
}
 
int main() {
    
    // Init UART
    UART_init();

    // Create and start Threads with callback 

    thread1.start(callback(communication_thread, "Thread ONE!"));
    thread2.start(callback(communication_thread, "Thread TWO!"));
    thread3.start(callback(communication_thread, "Thread THREE!"));
    thread4.start(callback(communication_thread, "Thread FOUR!"));

}
