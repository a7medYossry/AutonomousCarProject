/*


 * WDT.c
 *
 *  Created on: Jun 7, 2024
 *      Author: Mahmoud
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "WDT.h"
#include "WDT_PRAVIT.h"




void WDT_ENABEL(WDT_t time)
{

	u8 wdt_value=0x08;//WDE SET & WDTOE CLEARED 0B00001000
	wdt_value|=time;//0B00001011
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR=wdt_value;

}

void WDT_DISABLE()
{
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}

