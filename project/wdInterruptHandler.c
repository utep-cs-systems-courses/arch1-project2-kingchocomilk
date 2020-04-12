#include <msp430.h>
#include "stateMachine.h"
#include "buzzer.h"
#include "musicPlayer.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char watchDogTimerCount = 0;
  //buzzer_set_period(1234);
  //buzzer_set_period((short)(watchDogTimerCount * 10));
  if (++watchDogTimerCount == 125) {
    // update the music player
    musicPlayerUpdate();
    led_update();
    watchDogTimerCount = 0;
  }
}
