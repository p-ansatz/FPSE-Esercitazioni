/* Includes */
#include "MPU6050_lib.h"

/* Variables */
static I2C_HandleTypeDef i2cHandler; // I2C Handle
static float accelScalingFactor, gyroScalingFactor; // Accel and Gyro Scaling Factor
static int16_t AccelRW[3];
static int16_t GyroRW[3];

/* Initilization - Configuration */
void MPU6050_Init(I2C_HandleTypeDef *hi2c, MPU_ConfigTypeDef *config){	
	// Save the i2c handler internally
	memcpy(&i2cHandler, hi2c, sizeof(*hi2c));

	uint8_t Buffer = 0; // Unsigned char used for set registers values

	/* Power Management Settings */
	I2C_Write8(PWR_MAGT_1_REG, 0x80); //Reset Device
	HAL_Delay(100); // Wait at least 10ms after setting

	Buffer = config ->Clock_Source;
	Buffer |= (config ->Sleep_Mode_Bit << 6);

	I2C_Write8(PWR_MAGT_1_REG, Buffer);
	HAL_Delay(100); // Wait at least 10ms after setting
	
	Buffer = 0;
	/* Configuration Settings */
	Buffer = config->Config_Dlpf; // Set the Digital Low Pass Filter
	I2C_Write8(CONFIG_REG, Buffer);
	
	Buffer = 0;
	/* GYRO Configuration Settings */
	Buffer = (config->Gyro_Full_Scale << 3); // Select the Gyroscope Full Scale Range
	I2C_Write8(GYRO_CONFIG_REG, Buffer);

	Buffer = 0;
	/* ACCEL Configuration Settings */
	Buffer = (config->Accel_Full_Scale << 3); // Select the Accelerometer Full Scale Range
	I2C_Write8(ACCEL_CONFIG_REG, Buffer);

	/* Sample Rate Divider */
	I2C_Write8(SMPLRT_DIV_REG, 0x04); // Set Sample Rate Divider to default (0x04)

	/* Scaling factor, depending on SCALE selected */
	// Accelerometer Scaling Factor
	switch (config->Accel_Full_Scale){
		case AFS_SEL_2g:
			accelScalingFactor = (1.0f/16384.0f);
			break;
		
		case AFS_SEL_4g:
			accelScalingFactor = (1.0f/8192.0f);
			break;
		
		case AFS_SEL_8g:
			accelScalingFactor = (1.0f/4096.0f);
			break;
		
		case AFS_SEL_16g:
			accelScalingFactor = (1.0f/2048.0f);
			break;
		
		default:
			break;
	}

	//Gyroscope Scaling Factor 
	switch (config->Gyro_Full_Scale){
		case FS_SEL_250:
			gyroScalingFactor = 1.0f/131.0f;
			break;
		
		case FS_SEL_500:
			gyroScalingFactor = 1.0f/65.5f;
			break;
		
		case FS_SEL_1000:
			gyroScalingFactor = 1.0f/32.8f;
			break;
		
		case FS_SEL_2000:
			gyroScalingFactor = 1.0f/16.4f;
			break;
		
		default:
			break;
	}
}

/* Read Data */
void MPU6050_Read_RawData(RawData_Def *accel_rawDef, RawData_Def *gyro_rawDef){
	uint8_t i2cBuf[2];
	uint8_t AcceArr[6], GyroArr[6];
	I2C_Read(INT_STATUS_REG, &i2cBuf[1],1);

	if( i2cBuf[1] && 0x01){

		//Accel Raw Data
		I2C_Read(ACCEL_XOUT_H_REG, AcceArr,6);
		accel_rawDef->x = ((AcceArr[0]<<8) + AcceArr[1]); // x-Axis
		accel_rawDef->y = ((AcceArr[2]<<8) + AcceArr[3]); // y-Axis
		accel_rawDef->z = ((AcceArr[4]<<8) + AcceArr[5]); // z-Axis

		// Local raw data
		AccelRW[0] = accel_rawDef->x;
		AccelRW[1] = accel_rawDef->y;
		AccelRW[2] = accel_rawDef->z;

		//Gyro Raw Data
		I2C_Read(GYRO_XOUT_H_REG, GyroArr,6);
		gyro_rawDef->x = ((GyroArr[0]<<8) + GyroArr[1]); // x-Axis
		gyro_rawDef->y = ((GyroArr[2]<<8) + GyroArr[3]); // y-Axis
		gyro_rawDef->z = ((GyroArr[4]<<8) + GyroArr[5]); // z-Axis

		// Local raw data
		GyroRW[0] = gyro_rawDef->x;
		GyroRW[1] = gyro_rawDef->y;
		GyroRW[2] = gyro_rawDef->z;
	}
}

/* Read Scaled Data */
void MPU6050_Read_ScaledData(ScaledData_Def *accel_scaledDef, ScaledData_Def *gyro_scaledDef){

	// Accel Scaled data
	accel_scaledDef->x = ((AccelRW[0])*accelScalingFactor);
	accel_scaledDef->y = ((AccelRW[1])*accelScalingFactor);
	accel_scaledDef->z = ((AccelRW[2])*accelScalingFactor);

	// Gyro Scaled data
	gyro_scaledDef->x = (GyroRW[0])*gyroScalingFactor;
	gyro_scaledDef->y = (GyroRW[1])*gyroScalingFactor;
	gyro_scaledDef->z = (GyroRW[2])*gyroScalingFactor;
}


/* Get Accel scaled data (1g = 9.81m/s2) */
void MPU6050_Get_Accel_Scale(ScaledData_Def *accel_scaledDef){
	// Accel Scaled data
	accel_scaledDef->x = ((AccelRW[0]+0.0f)*accelScalingFactor);
	accel_scaledDef->y = ((AccelRW[1]+0.0f)*accelScalingFactor);
	accel_scaledDef->z = ((AccelRW[2]+0.0f)*accelScalingFactor);
}


/* Get Gyro scaled data */
void MPU6050_Get_Gyro_Scale(ScaledData_Def *gyro_scaledDef){
	// Gyro Scaled data
	gyro_scaledDef->x = (GyroRW[0])*gyroScalingFactor;
	gyro_scaledDef->y = (GyroRW[1])*gyroScalingFactor;
	gyro_scaledDef->z = (GyroRW[2])*gyroScalingFactor;
}

/* I2C Utility functions */
// I2C Read
void I2C_Read(uint8_t REG_ADDR, uint8_t *i2c_data_rx, uint8_t data_size){
	uint8_t i2c_data_tx[2];
	i2c_data_tx[0] = REG_ADDR;

	HAL_I2C_Master_Transmit(&i2cHandler, MPU_ADDR<<1, i2c_data_tx, 1, 10);
	HAL_I2C_Master_Receive(&i2cHandler, MPU_ADDR<<1, i2c_data_rx, data_size, 100);
}

// I2C Write 8 bit
void I2C_Write8(uint8_t REG_ADDR, uint8_t data){
	uint8_t i2c_data_tx[2];
	i2c_data_tx[0] = REG_ADDR;
	i2c_data_tx[1] = data;

	HAL_I2C_Master_Transmit(&i2cHandler, MPU_ADDR<<1, i2c_data_tx, 2, 100);
}
