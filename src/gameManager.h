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

#include "descriptions.h"
#include "auxiliaryFunctions.h"
#include "textParser.h"
#include "player.h"
#include "map.h"

// struct para chequear existencia; almacena
// si el input es correcto y la posición de la
// orden en el array de órdenes
typedef struct {
	int order;
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

	//objetoActivo*				colaObjetos[100]; 
	//activeObject*				objectStack = new activeObject[100]; // mejor global


	// parser propio para parsear el texto analizado
	textParser				parser;
	player					player;
	map						map;
	words					wordsExistant;

	unsigned int			targetOrder;
	char					inputText[MAX_INPUT_SIZE];

	void objectLoader(void);
	void placeLoader(void);
	void playerLoader(void);

public:
	gameManager();
	~gameManager();

	void gameLoad(void);
	void gameStart(void);

	void getInput(void);
	bool parsing(void);
	int checkExistance(void);
	void act(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------