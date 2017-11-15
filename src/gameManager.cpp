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

gameManager::gameManager()
{
	targetCommand = -1;

	textWords[0] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1); // 21 bytes (+1 por el \0, la orden más larga tendrá siempre menos
	textWords[1] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1);
	textWords[2] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1);
	textWords[3] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1);
	//memset(textWords[0], 0, 10);
	//strcpy_s(textWords[0], 10, "mima");
	//printf("%s\n", textWords[0]);

	// inicializo la semilla del rand
	srand(time(NULL));
}


gameManager::~gameManager()
{
}


void gameManager::gameLoad(void)
{
	this->map.loadPlacesObjectsCombinations();
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
	// en vez de fgets, usar sscanf??????????????
	// stackoverflow.com/questions/12019947/null-termination-of-char-array
	fgets(inputText, MAX_INPUT_SIZE, stdin);
	// parece que fgets deja en el buffer lo que sobra a partir de MAX_INPUT_SIZE,
	// lo que actúa como input en la siguiente iteración, por lo que mejor vaciar el array
	// OJO, AUNQUE DE MOMENTO FUNCIONA PORQUE REPITE MAX_INPUT_SIZE HASTA QUE ACABA
}

// parsear el input
bool gameManager::parsing(void)
{
	//printf("Soy parsing\n");
	if (this->parser.processText(inputText, textWords, &targetCommand))
	{
		return GOOD_INPUT;
	}
	else {
		return BAD_INPUT;
	}
}

// simplemente comprobar si la orden existe. Si la orden es correcta, ya se encargará act
// de comprobar el resto de parámetros


// en función de las palabras, actuar
void gameManager::act(void)
{
	//bool found = false; // los comandos son correctos, pero se puede ir hacia tal dirección o
						// usar tal objeto?

	//char *order = textWords[0]; // esto ya lo he comprobado antes
	char *element = textWords[1];
	char *prepos = textWords[2];
	char *element2 = textWords[3];

	char *auxDir; // puntero que permite cambiar los textos de algún elemento ante una acción	

	// hay que comprobar que element, prepos y element2 tengan los valores correctos
	// en función de la orden a ejecutar (look at shoes kek; eso no debe funcionar)

	switch (targetCommand) // en función de la orden, actúo
	{
	case LOOK_AROUND:
		// si sólo se ha escrito "mirar"
		lookAround(element, prepos, element2);		

		break;

	case LOOK_AT:
		//printf("Look at sth\n");

		lookAt(element);

		break;
	case PICK_UP:
		//printf("Pick up\n");

		pickUp(element);

		break;
	case GO: 

		go(element);

		break;
			
	case TALK_TO:
		printf("Talk to\n");
		break;
	case USE:
		printf("Use\n\n");

		if (prepos[0] == '\0' && element2[0] == '\0') // si no hay un with significa que es un uso en el player
		{
			//printf("%d, %d\n", (player.getObjectInventory(element) != NULL), (events.checkPlayerUsage(element)));
			if ((player.getObjectInventory(element) != NULL) && (events.checkPlayerUsage(element))) // si se debe activar el objeto
			{
				if (player.getObjectInventory(element)->getUsed() == false)
				{
					player.getObjectInventory(element)->setUsed(true);
					printText(events.getNotice(element));
				}
				else {
					printText("I've already used that.");
				}

			}
			else {
				printText(useErrorText[(rand() % 3)]);
			}
		}
		else { // si no es en player, es uso entre objetos o con el entorno, comprobar

		}

		// si se han desbloqueado todos los elementos de un desbloqueo total, desbloquear

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
}



void gameManager::lookAround(char *element, char *prepos, char *element2)
{
	if ((0 == strlen(element)) && (0 == strlen(prepos)) && (0 == strlen(element2)))
	{
		printText(map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_DESCRIPTION_TEXT]);

	}
	else {
		printText(lookAroundErrorText);
	}
}



void gameManager::lookAt(char *element)
{
	if ((!map.searchPlaceItem(element, player.getCurrentPlace(), MAX_NORMAL_ITEMS_PLACE, "normal")) &&
		(!map.searchPlaceItem(element, player.getCurrentPlace(), MAX_ACTIVE_ITEMS_PLACE, "active")) &&
		(!player.searchInventoryItem(element)))
	{
		printText(lookAtErrorText[(rand() % 3)]);
	}
}


// estaba refactorizando estas funciones y poniéndolas en act(), ya he acabado lookAt y sus search


void gameManager::pickUp(char *element)
{
	bool found = false;
	char *auxDir;
	normalObject *auxNormal;
	activeObject **auxActive;

	if (NULL != (auxActive = map.getActiveObject(element, player.getCurrentPlace())))
	{
		printText("Got it.");

		// añadir objeto al inventario
		player.addToInventory(*auxActive);

		// cambiar el texto del objeto normal para adaptarlo a que ya no posee el objeto
		if (NULL != (auxNormal = map.getNormalObject((*auxActive)->getHolder(), player.getCurrentPlace())))
		{
			auxDir = auxNormal->getDescription()[VALID_TEXT];
			auxNormal->getDescription()[VALID_TEXT] = auxNormal->getDescription()[AUX_TEXT];
			auxNormal->getDescription()[AUX_TEXT] = auxDir;
		}

		// eliminarlo de los del sitio (y ya funcionará) FALTA ESTO!!!!!!!!!!!!
		*auxActive = NULL;
	}
	else {
		printText(pickUpErrorText[(rand() % 3)]);
	}
}



void gameManager::go(char *element)
{
	bool found = false;

	int auxPR;
	// podria haber un loop para comprobar si la dirección es correcta antes de hacer la búsqueda


	if (PLACE_NOT_FOUND != (auxPR = map.getNextPlace(player.getCurrentPlace(), element)))
	{
		player.setCurrentPlace(auxPR);
		printText(map.getPlacesConfig()[auxPR]->description[PLACE_INITIAL_TEXT]);
	}
	else {
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
}