#include "mbed.h"

extern "C"{
#include "MPU6050_lib.h"
}

/* UART */
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

/* I2C structure */
I2C i2c_open(PB_9, PB_8); // This initialize the pins!
I2C_HandleTypeDef i2c1;

/* IMU MPU6050 Variables  */
MPU_ConfigTypeDef Mpu_Config;
RawData_Def Accel_Raw, Gyro_Raw;
ScaledData_Def Accel_Scaled, Gyro_Scaled;

/* I2C Configuration - using HAL structure */
void I2C_config(){
    i2c1.Instance = I2C1;
    i2c1.Init.ClockSpeed = 100000;
    i2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    i2c1.Init.OwnAddress1 = 0;
    i2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    i2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    i2c1.Init.OwnAddress2 = 0;
    i2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    i2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&i2c1);
}

/* MPU6050 Configuration */
void MPU6050_config(){
    Mpu_Config.Clock_Source = INTERNAL_8MHz;
    Mpu_Config.Accel_Full_Scale = AFS_SEL_4g;
    Mpu_Config.Config_Dlpf = DLPF_184A_188G_Hz;
    Mpu_Config.Gyro_Full_Scale = FS_SEL_500;
    Mpu_Config.Sleep_Mode_Bit = 0;  //1: sleep mode, 0: normal mode
    MPU6050_Init(&i2c1, &Mpu_Config); // Initialization - Configuration
}

int main(){

    UART_init();

    I2C_config();

    MPU6050_config();
    
    // Infinite Loop
    while(1) {
        MPU6050_Read_RawData(&Accel_Raw, &Gyro_Raw);
        MPU6050_Read_ScaledData(&Accel_Scaled, &Gyro_Scaled);
        uart_com.printf("Accel_RAW [x]:%f\n",Accel_Scaled.x);
        uart_com.printf("Accel_RAW [y]:%f\n",Accel_Scaled.y);
        uart_com.printf("Accel_RAW [z]:%f\n",Accel_Scaled.z);
        uart_com.printf("------------------\n");

        HAL_Delay(1000);
    }
}