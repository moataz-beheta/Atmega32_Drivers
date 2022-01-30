#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_configuration.h"

#ifndef			NULL
#define			NULL	(void *)0
#endif

void (*EXTI0_PfCallBack)(void) = NULL ; // pointer to function global variable

void EXTI_voidInit(void)
{
	#if 	EXTI0_SENSE_MODE == EXTI_FALLING
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	#elif 	EXTI0_SENSE_MODE == EXTI_RISING
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	#elif 	EXTI0_SENSE_MODE == EXTI_LOW_LEVEL
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	#elif 	EXTI0_SENSE_MODE == EXTI_IOC
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	#else
		#error	"Wrong Choice of External interrupt 0 Sense Mode!"
	#endif
	
	/*	Disable Interrupt 0						*/
	CLR_BIT(GICR,6);
	/*	Clear External interrupt 0 Flag			*/
	SET_BIT(GIFR,6);
}
void EXTI0_voidEnable(void)
{
	/*	Enable Interrupt 0						*/
	SET_BIT(GICR,6);
}
void EXTI0_voidDisable(void)
{
	/*	Disable Interrupt 0						*/
	CLR_BIT(GICR,6);
}

void GIE_voidEnable(void)
{
	/*	Enable Global Interrupt					*/
	SET_BIT(SREG,7);	
}
void GIE_voidDisable(void)
{
	/*	Disable Global Interrupt				*/
	CLR_BIT(SREG,7);	
}


void EXTI0_voidSetCallBack(void (pf)(void)) /* EXTI0_PfCallBack = pf = EXTI0_Func */
{
	EXTI0_PfCallBack = pf ;
}

void __vector_1 (void)	__attribute__((signal,used)); // 3ashan el optimizer mayemsa7housh , la2inoh bet3amalo call by hardware, fabeltaly el compiler mish hayshofoh
/*	ISR Function For External Interrupt 0		*/
void __vector_1 (void) // fi el reset & interrupt vector table in datasheet, rakmha 2, hena ba7ot el rakam -1 ya3ny hena 1
{
	EXTI0_PfCallBack();
}