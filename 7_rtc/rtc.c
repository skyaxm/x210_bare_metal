#include "common.h"

#define 	RTC_BASE	 (0xE2800000)
#define		rINTP      	 (*((volatile unsigned long *)(RTC_BASE + 0x30)))
#define		rRTCCON    	 (*((volatile unsigned long *)(RTC_BASE + 0x40)))
#define		rTICCNT    	 (*((volatile unsigned long *)(RTC_BASE + 0x44)))
#define		rRTCALM    	 (*((volatile unsigned long *)(RTC_BASE + 0x50)))
#define		rALMSEC    	 (*((volatile unsigned long *)(RTC_BASE + 0x54)))
#define		rALMMIN    	 (*((volatile unsigned long *)(RTC_BASE + 0x58)))
#define		rALMHOUR  	 (*((volatile unsigned long *)(RTC_BASE + 0x5c)))
#define		rALMDATE     (*((volatile unsigned long *)(RTC_BASE + 0x60)))
#define		rALMMON    	 (*((volatile unsigned long *)(RTC_BASE + 0x64)))
#define		rALMYEAR  	 (*((volatile unsigned long *)(RTC_BASE + 0x68)))
#define		rRTCRST      (*((volatile unsigned long *)(RTC_BASE + 0x6c)))
#define		rBCDSEC    	 (*((volatile unsigned long *)(RTC_BASE + 0x70)))
#define		rBCDMIN   	 (*((volatile unsigned long *)(RTC_BASE + 0x74)))
#define		rBCDHOUR     (*((volatile unsigned long *)(RTC_BASE + 0x78)))
#define		rBCDDATE     (*((volatile unsigned long *)(RTC_BASE + 0x7c)))
#define		rBCDDAY      (*((volatile unsigned long *)(RTC_BASE + 0x80)))
#define		rBCDMON      (*((volatile unsigned long *)(RTC_BASE + 0x84)))
#define		rBCDYEAR     (*((volatile unsigned long *)(RTC_BASE + 0x88)))
#define		rCURTICCNT   (*((volatile unsigned long *)(RTC_BASE + 0x90)))
#define		rRTCLVD    	 (*((volatile unsigned long *)(RTC_BASE + 0x94)))

/*
typedef struct rtc_time
{
	unsigned int year;
	unsigned int month;
	unsigned int date;			// ¼¸ºÅ
	unsigned int hour;			
	unsigned int minute;
	unsigned int second;
	unsigned int day;			// ÐÇÆÚ¼¸
}RTC;
*/

static unsigned int dec2bcd(unsigned int num)
{
	return ( ((num/10)<<4) | (num%10) );
}

static unsigned int bcd2dec(unsigned int bcd)
{
	return ( ((bcd&0xF0)>>4)*10 + (bcd & 0x0F) );
}

void rtc_set_time(const RTC *p)
{
	rRTCCON |= (1<<0);
	
	rBCDYEAR = dec2bcd(p->year - 2000);
	rBCDMON = dec2bcd(p->month);
	rBCDDATE = dec2bcd(p->date);
	rBCDHOUR = dec2bcd(p->hour);
	rBCDMIN = dec2bcd(p->minute);
	rBCDSEC = dec2bcd(p->second);
	rBCDDAY = dec2bcd(p->day);
	
	rRTCCON &= ~(1<<0);
}

void rtc_get_time(RTC *p)
{
	rRTCCON |= (1<<0);
	
	p->year = bcd2dec(rBCDYEAR) + 2000;
	p->month = bcd2dec(rBCDMON); 
    p->date = bcd2dec(rBCDDATE);
    p->hour = bcd2dec(rBCDHOUR);
    p->minute = bcd2dec(rBCDMIN); 
    p->second = bcd2dec(rBCDSEC); 
    p->day = bcd2dec(rBCDDAY); 
	
	rRTCCON &= ~(1<<0);
}