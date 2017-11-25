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
	playerEvents[1] = NULL; // (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[2] = NULL; // (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[3] = NULL; // (playerObject*)malloc(sizeof(playerObject) + 1);
	playerEvents[4] = NULL; // (playerObject*)malloc(sizeof(playerObject) + 1);


	craftedEvents[0] = (objectCombined*)malloc(sizeof(objectCombined) + 1);
	craftedEvents[1] = NULL; // (objectCombined*)malloc(sizeof(objectCombined) + 1);
	craftedEvents[2] = NULL; // (objectCombined*)malloc(sizeof(objectCombined) + 1);
	craftedEvents[3] = NULL; // (objectCombined*)malloc(sizeof(objectCombined) + 1);
	craftedEvents[4] = NULL; // (objectCombined*)malloc(sizeof(objectCombined) + 1);


	reactionEvents[0] = (placeReaction*)malloc(sizeof(placeReaction) + 1);
	reactionEvents[1] = NULL;
	reactionEvents[2] = NULL;
	reactionEvents[3] = NULL;
	reactionEvents[4] = NULL;


	initEvents();
}


events::~events()
{
}


void events::initEvents(void)
{
	playerEvents[PUT_SHOES]->name = "shoes";
	playerEvents[PUT_SHOES]->notice = "Now you have the heels on!";

	craftedEvents[FIX_VASE]->objectA = "vase";
	craftedEvents[FIX_VASE]->objectB = "tape";
	craftedEvents[FIX_VASE]->notice = "Now I have a fixed vase.";
	craftedEvents[FIX_VASE]->result = (activeObject*)malloc(sizeof(activeObject) + 1);
	craftedEvents[FIX_VASE]->result->setMembers("vase", fixedVase, NULL);

	reactionEvents[UNLOCK_BASEMENT]->objectA = "water";
	reactionEvents[UNLOCK_BASEMENT]->objectN = "lock";
	reactionEvents[UNLOCK_BASEMENT]->place = "basement";
	reactionEvents[UNLOCK_BASEMENT]->notice = "The basement is now unlocked.";
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


objectCombined* events::getObjectResult(char *element, char *element2)
{
	for (int combination = 0; combination < MAX_CRAFTED_OBJECTS; ++combination)
	{
		if ((NULL != craftedEvents[combination]) && // si no es null y element & element2 (en cualquier orden) existen en una combinación...
			(((0 == strcmp(element, craftedEvents[combination]->objectA)) || (0 == strcmp(element2, craftedEvents[combination]->objectA))) &&
			(0 == strcmp(element, craftedEvents[combination]->objectB) || (0 == strcmp(element2, craftedEvents[combination]->objectB)))))
		{
			return craftedEvents[combination];
		}
	}

	return NULL;
}

placeReaction* events::getReactionResult(char *element, char *element2)
{
	for (int item = 0; item < MAX_REACTIONS; ++item)
	{
		if ((NULL != reactionEvents[item]) &&
			((0 == strcmp(element, reactionEvents[item]->objectA)) && (0 == strcmp(element2, reactionEvents[item]->objectN))))
		{
			return reactionEvents[item];
		}
	}

	return NULL;
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