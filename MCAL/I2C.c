

#include "I2C.h"

void I2C_Init(void)
{
	// TWI initialization
	// Bit Rate: 400.000 kHz
	TWBR = 2;
	/*// Generate Acknowledge Pulse: On
	// TWI Interrupt: Off
	TWCR = 0x44;
	TWSR = 0x00;
	TWSR &= (~((1 << TWPS1) | (1 << TWPS0)));*/
	TWCR |= (1 << 2); //enable module
	TWSR = 0x00 ; //set prescaller bits to zero
}

void TWIStart(void)
{

	// Send Start Condition
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
}

void TWIStop(void)
{
	// Send Stop Condition
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWIWrite(unsigned char data)
{
	// Put data On TWI Register
	TWDR = data;
	// Send Data
	TWCR = (1 << TWINT) | (1 << TWEN);
	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
	
}

u8 TWIReadACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);    //enable Ack
	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
	
	// Read Data
	return TWDR;
}

u8 TWIReadNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	// Wait for TWINT flag set in TWCR Register
	while (!(TWCR & (1 << TWINT)));
	
	// Read Data
	return TWDR;
}