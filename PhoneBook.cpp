#include "RS232Comm.h"
#include "menu.h"
#include "phonebook.h"
#include "Heap.h"

PB Array[254];

int phoneBookCount = 0;


extern int phoneBookCount;
void AddToPhonebook(char *Sid) {
	/************ Add new sender ID to the phonebook ***************/
	Array[phoneBookCount].MessageCount = 1;
	Array[phoneBookCount].SID = Sid;
	phoneBookCount++;
}

void AnotherMessage(int index) {
	/************ Add new sender ID to the phonebook ***************/
	Array[index].MessageCount++;

}

void DisplayPhoneBook(void) {

	for (int i = 0; i < phoneBookCount; i++) {

		printf("Sender ID: %s\n", Array[i].SID);
		printf("Message count: %d\n", Array[i].MessageCount);
	}
}

void PriorityQ(void) {

	heaper.Print();
}