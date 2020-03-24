#include "buzzer.h"
#include <msp430.h>

void stateAdvance(unsigned char state) {

  switch(state) {
  case 0 :
    buzzer_set_period(2093); //Play C7
  case 1 :
    buzzer_set_period(2637); //Play E7
  case 2 :
    buzzer_set_period(2349); //Play D7
  case 3 :
    buzzer_set_period(3136); //Play G7
  case 4 :
    buzzer_set_period(3136); //Play G7
  case 5 :
    buzzer_set_period(2349); //Play D7
  case 6 :
    buzzer_set_period(2637); //Play E7
  case 7 :
    buzzer_set_period(2093); //Play C7
  }
}
