#include "Temp_Sensor.h"




u8 TEMP_Read(void)
{
	u16 adc=ADC_Read(Sensor_Pin);
	u16 volt=((u32)5000*adc)/1024;
	u16 temp=volt/10;
	
	return (u8)temp;
}
