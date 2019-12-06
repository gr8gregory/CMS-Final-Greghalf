/*
 * menuMain.cpp - This file contains the main menu functionality
 *
 * Copyright 2019 Caleb Hoeksema, Greg Huras
 *
 */

#include "OperatingSystem.h"
#include <stdio.h>
#include "menu.h"
#include "frame.h"
#include "Multithreading.h"
#include "phonebook.h"
#include "Heap.h"

Queue Recieve = Queue();
Queue Transmitt = Queue();
Queue Home = Queue();
Queue RecieveStation = Queue();
// 140 for 140 characters, and + the size of one int

MinHeap heaper = MinHeap((sizeof(char) * 140) + sizeof(int));
int msgFlag = 0;

int main(void) {
	Multithreading();
	Menu();
	return(0);
}

int Menu(void) {
	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("CMS Main Menu\n**********************************************************\n");

		printf("Send Audio Message (1)\nSend Text Message (2)\nSend Random Text Message (3)\nInbox (4) - %d New Messages\nPhonebook (5)\nSettings (6)\nDiagnostics (7)\n", msgFlag);
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
			// Audio Menu
			soundMenu();
			break;
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			// Text Menu
			textMenu();
			break;
		case('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			// random menu
			RanTextMenu();
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			// Inbox
			inbox();
			// Prints the messages in order, in th
			break;
		case('5'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			// Phonebook Menu
			phoneBook();
			break;
		case('6'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			// Settings Menu
			settings();
			break;
		case('7'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			// General Diagnostics
			mainDiagnostics();
			break;
		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			break;
		}

	}
	return 0;
}

int mainDiagnostics(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("\nText Diagnostics\n**********************************************************\n");

		printf("Test Queue Operation (1)\nSend Multiple Fortune Cookies(2)\nPrint Messages in Queue (3)\nPrint Message and Header informtaion of Queue (4)\nBack (5)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}

			QueueDiagnostics();
			break;
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			//();
			break;
		case('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			PrintMessagesInQ();
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			PrintContentsDiag();
			break;
		case('5'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			textMenu();
			break;
		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}

int inbox(void) {
	
	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Inbox\n**********************************************************\n");

		printf("Display Messages With Priority (1)\nDisplay PhoneBook (2)\nmain menu (3)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			PriorityQ();
			break;
			while ((c = getchar()) != '\n' && (c != EOF)) {}
		case ('2'):
			DisplayPhoneBook();
			break;
		case ('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Main Menu\n**********************************************************\n");
			Menu();
			break;
		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 

	}
	

	return 0;
}

int debug(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Sound Menu\n**********************************************************\n");

		printf("Record and play back (1)\nSettings (2)\nDiagnostic menu(3)\nReturn to main menu (4)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n**********************************************************\n");
			break;
			while ((c = getchar()) != '\n' && (c != EOF)) {}
		case ('2'):
			printf("Settings Menu\n**********************************************************\n");
			break;
		case ('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Diagnostic Menu\n**********************************************************\n");
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Main Menu\n**********************************************************\n");
			Menu();
			break;
		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 

	}

	return(0);
}

int soundDiag(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Audio Diagnostics\n**********************************************************\n");

		printf("Test Recording (1)\nTest Playback (2)\nText Audio Compression(3)\nBack (4)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n");
			break;
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n");
			break;
		case('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n");
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			soundMenu();
		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}

int textDiag(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Text Diagnostics\n**********************************************************\n");

		printf("Test Text Compression (1)\nBack (2)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n");
			break;
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			textMenu();
			break;
		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}

int settings(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Sound Menu\n**********************************************************\n");

		printf("Audio Message Settings (1)\nback (2)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			AudioSettings();
			break;

			while ((c = getchar()) != '\n' && (c != EOF)) {}
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Main Menu\n**********************************************************\n");
			Menu();
			break;

		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			error = 1;
			break;

		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 

	}

	return(0);
}

int RanTextMenu(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;
	int check = 0;


	while (error == 1) {
		printf("Random Message\n**********************************************************\n");

		printf("Send Random Message (1)\nDiagnositcs (2)\nBack (3)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):		//Send new message
			while ((c = getchar()) != '\n' && (c != EOF)) {}

			randomMessage();

			break;
		case('2'):		// Send old message
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n");
			break;

		case('3'):		// Send old message
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			Menu();
			break;

		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}

int phoneBook(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Sound Menu\n**********************************************************\n");

		printf("Record and play back (1)\nSettings (2)\nDiagnostic menu(3)\nReturn to main menu (4)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n**********************************************************\n");
			break;
			while ((c = getchar()) != '\n' && (c != EOF)) {}
		case ('2'):
			printf("Settings Menu\n**********************************************************\n");
			break;
		case ('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Diagnostic Menu\n**********************************************************\n");
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Main Menu\n**********************************************************\n");
			Menu();
			break;
		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}

int soundMenu(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;
	int check = 0;

	while (error == 1) {
		printf("Sound Menu\n**********************************************************\n");

		printf("Record and Send New Audio (1)\nRecieve Audio(2)\nDiagnostics (3)\nBack (4)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}

			SendAudio();

			break;
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			RecieveAudio();
			break;
		case('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			//soundDiag();
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			Menu();
		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}

int textMenu(void) {

	char c;

	char userIn[2] = { '\0' };
	char userIn2[2] = { '\0' };
	int error = 1;
	int check = 0;


	while (error == 1) {
		printf("Text Menu\n**********************************************************\n");

		printf("Send New Message (1)\nSend Old Message (2)\nRecieve a Message.(3)\nDiagnostics (4)\nBack (5)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):		//Send new message
			while ((c = getchar()) != '\n' && (c != EOF)) {}

			send_message(1);

			break;
		case('2'):		// Send old message
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n");
			break;
		case('3'):		// Recieve
			while ((c = getchar()) != '\n' && (c != EOF)) {}

			recieveMessage();

			break;
		case('4'):		// diagnostics
			while ((c = getchar()) != '\n' && (c != EOF)) {}

			send_message(2);

			break;
		case('5'):		// Back
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			Menu();
		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}
