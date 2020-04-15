#include <stdlib.h>
#include "buzzer.h"
#include "musicPlayer.h"
#include "music.h"
#include "led.h"

char musicHeadIndex;
char lengthOfSong;
short *currentSong;
short **allMusic;
int light_state;

/* Increment through currentSong to know the length of the song. */
char getLengthOfSong() {
  char index = 0;
  while (*(currentSong+index) != 0)
    index++;
  return index;
}

/* Get the note of the current song and play. This is the "needle". */
char musicPlayerUpdate() {
  lengthOfSong = getLengthOfSong();
  short note = *(currentSong + musicHeadIndex);
  buzzer_set_period(note);
  if (musicHeadIndex <= lengthOfSong)
    musicHeadIndex++;
  else
    musicHeadIndex = 0;

  // Update the state of the light
  if (musicHeadIndex == 0)
    light_state = 0;
  else if (musicHeadIndex == lengthOfSong)
    light_state = 3;
  else {
    if (light_state == 0)
      light_state = 1;
    if (light_state == 1)
      light_state = 2;
    if (light_state == 2)
      light_state = 1;
  } 
}

/* Initiallizes the the current song to play. Also starts the music head and length. */
void musicPlayerInit() {
  currentSong = *(allMusic + 0);
  musicHeadIndex = 0;
  lengthOfSong = getLengthOfSong();
}

