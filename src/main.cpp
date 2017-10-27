//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// Primer intento de juego text adventure.
//
// DESCRIPCIÓN:
// Función principal del juego.
//    
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "descripciones.h"
#include "startManager.h"
#include "auxiliaryFunctions.h"
//#include "lugar.h"
//#include "objetoActivo.h"



int main(int argc, char **argv)
{
	printf("Bienvenido al juego.\n\n");

	// Reservar todo el espacio necesariop para memoria dinámica
	allocateSpace();

	// Cargar juego
	startManager SM;
	SM.objectLoader();
	SM.placeLoader();

	// Iniciar juego
	SM.gameStart();

	// Bucle del juego
	play();

	// tests
	printf("Fin del juego.\n\n");
	system("pause");

	return 0;
}


//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------