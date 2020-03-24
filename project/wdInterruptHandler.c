#include <msp430.h>
#include "stateMachine.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  buzzer_set_period(3500);
  static char beatCount = 0;
  if (++beatCount == 125) {
    //stateAdvance();
    beatCount = 0;
  }
}
