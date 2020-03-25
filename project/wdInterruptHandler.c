#include <msp430.h>
#include "stateMachine.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  // tone is the hertz where we can find our notes.
  static short tone = 0;
  // There are different beats in the tune. Beat state is where on the scale we are.
  static char beatState = 0;
  // The count is for counting the time between the notes.
  static char watchDogTimerCount = 0;
  if (++watchDogTimerCount == 125) {
    // stateAdvance will give us the next tone.
    tone = stateAdvance(beatState);
    // This plays the tone on the board.
    buzzer_set_period(tone);
    // We reset the counter so we can play another long note.
    watchDogTimerCount = 0;
    // We reset the beat when we cycle through all the notes.
    if (beatState == 9)
      beatState = 0;
    else
      beatState++;
  }
}
