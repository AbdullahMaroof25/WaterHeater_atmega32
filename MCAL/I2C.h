


#ifndef I2C_H_
#define I2C_H_

#include "BitMath.h"
#include "StdTypes.h"
#include "MemMap.h"

void I2C_Init(void);
void TWIStart(void);
void TWIStop(void);
void TWI_ReStart(void);
void TWIWrite(u8 data);
u8 TWIReadACK(void);
u8 TWIReadNACK(void);

#endif /* I2C_H_ */