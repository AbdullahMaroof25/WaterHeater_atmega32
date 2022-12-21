
#include "Buttons.h"

static u8 user_temp  ;

void up_btn (void)
{
	user_temp = user_temp + 5;
	if (user_temp > 75)
	{
		user_temp = 75;
	}
	EEPROM_Write(user_temp);
}
void dwn_btn (void)
{
	
	user_temp = user_temp - 5;
	if (user_temp < 35)
	{
		user_temp = 35;
	}
	EEPROM_Write(user_temp);
}
void sleep_btn (void)
{
	Wake_Up();
	user_temp = EEPROM_Read();
}
u8 get_usr_temp (void)
{
	return user_temp;
}