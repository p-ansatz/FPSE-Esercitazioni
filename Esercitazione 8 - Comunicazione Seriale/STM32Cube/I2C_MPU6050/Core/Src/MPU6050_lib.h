/* Includes */
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>

/* Registers */
#define MPU_ADDR			0x68
#define WHO_AM_I_REG		0x75
#define PWR_MAGT_1_REG		0x6B
#define CONFIG_REG			0x1A
#define GYRO_CONFIG_REG		0x1B
#define ACCEL_CONFIG_REG	0x1C
#define SMPLRT_DIV_REG		0x19
#define INT_STATUS_REG		0x3A
#define ACCEL_XOUT_H_REG	0x3B
#define GYRO_XOUT_H_REG		0x43

#define TEMP_OUT_H_REG		0x41
#define FIFO_EN_REG 		0x23
#define INT_ENABLE_REG 		0x38
#define I2CMACO_REG 		0x23
#define USER_CNT_REG		0x6A
#define FIFO_COUNTH_REG 	0x72
#define FIFO_R_W_REG 		0x74

/* Enum/Structure for MPU6050 */
// MPU Configuration structure
typedef struct{
	uint8_t Clock_Source;
	uint8_t Gyro_Full_Scale;
	uint8_t Accel_Full_Scale;
	uint8_t Config_Dlpf;
	bool    Sleep_Mode_Bit; 
}MPU_ConfigTypeDef;

// Clock Source - For PWR_MGMT_1 Register
enum PM_CLKSEL_ENUM{
	INTERNAL_8MHz 	= 0x00,		// Internal 8MHz oscillator
	X_AXIS_REF		= 0x01,		// PLL with X axis gyroscope reference
	Y_AXIS_REF		= 0x02,		// PLL with Y axis gyroscope reference
	Z_AXIS_REF		= 0x03,		// PLL with Z axis gyroscope reference
	EXT_32_768KHz	= 0x04,		// PLL with external 32.768kHz reference
	EXT_19_2MHz		= 0x05,		// PLL with external 19.2MHz reference
	TIM_GENT_INREST	= 0x07		// Stops the clock and keeps the timing generator in reset
};

// Gyro Full Scale Range (deg/sec) - For GYRO_CONFIG Register
enum gyro_FullScale_ENUM{
	FS_SEL_250 	= 0x00,			// ± 250 °/s
	FS_SEL_500 	= 0x01,			// ± 500 °/s
	FS_SEL_1000 = 0x02,			// ± 1000 °/s
	FS_SEL_2000	= 0x03			// ± 2000 °/s
};

// Accelerometer Full Scale Range (1g = 9.81m/s2) - For ACCEL_CONFIG Register
enum accel_FullScale_ENUM{ 
	AFS_SEL_2g	= 0x00,			// ± 2g
	AFS_SEL_4g  = 0x01,			// ± 4g
	AFS_SEL_8g  = 0x02,			// ± 8g
	AFS_SEL_16g = 0x03			// ± 16g 
};

// Digital Low Pass Filter - For CONFIG Register
enum DLPF_CFG_ENUM{
	DLPF_260A_256G_Hz = 0x00,
	DLPF_184A_188G_Hz = 0x01,
	DLPF_94A_98G_Hz   = 0x02,
	DLPF_44A_42G_Hz   = 0x03,
	DLPF_21A_20G_Hz   = 0x04,
	DLPF_10_Hz 		  = 0x05,
	DLPF_5_Hz 		  = 0x06
};

// External Frame Synchronization - For CONFIG Register
enum EXT_SYNC_SET_ENUM{
	input_Disable = 0x00,
	TEMP_OUT_L	  = 0x01,
	GYRO_XOUT_L   = 0x02,
	GYRO_YOUT_L	  = 0x03,
	GYRO_ZOUT_L	  = 0x04,
	ACCEL_XOUT_L  = 0x05,
	ACCEL_YOUT_L  = 0x06,
	ACCEL_ZOUT_L  = 0x07
};

// Structure for raw data 
typedef struct{
	int16_t x;
	int16_t y;
	int16_t z;
}RawData_Def;

// Structure for scaled data 
typedef struct{
	float x;
	float y;
	float z;
}ScaledData_Def;

/* MPU6050 functions */
// Initilization - Configuration
void MPU6050_Init(I2C_HandleTypeDef *hi2c, MPU_ConfigTypeDef *config);
// Get Raw Data from the sensor
void MPU6050_Read_RawData(RawData_Def *accel_rawDef, RawData_Def *gyro_rawDef);
// Get Scaled Data from the raw data
void MPU6050_Read_ScaledData(ScaledData_Def *accel_scaledDef, ScaledData_Def *gyro_scaledDef);
// Get Accel scaled data
void MPU6050_Get_Accel_Scale(ScaledData_Def *accel_scaledDef);
// Get Gyro scaled data
void MPU6050_Get_Gyro_Scale(ScaledData_Def *gyro_scaledDef);

/* I2C Utility functions */
// I2C Read from Register
void I2C_Read(uint8_t REG_ADDR, uint8_t *i2c_data_rx, uint8_t data_size);
// I2C Write 8 Bit
void I2C_Write8(uint8_t REG_ADDR, uint8_t data);
