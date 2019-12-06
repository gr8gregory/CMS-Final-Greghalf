/* TxRx.cpp : Interface (Class definition) -- Multithreading example that use the
 *            C++11 std::thread
 *			  This example uses thread based member functions
 *			  Copyright Michael A. Galle
 */
#pragma once

#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#define TIMEOUT 1000 
#define running true

extern std::thread RX;
extern int msgFlag;		// to communicate that there are new messages

void Multithreading();
void readMsgs();
