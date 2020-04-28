#include "mbed.h"

// Define the frequencies for the basic notes
# define DO     0.0038221 // 1/261.63Hz
# define RE     0.0034052 // 1/293.66Hz
# define MI     0.0030337 // 1/329.63Hz
# define FA     0.0028634 // 1/349.23Hz
# define SOL    0.0025510 // 1/392Hz
# define LA     0.0022727 // 1/440Hz
# define SIb    0.0021451 // 1/466.16Hz
# define SI     0.0020247 // 1/493.88Hz
# define NN     0         // No note, a silence!

// Define the "beat length"
# define b1     500
# define b2     250
# define b3     125
# define b4     75

// Define the "song"
float notes[] = {DO,DO,RE,DO,NN, LA,LA,SIb,LA,NN, LA,(DO/2),SIb,LA,NN, SOL,LA,SOL,FA,NN};
float beats[] = {b1,b1,b3,b1,b1, b1,b1,b3, b1,b1, b1,  b2  ,b2, b1,b1, b1 ,b1, b3,b1,b1};

PwmOut Speaker(PA_8);

int main() {
    while(1){
        for(int k = 0; k < (sizeof(notes)/sizeof(int)); k++ ){

            if(notes[k] == NN)    // If there is a sound pause
                Speaker.write(0); // 0 Duty-Cycle
            else{
                Speaker.period(notes[k]);  //Set the PWM period, which determines the note of the sound
                Speaker.write(0.5);     //Set the PWM duty cycle that determines the volume of the sound (controlled by one potentiometer)
            }
                
            HAL_Delay(beats[k]);
        }
    }
}