#pragma once

// Prototype the functions to be used

#include <Windows.h>
#include "sound.h"


#define _CRT_SECURE_NO_WARNINGS

void purgePort(HANDLE hCom);
void outputToPort(LPCVOID buf, DWORD szBuf);
int inputFromPort(LPVOID buf, DWORD szBuf);

void recieveMessage(void);		// Port specific
void send_message(int status);		// Port specific
void SendMultipleCookies(void);		// Port specific
void randMessage(char* msg);		// Port specific

// Sub functions
void createPortFileRec(void);		// Port specific
void createPortFileSend(void);		// Port specific
int SetComParms(HANDLE hCom);		// Port General

// Initializes the port and sets the communication parameters

#define EX_FATAL 1
#define BUFSIZE 140
#define COMPORTT "COM4"  	  	// Transmitter port - Start receiver first - Two programs must run concurrently use this port for second program
#define COMPORTR "COM3"  	  	// Receiver port - Start receiver first - Two programs must run concurrently use this port for second program

#define TXTBUFF sizeof(MssgTxt)
							// A commtimout struct variable
#define RID 000

void initPortT(void);
void initPortR(void);

void SendAudio(void);
void RecieveAudio(void);