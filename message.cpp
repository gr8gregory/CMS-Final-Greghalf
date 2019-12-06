/* Implementation: Functions for File IO - Getting random messages from a file
*  By: Michael Galle
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			// Dynamic memory allocation for arrays that store quote location and length
#include "message.h"
#include <errno.h>
#include <time.h>
#include "menu.h"
#include "RS232Comm.h"


void randomMessage() {
	int numQuotes;					// Number of quotes in the file
	long int* quoteIndices;			// Array of quote locations in the file (index correspondes to quote number)
	int* quoteLengths;				// Array of quote lengths (index correspondes to quote number)
	char testBuff[140] = { '/0' };// Buffer to write the message to
	int result;						// result = 0 if successfully get a message


	// Count the number of quotes in the file and index it for fast access (only need to do this once) 
	numQuotes = fnumQuotes();

	// Number of quotes
	quoteIndices = fquoteIndices(numQuotes);					// Index locations of the quotes

	quoteLengths = fquoteLength(numQuotes, quoteIndices);		// Length of each quote (up to MAX_QUOTE_LENGTH) - cut off after - if greater than 140, set value to 140	



	//Get the random message from the file
	srand(time(NULL));					// Seed the random number generator
	result = GetMessageFromFile(testBuff, 140, frandNum(1, numQuotes), numQuotes, quoteIndices, quoteLengths);  // Later replace testBuff with 'node->msg.buff' which is a member of a node struct 

	randMessage(testBuff);
	
	getchar();
	RanTextMenu();
}

// Function gets a random number between min and max (max is the number of quotes in the file)
int frandNum(int min, int max) {
	return(min + (rand() % (max - min)));
}


// Function returns number of quotes in the file (only need to run once)
int fnumQuotes() {			//if you read one %, step forward again and if another % write file index
	FILE* fp;
	errno_t err;
	char c;
	int counter = 0;

	if (err = fopen_s(&fp, "FortuneCookies.txt", "r") == 0) {

		//Read file one character at a time

		while ((c = fgetc(fp)) != EOF) {
			if (c == '%') {
				if (fgetc(fp) == '%') {

					counter++;				//increments the number of quotes

				}
			}

		}


		fclose(fp);
		return(counter - 1);
	}
	else
	{
		printf("\nFailed to open File\n");
		fclose(fp);
		return(0);
	}


}

// Function returns an array that indicates the start of every quote in the file (number of characters from the start of the file) 
long int* fquoteIndices(int numQuotes) {

	FILE* fp;
	errno_t err;
	char e;
	int counter = 0;
	long int* quoteIndex;
	quoteIndex = (long int*)malloc(numQuotes * sizeof(long int));

	if (err = fopen_s(&fp, "FortuneCookies.txt", "r") == 0) {

		//Read file one character at a time

		while ((e = fgetc(fp)) != EOF) {
			if (e == '%') {
				if (fgetc(fp) == '%') {

					quoteIndex[counter] = ftell(fp);
					counter++;
				}
			}

		}


		fclose(fp);
		return(quoteIndex);
	}
	else
	{
		printf("\nFailed to open File\n");
		fclose(fp);
		return(0);
	}

}

// Function returns the smaller of the actual quote length or MAX_QUOTE_LENGTH
int* fquoteLength(int numQuotes, long int* quoteIndices) {

	/*
	start at start index and count char by char until %% or 140
	*/

	FILE* fp;
	errno_t err;
	int* qLen;
	qLen = (int*)malloc(numQuotes * sizeof(int));

	if (err = fopen_s(&fp, "FortuneCookies.txt", "r") == 0) {

		for (int i = 0; i < numQuotes; i++)
		{
			qLen[i] = (quoteIndices[i + 1] - quoteIndices[i] - 6);

		}





		fclose(fp);
		return(qLen);
	}
	else
	{
		printf("\nFailed to open File\n");
		fclose(fp);
		return(0);
	}
}

// Function that gets q random quote from the FortuneCookies file 
int GetMessageFromFile(char* buff, int iLen, int randNum, int numQuotes, long int* quoteIndices, int* quoteLengths) {

	FILE* fp;
	errno_t err;

	//int length = quoteLengths[randNum];


	if (err = fopen_s(&fp, "FortuneCookies.txt", "r") == 0) {

		fseek(fp, quoteIndices[randNum], SEEK_SET);

		if (quoteLengths[randNum] < 140) {

			for (int i = 0; i < quoteLengths[randNum]; i++)
			{
				buff[i] = fgetc(fp);
			}
			buff[quoteLengths[randNum]] = '\0';
		}
		else {

			for (int i = 0; i < 140; i++)
			{
				buff[i] = fgetc(fp);
			}
			buff[139] = '\0';

		}

		fclose(fp);
		return(0);
	}
	else
	{
		printf("\nFailed to open File\n");
		fclose(fp);
		return (1);
	}
}
