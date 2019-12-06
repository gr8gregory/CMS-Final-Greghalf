/* 
 * Multithreading.cpp
 * 
 */

#include <stdio.h>
#include <thread>		// std::thread
#include <Windows.h>
#include "Multithreading.h"
#include "RS232Comm.h"

void Multithreading() {
	std::thread RX(readMsgs);
	RX.detach();
}


void readMsgs() {
	while (running) {
		recieveMessage();
		//Sleep(1000);
	}
	return;
}
