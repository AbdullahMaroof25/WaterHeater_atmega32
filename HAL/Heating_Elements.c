#include "Heating_Elements.h"



void turn_on_heater(void)
{
	DIO_WritePin(heater_pin,HIGH);
}
void turn_off_heater(void)
{
	DIO_WritePin(heater_pin,LOW);
}
void turn_on_cooler(void)
{
	DIO_WritePin(cooler_pin,HIGH);
}
void turn_off_cooler(void)
{
	DIO_WritePin(cooler_pin,LOW);
}
void turn_on_heating__led(void)
{
	DIO_WritePin(heating__led_pin,HIGH);
}
void turn_off_heating__led(void)
{
	DIO_WritePin(heating__led_pin,LOW);
}
 
