# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR		= msp430-elf-ar

all: tune.elf 

#additional rules for files
tune.elf: ${COMMON_OBJECTS} stateMachine.o buzzer.o wdInterruptHandler.o libTimer.a toyMain.o sr.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: tune.elf
	msp430loader.sh tune.elf

sr.o: sr.h sr.s

clean:
	rm -f *.o *.elf

wdInterruptHandler.o: stateMachine.h

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

stateMachine.o: stateMachine.h

buzzer.o: buzzer.h libTimer.h
