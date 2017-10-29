//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa los objetos que puede observar el personaje.
//    
//-----------------------------------------------------------------------------

// guard de compilación para prevenir redefinición de la clase
#ifndef OBJETOPAS_H
#define OBJETOPAS_H

class passiveObject
{
public:
	passiveObject();
	~passiveObject();

	void interact(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------