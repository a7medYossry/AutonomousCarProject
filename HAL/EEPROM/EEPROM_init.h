/*
 * EEPROM_inet.h
 *
 *  Created on: Jun 1, 2024
 *      Author: Mahmoud
 */

#ifndef HAL_EEPROM_EEPROM_INIT_H_
#define HAL_EEPROM_EEPROM_INIT_H_


void EEPROM_WRITE(u16 wordadd,u8 data);

u8 EEPROM_READ(u16 wordadd);

#endif /* HAL_EEPROM_EEPROM_INIT_H_ */
