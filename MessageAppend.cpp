#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Frame.h"
#include "sound.h"
#include "RS232Comm.h"
#include "crc.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)

char* AppendMsg(char* msg, char* SenderID, char* RecieveID, int Priority) {


	char flag = 0x0; 
	long luncompressedLen = strlen(msg) + 1;
	long lcompressedLen;
	payloadText text;
	char buff[142];
	char cESC = '%';
	

	printf("\n%d", luncompressedLen);
	lcompressedLen = RLECompress((unsigned char*)msg, luncompressedLen ,(unsigned char*)buff, 142 ,cESC);
	printf("\n%d", lcompressedLen);
	
	
	text.message = (char*)malloc((luncompressedLen + 3) * sizeof(char));

	memcpy_s(text.message, (luncompressedLen + 3), buff, lcompressedLen);

	//text.message[luncompressedLen - 1] = '\0';
	
	header FRAME = { SenderID, flag, luncompressedLen, lcompressedLen, RecieveID, Priority };

	MssgTxt holder = { NULL, NULL };
	holder.Head = FRAME;
	holder.Text = text;
	
	cvt.FRAME = holder;

	printf("\n%d", (sizeof(cvt.FRAME.Head) + lcompressedLen));
	return cvt.convert;
}


void PrintQueue(link pn) {

	while (!Recieve.IsQueueEmpty()) {				// if there is no head's avaiable
		pn = Recieve.DeQueue();						//deque sends the current head to main and then moves head to next spot
		printf("\n sID of Node is: %d", pn->Data.sid);		//print what the current heads node value
		free(pn);					//free the head
	}
}

char* AppendAudio(short* Audio) {


	short sid = 0xaaa;							// Sender ID
	char flag = 0x0;
	long lDataLength = lBigBufSize;

	header FRAMEAUD = { NULL, sid, flag, lDataLength };
	
	payloadAudio audio;
	memcpy_s(audio.audioBuf, sizeof(audio.audioBuf), Audio, 48000);// this memcopy 

	MssgAud Holder = { NULL, NULL };
	Holder.Head = FRAMEAUD;
	Holder.Aud = audio;

	cvtA.FRAMEAUD = Holder;
	return cvtA.convert;
}


int RLEdeCompress(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cESC) {
	char num[3];
	char Let;
	int number;
	int dec;
	int inc = 0;

	for (int i = 0; i < iInLen; i++) {

		if (in[i] == cESC) {
			num[0] = in[i + 1];
			num[1] = in[i + 2];
			num[2] = '\0';
			Let = in[i + 3];
			number = (int)num[0] * 16 + (int)num[1];

			dec = (int)strtol(num, NULL, 16);

			for (int j = 0; j < dec; j++)
			{
				//printf("%c", Let);
				*out = Let;
				out++;
				inc++;
			}
			number = 0;
			i = i + 3;
		}
		else
		{
			*out = in[i];
			out++;
			inc++;
		}
	}
	out[0] = '\0';

	return 0;
}

int RLECompress(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cESC) {

	unsigned char charac;		// Repeated character
	unsigned char output[10];	// Temp buffer with space for the RLE sequence
	out[0] = '\0';				// Set so taht we can use strcat()
	int i = 0;					// Counter
	int count;					// Number of repeats

	while (i < iInLen) {		// Dont want to exceed the buffer

		count = 1;				// Starts the count of a set
		while ((in[i] == in[i + 1]) && (i < iInLen)) {	// While there are repeated characters, increment the counter

			charac = in[i];		// Save the repeated character 
			count++;
			i++;
		}

		// Encode the output
		if (count > 3) {
			// RLE encode 
			// copt to temp buffer
			sprintf((char*)output, "%c%02x%c", cESC, count, charac);
			// Copy temp buffer to output buffer
			strcat((char*)out, (char*)output);

		}
		else if (count == 3) {
			// Dont encode
			sprintf((char*)output, "%c%c%c", charac, charac, charac);
			strcat((char*)out, (char*)output);
		}
		else if (count == 2) {
			// Dont encode
			sprintf((char*)output, "%c%c", charac, charac);
			strcat((char*)out, (char*)output);
		}
		else if (count == 1) {
			output[0] = in[i];
			output[1] = '\0';
			strcat((char*)out, (char*)output);
		}
		i++;

	}
	return(strlen((char*)out));

}