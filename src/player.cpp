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
		this->inventory[item] = NULL;
	}
}


player::~player()
{
}

// no hace falta reordenar, se reordena en quitar
void player::addToInventory(activeObject * newObject)
{
	this->inventory[this->objectsPosessed++] = newObject;
}

// eliminar un objeto del inventario y reordenar
void player::deleteFromInventory(activeObject* deleteObject)
{
	bool sort = false;
	--objectsPosessed;

	// reordenar
	for (int item = 0, positionSort = 0; item < MAX_ITEMS_INVENTORY; ++item)
	{
		if (!sort) // si estoy buscando el item
		{
			if (0 == strcmp(deleteObject->name, inventory[item]->name))
			{
				inventory[item] = NULL;
				positionSort = item;
				sort = true;
			}
		}
		else { // si ya lo he encontrado, reordeno hasta llegar al final
			if (inventory[item] != NULL) // para que el último objeto no pase a NULL
			{
				inventory[positionSort++] = inventory[item];
				inventory[item] = NULL;
			}
			else {
				break; // si se ha llegado al final
			}
		}

	}
}

void player::setObjectsPossessed(int oPossessed)
{
	this->objectsPosessed = oPossessed;
}

void player::setCurrentPlace(int newPlace)
{
	this->currentPlace = newPlace;
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

activeObject * player::getObjectInventory(char * objectTarget)
{
	for (int i = 0; i < MAX_ITEMS_INVENTORY; ++i)
	{
		if ((inventory[i] != NULL) &&
			(0 == strcmp(objectTarget, inventory[i]->name)))
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
		for (int item = 0; item < MAX_ITEMS_INVENTORY; ++item)
		{
			if (this->inventory[item] != NULL)
			{
				if (0 == (item % 3)) // filas de 3 items
				{
					printf("\n");
				}
				printf("%s    ", this->inventory[item]->name);
			}
		}
	}
	else {
		printText("The inventory is empty.");
	}

}