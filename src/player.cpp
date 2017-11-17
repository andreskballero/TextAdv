#include "player.h"

void player::sortInventory(void)
{

}

player::player()
{
	this->objectsPosessed = 0;
	this->currentPlace = LOBBY;

	// inicializar todas las direcciones a NULL para poder realizar
	// búsquedas
	for (int item = 0; item < MAX_ITEMS_INVENTORY; ++item)
	{
		inventory[item] = NULL;
	}
}


player::~player()
{
}

// al final siempre tiene que haber un puntero a NULL para delimitar el final en caso de llenarse
void player::addToInventory(activeObject *newObject)
{
	if ((objectsPosessed + 1) != MAX_ITEMS_INVENTORY)
	{
		inventory[objectsPosessed++] = newObject;
	}
	else {
		printText("The inventory is full!");
	}
}

// eliminar un objeto del inventario y reordenar
// los objetos están en orden, sin nulls por en medio y con nulls al final si sobra espacio
void player::deleteFromInventory(char *deleteObject)
{
	bool found = false;

	for (int item = 0; item < objectsPosessed; ++item)
	{
		if (!found)
		{
			//printf("%s\n", inventory[item]->getName());
			if (0 == strcmp(deleteObject, inventory[item]->getName()))
			{
				--item;
				found = true;
			}
		}
		else {
			inventory[item] = inventory[item + 1];
			inventory[item + 1] = NULL;
		}

	}

	--objectsPosessed;
}

void player::setObjectsPossessed(int oPossessed)
{
	this->objectsPosessed = oPossessed;
}

void player::setCurrentPlace(int newPlace)
{
	this->currentPlace = newPlace;
}

bool player::searchInventoryObject(char *element)
{
	// busco el objeto entre los poseídos // esto podría ser una función de búsqueda
	for (int itemPossessed = 0; itemPossessed < (MAX_ITEMS_INVENTORY - 1); ++itemPossessed)
	{
		if ((inventory[itemPossessed] != NULL) &&
			(0 == strcmp(element, inventory[itemPossessed]->getName())))
		{
			printText(inventory[itemPossessed]->getDescription()[VALID_TEXT]);
			return FOUND;
		}
	}

	return NOT_FOUND;
}

int player::getObjectsPossessed(void)
{
	return this->objectsPosessed;
}

int player::getCurrentPlace(void)
{
	return this->currentPlace;
}

activeObject** player::getInventory(void)
{
	return this->inventory;
}

activeObject* player::getObjectInventory(char *objectTarget)
{
	for (int i = 0; i < (MAX_ITEMS_INVENTORY - 1); ++i)
	{
		if ((inventory[i] != NULL) &&
			(0 == strcmp(objectTarget, inventory[i]->getName())))
		{
			return inventory[i];
		}
	}

	return NULL; //si no existe
}


void player::showInventory(void)
{
	if (inventory[0] != NULL)
	{
		for (int item = 0; item < (MAX_ITEMS_INVENTORY - 1); ++item)
		{
			if (inventory[item] != NULL)
			{
				if (0 == (item % 3)) // filas de 3 items
				{
					printf("\n");
				}
				printf("%s    ", inventory[item]->getName());
			}
			else {
				break; // ya no hay más
			}
		}
	}
	else {
		printText("The inventory is empty.");
	}

}