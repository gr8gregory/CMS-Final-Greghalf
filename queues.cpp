/* Queues.cpp - Implementation of Queue functions
 *
 * Copyright 2019 Caleb Hoeksema, Gregory Huras, Laura Muhlbauerova
 *			October 15, 2019:	Add returnHead(),visit(), traverse(), and traverseR()
 */

#include "queues.h"
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "Multithreading.h"


int count = 0;

void Queue::queue(void) {			// Iniialise the queue
	Queue::Head = Queue::Tail = NULL;
}

int Queue::IsQueueEmpty(void) {		// check if queue is empty (you can't pop off of an empty queue)
	return(Queue::Head == NULL);
}

void Queue::AddToQueue(link pn) {		// Enqueue new node provided and instantiated in main
	if (IsQueueEmpty()) {
		Queue::Head = Queue::Tail = pn;		// pHead only stored for the first node added
	}
	else {						// push on the tail
		Queue::Tail->pNext = pn;		// old Tail points to the new node
		Queue::Tail = pn;				// make the Tail point to the end of the list (pn)
	}
	Queue::Tail->pNext = NULL;		// set the pointer from the last node to NULL
}

link Queue::DeQueue(void) {
	link pTemp;					// Holds current Head
	if (IsQueueEmpty()) {
		return NULL;
	}
	else {
		pTemp = Queue::Head;			// store the current head
		Queue::Head = Queue::Head->pNext;	// the next node becomes the head
		return (pTemp);			// returns the original head
	}
}


link Queue::returnHead(void) {
	return (Queue::Head);
}

void visit(link h) {
	if (count == 0) {
		printf("\nFirst message: %s\n", h->Data.message);
	}
}
void visitDiag(link h) {
	if (count == 0) {
		printf("\nFirst message: %s\n", h->Data.message);
		printf("\nMessage Length: %d\n", h->Data.lDataLength);
	}
}


void Queue::traverseR(link h, void (*visit)(link)) {
	if (h == NULL) return;
	traverseR(h->pNext, visit);
	visit(h);				// Call visit() after recursive call (prints contents)
}


int Queue::traverse(link h, void (*visit)(link)) {
	if (h == NULL) {
		return 0;
	}
	
	visit(h);	// Call visit() after recursive call (prints contents)
	count++;
	traverse(h->pNext, visit);
	return count;
}

void QueueDiagnostics(void) {

	link p, q;

	Queue Diag = Queue();

	for (int i = 0; i < 5; i++) {
		p = (link)malloc(sizeof(Node));
		//p->Data.sid = i;

		Diag.AddToQueue(p);
	}

	while (!Diag.IsQueueEmpty()) {				// if there is no head's avaiable
		q = Diag.DeQueue();						//deque sends the current head to main and then moves head to next spot
		printf("\n sID of Node is: %d", q->Data.sid);		//print what the current heads node value
		free(q);					//free the head
	}
	mainDiagnostics();
}

void PrintMessagesInQ(void) {

	link q;
	while (!Recieve.IsQueueEmpty()) {				// if there is no head's avaiable
		q = Recieve.DeQueue();						//deque sends the current head to main and then moves head to next spot

		printf("\n#%d: %s",q->Data.sid, q->Data.message);		//print what the current heads node value
		free(q);					//free the head
		msgFlag--;
	}
	mainDiagnostics();
}

void PrintContentsDiag(void) {

	link pn;
	int count = 0;

	count = Recieve.traverse(Recieve.returnHead(), visitDiag);
	printf("\n%d messages currently in your inbox.\n", count);
	mainDiagnostics();
}
