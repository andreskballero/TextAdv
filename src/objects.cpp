#include "objects.h"

void loadNormalObject(normalObject* object, char * newName, char ** newDescription)
{
	object->name = newName;
	object->description = newDescription;
}


void loadActiveObject(activeObject* object, char* newName, char** newDescription, char* newHolder)
{
	object->name = newName;
	object->description = newDescription;
	object->holder = newHolder;
	object->used = false;
}