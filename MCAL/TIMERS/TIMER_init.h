/*
 * TIMER_init.h
 *
 *  Created on: May 11, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_TIMERS_TIMER_INIT_H_
#define MCAL_TIMERS_TIMER_INIT_H_
/*************************TIMER0*************************/


#define		TIMER0_SCALER_1     	 1
#define		TIMER0_SCALER_8    		 2
#define	    TIMER0_SCALER_64 		 3
#define 	TIMER0_SCALER_256        4
#define 	TIMER0_SCALER_1024       5
#define 	EXTERNALl_FALLING        6
#define 	EXTERNAL_RISING          7


#define		TIMER0_NORMAL_MODE        0
#define		TIMER0_PHASECORRECT_MODE  1
#define		TIMER0_CTC_MODE           2
#define		TIMER0_FASTPWM_MODE       3








#define	OC0_DISCONNECTED   0
#define	RESERVED           1
#define	OC0_NON_INVERTING  2
#define OC0_INVERTING      3




void vTIMER0_INIT(void);


void vTIMER0_START(void);

void vTIMER0_STOP(void);

void vTIMER0_preload(u8 preload);

void vTIMER0_Compare_OCR0(u8 OCR);


void vTIMER0_OF_CallBack(void(*Fptr)(void));

void vTIMER0_OC_CallBack(void(*Fptr)(void));




/*************************TIMER1*************************/


#define 	TIMER1_SCALER_1     0
#define		TIMER1_SCALER_8     1
#define		TIMER1_SCALER_64    2
#define		TIMER1_SCALER_256   3
#define		TIMER1_SCALER_1024  4
#define		EXTERNAL0_FALLING   5
#define		EXTERNAL0_RISING    6




#define TIMER1_NORMAL_MODE            0
#define	TIMER1_CTC_ICR_TOP_MODE       1
#define	TIMER1_CTC_OCRA_TOP_MODE      2
#define	TIMER1_FASTPWM_ICR_TOP_MODE   3
#define	TIMER1_FASTPWM_OCRA_TOP_MODE  4


#define	OCRA1_DISCONNECTED   0
#define	RESERVED           1
#define	ORA1_NON_INVERTING  2
#define OCA1_INVERTING      3



#define	OCRB1_DISCONNECTED   0
#define	RESERVED           1
#define	ORB1_NON_INVERTING  2
#define OCB1_INVERTING      3



#define ICU_Edge_type_RISING     0
#define ICU_Edge_type_FALLING    1






void vTIMER1_INIT(void);


void vTIMER1_START(void);

void vTIMER1_STOP(void);

void vTIMER1_preload(u8 preload);

void Timer1_OCRA1Mode(u8 oc1a_mode);

void Timer1_OCRB1Mode(u8 oc1b_mode);

void vTIMER1_Compare_OCR1A(u8 OCRA);

void vTIMER1_Compare_OCRB1(u8 OCRB);

void vTIMER1_ICU1(u8 ICU);

void Timer1_InputCaptureEdge(u8 ICU_Edge_type_edge);


void Timer1_ICU_InterruptEnable(void);

void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_InterruptEnable(void);

void Timer1_OVF_InterruptDisable(void);

void Timer1_OCA_InterruptEnable(void);

void Timer1_OCA_InterruptDisable(void);

void Timer1_OCB_InterruptEnable(void);

void Timer1_OCB_InterruptDisable(void);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));



/*************************TIMER2*************************/




#endif /* MCAL_TIMERS_TIMER_INIT_H_ */
