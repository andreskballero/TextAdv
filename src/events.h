//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa el gestor de eventos que desencadenan acciones
//    
//-----------------------------------------------------------------------------

#ifndef EVENTS_H
#define EVENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "descriptions.h"

typedef struct
{
	char *name;
	char *notice;
} playerObject;

typedef struct {
	char *objectA;
	char *objectB;

	char *result; // nombre del objeto resultante de la combinación de los anteriores
	// si tengo ambos, añado uno nuevo y estos los elimino del inventario
} objectCombined;

class events
{
private:
	playerObject			*playerEvents[MAX_PLAYER_EVENTS]; // guardo el nombre de los objetos que puede usar el player

	objectCombined			*craftedEvents[TOTAL_CRAFTED_OBJECTS]; // guardo el nombre de parejas de objetos combinables + su resultado

	//activeObject			*craftedObjects[TOTAL_CRAFTED_OBJECTS]; // aqui guardo todos los objetos que pueden ser fruto de combinaciones de objetos


	void initEvents(void);
public:
	events();
	~events();

	char* getNotice(char *target);

	bool checkPlayerUsage(char *objectUsed);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------