#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_Interface.h"

#include "SSD.h"


u8 num_array[]={0,1,2,3,4,5,6,7,8,9};
void Temp_Display(u8 temp)
{
	 DIO_WritePin(SSD1_ON,LOW);
	 DIO_WritePin(SSD2_ON,HIGH);
	 DIO_WritePort(ssd_port,num_array[(temp%10)]);
	
	 DIO_WritePin(SSD1_ON,HIGH);
	 DIO_WritePin(SSD2_ON,LOW);
	 DIO_WritePort(ssd_port,num_array[(temp/10)]);
	 
}