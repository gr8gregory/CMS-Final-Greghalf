/* Queues.h - Interface for Queue functionality
 *
 * Copyright 2019 Caleb Hoeksema, Gregory Huras, Laura Muhlbauerova
 *			October 15, 2019:	Add returnHead(), visit(), traverse(), and traverseR()
 */

#pragma once					// so it is only included once - could use ifndef instead
 //const int iLength = 140;		// Length of the array for storing the message

#include <stdlib.h> 

 // Rename the structures
typedef struct node Node;
typedef struct item Item;
typedef Node* link;


struct item {
	char message[140];		// Message text
	char* sid;				// Sender ID
	char* rid;				// Receiver ID
	int priority;				// Priority of message
	short int seqNum;			// Message number (used in communications)
	char flag;					//0 - text, no comp. 1 - text, comp. 2 - audio, no comp. 3 - audio, comp
	long lDataLength;			//sizeof the actual data of the message
};

struct node {
	link pNext;					// pointer to this type of structure (next node in linked list)
	Item Data;					// structure holding information
};


class Queue {
private:
	link Head, Tail;

public:
	void queue(void);
	int IsQueueEmpty(void);
	void AddToQueue(link);
	link DeQueue(void);
	link returnHead(void);

	void traverseR(link h, void (*visit)(link));
	int traverse(link h, void (*visit)(link));
};









void visit(link h);
char* AppendMsg(char* msg, char* SenderID, char* ReceiverID, int Priority);
int RLEdeCompress(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cESC);
int RLECompress(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cESC);


void QueueDiagnostics(void);
void PrintMessagesInQ(void);
void PrintContentsDiag(void);
static int MessageCounter = 0;

extern Queue Recieve;
extern Queue Transmitt;
extern Queue Home;
extern Queue RecieveStation;

// Function Prototypes
//void InitQueue(void);



// Recursive Queue functions
/*
link returnHead();
void visit(link h);
void traverseR(link h, void (*visit)(link));
void traverse(link h, void (*visit)(link));
*/