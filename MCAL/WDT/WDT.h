/*
 * WDT.h
 *
 *  Created on: Jun 7, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_WDT_WDT_H_
#define MCAL_WDT_WDT_H_
typedef enum WDT
{
	t_16_7,
	t_32,
	t_56,
	t_500=5

}WDT_t;


void WDT_ENABEL(WDT_t time);

void WDT_DISABLE();



#endif /* MCAL_WDT_WDT_H_ */
