#include "activeObject.h"



activeObject::activeObject()
{
	name = NULL;
	description = NULL;
	holder = NULL;
	used = false;
}


activeObject::~activeObject()
{
}

void activeObject::setMembers(char *newName, char **newDescription, char *newHolder, bool newPickedUp, bool newUsed)
{
	name = newName;
	description = newDescription;
	holder = newHolder;
	pickedUp = newPickedUp;
	used = newUsed;
}


void activeObject::setPickedUp(bool state)
{
	pickedUp = state;
}


void activeObject::setUsed(bool newUsed)
{
	used = newUsed;
}



char* activeObject::getHolder(void)
{
	return holder;
}


bool activeObject::getPickedUp(void)
{
	return pickedUp;
}


bool activeObject::getUsed(void)
{
	return used;
}
