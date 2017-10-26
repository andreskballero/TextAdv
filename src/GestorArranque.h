//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa un gestor para cargar todos los elementos del
// juego con sus respectivos valores y contenido.
//    
//-----------------------------------------------------------------------------

#ifndef GESTARR_H
#define GESTARR_H

//includes
#include "descripciones.h"
#include "lugar.h"
#include "objetoActivo.h"

class GestorArranque
{
private:
	// porque como m�ximo se cargar�n 100 objetos en el juego

	// hecho con array din�mico para poder eliminar con el delete los objetos
	// contenidos reservados de forma din�mica

	//objetoActivo*				colaObjetos[100]; 
	objetoActivo*				colaObjetos = new objetoActivo[100];

public:
	GestorArranque();
	~GestorArranque();

	void cargaObjetos(void);
	void cargaLugares(void);

	void iniciaPartida(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------