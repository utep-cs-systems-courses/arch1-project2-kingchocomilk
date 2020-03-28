#include <stdlib.h>
#include "musicPlayer.h"
#include "music.h"

int getLengthOf(short *notes) {
  int length = 0;
  int index = 0;
  while (*(notes + index) != 0) {
    length++;
    index++;
  }
  return index-1;
}

void populateSong(short notes[], int notesLength, short *songSection) {
  songSection = (short *) malloc(sizeof(short) * notesLength);
  for (int i = 0; i <= notesLength; i++) {
    *(songSection + i) = notes[i];
  }
}

void musicInit() {
  // Inside here, hardcode this songs for the ones we have notes for
  int firstSongLength = getLengthOf(nullSong);
  int secondSongLength = getLengthOf(westMinsterSong);
  int thirdSongLength = getLengthOf(oldSpiceSong);
  int fourthSongLength = getLengthOf(allKeysSong);

  populateSong(nullSong, firstSongLength, firstSong);
  populateSong(westMinsterSong, secondSongLength, secondSong);
  populateSong(oldSpiceSong, thirdSongLength, thirdSong);
  populateSong(allKeysSong, fourthSongLength, fourthSong);

  allMusic = (short **) malloc(sizeof(int) * 5);
  *allMusic = firstSong;
  *(allMusic + 1) = secondSong;
  *(allMusic + 2) = thirdSong;
  *(allMusic + 3) = fourthSong;
  *(allMusic + 4) = 0;
}
