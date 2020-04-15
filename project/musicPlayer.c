#include <stdlib.h>
#include "buzzer.h"
#include "musicPlayer.h"
#include "music.h"

char musicHeadIndex;
char lengthOfSong;
short *currentSong;
short **allMusic;

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
}

/* Initiallizes the the current song to play. Also starts the music head and length. */
void musicPlayerInit() {
  currentSong = *(allMusic + 0);
  musicHeadIndex = 0;
  lengthOfSong = getLengthOfSong();
}

