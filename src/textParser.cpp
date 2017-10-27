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

#include "descriptions.h"
#include "textParser.h"

#define LETRA_A 64
#define LETRA_z 123

bool textParser::checkCorrect(char* receivedOrder)
{
	return true;
}

textParser::textParser()
{
}


textParser::~textParser()
{
}

// Función que procesa el la línea de input para guardar las palabras
// en sus posiciones globales;
// si se ha parseado una orden de manera correcta, entonces
// se compara con las posibles opciones y se procede a actuar
bool textParser::processText(char * orderElement)
{
	bool correctOrder = true;
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
	for (int index = 0, indexWord = 0, globalWord = 0; index < strlen(orderElement); ++index, ++indexWord)
	{
		if ((orderElement[index] > LETRA_A) && (orderElement[index] < LETRA_z)) {
			text[indexWord] = orderElement[index];
		}
		else {
			// recuerda que cualquier string debe, cuando se llena manualmente
			// (cuando no proviene de string literal char* a = "aja"; , necesita el
			// null terminator
			text[indexWord] = '\0';
			strcpy_s(textWords[globalWord++], sizeof(text) + 1, text);
			indexWord = -1;

			//printf("%s\n", textWords[0]);
			printf("%s, %s, %s, %s\n", textWords[0], textWords[1], textWords[2], textWords[3]);

			memset(text, 0, sizeof(text)); // reseteo text
		}
	}

	return correctOrder;
}

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------