/*
 * I2C.c
 *
 *  Created on: Feb 17, 2021
 *      Author: Everton A. Gomes
 */

#include "I2C.h"


void i2c_write(uint8_t add_slave, uint8_t add_reg, uint8_t data)
{
	uint8_t i2c_data[2];
	i2c_data[0] = add_reg;	//the register we want to write into
	i2c_data[1] = data;		//data to be written

	add_slave = (add_slave << 1);	//slave address must be shifted left before write/read operations
	HAL_I2C_Master_Transmit(&hi2c1, add_slave, i2c_data, 2, 100);

}


void i2c_read(uint8_t add_slave, uint8_t add_reg, int8_t *buff, uint8_t quant)
{
	uint8_t i2c_data[1];	//this array is used for tell the slave what register we want to read
	i2c_data[0] = add_reg;	//register to be read

	//Sending to the slave the register we want to read
	add_slave = (add_slave << 1);	//slave address must be shifted left before write/read operations
	HAL_I2C_Master_Transmit(&hi2c1, add_slave, i2c_data, 1, HAL_MAX_DELAY);

	//Receiving data from slave
	HAL_I2C_Master_Receive(&hi2c1, add_slave, buff, quant, HAL_MAX_DELAY);

}

