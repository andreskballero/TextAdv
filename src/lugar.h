//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa las diferentes localizaciones por las que se puede
// mover el personaje.
//    
//-----------------------------------------------------------------------------

// guard de compilación para prevenir redefinición de la clase
#ifndef LUGAR_H
#define LUGAR_H

// includes
#include <stdio.h>
#include <stdlib.h>

#include "objetoActivo.h"
#include "objetoPasivo.h"

// defines

class lugar
{
private:
	int					id;

	// hay dos descripciones: [0] es la de entrada, [1] la normal
	char*				descripcion[2];

	// como mucho, 4 objetos activos y pasivos por lugar
	objetoActivo*		objetosA[4];
	objetoPasivo*		objetosP[4];

public:
	lugar(int id,  char* descripcion[]);
	~lugar();

	uint8_t getId(void);
	char** getDescripcion(void);

	void setObjetosActivo(objetoActivo* obj0, objetoActivo* obj1, objetoActivo* obj2, objetoActivo* obj3);
	objetoActivo** getObjetosActivo(void);

	void setObjetosPasivo(objetoPasivo* obj0, objetoPasivo* obj1, objetoPasivo* obj2, objetoPasivo* obj3);
	objetoPasivo** getObjetosPasivo(void);

};

#endif
