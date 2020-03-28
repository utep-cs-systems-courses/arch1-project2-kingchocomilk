#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "musicPlayer.h"

void led_init()
{
  P2DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    if (lengthOfSong <= 1)
      ledFlags |= LED_RED;
    else
      ledFlags |= LED_GREEN;
    //    ledFlags |= switch1_state_down ? LED_RED : 0;
    //ledFlags |= switch_state_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

