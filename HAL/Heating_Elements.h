

#ifndef HEATING_ELEMENTS_H_
#define HEATING_ELEMENTS_H_

#include "BitMath.h"
#include "DIO_Interface.h"
#include "MemMap.h"


#define heater_pin          PINC5
#define cooler_pin          PINC6
#define heating__led_pin    PINC7


void turn_on_heater(void);
void turn_off_heater(void);
void turn_on_cooler(void);
void turn_off_cooler(void);
void turn_on_heating__led(void);
void turn_off_heating__led(void);




#endif /* HEATING_ELEMENTS_H_ */