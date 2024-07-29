
#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	ADMUX  = ( (Config_Ptr->ref_volt) << REFS0) ;

	ADCSRA = (1<<ADEN);

	ADCSRA |= ((Config_Ptr->prescaler) & (0xFC) ) ;
}

uint16 ADC_readChannel(uint8 channel)
{
	ADMUX = (ADMUX & 0XE0) | channel ;

	SET_BIT(ADCSRA,ADSC);

	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);

	return ADC;
}
