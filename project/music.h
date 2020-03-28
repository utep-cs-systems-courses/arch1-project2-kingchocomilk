/* These are all the Note to Frequency constants. All values are rounded. 
   https://www.doctormix.com/docs/Note-To-Frequancy_chart.jpg*/
#define Z0  (short)1 // No sound. Empty null note.
#define A0  (short)28
#define Bb0 (short)29
#define B0  (short)31
#define C1  (short)33
#define Db1 (short)35
#define D1  (short)37
#define Eb1 (short)39
#define E1  (short)41
#define F1  (short)44
#define Gb1 (short)46
#define G1  (short)49
#define Ab1 (short)52
#define A1  (short)55
#define Bb1 (short)58
#define B1  (short)62
#define C2  (short)65
#define Db2 (short)69
#define D2  (short)73
#define Eb2 (short)78
#define E2  (short)82
#define F2  (short)87
#define Gb2 (short)92
#define G2  (short)98
#define Ab2 (short)104
#define A2  (short)110
#define Bb2 (short)117
#define B2  (short)123
#define C3  (short)131
#define Db3 (short)139
#define D3  (short)147
#define Eb3 (short)156
#define E3  (short)165
#define F3  (short)175
#define Gb3 (short)185
#define G3  (short)196
#define Ab3 (short)208
#define A3  (short)220
#define Bb3 (short)233
#define B3  (short)247
#define C4  (short)262
#define Db4 (short)277
#define D4  (short)294
#define Eb4 (short)311
#define E4  (short)330
#define F4  (short)349
#define Gb4 (short)370
#define G4  (short)392
#define Ab4 (short)415
#define A4  (short)440
#define Bb4 (short)466
#define B4  (short)494
#define C5  (short)523
#define Dd5 (short)554
#define D5  (short)587
#define Eb5 (short)622
#define E5  (short)659
#define F5  (short)698
#define Gb5 (short)740
#define G5  (short)784
#define Ab5 (short)831
#define A5  (short)880
#define Bb5 (short)932
#define B5  (short)988
#define C6  (short)1047
#define Db6 (short)1109
#define D6  (short)1175
#define Eb6 (short)1245
#define E6  (short)1319
#define F6  (short)1397
#define Gb6 (short)1480
#define G6  (short)1568
#define Ab6 (short)1661
#define A6  (short)1760
#define Bb6 (short)1865
#define B6  (short)1976
#define C7  (short)2093
#define Db7 (short)2217
#define D7  (short)2349
#define Eb7 (short)2489
#define E7  (short)2637
#define F7  (short)2794
#define Gb7 (short)2960
#define G7  (short)3136
#define Ab7 (short)3322
#define A7  (short)3520
#define Bb7 (short)3729
#define B7  (short)3951
#define C8  (short)4186

/* To help understanding the notes like a piano, reference:
       www.choose-piano-lessons.com/piano-keys.html */
// Add more music here. Up to 3.
short nullSong[] = {Z0};
short westMinsterSong[] = {Z0, F7, A7, G7, C7, Z0, C7, G7, A7, F7, Z0};
short oldSpiceSong[] = {Z0, G6, G6, A6, C7, B6, D7, E7, C6, Z0}; // GGACBDEC
short allKeysSong[] = {Z0, A6, B6, C7, D7, E7, F7, G7, Z0};

// Since I cannot initialize an irregular 2d array of notes they need to be allocated.
short *firstSong;
short *secondSong;
short *thirdSong;
short *fourthSong;
// Need to use malloc for this.
short **allMusic;


void musicInit();
