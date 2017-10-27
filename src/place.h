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

#include "activeObject.h"
#include "passiveObject.h"

class place
{
private:
	int					id;

	// hay dos descripciones: [0] es la de entrada, [1] la normal
	char*				description[2];

	// como mucho, 4 objetos activos y pasivos por lugar
	activeObject*		objectsA[4];
	passiveObject*		objectsP[4];
public:
	place();
	place(int id, char* description[]);
	~place();

	int getId(void);
	char** getDescription(void);

	void setActiveObjects(activeObject* obj0, activeObject* obj1, activeObject* obj2, activeObject* obj3);
	activeObject** getActiveObjects(void);

	void setPassiveObjects(passiveObject* obj0, passiveObject* obj1, passiveObject* obj2, passiveObject* obj3);
	passiveObject** getPassiveObjects(void);
};

#endif