//#ifndef POLLINGROUTINE_C
//#define POLLINGROUTINE_C


/* Polling values from ADC1_IN0 to DMA */
#include <PollingRoutine.h>
#include <cmsis_os.h>
#include <main.h>
#include <stm32f7xx_hal_adc.h>
#include <stm32f7xx_hal_tim.h>




extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern osSemaphoreId binaryADC_NewValuesSemHandle;
uint16_t value[NVAL] = {0};
uint16_t i;

void PollingAnalogInit ()
{
	HAL_ADC_Start_DMA ( &hadc1, (uint32_t *)&value, NVAL);
	HAL_TIM_Base_Start_IT ( &htim1 );
}

void PollingAnalogRoutine()
{
	for (i=0; i<NVAL; i++)
	{
		value[i] = HAL_ADC_GetValue ( &hadc1 );
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  osSemaphoreRelease (binaryADC_NewValuesSemHandle);
}

//#endif