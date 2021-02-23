/*
 * MPU6050.c
 *
 *  Created on: Feb 17, 2021
 *      Author: Everton A. Gomes
 */

#include "MPU6050.h"
#include "I2C.h"



void mpu6050_set_sleep_mode()
{
	//sets sleep mode and stops the MPU internal clock
	i2c_write(MPU6050_ADD, MPU_REG_PWR_MGMT_1, 0x40);
	HAL_Delay(10);
}


void mpu6050_set_accel_scale(uint8_t accel_scale)
{
	accel_scale = accel_scale << 3;	//AFS_SEL is in 4-3 bits from ACCEL_CONFIG register
	i2c_write(MPU6050_ADD, MPU_REG_ACCEL_CONFIG, accel_scale);
	HAL_Delay(10);
}


void mpu6050_set_gyro_scale(uint8_t gyro_scale)
{
	gyro_scale = gyro_scale << 3;	//FS_SEL is in 4-3 bits from GYRO_CONFIG register
	i2c_write(MPU6050_ADD, MPU_REG_GYRO_CONFIG, gyro_scale);
	HAL_Delay(10);
}


void mpu6050_set_bandwidth(uint8_t bw)
{
	i2c_write(MPU6050_ADD, MPU_REG_CONFIG, bw);
	HAL_Delay(10);
}


void mpu6050_set_sample_rate(uint8_t smplr)
{
	i2c_write(MPU6050_ADD, MPU_REG_SMPRT_DIV, smplr);
	HAL_Delay(10);
}


void mpu6050_set_clock_source(uint8_t clk_src)
{
	HAL_Delay(100);
	i2c_write(MPU6050_ADD, MPU_REG_PWR_MGMT_1, clk_src);
	HAL_Delay(100);
}


void mpu6050_init()
{
	HAL_Delay(300);
	int8_t slave_add[1];
	i2c_read(MPU6050_ADD, MPU_REG_WHO_AM_I, slave_add, 1);
	mpu6050_set_sleep_mode();
	i2c_read(MPU6050_ADD, MPU_REG_WHO_AM_I, slave_add, 1);
	mpu6050_set_sample_rate(MPU6050_SMPLRT_DIV);
	mpu6050_set_gyro_scale(MPU6050_GYRO_SCALE_2000DPS);
	mpu6050_set_accel_scale(MPU6050_ACCEL_SCALE_2G);
	mpu6050_set_clock_source(MPU6050_PLL_GYRO_X_REF);
	mpu6050_set_bandwidth(MPU6050_BANDWIDTH_21_HZ);
}


int16_t mpu6050_get_x_axis()
{
	int8_t i2c_rec_data[2];
	int8_t x_low, x_high;
	int16_t x;

	i2c_read(MPU6050_ADD, MPU_REG_ACCEL_XOUT_H, i2c_rec_data, 2);

	x_high = i2c_rec_data[0];
	x_low = i2c_rec_data[1];
	x = (int16_t)(x_high << 8) | (x_low);

	return x;
}


int16_t mpu6050_get_y_axis()
{
	int8_t i2c_rec_data[2];
	int8_t y_low, y_high;
	int16_t y;

	i2c_read(MPU6050_ADD, MPU_REG_ACCEL_YOUT_H, i2c_rec_data, 2);

	y_high = i2c_rec_data[0];
	y_low = i2c_rec_data[1];
	y = (int16_t)(y_high << 8) | (y_low);

	return y;
}


int16_t mpu6050_get_z_axis()
{
	int8_t i2c_rec_data[2];
	int8_t z_low, z_high;
	int16_t z;

	i2c_read(MPU6050_ADD, MPU_REG_ACCEL_ZOUT_H, i2c_rec_data, 2);

	z_high = i2c_rec_data[0];
	z_low = i2c_rec_data[1];
	z = (int16_t)(z_high << 8) | (z_low);

	return z;
}



int16_t mpu6050_get_x_gyro()
{
	int8_t i2c_rec_data[2];
	int8_t x_low, x_high;
	int16_t x;

	i2c_read(MPU6050_ADD, MPU_REG_GYRO_XOUT_H, i2c_rec_data, 2);

	x_high = i2c_rec_data[0];
	x_low = i2c_rec_data[1];
	x = (int16_t)(x_high << 8) | (x_low);

	return x;
}


int16_t mpu6050_get_y_gyro()
{
	int8_t i2c_rec_data[2];
	int8_t y_low, y_high;
	int16_t y;

	i2c_read(MPU6050_ADD, MPU_REG_GYRO_YOUT_H, i2c_rec_data, 2);

	y_high = i2c_rec_data[0];
	y_low = i2c_rec_data[1];
	y = (int16_t)(y_high << 8) | (y_low);

	return y;
}


int16_t mpu6050_get_z_gyro()
{
	int8_t i2c_rec_data[2];
	int8_t z_low, z_high;
	int16_t z;

	i2c_read(MPU6050_ADD, MPU_REG_GYRO_ZOUT_H, i2c_rec_data, 2);

	z_high = i2c_rec_data[0];
	z_low = i2c_rec_data[1];
	z = (int16_t)(z_high << 8) | (z_low);

	return z;
}


int16_t mpu6050_get_temp()
{
	int8_t i2c_rec_data[2];
	int8_t t_low, t_high;
	int16_t t;

	i2c_read(MPU6050_ADD, MPU_REG_TEMP_OUT_H, i2c_rec_data, 2);

	t_high = i2c_rec_data[0];
	t_low = i2c_rec_data[1];
	t = (int16_t)(t_high << 8) | (t_low);

	//Gets temperature in Celsius degrees
	t = t/340 + 36;

	return t;
}







