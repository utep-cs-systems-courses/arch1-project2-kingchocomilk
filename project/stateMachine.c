#include "buzzer.h"
#include <msp430.h>

/* Notes for our Westminster Doorbell tone! */ 
#define C (short)2093
#define D (short)2349
#define E (short)2637
#define G (short)3136

short stateAdvance(char beatState) {
  if (beatState == 0)
    return C;
  if (beatState == 1)
    return E;
  if (beatState == 2)
    return D;
  if (beatState == 3)
    return G;
  if (beatState == 4)
    return 0;
  if (beatState == 5)
    return G;
  if (beatState == 6)
    return D;
  if (beatState == 7)
    return C;
  if (beatState == 8)
    return E;
  else
    return 0;
}
