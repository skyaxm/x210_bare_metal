#define GPJ0CON 0xE0200240
#define GPJ0DAT 0xE0200244
#define rGPJ0CON *(volatile unsigned int*)GPJ0CON
#define rGPJ0DAT *(volatile unsigned int*)GPJ0DAT

void delay(void)
{
	int count = 1000000;
	while(count--);
}

void led_blink(void)
{
	rGPJ0CON = 0x11111111;
	
	while(1){
		rGPJ0DAT = ( (0<<3) | (0<<4) | (0<<5) );
		delay();
		rGPJ0DAT = ( (1<<3) | (1<<4) | (1<<5) );
		delay();
		
	}
}