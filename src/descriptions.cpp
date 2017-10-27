//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Archivo donde guardar todas las macros y definiciones de textos.
//    
//-----------------------------------------------------------------------------
#include "descriptions.h"

char*				welcomeText = {"Bienvenido a \"Encuentra tu jeta\". Esta es una " \
										"divertida historia para todos, mayores y mas mayores " \
										"aun. �Disfruta!"};

char*				contextText = {"Estas en una casa... haz algo!"};

char*				lobbyText[] = { "Entras al recibidor. Parece una familia limpia.",
										"En el recibidor hay un cesto, una foto de la " \
										"familia, un espejo y unas escaleras de acceso " \
										"al segundo piso." };

char*				basketText = "Es un bonito cesto de mimbre.";
char*				basketName = "un cesto";
char*				fampicText = "Es una bonita foto de familia.";
char*				fampicName = "una foto de familia";
char*				mirrorText = "Es un espejo.";
char*				mirrorName = "un espejo";
char*				stairsupText = "Son las escaleras para subir a la primera planta.";
char*				stairsupName = "unas escaleras hacia arriba";


place*				placeStack = new place[TOTAL_PLACES];

// hecho con array din�mico para poder eliminar con el delete los objetos
// contenidos reservados de forma din�mica
// est� bien hacer esto aqu�?
activeObject*		objectStack = new activeObject[TOTAL_OBJECTS];
// acu�rdate de delete[] objectStack;

char*				textWords[MAX_WORDS_INPUT];

char*				possibleOrders[] = { "mirar", "coger" };


//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------