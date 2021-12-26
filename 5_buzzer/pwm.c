
#define GPD0CON	0xE02000A0

#define TCFG0 	0xE2500000
#define TCFG1 	0xE2500004
#define TCON	0xE2500008

#define TCNTB2	0xE2500024
#define TCMPB2	0xE2500028

#define rGPD0CON	(*(volatile unsigned int*)GPD0CON)

#define rTCFG0		(*(volatile unsigned int*)TCFG0)
#define rTCFG1		(*(volatile unsigned int*)TCFG1) 
#define rTCON		(*(volatile unsigned int*)TCON)

#define rTCNTB2		(*(volatile unsigned int*)TCNTB2)
#define rTCMPB2		(*(volatile unsigned int*)TCMPB2)

void pwm_timer2_init(void)
{
	//把GPD0引脚设置为pwm模式
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (2<<8);
	
	rTCFG0 &= ~(0xFF<<8);
	rTCFG0 |= (65<<8);
	
	rTCFG1 &= ~(0xF<<8);
	rTCFG1 |= (1<<8);
	
	rTCNTB2 = 250;
	rTCMPB2 = 125;
	
	rTCON |= (1<<15);	
	//手动更新到TCNT
	rTCON |= (1<<13);
	rTCON &= ~(1<<13);
	
	rTCON |= (1<<12);
}