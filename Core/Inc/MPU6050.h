/*
 * MPU6050.h
 *
 *  Created on: Feb 17, 2021
 *      Author: Everton A. Gomes
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stm32f1xx_hal.h"


//-----------------------------------------//
/*
 * STM32F103C8 Pinout - I2C_1
 * SDA - PB7
 * SCL - PB8
 *
 * See https://github.com/MYaqoobEmbedded/STM32-Tutorials/tree/master/Tutorial%2035%20-%20MPU6050%20IMU%20Module
 * for more information about STM32F4 Discovery board project with MPU6050
 */


//-----------------------------------------//

//MPU6050 registers
#define MPU_REG_SELF_TEST_X_GYRO	0x00
#define MPU_REG_SELF_TEST_Y_GYRO	0x01
#define MPU_REG_SELF_TEST_Z_GYRO	0x02
#define MPU_REG_SELF_TEST_X_ACCEL	0x0D
#define MPU_REG_SELF_TEST_Y_ACCEL	0x0E
#define MPU_REG_SELF_TEST_Z_ACCEL	0x0F
#define MPU_REG_XG_OFFSET_H			0x13
#define MPU_REG_XG_OFFSET_L			0x14
#define MPU_REG_YG_OFFSET_H			0x15
#define MPU_REG_YG_OFFSET_L			0x16
#define MPU_REG_ZG_OFFSET_H			0x17
#define MPU_REG_ZG_OFFSET_L			0x18
#define MPU_REG_SMPRT_DIV			0x19
#define MPU_REG_CONFIG				0x1A
#define MPU_REG_GYRO_CONFIG			0x1B
#define MPU_REG_ACCEL_CONFIG		0x1C
#define MPU_REG_ACCEL_CONFIG_2		0x1D
#define MPU_REG_LP_ACCEL_ODR		0x1E
#define MPU_REG_WOM_THR				0x1F
#define MPU_REG_FIFO_EN				0x23
#define MPU_REG_I2C_MST_CTRL		0x24
#define MPU_REG_I2C_SLV0_ADDR		0x25
#define MPU_REG_I2C_SLV0_REG		0x26
#define MPU_REG_I2C_SLV0_CTRL		0x27
#define MPU_REG_I2C_SLV1_ADDR		0x28
#define MPU_REG_I2C_SLV1_REG		0x29
#define MPU_REG_I2C_SLV1_CTRL		0x2A
#define MPU_REG_I2C_SLV2_ADDR		0x2B
#define MPU_REG_I2C_SLV2_REG		0x2C
#define MPU_REG_I2C_SLV2_CTRL		0x2D
#define MPU_REG_I2C_SLV3_ADDR		0x2E
#define MPU_REG_I2C_SLV3_REG		0x2F
#define MPU_REG_I2C_SLV3_CTRL		0x30
#define MPU_REG_I2C_SLV4_ADDR		0x31
#define MPU_REG_I2C_SLV4_REG		0x32
#define MPU_REG_I2C_SLV4_DO			0x33
#define MPU_REG_I2C_SLV4_CTRL		0x34
#define MPU_REG_I2C_SLV4_DI			0x35
#define MPU_REG_I2C_MST_STATUS		0x36
#define MPU_REG_INT_PIN_CFG			0x37
#define MPU_REG_INT_ENABLE			0x38
#define MPU_REG_INT_STATUS			0x3A
#define MPU_REG_ACCEL_XOUT_H		0x3B
#define MPU_REG_ACCEL_XOUT_L		0x3C
#define MPU_REG_ACCEL_YOUT_H		0x3D
#define MPU_REG_ACCEL_YOUT_L		0x3E
#define MPU_REG_ACCEL_ZOUT_H		0x3F
#define MPU_REG_ACCEL_ZOUT_L		0x40
#define MPU_REG_TEMP_OUT_H			0x41
#define MPU_REG_TEMP_OUT_L			0x42
#define MPU_REG_GYRO_XOUT_H			0x43
#define MPU_REG_GYRO_XOUT_L			0x44
#define MPU_REG_GYRO_YOUT_H			0x45
#define MPU_REG_GYRO_YOUT_L			0x46
#define MPU_REG_GYRO_ZOUT_H			0x47
#define MPU_REG_GYRO_ZOUT_L			0x48
#define MPU_REG_EXT_SENS_DATA_00	0x49
#define MPU_REG_EXT_SENS_DATA_01	0x4A
#define MPU_REG_EXT_SENS_DATA_02	0x4B
#define MPU_REG_EXT_SENS_DATA_03	0x4C
#define MPU_REG_EXT_SENS_DATA_04	0x4D
#define MPU_REG_EXT_SENS_DATA_05	0x4E
#define MPU_REG_EXT_SENS_DATA_06	0x4F
#define MPU_REG_EXT_SENS_DATA_07	0x50
#define MPU_REG_EXT_SENS_DATA_08	0x51
#define MPU_REG_EXT_SENS_DATA_09	0x52
#define MPU_REG_EXT_SENS_DATA_10	0x53
#define MPU_REG_EXT_SENS_DATA_11	0x54
#define MPU_REG_EXT_SENS_DATA_12	0x55
#define MPU_REG_EXT_SENS_DATA_13	0x56
#define MPU_REG_EXT_SENS_DATA_14	0x57
#define MPU_REG_EXT_SENS_DATA_15	0x58
#define MPU_REG_EXT_SENS_DATA_16	0x59
#define MPU_REG_EXT_SENS_DATA_17	0x5A
#define MPU_REG_EXT_SENS_DATA_18	0x5B
#define MPU_REG_EXT_SENS_DATA_19	0x5C
#define MPU_REG_EXT_SENS_DATA_20	0x5D
#define MPU_REG_EXT_SENS_DATA_21	0x5E
#define MPU_REG_EXT_SENS_DATA_22	0x5F
#define MPU_REG_EXT_SENS_DATA_23	0x60
#define MPU_REG_I2C_SLV0_DO			0x63
#define MPU_REG_I2C_SLV1_DO			0x64
#define MPU_REG_I2C_SLV2_DO			0x65
#define MPU_REG_I2C_SLV3_DO			0x66
#define MPU_REG_I2C_MST_DELAY_CTRL	0x67
#define MPU_REG_SIGNAL_PATH_RESET	0x68
#define MPU_REG_ACCEL_INTEL_CTRL	0x69
#define MPU_REG_USER_CTRL			0x6A
#define MPU_REG_PWR_MGMT_1			0x6B
#define MPU_REG_PWR_MGMT_2			0x6C
#define MPU_REG_FIFO_COUNT_H		0x72
#define MPU_REG_FIFO_COUNT_L		0x73
#define MPU_REG_FIFO_R_W			0x74
#define MPU_REG_WHO_AM_I			0x75
#define MPU_REG_XA_OFFSET_H			0x77
#define MPU_REG_XA_OFFSET_L			0x78
#define MPU_REG_YA_OFFSET_H			0x7A
#define MPU_REG_YA_OFFSET_L			0x7B
#define MPU_REG_ZA_OFFSET_H			0x7D
#define MPU_REG_ZA_OFFSET_L			0x7E

