


#ifndef E2PROM_H_
#define E2PROM_H_

#include "MemMap.h"
#include "I2C.h"
#include "StdTypes.h"

#define temp_adress   0x05


void EEPROM_Write (char data);
u8 EEPROM_Read (void);




#endif /* E2PROM_H_ */