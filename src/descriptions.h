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
#define MAX_ITEMS_INVENTORY		20
#define MAX_ACTIVE_ITEMS_PLACE	4
#define MAX_NORMAL_ITEMS_PLACE	8
#define MAX_NEXT_PLACES			6

#define TOTAL_OBJECTS			100
#define TOTAL_COMMANDS			8
#define TOTAL_PLACES			7 // piso de abajo 7, finales son 14

#define PLACE_INITIAL_TEXT		0
#define PLACE_DESCRIPTION_TEXT	1

#define OBJECT0					0
#define OBJECT1					1
#define OBJECT2					2
#define OBJECT3					3

#define LEFT					0
#define RIGHT					1
#define FORWARD					2
#define	BACKWARD				3
#define UP						4
#define DOWN					5

// identificadores de orden
#define LOOK_AROUND				0
#define LOOK_AT					1
#define PICK_UP					2
#define GO						3
#define TALK_TO					4
#define USE						5
#define GIVE					6
#define HELP					7

// identificadores de habitación
#define LOBBY					0
#define GARAGE					1
#define DOWNSTAIRS_CORRIDOR		2
#define KITCHEN					3
#define WC						4
#define LIVING_ROOM				5
#define BASEMENT				6
#define UPSTARIS_HALL			7 // rellano piso de arriba
#define UPSTAIRS_CORRIDOR		8 // pasillo piso de arriba
#define MAIN_BEDROOM			9
#define TWINS_BEDROOM			10
#define OWN_BEDROOM				11
#define OFFICE					12
#define GARRET					13

// identificadores de objeto activo


// identificadores de objeto normal
#define LOBBY_PICTURE			0
#define LOBBY_PLATE				1
#define LOBBY_PEG				2
#define LOBBY_CARPET			3
#define LOBBY_COMMODE			4
#define LOBBY_STAIRS			5

// otros
#define LETRA_A					64
#define LETRA_z					123
#define CHARS_PER_LINE			70

#define BAD_INPUT				false
#define GOOD_INPUT				true

// texto de ayuda
extern char*					helpText;

// textos de situación
extern char*					welcomeText;
extern char*					contextText;

// descripciones de lugar
	// planta baja
extern char*					lobbyText[];
extern char*					downstairsCorridorText[]; // pasillo planta baja
extern char*					garageText[];
extern char*					kitchenText[];
extern char*					bathroomText[];
extern char*					livingRoomText[];

	// sótano
extern char*					basementText[];

	// primera planta
extern char*					upstairsHallText[]; // rellano primer piso
extern char*					upstairsCorridorText[]; // pasillo primer piso
extern char*					mainBedroomText[];
extern char*					twinsBedroomText[];
extern char*					ownBedroomText[];
extern char*					officeText[];

	// desván
extern char*					garretText[];







// descripciones de objeto normal

	// recibidor
extern char*					lobbyPictureText;
extern char*					lobbyPlateText;
extern char*					lobbyPegText;
extern char*					lobbyCarpetText;
extern char*					lobbyCommodeText;
extern char*					lobbyStairsText;


	// cocina

// variables globales
	// objetos activos de los lugares
extern activeObject*			lobbyActiveObjects[];
extern activeObject*			garageActiveObjects[];

// lista que usa el parser para guardar el input
extern char*					textWords[];

// órdenes que existen en el juego
extern char*					possibleCommands[];

// posibles direcciones que	se contemplan en las
// diversas zonas del juego
//extern char*					possibleDirections[];

// posibles lugares del juego
//extern char*					possiblePlaces[];

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------