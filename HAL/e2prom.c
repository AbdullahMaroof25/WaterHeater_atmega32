
#include "e2prom.h"

void EEPROM_Write (char data)
{

	TWIStart();

	TWIWrite(0xA8); 

	TWIWrite(temp_adress);

	TWIWrite(data);

	TWIStop();

}

u8 EEPROM_Read (void)
{
	u8 temp = 0 ;
	
	TWIStart();

	TWIWrite(0xA8);

	TWIWrite(temp_adress);

	TWIStart();

	TWIWrite(0xA9);

	temp = TWIReadNACK();

	TWIStop();
	
	
	
	return temp;
}
