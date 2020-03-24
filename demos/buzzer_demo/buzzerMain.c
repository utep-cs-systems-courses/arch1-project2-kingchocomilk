#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
 
    buzzer_init();
    buzzer_set_period(2093);	/* start buzzing!!! */
    buzzer_set_period(2093);

    or_sr(0x18);          // CPU off, GIE on
}
