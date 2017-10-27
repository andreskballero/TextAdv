//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa un gestor para cargar todos los elementos del
// juego con sus respectivos valores y contenido.
//    
//-----------------------------------------------------------------------------

#ifndef GESTARR_H
#define GESTARR_H

//includes
#include "descriptions.h"
#include "place.h"
#include "activeObject.h"

class startManager
{
private:
	// porque como máximo se cargarán 100 objetos en el juego

	// hecho con array dinámico para poder eliminar con el delete los objetos
	// contenidos reservados de forma dinámica

	//objetoActivo*				colaObjetos[100]; 
	//activeObject*				objectStack = new activeObject[100]; // mejor global
public:
	startManager();
	~startManager();

	void objectLoader(void);
	void placeLoader(void);

	void gameStart(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------