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
#include <stdlib.h>
#include <string.h>

#include "gameManager.h"


// debería cargar todos los objetos automáticamente, mediante 
// referencias claras y ordenadas
void gameManager::objectLoader(void)
{
	// revisar esto... es necesario el new porque, si no, los objetos se destruyen al
	// terminar la función y se pierden las referencias

	/*activeObject* cesto = new activeObject(BASKET, basketName, basketText);
	activeObject* fotoFam = new activeObject(FAMPIC, fampicName, fampicText);
	activeObject* espejo = new activeObject(MIRROR, mirrorName, mirrorText);
	activeObject* escalerasArriba = new activeObject(STAIRSUP, stairsupName, fampicText);*/

	// esto sería otra solución, con un init, para no llamar al constructor manualmente
	//activeObject* cesto = (activeObject*) malloc(sizeof(activeObject));
	//cesto->init(BASKET, basketName, basketText);

	//printf("%s\n", cesto.getDescripcion());

	/*objectStack[0] = cesto;
	objectStack[1] = fotoFam;
	objectStack[2] = espejo;
	objectStack[3] = escalerasArriba;*/

	/*placeActiveObjects[LOBBY] = { { new activeObject(BASKET, basketName, basketText) },
								  { new activeObject(FAMPIC, fampicName, fampicText) },
								  { new activeObject(MIRROR, mirrorName, mirrorText) },
								  { new activeObject(STAIRSUP, stairsupName, fampicText) } };*/

	// inicializar los objetos de cada place
			
		// lobby
	lobbyActiveObjects[OBJECT0] = new activeObject(BASKET, basketName, basketText);
	lobbyActiveObjects[OBJECT1] = new activeObject(FAMPIC, fampicName, fampicText);
	lobbyActiveObjects[OBJECT2] = new activeObject(MIRROR, mirrorName, mirrorText);
	lobbyActiveObjects[OBJECT3] = new activeObject(STAIRSUP, stairsupName, fampicText);

		// corridor

		// etc
}


// debería cargar todos los lugares automáticamente, mediante 
// referencias claras y ordenadas, además de añadir los objetos
// a los lugares
void gameManager::placeLoader(void)
{
	// inicializar lugares
	/*place* lobby = new place(LOBBY, "lobby", lobbyText);
	placeStack[LOBBY] = lobby;
	printf("%s\n\n%s\n\n%s\n\n", lobby->getDescription()[PLACE_INITIAL], lobby->getDescription()[PLACE_DESCRIPTION], lobby->getName());

	// cargar objetos inicializados
	lobby->setActiveObjects(objectStack[0], objectStack[1], objectStack[2], objectStack[3]);*/
	//activeObject** aux = lobby->getActiveObjects();
	//printf("%s\n\n", aux[1]->getDescription());
	//printf("%s\n", recibidor.getObjetosActivo()[1]->getDescripcion());
	//printf("%s\n", recibidor.getObjetosActivo()[2]->getDescripcion());
	//printf("%s\n", recibidor.getObjetosActivo()[3]->getDescripcion());

	this->map.loadObjectsAndPlaces();
}


void gameManager::playerLoader(void)
{
	player.setObjectsPossessed(0);
	player.setCurrentPlace(LOBBY);
}

gameManager::gameManager()
{
	// inicializar struct
	//wordsExistant.correct = false;
	//wordsExistant.order = 0;
	//wordsExistant.element = 0;
	//wordsExistant.prepos = 0;
	//wordsExistant.element2 = 0;

	targetOrder = -1;
}


gameManager::~gameManager()
{
}


void gameManager::gameLoad(void)
{
	this->objectLoader();
	this->placeLoader();
	this->playerLoader();
	//this->map.loadObjectsPlaces();
}


void gameManager::gameStart(void)
{
	printf("%s\n\n%s\n\n", welcomeText, contextText);
}

// recibir el input
void gameManager::getInput(void)
{
	// de momento vale, pero hay que asegurar que el input no sea mayor que el
	// buffer del array... si no... crec!
	// no hace falta memset porque aparentemente el scanf ya limpia el array
	// cuando se vuelve a usar

	printf("\nIntroducir orden: ");
	//scanf_s("%s", textoInput, sizeof(char)*100);

	// en vez de fgets, usar sscanf??????????????
	// stackoverflow.com/questions/12019947/null-termination-of-char-array
	fgets(inputText, MAX_INPUT_SIZE, stdin);

	// parece que fgets deja en el buffer lo que sobra a partir de MAX_INPUT_SIZE,
	// lo que actúa como input en la siguiente iteración, por lo que mejor vaciar el array
	// OJO, AUNQUE DE MOMENTO FUNCIONA PORQUE REPITE MAX_INPUT_SIZE HASTA QUE ACABA
	/*if (strlen(inputText) == MAX_INPUT_SIZE)
	{
		memset(inputText, 0, MAX_INPUT_SIZE);
	}*/

	/*printf("%d\n\n", strlen(inputText));
	printf("%d\n\n", strlen(inputText));*/

	/*for (int i = 0; i < strlen(inputText); ++i)
	{
		printf("%ca\n", inputText[i]);
		printf("%d\n", inputText[i]);
	}

	int **a = NULL;
	int* punt = NULL;
	int i = 40;

	a = &punt;
	punt = &i;
	*a = punt;
	printf("%d, %d, %d\n", *a, &i, **a);*/

	//printf("%d, %d\n\n", textoInput[0], strlen(textoInput));
}

