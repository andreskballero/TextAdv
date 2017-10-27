//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Definiciones del gestor de acciones.
//    
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

#include "descriptions.h"
#include "actionManager.h"



actionManager::actionManager()
{
	// inicializar struct
	wordsExistant.correct = false;
	wordsExistant.order = 0;
	wordsExistant.element = 0;
	wordsExistant.prepos = 0;
	wordsExistant.element2 = 0;
}


actionManager::~actionManager()
{
}

// recibir el input
void actionManager::inputAnalysis(void)
{
	// de momento vale, pero hay que asegurar que el input no sea mayor que el
	// buffer del array... si no... crec!
	// no hace falta memset porque aparentemente el scanf ya limpia el array
	// cuando se vuelve a usar

	printf("Introducir orden: ");
	//scanf_s("%s", textoInput, sizeof(char)*100);

	// en vez de fgets, usar sscanf??????????????
	// stackoverflow.com/questions/12019947/null-termination-of-char-array
	fgets(inputText, MAX_INPUT_SIZE, stdin);

	//printf("%d, %d\n\n", textoInput[0], strlen(textoInput));
}

// parsear el input
bool actionManager::parsing(void)
{
	printf("Soy parsing\n\n");
	return this->parser.processText(inputText);
}

// comprobar que del input se extraen los elementos correctos que se
// corresponden con órdenes del juego; devuelve una struct con la orden, 
// el elemento, preposición y elemento2
int actionManager::checkExistance(void)
{
	printf("Soy checkexistance\n\n");

	char* order = textWords[0];
	char* element = textWords[1];
	char* prepos = textWords[2];
	char* element2 = textWords[3];

	// no sólo comprobar la orden, tambien objetos... etc OJO!!!!!
	for (int orderPosition = 0; orderPosition < TOTAL_ORDERS; ++orderPosition)
	{
		if (0 == strcmp(order, possibleOrders[orderPosition]))
		{
			wordsExistant.order = orderPosition;
			wordsExistant.correct = true;
			printf("La orden %s existe\n", order);
		}
	}

	return true;
}


// en función de las palabras, actuar
void actionManager::generateAnswer(void)
{
	// compruebo si existe la orden y elementos
	if (wordsExistant.correct)
	{
		switch (wordsExistant.order)
		{
		case LOOK_AT:
			printf("%s\n", placeStack[LOBBY].getDescription()[PLACE_DESCRIPTION]);
			break;
		case PICK_UP:
			printf("Wololo!\n");
			break;
		default:
			printf("Esa orden no existe\n");
			break;
		}
	}
	else {
		printf("Esa orden no existe\n");
	}
	
}

void actionManager::act(void)
{
}
