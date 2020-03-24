#ifndef switches_included
#define switches_included

#define SW1 BIT0 //p2.0 is sw1
#define SW2 BIT1 //p2.1 is sw2
#define SW3 BIT2 //p2.2 is sw3
#define SW4 BIT3 //p2.3 is sw4
#define SWITCHES SW1 | SW2 | SW3 | SW4		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
// NOTE TO FREQUENCY CHART
