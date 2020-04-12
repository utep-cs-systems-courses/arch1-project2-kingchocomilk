#include <stdlib.h>
#include "buzzer.h"
#include "musicPlayer.h"
#include "music.h"

char musicHeadIndex;
char lengthOfSong;
short *currentSong;
short **allMusic;


char getLengthOfSong() {
  char index = 0;
  //buzzer_set_period(1234);
  while (*(currentSong+index) != 0){
    index++;
    //buzzer_set_period((short)index * (short)154);
  }
  if (index == 11)
    //buzzer_set_period(1234);
  return index;
}

char musicPlayerUpdate() {
  // Increment to the next note in the song
  // If the index reaches the end of the song. Keep playing 0
  //buzzer_set_period(1111);
  lengthOfSong = getLengthOfSong();
  short note = *(currentSong + musicHeadIndex);
  buzzer_set_period(note);
  if (musicHeadIndex <= lengthOfSong) {
    //buzzer_set_period(1111);
    musicHeadIndex++;
  }
  else {
    musicHeadIndex = 0;
  }
}

void musicPlayerInit() {
  musicHeadIndex = 0;
  lengthOfSong = 1;
  currentSong = *(allMusic + 3);
}

