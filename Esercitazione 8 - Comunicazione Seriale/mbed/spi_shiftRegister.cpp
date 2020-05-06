#include "mbed.h"

/* SPI Signals */
DigitalOut SS(PB_6); // SS
SPI spi_conn(PA_7, PA_6, PA_5); // MOSI, MISO, SCLK

/* Define Colours- Shift Register Outputs
 * QA -> NO
 * QB -> RED
 * QC -> NO
 * QD -> GREEN
 * QE -> NO
 * QF -> BLU
 *
 * Q-H G F E D C B A
 * 0b0 0 0 0 0 0 0 0
 * */

#define RED 0b00000010
#define GRE 0b00001000
#define BLU 0b00100000
#define ORA 0b00001010
#define VIO 0b00100010
#define LBL 0b00101000
#define WHI 0b00101010

void SPI_Config(){
    // Setup the SPI for 8 bit data, Mode 0 operation
    spi_conn.format(8,0);     
    // Clock frequency is 1MHz
    spi_conn.frequency(1000000); 
}

void ShiftReg_out(uint8_t data){
    SS = 0;
    spi_conn.write(data); // Send data via SPI
    SS = 1;
}

int main() {
    uint8_t data;
    
    SPI_Config();
    
    data = GRE;
    ShiftReg_out(data);
    
    while (1){
        data = GRE;
        ShiftReg_out(data);
        HAL_Delay(1000);
        data = WHI;
        ShiftReg_out(data);
        HAL_Delay(1000);
    }
}