//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase virtual pura que representa los objetos con que puede interactuar
// el personaje, tanto para cogerlos como para simplemente observarlos.
//    
//-----------------------------------------------------------------------------

// guard de compilación para prevenir redefinición de la clase
#ifndef OBJETO_H
#define OBJETO_H

// includes
#include <stdio.h>
#include <stdlib.h>

class objeto
{
protected:
	int					id;
	char*				descripcion;

public:
	objeto();
	objeto(int id, char* descripcion);
	~objeto();

	char* getDescripcion(void);
	virtual void interactuar(void) = 0;
};

#endif