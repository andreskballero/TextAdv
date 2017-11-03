//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Definiciones del parser.
//    
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

#include "textParser.h"



bool textParser::checkCorrect(char* receivedInput)
{
	int checkWords = 0;

	// longitud del input
	if (strlen(receivedInput) == (MAX_INPUT_SIZE - 1))
	{
		printf("+80\n");
		return BAD_INPUT;
	}
		
	// cantidad de palabras (si hay más de 3 espacios (4 palabras), mal
	for (unsigned int numSpaces = 0; numSpaces < strlen(receivedInput); ++numSpaces)
	{
		if (receivedInput[numSpaces] == ' ')
		{
			if ( (++checkWords) == MAX_WORDS_INPUT)
			{
				printf("Demasiadas palabras\n");
				return BAD_INPUT;
			}
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

// función que procesa la línea de input para guardar las palabras
// en sus posiciones globales;
// si se ha parseado una orden de manera correcta, entonces
// se compara con las posibles opciones y se procede a actuar
bool textParser::processText(char * orderElement)
{
	// compruebo que el input cumpla con los requisitos mínimos
	// de un input (longitud, elementos)
	if (!checkCorrect(orderElement))
	{
		printf("Input incorrecto\n\n");
		return BAD_INPUT;
	}
		
	// reseteo de las posiciones globales, mejor hacerlo en otro
	// sitio; eso hara que si hay dos palabras, 2 y 3 estén a null
	// para poder procesarse
	memset(textWords[0], 0, MAX_WORD_SIZE); // no textWords[0] porque es el tamaño del puntero (4)
	memset(textWords[1], 0, MAX_WORD_SIZE);
	memset(textWords[2], 0, MAX_WORD_SIZE);
	memset(textWords[3], 0, MAX_WORD_SIZE);

	//printf("%d\n", sizeof(textWords[0]));

	char text[MAX_WORD_SIZE]; // array auxiliar para guardar cada palabra, por ahora máximo tendrá 20 chars la más larga

	// recorro todo el input buscando las palabras y aisándolas
	for (unsigned int index = 0, indexWord = 0, globalWord = 0; index < strlen(orderElement); ++index, ++indexWord)
	{
		if ((orderElement[index] > LETRA_A) && (orderElement[index] < LETRA_z)) {
			text[indexWord] = orderElement[index];
			// si la palabra actual es de más de 20 chars
			if ( (indexWord + 1) == MAX_WORD_SIZE)
			{
				return BAD_INPUT;
			}
		}
		else {
			// recuerda que cualquier string debe, cuando se llena manualmente
			// (cuando no proviene de string literal char* a = "aja"; , necesita el
			// null terminator
			text[indexWord] = '\0';
			strcpy_s(textWords[globalWord++], sizeof(text) + 1, text);
			indexWord = -1; // reset del índice local de palabras

			//printf("%s\n", textWords[0]);
			printf("\t[%s, %s, %s, %s]\n\n", textWords[0], textWords[1], textWords[2], textWords[3]);

			memset(text, 0, sizeof(text)); // reseteo text
		}
	}

	return GOOD_INPUT;
}

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------