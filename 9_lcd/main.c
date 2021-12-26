#include "stdio.h"
#include "int.h"
#include "common.h"

#define KEY_EINT2		NUM_EINT2		// left
#define KEY_EINT3		NUM_EINT3		// down
#define KEY_EINT16_19	NUM_EINT16_31	// 其余4个共用的

int main(void)
{
	uart_init();
	
	// 如果程序中要使用中断，就要调用中断初始化来初步初始化中断控制器
	//system_init_exception();
	
	printf("\n-------------LCD test--------------\n");	
	
	lcd_test();
		
	// 绑定isr到中断控制器硬件
	//intc_setvectaddr(NUM_WDT, isr_wdt);
	
	// 使能中断
	//intc_enable(NUM_WDT);
	
	return 0;
}
