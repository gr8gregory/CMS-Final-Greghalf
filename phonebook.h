#pragma once

// an array of structs from 0 - 254 stucts 
// structs called data containing the amount of messages and the timestamp on each message.
// the inbox will display the number of messages from each sender, and the timestamp of the last message.
#include <ctime>

typedef struct data {
	char *SID;
	int MessageCount;
}PB;

extern PB Array[];
extern int phoneBookCount;

void AddToPhonebook(char *Sid);
void DisplayPhoneBook();

void AnotherMessage(int index);

void PriorityQ(void);