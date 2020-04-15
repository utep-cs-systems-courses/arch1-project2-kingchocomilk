	.cdecls LIST "msp430.h", "led.h", "switches.h", "musicPlayer.h", "music.h"
	.arch msp430g2553
	.p2align 1, 0

	.data
jump_table:	
	.word case_0		; All different cases here
	.word case_1
	.word case_2
	.word case_3

	.text
led_init:
	bis LEDS, P1DIR		; Initiallize the lights
	mov #1, &switch_state_changed ; Update flag
	call led_update		      ; Call update
	ret

	
led_update:
	cmp #0, &switch_state_changed ; Check if state > 0
	jeq update_end		      ; Jump to end if not true
	cmp #4, &light_state	      ; Compare if the state is over the cases count
	jge update_end		      ; If it was greater than or equal to, jump to end
	mov &light_state, r12	      ; Temp variable for doubling index for wordsize
	add r12, r12		      
	mov jump_table(r12), r0	; We jump our switch-case into our jump table

case_0:
	mov.b #0, &P1OUT 	; Turn off all lights cleanly
	mov.b &LEDS, &P1OUT	; Both lights are on at the beginning
	jmp update_end		; Break and jump to the end.

case_1:
	mov.b #0, &P1OUT	; Turn off all lights cleanly
	mov.b &LED_RED, &P1OUT	; Light red while playing
	jmp update_end		; Break and jump to the end.

case_2:
	mov.b #0, P1OUT		; Turn off all lights cleanly
	mov.b &LED_GREEN, &P1OUT ; Light green
	jmp update_end		 ; Break and jump to the end.

case_3:
	mov.b #0, &P1OUT	; Turn off all lights cleanly
	jmp update_end		; Break and jump to the end.
	
update_end:	
	mov #0, &switch_state_changed ; Turn off flag
	ret
	
