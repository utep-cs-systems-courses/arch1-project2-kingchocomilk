#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

int main() {
  /* 
     Each of these calls needs an explanation. It isn't good that we just call
     them without somekind of context. It needs the trace of calls on all of 
     these files and figure out what the hell is going on. Best way to document
     this is to make a format. First an english description of what's happening 
     and the linear series of calls.

     Description...
     toyMain.c[main()] --> etc...
   */
  
  // implemented in /timerLibs/clocksTimer.c
  // uses constants from /opt/ti/msp430_gcc/include/msp430g2553.h
  // What is sfr_w()?
  configureClocks();

  buzzer_init();
  enableWDTInterrupts();
  
  or_sr(0x18);
  
}
