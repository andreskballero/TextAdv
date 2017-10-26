#include "objeto.h"

objeto::objeto()
{
}

objeto::objeto(int id, char* descripcion)
{
	this->id = id;
	this->descripcion = descripcion;
}

objeto::~objeto()
{
}

char* objeto::getDescripcion()
{
	return this->descripcion;
}