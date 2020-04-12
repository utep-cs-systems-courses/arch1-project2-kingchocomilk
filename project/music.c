#include <stdlib.h>
#include "musicPlayer.h"
#include "music.h"

short *nullSong;
short *westMinsterSong;
short *oldSpiceSong;
short *allKeysSong;
short **allMusic;

int getLengthOf(short *notes) {
  int length = 0;
  int index = 0;
  while (*(notes + index) != 0) {
    length++;
    index++;
  }
  return index-1;
}

void musicInit() {
  nullSong = (short*) malloc(sizeof(short) * 2);
  *nullSong = Z0;
  *(nullSong + 1) = 0;

  westMinsterSong = (short*) malloc(sizeof(short) * 12);
  *westMinsterSong = Z0;
  *(westMinsterSong + 1) = F7;
  *(westMinsterSong + 2) = A7;
  *(westMinsterSong + 3) = G7;
  *(westMinsterSong + 4) = C7;
  *(westMinsterSong + 5) = Z0;
  *(westMinsterSong + 6) = C7;
  *(westMinsterSong + 7) = G7;
  *(westMinsterSong + 8) = A7;
  *(westMinsterSong + 9) = F7;
  *(westMinsterSong + 10) = Z0;
  *(westMinsterSong + 11) = 0;

  oldSpiceSong = (short*) malloc(sizeof(short) * 11);
  *oldSpiceSong = Z0;
  *(oldSpiceSong + 1) = G6;
  *(oldSpiceSong + 2) = G6;
  *(oldSpiceSong + 3) = A6;
  *(oldSpiceSong + 4) = C7;
  *(oldSpiceSong + 5) = B6;
  *(oldSpiceSong + 6) = D7;
  *(oldSpiceSong + 7) = E7;
  *(oldSpiceSong + 8) = C6;
  *(oldSpiceSong + 9) = Z0;
  *(oldSpiceSong + 10) = 0;

  allKeysSong = (short*) malloc(sizeof(short) * 10);
  *allKeysSong = Z0;
  *(allKeysSong + 1) = A6;
  *(allKeysSong + 2) = B6;
  *(allKeysSong + 3) = C7;
  *(allKeysSong + 4) = D7;
  *(allKeysSong + 5) = E7;
  *(allKeysSong + 6) = F7;
  *(allKeysSong + 7) = G7;
  *(allKeysSong + 8) = Z0;
  *(allKeysSong + 9) = 0;

  allMusic = (short**) malloc(sizeof(short**) * 5);
  *allMusic = nullSong;
  *(allMusic + 1) = westMinsterSong;
  *(allMusic + 2) = oldSpiceSong;
  *(allMusic + 3) = allKeysSong;
  *(allMusic + 4) = 0;
}
