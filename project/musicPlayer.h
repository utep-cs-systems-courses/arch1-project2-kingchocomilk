#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

/* Responsible for tracking where the current note is. */
extern char musicHeadIndex;

/* Know the length of song. */
extern char lengthOfSong;

/* Have the current song pointer here. */
extern short *currentSong;

char musicPlayerUpdate();

void musicPlayerInit();

#endif
