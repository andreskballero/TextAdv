//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa un gestor para realizar las acciones que se escriban.
// Debe contener un parser que pueda analizar lo que se dice y un gestor
// que controle el estado del mapa.
//    
//-----------------------------------------------------------------------------

#ifndef GESTACC_H
#define GESTACC_H

#include "textParser.h"

// struct para chequear existencia
typedef struct {
	bool correct;
	int order;
	int element;
	int prepos;
	int element2;
} words;

class actionManager
{
private:
	// parser propio para parsear el texto analizado
	textParser				parser;

	char				inputText[100];

	words wordsExistant;

public:
	actionManager();
	~actionManager();

	void inputAnalysis(void);
	bool parsing(void);
	int checkExistance(void);
	void generateAnswer(void);
	void act(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------