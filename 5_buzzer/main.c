#include "stdio.h"

void uart_init(void);
void pwm_timer2_init(void);

int main(void)
{
	pwm_timer2_init();
	
	return 0;
}