#include "stdio.h"
#include "int.h"
#include "common.h"

#define KEY_EINT2		NUM_EINT2		// left
#define KEY_EINT3		NUM_EINT3		// down
#define KEY_EINT16_19	NUM_EINT16_31	// 其余4个共用的

static void wait(int cnt)
{
	volatile int i, j;
	for(i = 0; i<cnt; i++)
	{
		for(j=0; j<1000; j++)
		{
			
		}
	}
}

int main(void)
{
	uart_init();
	//key_init();
	//key_init_interrupt();
	//wdt_interrupt_init();
	
	// 如果程序中要使用中断，就要调用中断初始化来初步初始化中断控制器
	system_init_exception();
	
	printf("-------------rtc test--------------");
	
	RTC rtc_write = {
		.year = 2021,
		.month = 12,
		.date = 19,
		.hour = 22,
		.minute = 8,
		.second = 50,
		.day = 0
	};
	rtc_set_time(&rtc_write);
	
	//delay(100);	
	
		
	// 绑定isr到中断控制器硬件
	//intc_setvectaddr(KEY_EINT2, isr_eint2);
	//intc_setvectaddr(KEY_EINT3, isr_eint3);
	//intc_setvectaddr(KEY_EINT16_19, isr_eint16171819);
	//intc_setvectaddr(NUM_WDT, isr_wdt);
	
	// 使能中断
	//intc_enable(KEY_EINT2);
	//intc_enable(KEY_EINT3);
	//intc_enable(KEY_EINT16_19);
	//intc_enable(NUM_WDT);
	
	// 在这里加个心跳
	RTC rtc_read;
	while (1)
	{
		rtc_get_time(&rtc_read);
		printf("rtc: %d-%d-%d %d:%d:%d %d\t", rtc_read.year, rtc_read.month, rtc_read.date, rtc_read.hour, rtc_read.minute, rtc_read.second, rtc_read.day);
		
		wait(1000);
		//int i = 10000;
		//while(i--);
		
		//delay(100);	
	}

	return 0;
}