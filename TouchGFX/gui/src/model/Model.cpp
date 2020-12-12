#include <cmsis_os.h>
#include <PollingRoutine.h>
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <main.h>




extern osSemaphoreId binaryADC_NewValuesSemHandle;
extern uint16_t value[NVAL];

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if ( binaryADC_NewValuesSemHandle != NULL )
	{
		if ( osSemaphoreWait (binaryADC_NewValuesSemHandle, 1000) == osOK )
		{
			AnalogUpdate();
		}
	}	
}

void Model::AnalogUpdate ()
{
	uint32_t sum=0;
	uint16_t i;
	
	for ( i=0; i < NVAL; i++ )
	{
		sum += value[i];
	}
	modelListener->AnalogUpdate( sum/NVAL );
}