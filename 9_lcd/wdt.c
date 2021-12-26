#include "int.h"
#include "stdio.h"

#define	WTCON		0xE2700000
#define WTDAT		0xE2700004
#define WTCNT		0xE2700008
#define WTCLRINT	0xE270000C

#define	rWTCON	 	(*(volatile unsigned int*)WTCON)
#define rWTDAT		(*(volatile unsigned int*)WTDAT)
#define rWTCNT		(*(volatile unsigned int*)WTCNT)
#define rWTCLRINT	(*(volatile unsigned int*)WTCLRINT)

void wdt_interrupt_init(void)
{
	rWTCON &= ~(1<<0);
	rWTCON |= (1<<2);
	rWTCON |= (3<<3);
	
	rWTCON &= ~(0xFF<<8);
	rWTCON |= (65<<8);
	
	rWTDAT = 10000;
	rWTCNT = 10000;
	
	rWTCON |= (1<<5);	
}

void isr_wdt(void)
{
	static int cnt = 0;
	
	printf("this is %d watchdog timer interrupt.\n", cnt++);
	
	rWTCLRINT = 1;
	intc_clearvectaddr();
}