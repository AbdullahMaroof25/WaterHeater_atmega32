


#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "StdTypes.h"
#include "DIO_Interface.h"
#include "BitMath.h"

#define up_btn_pin   PINA1
#define dwn_btn_pin   PINA1
#define slp_btn_pin   PINA1


void up_btn (void);
void dwn_btn (void);
void sleep_btn (void);
u8   get_usr_temp (void);





#endif /* BUTTONS_H_ */