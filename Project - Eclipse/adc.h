

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

typedef enum
{
	AREF , AVCC , RESERVED , Internal_Vref_256

}ADC_ReferenceVolatge;

typedef enum
{
	ADC_CPU_2 = 1 ,ADC_CPU_4,ADC_CPU__8,ADC_CPU_16,ADC_CPU_32,ADC_CPU_64,ADC_CPU_128

}ADC_Prescaler;

typedef struct {

	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
