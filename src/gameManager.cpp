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
		lookAround();		

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

		talkTo(element);

		break;
	case USE:
		printf("Use\n\n");

		use(element, prepos, element2);

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



void gameManager::lookAround()
{
	//printText(map.getPlacesConfig()[player.getCurrentPlace()]->description[PLACE_DESCRIPTION_TEXT]);

	printText(map.getActivePlace()->description[PLACE_DESCRIPTION_TEXT]);
}



void gameManager::lookAt(char *element)
{
	if ((!map.searchPlaceNormalItem(element)) &&
		(!map.searchPlaceActiveItem(element)) &&
		(!player.searchInventoryObject(element)))
	{
		printText(lookAtErrorText[(rand() % 2)]);
	}
}


// estaba refactorizando estas funciones y poniéndolas en act(), ya he acabado lookAt y sus search


void gameManager::pickUp(char *element)
{
	bool found = false;
	char *auxDir;
	normalObject *auxNormal;
	activeObject *auxActive;

	// si existe y no se ha cogido ya...
	if ((NULL != (auxActive = map.getActiveObject(element))) &&
		(!auxActive->getPickedUp()))
	{
		printText("Got it.");

		// añadir objeto al inventario
		player.addToInventory(auxActive);

		// cambiar el texto del objeto normal para adaptarlo a que ya no posee el objeto
		if (NULL != (auxNormal = map.getNormalObject(auxActive->getHolder())))
		{
			auxDir = auxNormal->getDescription()[VALID_TEXT];
			auxNormal->getDescription()[VALID_TEXT] = auxNormal->getDescription()[AUX_TEXT];
			auxNormal->getDescription()[AUX_TEXT] = auxDir;
		}

		// poner que ya se ha cogido
		auxActive->setPickedUp(true);
	}
	else {
		if ((NULL != (map.getNormalObject(element))) &&
			(0 == strcmp(element, map.getNormalObject(element)->getName())))
		{
			printText(pickUpErrorText[1]);
		}
		else {
			printText(pickUpErrorText[0]);
		}
	}
}


void gameManager::go(char *element)
{
	bool found = false;

	int auxPR;

	if (PLACE_NOT_FOUND != (auxPR = map.getNextPlace(element)))
	{
		if (map.getPlacesConfig()[auxPR]->accessible)
		{
			player.setCurrentPlace(auxPR);
			map.setActivePlace(auxPR);
			printText(map.getActivePlace()->description[PLACE_INITIAL_TEXT]);
		}
		else {
			if (0 == strcmp("basement", map.getPlacesConfig()[auxPR]->name)) // específico de basement
			{
				printText(lockedPlaces[0]);
			}
			else {
				printText(lockedPlaces[1]);
			}
			
		}
		
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



void gameManager::use(char *element, char *prepos, char *element2)
{
	if (prepos[0] == '\0' && element2[0] == '\0') // si no hay un with significa que es un uso en el player
	{
		//printf("%d, %d\n", (player.getObjectInventory(element) != NULL), (events.checkPlayerUsage(element)));
		if ((NULL != player.getObjectInventory(element)) && (events.checkPlayerUsage(element))) // si se puede activar el objeto
		{
			if (false == player.getObjectInventory(element)->getUsed())
			{
				player.getObjectInventory(element)->setUsed(true);
				printText(events.getNotice(element));
			}
			else {
				printText(useErrorText[2]);
			}

		}
		else {
			if (NULL == player.getObjectInventory(element))
			{
				printText(useErrorText[0]);
			}
			else {
				printText(useErrorText[3]);
			}
			
		}
	}
	else { // si no es en player, es uso entre objetos o con el entorno, comprobar si existen ambos
		if ((NULL != player.getObjectInventory(element)) &&
			((NULL != player.getObjectInventory(element2)) || (NULL != map.getNormalObject(element2))))
		{
			if (0 == strcmp(prepos, "with"))
			{
				objectCombined* auxObject;

				if (NULL != (auxObject = events.getObjectResult(element, element2))) // existe un objeto asociado a esos
				{
					player.deleteFromInventory(element);
					player.deleteFromInventory(element2);
					player.addToInventory(auxObject->result);
					printText(auxObject->notice);
				}
				else {
					printText(useActivesErrorText[(rand() % 2)]);
				}
			}
			else { // la única alternativa es "on"
				placeReaction *auxReaction;
				if (NULL != (auxReaction = events.getReactionResult(element, element2)))
				{
					player.deleteFromInventory(element);
					map.getPlace(auxReaction->place)->accessible = true;
					printText(auxReaction->notice);
				}
				else {
					printText(useReactionErrorText[(rand() % 2)]);
				}
			}
		}
		else {
			if (NULL == player.getObjectInventory(element))
			{
				printText(useErrorText[0]);
			}
			else {
				printText(useErrorText[1]);
			}
		}
	}
}


void gameManager::talkTo(char *element)
{
	NPC* auxNpc;
	char option[3]; // un numero y el newline; si hay 3 es que se han introducido caraceteres de más
	int bye = 0;
	bool end = false;

	if (NULL != (auxNpc = map.getNpc(element)))
	{
		while (!end)
		{
			int line = 0;
			int list = 1;
			int linesToConsider = auxNpc->getDiagLines();
			int linesToPrint = (auxNpc->getDiagLines() * 0.5);

			while ((line < linesToConsider) && (list <= linesToPrint))
			{
				if (NULL != auxNpc->getDialog()[line])
				{
					if (!auxNpc->getDialog()[line]->said)
					{
						printf("%d - %s\n", list, auxNpc->getDialog()[line]->textLine);
						++list;
					}
				}
				++line;
			}
			printf("%d - %s\n\n", list, "Bye.");
			bye = list;

			// interacción
			printf("Select line: ");
			fgets(option, 3, stdin); // get de la opción; no lo hago con un único char y getChar por controlar el input
			printText("");

			if (VALID_LINE == strlen(option))
			{
				int response = atoi(option);

				if (bye == response)
				{
					end = true;
					printText("Okay. Back to my mission.");
				}
				else if (response > 0 && response < bye) {
					int current = 0, actual = 0;
					while (actual < response)
					{
						if ((NULL != auxNpc->getDialog()[current]) && 
							(!auxNpc->getDialog()[current]->said))
						{
							++actual;
						}
						++current;
					}
					--current; // neutralizar la última suma
					printText(auxNpc->getDialog()[current]->textResponse);
					auxNpc->getDialog()[current]->said = true;

					// en vez de haber inicializado said a true, podría haber tenido una variable
					// bool que dijera si era respuesta o algo así
					if ((NULL != auxNpc->getDialog()[current + linesToPrint]) &&
						(current < linesToPrint))
					{
						auxNpc->getDialog()[current + linesToPrint]->said = false;
					}
				}
				else {
					printText("Say what?");
				}
			}
			else {
				printText("I do not consider saying that.");
			}
		}
	}
	else {
		printText(talkToErrorText[rand() % 2]);
	}
}