// parsear el input
bool gameManager::parsing(void)
{
	printf("Soy parsing\n");
	return this->parser.processText(inputText);
}

// simplemente comprobar la orden. Si la orden es correcta, ya se encargará act
// de comprobar el resto de parámetros
int gameManager::checkExistance(void)
{
	printf("Soy checkexistance, compruebo la orden, el resto lo hace act\n");

	//wordsExistant.correct = false;
	//bool correct = false;

	char* order = textWords[0];
	//char* element = textWords[1];
	//char* prepos = textWords[2];
	//char* element2 = textWords[3];

	// no sólo comprobar la orden, tambien objetos... etc OJO!!!!!
	for (int orderPosition = 0; orderPosition < TOTAL_ORDERS; ++orderPosition)
	{
		//printf("1");
		if (0 == strcmp(order, possibleOrders[orderPosition]))
		{
			//wordsExistant.order = orderPosition;
			//correct = true;
			//printf("\tLa orden %s existe\n\n", order);
			//break;
			targetOrder = orderPosition;
			return GOOD_INPUT;
		}
	}

	// si llego aquí, es que no se ha encontrado la orden
	return BAD_INPUT;

	// si no se ha encontrado la orden
	//if (!correct)
	//{
		//return BAD_INPUT;
	//}

	// si se ha encontrado, compruebo a qué place o elemento va asociada
	/*for (int directionPosition = 0; directionPosition < MAX_NEXT_PLACES; ++directionPosition)
	{
		if (0 == strcmp(element, possibleDirections[directionPosition]))
		{
			wordsExistant.element = directionPosition;
			correct = true;
			printf("\tEl elemento %s %d existe\n\n", element, directionPosition);
			break;
		}
	}

	return GOOD_INPUT;*/
}


// en función de las palabras, actuar
void gameManager::act(void)
{
	bool found = false; // los comandos son correctos, pero se puede ir hacia tal dirección o
						// usar tal objeto?
	//int posAct = player.getCurrentPlace(); // posición actual determina las acciones posibles

	//char* order = textWords[0];
	char* element = textWords[1];
	char* prepos = textWords[2];
	char* element2 = textWords[3];

	unsigned int place = -1, object = -1;
	

	// compruebo si existe la orden y elementos
	//if (wordsExistant.correct)
	//{
		switch (targetOrder) //(wordsExistant.order)
		{
		case LOOK_AT:
			//printf("%s\n", placeStack[LOBBY].getDescription()[PLACE_DESCRIPTION]);

			// si sólo se ha escrito "mirar"
			if ((0 == strlen(element)) && (0 == strlen(prepos)) && (0 == strlen(element2)))
			{
				printf("Estoy en: %s\n\nDescripcion del lugar: %s\n\n", map.getPlacesConfig()[player.getCurrentPlace()]->name, map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_DESCRIPTION]);

			}
			else {
				printf("Mirar que?");
			}
			// más adelante, el jugador podrá mirar también objetos, pero siempre que
			// se encuentren en la misma habitación
			// - mirar algo!
			break;
		case PICK_UP:
			printf("Pick up\n");
			break;
		case GO_TO: // AQUÍ ESTOY!: AHORA, CARGAR VARIAS HABITACIONES Y ESTABLECER LAS RELACIONES
					// Y MOVER AL PERSONAJE POR ELLAS

			// comprobar que exista el sitio
			for (int direction = 0; direction < MAX_NEXT_PLACES; ++direction)
			{
				if (0 == strcmp(element, possibleDirections[direction]))
				{
					place = direction;
				}
			}

			//printf("test\n\n");
			for (int searchDirection = 0; searchDirection < MAX_NEXT_PLACES; ++searchDirection) // para cada posible dirección
			{
				for (int searchPlace = 0; searchPlace < TOTAL_PLACES; ++searchPlace) // busco el nuevo lugar entre todos
				{
					//printf("%d\n", map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection]);
					if ( (map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection] != NULL) && // si en esa dirección hay algo
						 (0 == strcmp(map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection]->direction, possibleDirections[place])) && // si esa dirección es la indicada
						 (0 == strcmp(map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection]->nextPlace, possiblePlaces[searchPlace]))) // si el siguiente sitio es el de la dir. indicada
					{
						// me muevo
						player.setCurrentPlace(searchPlace);
						printf("%d\n\n", player.getCurrentPlace());
						found = true;
						printf("Estoy en: %s\n\nDescripcion del lugar: %s\n\n", map.getPlacesConfig()[player.getCurrentPlace()]->name, map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_DESCRIPTION]);
					}
				}	
			}

			if (!found)
			{
				printf("No se puede ir en esa direccion.\n\n");

			}

			break;
			
		default:
			printf("Esa orden no existe.\n\n");
		}
}
