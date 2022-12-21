#include "Buttons.h"
#include "DIO_Interface.h"
#include "EXT_INT.h"
#include "e2prom.h"
#include "ADC.h"
#include "SSD.h"
#include "Temp_Sensor.h"
#include "Heating_Elements.h"
#include "MemMap.h"
#include "I2C.h"

//#include <util/delay.h>
//#define F_CPU 8000000 UL

int main(void)
{
	u8 user_temp ;
	u8 sens_temp ;
	EXT_voidInitGlobalInterrupts();
	SetCallBack_ExtInt(EXT_INT_2,sleep_btn);
	Sleep_Mode();
	
	
	EXT_voidEnableExtInt(EXT_INT_0,RISIN_EDGE);
	EXT_voidEnableExtInt(EXT_INT_1,RISIN_EDGE);
	EXT_voidEnableExtInt(EXT_INT_2,RISIN_EDGE);
	SetCallBack_ExtInt(EXT_INT_0,up_btn);
	SetCallBack_ExtInt(EXT_INT_1,dwn_btn);
	SetCallBack_ExtInt(EXT_INT_2,sleep_btn);
	
	
	 
	DIO_Init();
	I2C_Init();
	EEPROM_Write(60);
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
	
	sens_temp = TEMP_Read();
	user_temp = get_usr_temp();
	
	
   
     
	
	
	
    while (1) 
    {
		sens_temp = TEMP_Read();
		user_temp = get_usr_temp();
		
		Temp_Display(user_temp);
		
		if ((user_temp < sens_temp) )
		{
			
			turn_on_heater();
			turn_off_cooler();
		}
		else if ((user_temp > sens_temp) )
		{
			
			turn_off_heater();
			turn_on_cooler();
		}
		
		
    }
}

