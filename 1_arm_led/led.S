
#define GPJ0CON 0xE0200240
#define GPJ0DAT 0xE0200244

.global _start

_start:
	@把0x11111111写入GPJ0CON寄存器
	ldr r0, =0x11111111
	ldr r1, =GPJ0CON
	str r0, [r1]		@r1此时当作指针

flash:	
	ldr r0, =( (0<<3) | (1<<4) | (1<<5) )	
	ldr r1, =GPJ0DAT
	str r0, [r1]	
	bl delay
	
	ldr r0, =( (1<<3) | (0<<4) | (1<<5) )	
	ldr r1, =GPJ0DAT
	str r0, [r1]	
	bl delay
	
	ldr r0, =( (1<<3) | (1<<4) | (0<<5) )	
	ldr r1, =GPJ0DAT
	str r0, [r1]	
	bl delay
	
	b flash
	
delay:
	ldr r2, =9000000
	ldr r3, =0
	
delay_loop:	
	sub r2, r2, #1
	cmp r2, r3	
	bne delay_loop
	mov pc, lr
