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
tune.elf: ${COMMON_OBJECTS} buzzer.o led.o music.o musicPlayer.o wdInterruptHandler.o switches.o libTimer.a toyMain.o sr.o p1_interrupt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: tune.elf
	msp430loader.sh tune.elf

sr.o: sr.h sr.s

p1_interrupt_handler.o: p1_interrupt_handler.c switches.o

led.o: led.h led_update.s music.o musicPlayer.o

musicPlayer.o: musicPlayer.h musicPlayer.c music.o music.h music.c

switches.o: switches.h switches.c music.o musicPlayer.o

music.o: music.h music.c musicPlayer.o musicPlayer.c musicPlayer.h

clean:
	rm -f *.o *.elf

wdInterruptHandler.o: wdInterruptHandler.c

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

buzzer.o: buzzer.h libTimer.h
