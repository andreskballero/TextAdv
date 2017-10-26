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

#include "Parser.h"

class GestorAcciones
{
private:
	// parser propio para parsear el texto analizado
	Parser				parser;

	char				textoInput[100];
public:
	GestorAcciones();
	~GestorAcciones();

	void analizarInput(void);
	void parsear(void);
	void generarRespuesta(void);
	void actuar(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
