#include "objetoActivo.h"

objetoActivo::objetoActivo()
{
}

objetoActivo::objetoActivo(int id, char* nombre, char* descripcion)
{
	this->estado = false;
	this->nombre = nombre;
	this->descripcion = descripcion;
}

objetoActivo::~objetoActivo()
{
}

int objetoActivo::getID(void)
{
	return this->id;
}

char* objetoActivo::getNombre(void)
{
	return this->nombre;
}

char* objetoActivo::getDescripcion(void)
{
	return this->descripcion;
}

bool objetoActivo::getEstado(void)
{
	return this->estado;
}

void objetoActivo::interactuar(void)
{
	// cogerlo
}