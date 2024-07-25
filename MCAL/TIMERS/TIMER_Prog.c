/*
 * TIMER_Prog.c
 *
 *  Created on: May 11, 2024
 *      Author: Mahmoud
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TIMER_init.h"
#include "TIMER_confg.h"
#include "TIMER_praivat.h"

/***********************************************TIMER0*******************/
void (*TIMER0_OF_callback)(void)=NULLPTR;
void (*TIMER0_OC_callback)(void)=NULLPTR;

void vTIMER0_INIT(void) // SELLECT MOOD AND PIE AND SELLECT COMPATR MATCH
{

#if TIMER0_MODE==TIMER0_NORMAL_MODE
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
	// ENABLE PIE OVER FLOW
	SET_BIT(TIMSK,TOIE0);
#elif TIMER0_MODE==TIMER0_PHASECORRECT_MODE
	CLEAR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

#if TIMER0_COMPARE_MATCH_MODE==OC0_DISCONNECTED
	// CLEAR COM01 COM00
	CLEAR_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,COM01);
#elif  TIMER0_COMPARE_MATCH_MODE==OC0_NON_INVERTING
	// mode non inverting
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif  TIMER0_COMPARE_MATCH_MODE==OC0_INVERTING
	// mode invering
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif

#elif TIMER0_MODE==TIMER0_CTC_MODE
	SET_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
	// ENABLE PIE COMPARE MATCH
	SET_BIT(TIMSK,OCIE0);

#elif TIMER0_MODE==TIMER0_FASTPWM_MODE
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
#if TIMER0_COMPARE_MATCH_MODE==OC0_DISCONNECTED
	// CLEAR COM01 COM00
	CLEAR_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,COM01);
#elif  TIMER0_COMPARE_MATCH_MODE==OC0_NON_INVERTING
	// mode non inverting
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif  TIMER0_COMPARE_MATCH_MODE==OC0_INVERTING
	// mode invering
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif



#endif



}


void vTIMER0_START(void)// SELLECT PRESCALER
{
	TCCR0=TCCR0&0b11111000;
	TCCR0=TCCR0|TIMER0_PRESCALLER;

}

void vTIMER0_STOP(void)
{
	CLEAR_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);
}


void vTIMER0_preload(u8 preload)
{
	if(preload<=255)
		TCNT0=preload;
}

void vTIMER0_Compare_OCR0(u8 OCR)
{
	if(OCR<=255)
		OCR0=OCR;
}



void vTIMER0_OF_CallBack(void(*Fptr)(void))
{
	TIMER0_OF_callback=Fptr;
}

void vTIMER0_OC_CallBack(void(*Fptr)(void))
{

	TIMER0_OC_callback=Fptr;
}



void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void){

	if(TIMER0_OF_callback!=NULLPTR)
		TIMER0_OF_callback();

}

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void){

	if(TIMER0_OC_callback!=NULLPTR)
		TIMER0_OC_callback();

}


/***********************************************TIMER1*******************/

static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;


void vTIMER1_INIT(void)
{

#if TIMER1_MODE==TIMER1_NORMAL_MODE
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
#elif TIMER1_MODE==TIMER1_CTC_ICR_TOP_MODE
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

#elif TIMER1_MODE==TIMER1_CTC_OCRA_TOP_MODE

	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
#elif  TIMER1_MODE==TIMER1_FASTPWM_ICR_TOP_MODE
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif  TIMER1_MODE==TIMER1_FASTPWM_OCRA_TOP_MODE
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#endif


}


void Timer1_OCRA1Mode(u8 oc1a_mode)
{
	switch (oc1a_mode)
	{
	case OCRA1_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;

	case ORA1_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	case OCA1_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(u8 oc1b_mode)
{
	switch (oc1b_mode)
	{
	case OCRB1_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;

	case ORB1_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	case OCB1_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}


void vTIMER1_START(void)
{
	TCCR1B=TCCR1B&0b11111000;
	TCCR1B=TCCR1B|TIMER1_PRESCALLER;
}

void vTIMER1_STOP(void)
{
	CLEAR_BIT(TCCR1B,0);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);
}

void vTIMER1_preload(u8 preload)
{
	TCNT1=preload;
}

void vTIMER1_Compare_OCR1A(u8 OCRA)
{
	OCR1A=OCRA;
}
void vTIMER1_Compare_OCRB1(u8 OCRB)
{
	OCR1B=OCRB;
}

void vTIMER1_ICU1(u8 ICU)
{
	ICR1=ICU;
}
void Timer1_InputCaptureEdge(u8 ICU_Edge_type_edge)
{
	if(ICU_Edge_type_edge==ICU_Edge_type_RISING)
		SET_BIT(TCCR1B,ICES1);

	else if(ICU_Edge_type_edge==ICU_Edge_type_RISING)
		CLEAR_BIT(TCCR1B,ICES1);
}


void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}


void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_9 (void){

	if(Timer1_OVF_Fptr!=NULLPTR)
		Timer1_OVF_Fptr();

}

void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_7 (void){

	if(Timer1_OCA_Fptr!=NULLPTR)
		Timer1_OCA_Fptr();

}

void __vector_8 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_8 (void){

	if(Timer1_OCB_Fptr!=NULLPTR)
		Timer1_OCB_Fptr();

}

void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_6 (void){

	if(Timer1_ICU_Fptr!=NULLPTR)
		Timer1_ICU_Fptr();

}



