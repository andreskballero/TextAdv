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

#include "place.h"
#include "activeObject.h"

// defines genéricos
#define MAX_WORDS_INPUT			4
#define MAX_WORD_SIZE			20
#define MAX_INPUT_SIZE			100
#define TOTAL_OBJECTS			100
#define TOTAL_ORDERS			2
#define TOTAL_PLACES			10

#define PLACE_INITIAL			0
#define PLACE_DESCRIPTION		1

// identificadores de orden
#define LOOK_AT					0
#define PICK_UP					1

// identificadores de habitación (0-9)
#define LOBBY					0
#define KITCHEN					1

// identificadores de objeto activo (10-19)


// identificadores de objeto pasivo (20-29)
#define BASKET				20
#define FAMPIC				21
#define MIRROR				22
#define STAIRSUP			23

// textos de situación
extern char*				welcomeText;
extern char*				contextText;

// descripciones de lugar
extern char*				lobbyText[];
// como ponerlo en tabla sin que printe los tabs?
// COMO PRINTAR LA ü


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


// variables globales para que cualquier clase pueda acceder a ellas

extern place*				placeStack;

extern activeObject*		objectStack;

extern char*				textWords[];

extern char*				possibleOrders[];
#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------