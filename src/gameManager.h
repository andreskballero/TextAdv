//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase principal del juego. 
// Realiza el procesado general de la acción del juego y representa un gestor
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

// defines de búsqueda
#define NORMAL_ITEM				0
#define ACTIVE_ITEM				1
#define INVENTORY_ITEM			2

// struct para chequear existencia; almacena
// si el input es correcto y la posición de la
// orden en el array de órdenes
typedef struct {
	int command;
	int element;
	int prepos;
	int element2;
} words;

class gameManager
{
private:
	// porque como máximo se cargarán 100 objetos en el juego

	// hecho con array dinámico para poder eliminar con el delete los objetos
	// contenidos reservados de forma dinámica

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

public:
	gameManager();
	~gameManager();

	void gameLoad(void);
	void gameStart(void);

	void getInput(void);
	bool parsing(void);
	bool checkCommand(void);
	void act(void);

	void lookAround(char *element, char *prepos, char *element2);
	void lookAt(char *element);
	void pickUp(char *element);
	void go(char *element);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------