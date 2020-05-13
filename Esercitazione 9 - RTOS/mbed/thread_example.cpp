#include "mbed.h"
 
DigitalOut led1(PA_5);
DigitalOut led2(PA_6);
Thread thread;
 
void led2_thread() {
    while (true) {
        led2 = !led2;
        osDelay(1000);
    }
}
 
int main() {
    thread.set_priority(osPriorityNormal);
    thread.start(led2_thread);

    while (true) {
        led1 = !led1;
        osDelay(500);
    }
}
