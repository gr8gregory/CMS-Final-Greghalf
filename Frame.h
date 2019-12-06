#pragma once
#include "queues.h"
#include "sound.h"
#include "rle.h"

typedef struct header Header;
typedef struct  payloadText plText;
typedef struct  payloadAudio plAudio;
typedef struct MssgTxt* ptrTxt;
typedef struct MssgAud* ptrAud;

struct header {

	char *sid;				// Sender ID
	char flag; //0 - text, no comp. 1 - text, comp. 2 - audio, no comp. 3 - audio, comp
	long luncompressedLen;
	long lcompressedLen;
	char *rid;
	int priority;

};// add sender address

struct payloadText {
	char *message;
};

struct payloadAudio { //Set these values at a different time with respect to the audio settings
	short audioBuf[50000];		// Change this value to 140 for audio with multi thread
};

struct MssgTxt {
	Header Head;
	plText Text;
};

struct MssgAud {
	Header Head;
	plAudio Aud;
};

static union Convert {
	MssgTxt FRAME;
	char convert[sizeof(Header) + sizeof(plText)];

} cvt;

static union ConvertAudio {
	MssgAud FRAMEAUD;
	char convert[sizeof(Header) + sizeof(plAudio)];

} cvtA;

static link pointer;
