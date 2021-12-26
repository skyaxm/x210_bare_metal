
void uart_init(void);
void uart_putc(char);

void main(void)
{
	uart_init();
	while(1)
	{	
		uart_putc('A');
	}
	
	//return 0;
}