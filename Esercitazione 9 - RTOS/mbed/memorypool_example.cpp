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

// Define Structure - self defined type of message!
typedef struct{
    int elem1;
    int elem2;
}msg_t;

// Define Threads and MemoryPool with Queue
Thread Producer, Consumer;
MemoryPool<msg_t, 16> memPool;
Queue<msg_t, 16> queue;

// Threads Definition
void producer_thread() {
    while(true){
        // Allocate Memory area with MemoryPool alloc()
        msg_t *message = memPool.alloc();
        
        // Create elements
        message->elem1 = rand() % 100;
        message->elem2 = rand() % 100;
        
        // Put Message into queue
        queue.put(message); 
        uart_com.printf("Produced: %d ;  %d\n", message->elem1, message->elem2);
        
        // Wait before new production!
        osDelay(2000);
    }
}
void consumer_thread(){
    while(true){
        osEvent evt = queue.get();
        if(evt.status == osEventMessage){
            // Get message and consume it!
            msg_t *message_consumed = (msg_t*)evt.value.p; // 'p' indicates the pointer to the message
            uart_com.printf("Consumed: %d ;  %d\n", message_consumed->elem1, message_consumed->elem2);
            memPool.free(message_consumed); // Free Memory!
        }
        osDelay(1000);
    }
}
 
int main() {
    
    // Init UART
    UART_init();
    
    // Create and start Threads
    Producer.start(producer_thread);
    Consumer.start(consumer_thread);
}
