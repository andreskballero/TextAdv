//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase principal del juego. 
// Realiza el procesado general de la acci�n del juego y representa un gestor
// para realizar las acciones que se escriban.
//    
//-----------------------------------------------------------------------------

#ifndef GESTACC_H
#define GESTACC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "descriptions.h"
#include "auxiliaryFunctions.h"
#include "textParser.h"
#include "player.h"
#include "map.h"
#include "events.h"

// defines de b�squeda
#define NORMAL_ITEM				0
#define ACTIVE_ITEM				1
#define INVENTORY_ITEM			2

#define VALID_LINE				2

// struct para chequear existencia; almacena
// si el input es correcto y la posici�n de la
// orden en el array de �rdenes
typedef struct {
	int command;
	int element;
	int prepos;
	int element2;
} words;

class gameManager
{
private:
	// porque como m�ximo se cargar�n 100 objetos en el juego

	// hecho con array din�mico para poder eliminar con el delete los objetos
	// contenidos reservados de forma din�mica

	//objetoActivo				*colaObjetos[100]; 
	//activeObject				*objectStack = new activeObject[100]; // mejor global


	// parser propio para parsear el texto analizado
	textParser				parser;
	player					player;
	map						map;
	events					events;
	words					wordsExistant;

	unsigned int			targetCommand;
	char					inputText[MAX_INPUT_SIZE];

	// lista que usa el parser para guardar el input
	char					*textWords[MAX_WORDS_INPUT];

public:
	gameManager();
	~gameManager();

	void gameLoad(void);
	void gameStart(void);

	void getInput(void);
	bool parsing(void);
	void act(void);

	void lookAround();
	void lookAt(char *element);
	void pickUp(char *element);
	void go(char *element);
	void use(char *element, char *prepos, char *element2);
	void talkTo(char *element);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------