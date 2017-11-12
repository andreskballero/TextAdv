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

void activeObject::setMembers(char * newName, char ** newDescription, char * newHolder, bool newUsed)
{
	name = newName;
	description = newDescription;
	holder = newHolder;
	used = newUsed;
}



void activeObject::setUsed(bool newUsed)
{
	used = newUsed;
}



char* activeObject::getHolder(void)
{
	return holder;
}



bool activeObject::getUsed(void)
{
	return used;
}
