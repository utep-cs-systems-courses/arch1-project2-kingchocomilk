#include "buzzer.h"
#include "musicPlayer.h"
#include "music.h"

char getLengthOfSong() {
  int index = 0;
  while (*(currentSong+index) != 0)
    index++;
  return index;
}

char musicPlayerUpdate() {
  // Increment to the next note in the song
  // If the index reaches the end of the song. Keep playing 0
  lengthOfSong = getLengthOfSong();
  short note = *(currentSong + musicHeadIndex);
  buzzer_set_period(note);
  if (musicHeadIndex != lengthOfSong) {
    if (musicHeadIndex != 0) {
      musicHeadIndex++;
    }
    else {
      musicHeadIndex = 0;
    }
  }
}

void musicPlayerInit() {
  musicHeadIndex = 0;
  lengthOfSong = 1;
  currentSong = *allMusic;
}

