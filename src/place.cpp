#include "place.h"



place::place()
{
}


place::place(int id, char * description[])
{
	this->id = id;
	this->description[0] = description[0];
	this->description[1] = description[1];
}

place::~place()
{
}

int place::getId(void)
{
	return this->id;
}

char ** place::getDescription(void)
{
	return this->description;
}

void place::setActiveObjects(activeObject * obj0, activeObject * obj1, activeObject * obj2, activeObject * obj3)
{
	objectsA[0] = obj0;
	objectsA[1] = obj1;
	objectsA[2] = obj2;
	objectsA[3] = obj3;
}

activeObject ** place::getActiveObjects(void)
{
	return this->objectsA;
}

void place::setPassiveObjects(passiveObject * obj0, passiveObject * obj1, passiveObject * obj2, passiveObject * obj3)
{
	objectsP[0] = obj0;
	objectsP[1] = obj1;
	objectsP[2] = obj2;
	objectsP[3] = obj3;
}

passiveObject ** place::getPassiveObjects(void)
{
	return this->objectsP;
}
