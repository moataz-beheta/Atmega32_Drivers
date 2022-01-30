#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_configuration.h"
#include "ADC_Private.h"
#include "ADC_Register.h"
#include "ADC_interface.h"

void	ADC_Init	(void)
{
	/*	Enable ADC		*/
	SET_BIT(ADCSRA,7);
	
	/*	Voltage Reference		*/
	
	#if 	V_Ref == AREF
	CLR_BIT(ADMUX,6);	//REFS0 Pin
	CLR_BIT(ADMUX,7);	//REFS1 Pin
	
	#elif 	V_Ref == AVCC
	SET_BIT(ADMUX,6);	//REFS0 Pin
	CLR_BIT(ADMUX,7);	//REFS1 Pin
	
	#elif 	V_Ref == Internal
	SET_BIT(ADMUX,6);	//REFS0 Pin
	SET_BIT(ADMUX,7);	//REFS1 Pin
	
	#else
	#error	"Wrong Choice of ADC Voltage Reference!"
	#endif
	
	/*	Prescaler				*/
	#if 	Prescaler == Clock_Div_2
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	CLR_BIT(ADCSRA,1);	//ADPS1 Pin
	CLR_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_4
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	CLR_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_8
	SET_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	CLR_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_16
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	CLR_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_32
	SET_BIT(ADCSRA,0);	//ADPS0 Pin
	CLR_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin

	#elif 	Prescaler == Clock_Div_64
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin

	#elif 	Prescaler == Clock_Div_128
	SET_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#else
	#error	"Wrong Choice of ADC Prescaler!"
	#endif


	/*	Interrupt Enable 			*/
	#if 	Interrupt == ON
	SET_BIT(ADCSRA,3);	
	
	#elif 	Interrupt == OFF
	CLR_BIT(ADCSRA,3);
	
	#else
	#error	"Wrong Choice of ADC Interrupt Enable!"
	#endif
	
	/*	Interrupt Flag	 			*/
	SET_BIT(ADCSRA,4);	//Clear Flag
	
}

	
	
u16		ADC_Read	(u8 Channel)
{
	ADMUX |= (Channel & 0x1f);
	
	u16	Local_u16Value = 0;
	
	/*	Start Single Conversion		*/
	SET_BIT(ADCSRA,6);	
	
	/* wait till conversion is done		*/
	while	((GET_BIT(ADCSRA,4)) == 0);
	SET_BIT(ADCSRA,4);	//Clear Flag
	
	/*	Read The Conversion Value	*/
	Local_u16Value = ADC;
	
	return Local_u16Value;
}