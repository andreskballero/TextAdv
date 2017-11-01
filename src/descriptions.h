//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Archivo de cabecera donde guardar todas las macros y declaraciones de textos.
//    
//-----------------------------------------------------------------------------

#ifndef DESCRIPCIONES_H
#define DESCRIPCIONES_H

// includes
#include <stdio.h>
#include <stdlib.h>

#include "activeObject.h"

// defines genéricos
#define MAX_WORDS_INPUT			4
#define MAX_WORD_SIZE			20
#define MAX_INPUT_SIZE			80
#define MAX_ITEMS_INVENTORY		10
#define MAX_ACTIVE_ITEMS_PLACE	4
#define MAX_NEXT_PLACES			4

#define TOTAL_OBJECTS			100
#define TOTAL_ORDERS			3
#define TOTAL_PLACES			2

#define PLACE_INITIAL			0
#define PLACE_DESCRIPTION		1

#define OBJECT0					0
#define OBJECT1					1
#define OBJECT2					2
#define OBJECT3					3

#define LEFT					0
#define RIGHT					1
#define FORWARD					2
#define	BACKWARD				3

// identificadores de orden
#define LOOK_AT					0
#define PICK_UP					1
#define GO_TO					2

// identificadores de habitación
#define LOBBY					0
#define GARAGE					1
#define CORRIDOR				2
#define KITCHEN					3
#define BATHROOM				4
#define LIVINGROOM				5

// identificadores de objeto activo (10-19)


// identificadores de objeto pasivo (20-29)
#define BASKET					20
#define FAMPIC					21
#define MIRROR					22
#define STAIRSUP				23

// otros
#define LETRA_A				64
#define LETRA_z				123

#define BAD_INPUT			false
#define GOOD_INPUT			true


// textos de situación
extern char*				welcomeText;
extern char*				contextText;

// descripciones de lugar
extern char*				lobbyText[];
extern char*				corridorLvl0Text[];
extern char*				garageText[];
extern char*				kitchenText[];
extern char*				bathroomText[];
extern char*				livingRoomText[];

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
extern activeObject*		garageActiveObjects[];

// lista que usa el parser para guardar el input
extern char*				textWords[];

// órdenes que existen en el juego
extern char*				possibleOrders[];

// posibles direcciones que se contemplan en las
// diversas zonas del juego
extern char*				possibleDirections[];

// posibles lugares del juego
extern char*				possiblePlaces[];

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------