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

  nullSong[0] = Z0;
  westMinsterSong[0] = Z0;
  westMinsterSong[1] = F7;
  westMinsterSong[2] = A7;
  westMinsterSong[3] = G7;
  westMinsterSong[4] = C7;
  westMinsterSong[5] = Z0;
  westMinsterSong[6] = C7;
  westMinsterSong[7] = G7;
  westMinsterSong[8] = A7;
  westMinsterSong[9] = F7;
  westMinsterSong[10] = Z0;
  oldSpiceSong[0] = Z0;
  oldSpiceSong[1] = G6;
  oldSpiceSong[2] = G6;
  oldSpiceSong[3] = A6;
  oldSpiceSong[4] = C7;
  oldSpiceSong[5] = B6;
  oldSpiceSong[6] = D7;
  oldSpiceSong[7] = E7;
  oldSpiceSong[8] = C6;
  oldSpiceSong[9] = Z0;
  allKeysSong[0] = Z0;
  allKeysSong[1] = A6;
  allKeysSong[2] = B6;
  allKeysSong[3] = C7;
  allKeysSong[4] = D7;
  allKeysSong[5] = E7;
  allKeysSong[6] = F7;
  allKeysSong[7] = G7;
  allKeysSong[8] = Z0;
  
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
