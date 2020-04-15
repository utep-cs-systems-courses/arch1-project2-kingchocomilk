#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "musicPlayer.h"
#include "music.h"

char switch1_state_down, switch2_state_down, switch3_state_down,
  switch4_state_down, switch_state_changed; /* effectively boolean */
short **allMusic; // Music list
short *currentSong; // Currently Playing!
int light_state;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  /* 0 when the switch is up */
  switch1_state_down = (p2val & SW1) ? 0 : 1; 
  switch2_state_down = (p2val & SW2) ? 0 : 1;
  switch3_state_down = (p2val & SW3) ? 0 : 1;
  switch4_state_down = (p2val & SW4) ? 0 : 1;

  /* Change the music. */
  if (switch1_state_down) { 
    // Change the pointer to the selected song.
    currentSong = *(allMusic + 0);
    // Update the music player to know how long the song is.
    lengthOfSong = getLengthOfSong();
    // Reset the "needlehead" back to the beginning.
    musicHeadIndex = 0;
    // Reset the light state.
    light_state = 0;
  }
  else if (switch2_state_down) {
    currentSong = *(allMusic + 1);
    lengthOfSong = getLengthOfSong();
    musicHeadIndex = 0;
    light_state = 0;
  }
  else if (switch3_state_down) {
    currentSong = *(allMusic + 2);
    lengthOfSong = getLengthOfSong();
    musicHeadIndex = 0;
    light_state = 0;
  }
  else if (switch4_state_down) {
    currentSong = *(allMusic + 3);
    lengthOfSong = getLengthOfSong();
    musicHeadIndex = 0;
    light_state = 0;
  }
  switch_state_changed = 1;
  led_update();
}