//-----------------------------------------//

//Constants
#define MPU6050_ADD					0x68	//Accelerometer I2C address
#define MPU6050_ADD_8BIT			0xD0	//Accelerometer I2C 8-bit address
#define MPU6050_ADD_WRITE			0xD0	//Address with write command
#define MPU6050_ADD_READ			0xD1	//Address with read command
#define MPU6050_SMPLRT_DIV			0x07	//Sample rate divider

//Bandwidths
enum {
	MPU6050_BANDWIDTH_260_HZ,
	MPU6050_BANDWIDTH_184_HZ,
	MPU6050_BANDWIDTH_94_HZ,
	MPU6050_BANDWIDTH_44_HZ,
	MPU6050_BANDWIDTH_21_HZ,
	MPU6050_BANDWIDTH_10_HZ,
	MPU6050_BANDWIDTH_5_HZ
};

//Accelerometer scales
enum {
	MPU6050_ACCEL_SCALE_2G,
	MPU6050_ACCEL_SCALE_4G,
	MPU6050_ACCEL_SCALE_8G,
	MPU6050_ACCEL_SCALE_16G
};

//Gyroscope scales
enum {
	MPU6050_GYRO_SCALE_250DPS,
	MPU6050_GYRO_SCALE_500DPS,
	MPU6050_GYRO_SCALE_1000DPS,
	MPU6050_GYRO_SCALE_2000DPS
};

//Clock sources
enum {
	MPU6050_INTERNAL_OSCILLATOR,
	MPU6050_PLL_GYRO_X_REF,
	MPU6050_PLL_GYRO_Y_REF,
	MPU6050_PLL_GYRO_Z_REF,
	MPU6050_PLL_32768K_REF,
	MPU6050_PLL_192M_REF

};

//--------------------------------------//


//Function prototypes
void mpu6050_init();
void mpu6050_set_sleep_mode();
void mpu6050_set_accel_scale(uint8_t accel_scale);
void mpu6050_set_gyro_scale(uint8_t gyro_scale);
void mpu6050_set_bandwidth(uint8_t bw);
void mpu6050_set_sample_rate(uint8_t smplr);
void mpu6050_set_clock_source(uint8_t clk_src);
int16_t mpu6050_get_x_axis();
int16_t mpu6050_get_y_axis();
int16_t mpu6050_get_z_axis();
int16_t mpu6050_get_x_gyro();
int16_t mpu6050_get_y_gyro();
int16_t mpu6050_get_z_gyro();
int16_t mpu6050_get_temp();


#endif /* INC_MPU6050_H_ */
