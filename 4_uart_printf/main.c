#include "stdio.h"

void uart_init(void);
void uart_putc(char);

void main(void)
{
	uart_init();
	while(1)
	{	
		printf("A");
	}
	
	//return 0;
}