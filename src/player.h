//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa un jugador, con todos los elementos que le definen,
// su inventario y el lugar donde est�.
//    
//-----------------------------------------------------------------------------

#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>

#include "auxiliaryFunctions.h"
#include "activeObject.h"

class player
{
private:
	// n�mero e inventario de objetos
	int						objectsPosessed;
	activeObject			*inventory[MAX_ITEMS_INVENTORY];

	// posici�n actual del jugador
	int						currentPlace;

	void sortInventory(void);
public:
	player();
	~player();

	// a�adir un objeto al inventario
	void addToInventory(activeObject *newObject);
	void deleteFromInventory(activeObject *deleteObject);

	void setObjectsPossessed(int oPossessed);
	void setCurrentPlace(int newPlace);

	int getObjectsPossessed(void);
	int getCurrentPlace(void);
	activeObject** getInventory(void);
	activeObject* getObjectInventory(char *objectTarget);

	void showInventory(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------