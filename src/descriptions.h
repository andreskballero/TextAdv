//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Archivo de cabecera donde guardar todas las macros y declaraciones de textos.
//    
//-----------------------------------------------------------------------------

#ifndef DESCRIPCIONES_H
#define DESCRIPCIONES_H

// includes
#include <stdio.h>
#include <stdlib.h>

#include "activeObject.h"

// defines gen�ricos
#define MAX_WORDS_INPUT			4
#define MAX_WORD_SIZE			20
#define MAX_INPUT_SIZE			100
#define MAX_ITEMS_INVENTORY		10
#define MAX_ACTIVE_ITEMS_PLACE	4
#define MAX_NEXT_PLACES			4

#define TOTAL_OBJECTS			100
#define TOTAL_ORDERS			2
#define TOTAL_PLACES			10

#define PLACE_INITIAL			0
#define PLACE_DESCRIPTION		1

#define OBJECT0					0
#define OBJECT1					1
#define OBJECT2					2
#define OBJECT3					3


// identificadores de orden
#define LOOK_AT					0
#define PICK_UP					1
#define GO_TO					2

// identificadores de habitaci�n
#define LOBBY					0
#define KITCHEN					1

// identificadores de objeto activo (10-19)


// identificadores de objeto pasivo (20-29)
#define BASKET					20
#define FAMPIC					21
#define MIRROR					22
#define STAIRSUP				23


// textos de situaci�n
extern char*				welcomeText;
extern char*				contextText;

// descripciones de lugar
extern char*				lobbyText[];

// descripciones de objeto activo
	// recibidor
extern char*				basketText;
extern char*				basketName;
extern char*				fampicText;
extern char*				fampicName;
extern char*				mirrorText;
extern char*				mirrorName;
extern char*				stairsupText;
extern char*				stairsupName;

	// cocina


// descripciones de objeto pasivo


// variables globales
	// objetos activos de los lugares
extern activeObject*		lobbyActiveObjects[];

// lista que usa el parser para guardar el input
extern char*				textWords[];

// �rdenes que existen en el juego
extern char*				possibleOrders[];

// posibles direcciones que se contemplan en las
// diversas zonas del juego
extern char*				possibleDirections[];

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------