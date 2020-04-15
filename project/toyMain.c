#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"
#include "musicPlayer.h"
#include "music.h"
#include "switches.h"
#include "led.h"

int main() {

  configureClocks();

  musicInit();
  musicPlayerInit();

  // The buzzer is initialized and ready.
  buzzer_init();
  switch_init();
  led_init();

  // The clock is used to cycle through the states.
  enableWDTInterrupts();

  // Leave the main program and go into the interrupt.
  or_sr(0x18);
}
