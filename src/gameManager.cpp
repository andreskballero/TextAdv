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
	//lobbyActiveObjects[OBJECT0] = new activeObject(basketName, basketText);
	//lobbyActiveObjects[OBJECT1] = new activeObject(fampicName, fampicText);
	//lobbyActiveObjects[OBJECT2] = new activeObject(mirrorName, mirrorText);
	//lobbyActiveObjects[OBJECT3] = new activeObject(stairsupName, fampicText);

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

	// inicializo la semilla del rand
	srand(time(NULL));
}

gameManager::gameManager()
{
	// inicializar struct
	//wordsExistant.correct = false;
	//wordsExistant.order = 0;
	//wordsExistant.element = 0;
	//wordsExistant.prepos = 0;
	//wordsExistant.element2 = 0;

	targetCommand = -1;
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

	printf("\n> ");
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
	//printf("Soy parsing\n");
	return this->parser.processText(inputText);
}

// simplemente comprobar la orden. Si la orden es correcta, ya se encargará act
// de comprobar el resto de parámetros
bool gameManager::checkCommand(void)
{
	//printf("Soy checkexistance, compruebo la orden, el resto lo hace act\n");

	//wordsExistant.correct = false;
	//bool correct = false;

	char* command = textWords[0];
	//char* element = textWords[1];
	//char* prepos = textWords[2];
	//char* element2 = textWords[3];

	// no sólo comprobar la orden, tambien objetos... etc OJO!!!!!
	for (int commandPosition = 0; commandPosition < TOTAL_COMMANDS; ++commandPosition)
	{
		//printf("1");
		if (0 == strcmp(command, possibleCommands[commandPosition]))
		{
			//wordsExistant.order = orderPosition;
			//correct = true;
			//printf("\tLa orden %s existe\n\n", order);
			//break;
			targetCommand = commandPosition;
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

	char* auxDir;

	unsigned int place = -1, object = -1;
	

	// compruebo si existe la orden y elementos
	//if (wordsExistant.correct)
	//{
		switch (targetCommand) //(wordsExistant.order)
		{
		case LOOK_AROUND:
			//printf("%s\n", placeStack[LOBBY].getDescription()[PLACE_DESCRIPTION]);

			// si sólo se ha escrito "mirar"
			if ((0 == strlen(element)) && (0 == strlen(prepos)) && (0 == strlen(element2)))
			{
				printText(map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_DESCRIPTION_TEXT]);

			}
			else {
				printText(lookAroundErrorText);
			}
			// más adelante, el jugador podrá mirar también objetos, pero siempre que
			// se encuentren en la misma habitación
			// - mirar algo!

			break;
		case LOOK_AT:
			//printf("Look at sth\n");

			int currentPlace;
			currentPlace = player.getCurrentPlace();

			// busco el objeto entre los normales
			for (int itemNormal = 0; itemNormal < MAX_NORMAL_ITEMS_PLACE && !found; ++itemNormal)
			{
				// si hay algún objeto ahi, y si lo introducido 
				if ((map.getPlacesConfig()[currentPlace]->nObjects[itemNormal]->name != NULL) &&
					((0 == strcmp(element, map.getPlacesConfig()[currentPlace]->nObjects[itemNormal]->name))))
				{
					found = true;
					printText(map.getPlacesConfig()[currentPlace]->nObjects[itemNormal]->description[VALID_TEXT]);
				}
			}

			// busco el objeto entre los activos
			for (int itemActive = 0; itemActive < MAX_ACTIVE_ITEMS_PLACE && !found; ++itemActive)
			{
				if ((map.getPlacesConfig()[currentPlace]->aObjects[itemActive] != NULL) &&
					(0 == strcmp(element, map.getPlacesConfig()[currentPlace]->aObjects[itemActive]->name)))
				{
					found = true;
					printText(map.getPlacesConfig()[currentPlace]->aObjects[itemActive]->description[VALID_TEXT]);
				}
			}

			// busco el objeto entre los poseídos
			for (int itemPossessed = 0; itemPossessed < MAX_ITEMS_INVENTORY && !found; ++itemPossessed)
			{
				if (player.getInventory()[itemPossessed] != NULL &&
					0 == strcmp(element, player.getInventory()[itemPossessed]->name))
				{
					found = true;
					printText(player.getInventory()[itemPossessed]->description[VALID_TEXT]);
				}
			}

			if (!found)
			{
				printText(lookAtErrorText[(rand() % 3)]);
			}

			break;
		case PICK_UP:
			//printf("Pick up\n");

			for (int item = 0; item < MAX_ACTIVE_ITEMS_PLACE; ++item)
			{
				if ((map.getPlacesConfig()[player.getCurrentPlace()]->aObjects[item] != NULL) &&
					(0 == strcmp(element, map.getPlacesConfig()[player.getCurrentPlace()]->aObjects[item]->name)))
				{
					found = true;
					printText("Done.");

					// añadir objeto al inventario
					player.addToInventory(map.getPlacesConfig()[player.getCurrentPlace()]->aObjects[item]);

					// cambiar el texto del objeto normal para adaptarlo a que ya no posee el objeto
					for (int i = 0; i < MAX_NORMAL_ITEMS_PLACE; ++i)
					{
						if ((map.getPlacesConfig()[player.getCurrentPlace()]->nObjects[i] != NULL) &&
							(0 == strcmp(map.getPlacesConfig()[player.getCurrentPlace()]->aObjects[item]->holder, map.getPlacesConfig()[player.getCurrentPlace()]->nObjects[i]->name)))
						{
							auxDir = map.getPlacesConfig()[player.getCurrentPlace()]->nObjects[i]->description[VALID_TEXT];
							map.getPlacesConfig()[player.getCurrentPlace()]->nObjects[i]->description[VALID_TEXT] = map.getPlacesConfig()[player.getCurrentPlace()]->nObjects[i]->description[AUX_TEXT];
							map.getPlacesConfig()[player.getCurrentPlace()]->nObjects[i]->description[AUX_TEXT] = auxDir;
							break;
						}
					}

					// eliminarlo de los del sitio
					map.getPlacesConfig()[player.getCurrentPlace()]->aObjects[item] = NULL;
				}
			}

			if (!found)
			{
				printText(pickUpErrorText[(rand() % 3)]);
			}

			break;
		case GO: 

			// podria haber un loop para comprobar si la dirección es correcta antes de hacer la búsqueda

			//printf("test\n\n");
			for (int searchDirection = 0; searchDirection < MAX_NEXT_PLACES && !found; ++searchDirection) // para cada posible dirección
			{
				if ((!found) &&
					(map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection] != NULL) && // si en esa dirección hay algo
					(0 == strcmp(map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection]->direction, element)))
				{
					for (int searchPlace = 0; searchPlace < TOTAL_PLACES && !found; ++searchPlace) // busco el nuevo lugar entre todos
					{
						// cojo el numero del nuevo lugar del player y se lo asigno
						if (0 == strcmp(map.getPlacesConfig()[player.getCurrentPlace()]->nextPlaces[searchDirection]->nextPlace, map.getPlacesConfig()[searchPlace]->name))
						{
							found = true;
							player.setCurrentPlace(searchPlace);
						}
					}
					//printf("%s\n", map.getPlacesConfig()[player.getCurrentPlace()]->name);
					//printf("Estoy en: %s\n\nDescripcion del lugar: %s\n\n", map.getPlacesConfig()[player.getCurrentPlace()]->name, map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_DESCRIPTION_TEXT]);
					printText(map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_INITIAL_TEXT]);
						
					//break; // porque si voy izquierda, y en ese lugar hay otro izquierda y el numero del lugar es superior, pasa a ese lugar tambien
					// arreglado con el found
				}
			}
			
			if (!found)
			{
				if (0 == strcmp(element, "down"))
				{
					printText(goErrorText[1]);
				}
				else if (0 == strcmp(element, "up"))
				{
					printText(goErrorText[2]);
				}
				else {
					printText(goErrorText[0]);
				}
			}

			break;
			
		case TALK_TO:
			printf("Talk to\n");
			break;
		case USE:
			printf("Use\n");
			break;
		case GIVE:
			printf("Give\n");
			break;
		case HELP:
			printText(helpText);
			break;
		case INVENTORY:
			player.showInventory();
			break;
		default:
			printf("Esa orden no existe.\n\n");
		}

		//printf("\n\n//==================================================//\n");
}
