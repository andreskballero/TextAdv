#include "player.h"


player::player()
{
	this->objectsPosessed = 0;
	this->currentPlace = NULL;
}


player::~player()
{
}

void player::addToInventory(activeObject * newObject)
{
	this->inventory[this->objectsPosessed++] = newObject;

}

void player::move(char * currentPosition, char * targetDirection)
{

}

void player::setObjectsPossessed(int oPossessed)
{
	this->objectsPosessed = oPossessed;
}

void player::setCurrentPlace(placeConfig* newPlace)
{
	this->currentPlace = newPlace;
}

int player::getObjectsPossessed(void)
{
	return this->objectsPosessed;
}

placeConfig * player::getCurrentPlace(void)
{
	return this->currentPlace;
}
