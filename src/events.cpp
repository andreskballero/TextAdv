//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa 
//    
//-----------------------------------------------------------------------------

#include "events.h"



events::events()
{
	playerEvents[0] = (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[1] = (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[2] = (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[3] = (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[4] = (playerObject*)malloc(sizeof(playerObject) + 1);

	initEvents();
}


events::~events()
{
}

char* events::getNotice(char *target)
{
	for (int item = 0; item < MAX_PLAYER_EVENTS; ++item)
	{
		if ((playerEvents[item] != NULL) &&
			(0 == strcmp(target, playerEvents[item]->name)))
		{
			return playerEvents[item]->notice; // si encuentro el objeto entre los que desencadenan algo
		}
	}
}


void events::initEvents(void)
{
	playerEvents[PUT_SHOES]->name = "shoes";
	playerEvents[PUT_SHOES]->notice = "Now you have the heels on!";
}

bool events::checkPlayerUsage(char *objectUsed)
{
	for (int item = 0; item < MAX_PLAYER_EVENTS; ++item)
	{
		if ((playerEvents[item] != NULL) &&
			(0 == strcmp(objectUsed, playerEvents[item]->name)))
		{
			return true; // si encuentro el objeto entre los que desencadenan algo
		}
	}

	return false;
}