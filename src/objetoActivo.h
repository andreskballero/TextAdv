//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa los objetos que puede guardarse el personaje.
//    
//-----------------------------------------------------------------------------

// guard de compilaci�n para prevenir redefinici�n de la clase
#ifndef OBJETOACT_H
#define OBJETOACT_H

// includes
#include <stdio.h>
#include <stdlib.h>

// defines

class objetoActivo
{
private: 
	int					id;
	char*				nombre;
	char*				descripcion;
	// el estado determina si el objeto ya ha sido cogido (true) o no (false)
	bool				estado;

public:
	objetoActivo();
	objetoActivo(int id, char* nombre, char* descripcion);
	~objetoActivo();

	int getID(void);
	char* getNombre(void);
	char* getDescripcion(void);
	bool getEstado(void);
	void interactuar(void);
};

#endif