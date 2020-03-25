#include <msp430.h>
#include "stateMachine.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  // buzzer_set_period(3500);
  static short tone = 0;
  static char beatState = 0;
  static char watchDogTimerCount = 0;
  if (++watchDogTimerCount == 125) {
    tone = stateAdvance(beatState);
    buzzer_set_period(tone);
    watchDogTimerCount = 0;
    if (beatState == 9)
      beatState = 0;
    else
      beatState++;
  }
}
