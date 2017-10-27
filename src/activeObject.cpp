#include "activeObject.h"



activeObject::activeObject()
{
}

activeObject::activeObject(int id, char * name, char * description)
{
	this->state = false;
	this->name = name;
	this->description = description;
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
	return this->state;
}

void activeObject::interact(void)
{
}
