#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "musicPlayer.h"
#include "music.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    switch (light_state) {
    case 0: // Both lights, beginning of song.
      P1OUT = 0;
      P1OUT = LEDS;
      break;
    case 1: // Red light, cadencing along with the music.
      P1OUT = 0;
      P1OUT = LED_RED;
      break;
    case 2: // Green light
      P1OUT = 0;
      P1OUT = LED_GREEN;
      break;
    case 3: // Both off, signifying the end of the song.
      P1OUT = 0;
      break;
    }
  }
  switch_state_changed = 0;
}

