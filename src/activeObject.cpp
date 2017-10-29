#include "activeObject.h"



activeObject::activeObject()
{
}

activeObject::activeObject(int id, char * name, char * description)
{
	this->name = name;
	this->description = description;
	this->pickedUp = false;
}

activeObject::~activeObject()
{
}

int activeObject::getID(void)
{
	return this->id;
}

char * activeObject::getName(void)
{
	return this->name;
}

char * activeObject::getDescription(void)
{
	return this->description;
}

bool activeObject::getState(void)
{
	return this->pickedUp;
}

void activeObject::interact(void)
{
}
