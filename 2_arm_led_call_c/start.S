#define SVC_STACK 0xD0037D80
#define WTCON	0xE2700000

.global _start

_start:
	ldr r0, =WTCON
	ldr r1, =0x0
	str r1, [r0]
	
	ldr sp, =SVC_STACK
	
	bl led_blink
	
	b .