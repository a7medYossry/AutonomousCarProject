/*
 * SPI_init.h
 *
 *  Created on: May 25, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_

#define LSB    0
#define MSB    1

#define  MASTER 0
#define  SLAVE  1

#define RAISING 0
#define FALLING 1

#define SAMPLE  0
#define SETUP   1


void SPI_INIT();

void SPI_TRAS_RECIVE( u8 DATA ,u8 *recive );

#endif /* MCAL_SPI_SPI_INIT_H_ */
