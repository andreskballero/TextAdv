#include "normalObject.h"



normalObject::normalObject()
{
	name = NULL;
	description = NULL;
}


normalObject::~normalObject()
{
}



void normalObject::setMembers(char *newName, char ** newDescription)
{
	name = newName; // como es que newName se puede asignar sin perderse
					// si se llama como setMembers("tal", dir); ??
	description = newDescription;
}



char* normalObject::getName(void)
{
	return name;
}



char** normalObject::getDescription(void)
{
	return description;
}