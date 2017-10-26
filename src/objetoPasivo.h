//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa los objetos que puede observar el personaje.
//    
//-----------------------------------------------------------------------------

// guard de compilaci�n para prevenir redefinici�n de la clase
#ifndef OBJETOPAS_H
#define OBJETOPAS_H

// includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "objeto.h"

class objetoPasivo : public objeto 
{
private:

public:
	objetoPasivo();
	~objetoPasivo();

	void interactuar(void);
};

#endif