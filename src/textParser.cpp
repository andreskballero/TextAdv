//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Definiciones del parser.
//    
//-----------------------------------------------------------------------------


#include "textParser.h"



bool textParser::checkCorrect(char *receivedInput)
{
	int checkWords = 0;

	// longitud del input
	if (strlen(receivedInput) == (MAX_INPUT_SIZE - 1))
	{
		printf("No input can be that long.\n");
		return BAD_INPUT;
	}
		
	// cantidad de palabras (si hay m�s de 3 espacios (4 palabras), mal
	for (unsigned int numChars = 0, wordLength = 0; numChars < strlen(receivedInput); ++numChars)
	{
		if (receivedInput[numChars] == ' ' || receivedInput[numChars] == '\n') // strlen devuelve tama�o sin contar null, y antes de null hay \n
		{
			if ((wordLength + 1) >= MAX_WORD_SIZE)
			{
				printf("Word too long.\n");
				return BAD_INPUT;
			}
			else {
				wordLength = 0;
			}

			if ((receivedInput[numChars] == ' ') && ((++checkWords) == MAX_WORDS_INPUT))
			{
				printf("Too many words.\n");
				return BAD_INPUT;
			}

			while (receivedInput[numChars + 1] == ' ') // si hay muchos espacios seguidos, contarlos como uno
			{
				++numChars;
			}
		}
		else {
			++wordLength;
		}
	}

	// si nada me ha parado, es que el input es bueno
	return GOOD_INPUT;
}

textParser::textParser()
{
}


textParser::~textParser()
{
}

// funci�n que procesa la l�nea de input para guardar las palabras
// en sus posiciones globales;
// si se ha parseado una orden de manera correcta, entonces
// se compara con las posibles opciones y se procede a actuar
bool textParser::processText(char *commandElements)
{
	// compruebo que el input cumpla con los requisitos m�nimos
	// de un input (longitud, elementos)
	if (!checkCorrect(commandElements))
	{
		//printf("Input incorrecto\n\n");
		return BAD_INPUT;
	}
		
	// reseteo de las posiciones globales, mejor hacerlo en otro
	// sitio; eso hara que si hay dos palabras, 2 y 3 est�n a null
	// para poder procesarse
	memset(textWords[0], 0, MAX_WORD_SIZE); // no textWords[0] porque es el tama�o del puntero (4)
	memset(textWords[1], 0, MAX_WORD_SIZE);
	memset(textWords[2], 0, MAX_WORD_SIZE);
	memset(textWords[3], 0, MAX_WORD_SIZE);

	//printf("%d\n", sizeof(textWords[0]));

	char text[MAX_WORD_SIZE]; // array auxiliar para guardar cada palabra, por ahora m�ximo tendr� 20 chars la m�s larga

	// recorro todo el input buscando las palabras y ais�ndolas
	for (unsigned int index = 0, indexWord = 0, globalWord = 0; index < strlen(commandElements); ++index, ++indexWord)
	{
		if ((commandElements[index] > LETRA_A) && (commandElements[index] < LETRA_z)) {
			text[indexWord] = commandElements[index];
		}
		else {
			// recuerda que cualquier string debe, cuando se llena manualmente
			// (cuando no proviene de string literal char *a = "aja"; , necesita el
			// null terminator

			text[indexWord] = '\0'; // para poder comparar

			//printf("%s\n", text);
			//printf("%d, %d, %d, %d\n", !strcmp(text, "look"), !strcmp(text, "pick"), !strcmp(text, "go"), !strcmp(text, "talk"));

			if (strcmp(text, "look") && strcmp(text, "pick") && strcmp(text, "talk"))
			{
				strcpy_s(textWords[globalWord++], sizeof(text) + 1, text);
				indexWord = -1; // reset del �ndice local de palabras

								//printf("%s\n", textWords[0]);
				printf("\t[%s, %s, %s, %s]\n\n", textWords[0], textWords[1], textWords[2], textWords[3]);

				memset(text, 0, sizeof(text)); // reseteo text
			}
			else {
				text[indexWord] = ' '; // devuelvo el espacio a su lugar para seguir con la orden
			}

			// podria hacerse con una funci�n, que tambi�n est� en checkcorrect
			// si hay muchos espacios seguidos, hacer como si solo fuera uno
			// no hay que comprobar que vaya a acceder fuera de la memoria del array porque el
			// strlen devuelve len-1 (no cuenta la null termination)
			while (commandElements[index + 1] == ' ')
			{
				++index;
			}
			
		}
	}

	return GOOD_INPUT;
}

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------