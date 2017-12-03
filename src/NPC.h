//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa NPCs, con los que se puede hablar
//    
//-----------------------------------------------------------------------------

#ifndef NPC_H_
#define NPC_H_

#include <stdio.h>
#include <stdlib.h>

#include "descriptions.h"

typedef struct {
	char *textLine;
	char *textResponse;
	bool said;
} dialog;

class NPC
{
private:
	char *name;
	int room;
	int diagLines;
	dialog **conversation;
public:
	NPC();
	~NPC();

	char* getName(void);
	int getRoom(void);
	int getDiagLines(void);
	dialog** getDialog(void);

	void initNPC(char *newName, int currentRoom, int totalDiag, char **lines, char **responses);
};

#endif