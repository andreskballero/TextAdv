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

#include "map.h"

class player
{
private:
	// n�mero e inventario de objetos
	int objectsPosessed;
	activeObject*			inventory[MAX_ITEMS_INVENTORY];

	// posici�n actual del jugador
	int						currentPlace;
public:
	player();
	~player();

	// a�adir un objeto al inventario
	void addToInventory(activeObject* newObject);
	// mover al jugador (TO-DO)
	void move(char* currentPosition, char* targetDirection);

	void setObjectsPossessed(int oPossessed);
	void setCurrentPlace(int newPlace);
	int getObjectsPossessed(void);
	int getCurrentPlace(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------