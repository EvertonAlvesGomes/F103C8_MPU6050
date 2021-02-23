/*
 * I2C.h
 *
 *  Created on: Feb 17, 2021
 *      Author: Everton A. Gomes
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stm32f1xx_hal.h"

//Variables
extern I2C_HandleTypeDef hi2c1;


//Function Prototypes
void i2c_write(uint8_t add_slave, uint8_t add_reg, uint8_t data);	//add = address to be written, data = what will be written
void i2c_read(uint8_t add_slave, uint8_t add_reg, int8_t *buff, uint8_t quant);	//quant = quantity of bytes to be read

#endif /* INC_I2C_H_ */
