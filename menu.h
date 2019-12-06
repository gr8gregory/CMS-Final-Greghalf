/*
 * soundmenu.cpp - This file contains the sound menu interface
 *
 * Copyright 2019 Caleb Hoeksema, Greg Huras
 *
 */

#pragma once

#include "RS232Comm.h"
#include "queues.h"
#include "Frame.h"
#include "message.h"
#include "queues.h"
#include "sound.h"
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
// Menu
int Menu(void); 
	int soundMenu(void);
	int soundDiag(void);
	int textMenu(void);
	int textDiag(void);
	int randomMenu(void);
	int inbox(void);
	int phoneBook(void);
	int settings(void);
	int mainDiagnostics(void);
	int RanTextMenu(void);
	
// Diagnostic Functions
int checkSound();
// Test comment
