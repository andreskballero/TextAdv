#include "lugar.h"

// inicializa id y copia las descripciones al objeto
lugar::lugar(int id, char* descripcion[])
{
	this->id = id;
	this->descripcion[0] = descripcion[0];
	this->descripcion[1] = descripcion[1];
}


lugar::~lugar()
{
}

uint8_t lugar::getId(void)
{
	return id;
}

char ** lugar::getDescripcion(void)
{
	return descripcion;
}

void lugar::setObjetosActivo(objetoActivo * obj0, objetoActivo * obj1, objetoActivo * obj2, objetoActivo * obj3)
{
	objetosA[0] = obj0;
	objetosA[1] = obj1;
	objetosA[2] = obj2;
	objetosA[3] = obj3;
}

objetoActivo** lugar::getObjetosActivo(void)
{
	return objetosA;
}

void lugar::setObjetosPasivo(objetoPasivo* obj0, objetoPasivo* obj1, objetoPasivo* obj2, objetoPasivo* obj3)
{
	objetosP[0] = obj0;
	objetosP[1] = obj1;
	objetosP[2] = obj2;
	objetosP[3] = obj3;
}

objetoPasivo** lugar::getObjetosPasivo(void)
{
	return objetosP;
}