//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa un jugador, con todos los elementos que le definen,
// su inventario y el lugar donde está.
//    
//-----------------------------------------------------------------------------

#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

class player
{
private:
	// número e inventario de objetos
	int objectsPosessed;
	activeObject*			inventory[MAX_ITEMS_INVENTORY];

	// posición actual del jugador
	int						currentPlace;
public:
	player();
	~player();

	// añadir un objeto al inventario
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