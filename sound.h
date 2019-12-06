/*	Filename: sound.h
	Author: Michael Galle
	Date: 2019
	Details: Interface - Contains prototypes for Windows sound API (sound recording and playback functions)
*/
#pragma once


// CONSTANTS - SET RECORDING TIME AND RATE
#define	DEFAULT_NSAMPLES	4000	
#define MIN_BUFSIZE			1000
#define RECORD_TIME			6		// seconds to record from mic
#define SAMPLES_SEC			8000	// number of samples per second
#define	NFREQUENCIES		96		// number of frequencies used - leave this alone
#define _CRT_SECURE_NO_WARNINGS

// FUNCTION PROTOTYPES
/* ************************ */
// Playback
int InitializePlayback();
int PlayBuffer(short* piBuf, long lSamples);
void ClosePlayback(void);
int sound_interface(void);


// Recording
int InitializeRecording();
int	RecordBuffer(short* piBuf, long lBufSize);
void CloseRecording(void);

//extern int sampleSec, recordTime;

void AudioSettings(void);
char* AppendAudio(short* Audio);

extern short iBigBuf[];
extern long lBigBufSize;
