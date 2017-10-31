//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Archivo donde guardar todas las macros y definiciones de textos.
//    
//-----------------------------------------------------------------------------
#include "descriptions.h"

char*				welcomeText = {"Bienvenido a \"Encuentra tu jeta\". Esta es una " \
										"divertida historia para todos, mayores y mas mayores " \
										"aun. ¡Disfruta!"};

char*				contextText = {"Estas en una casa... haz algo!"};

char*				lobbyText[] = { "El recibidor. Bonito e iluminado.",
									"En el recibidor hay un cesto, una foto de la " \
									"familia, un espejo y unas escaleras de acceso " \
									"al segundo piso." };

char*				corridorLvl0Text[] = {"Un pasillo.", "El pasillo es recto, " \
											"como suelen ser los pasillos."};
char*				garageText[] = { "El garaje de la casa.", "Menudo Ferrari tienen." };
char*				kitchenText[] = { "La cocina.", "Es una cocina cálida, pero la de " \
										"mi abuela era mucho mejor."};
char*				bathroomText[] = { "El cuarto de baño del piso de abajo.", "Es un " \
										"cuarto de bano pequeno. No sé cómo se las arreglan." };
char*				livingRoomText[] = { "Un espacioso salón comedor.", "En este salón se " \
										"podría celebrar una comida estupenda."};

char*				basketText = "Es un bonito cesto de mimbre.";
char*				basketName = "un cesto";
char*				fampicText = "Es una bonita foto de familia.";
char*				fampicName = "una foto de familia";
char*				mirrorText = "Es un espejo.";
char*				mirrorName = "un espejo";
char*				stairsupText = "Son las escaleras para subir a la primera planta.";
char*				stairsupName = "unas escaleras hacia arriba";


activeObject*		lobbyActiveObjects[MAX_ACTIVE_ITEMS_PLACE];
activeObject*		garageActiveObjects[MAX_ACTIVE_ITEMS_PLACE];

// lugares del juego

// hecho con array dinámico para poder eliminar con el delete los objetos
// contenidos reservados de forma dinámica
// está bien hacer esto aquí?
activeObject*		objectStack[TOTAL_OBJECTS];
// acuérdate de delete[] objectStack;

char*				textWords[MAX_WORDS_INPUT];

char*				possibleOrders[] = {"mirar", "coger", "ir"};

char*				possibleDirections[] = {"atras", "izquierda", "derecha", "adelante"};

char*				possiblePlaces[] = { "lobby", "garaje" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------