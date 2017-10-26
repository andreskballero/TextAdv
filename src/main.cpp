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

//#include "descripciones.h"
#include "GestorArranque.h"
#include "funcionesAuxiliares.h"
//#include "lugar.h"
//#include "objetoActivo.h"



int main(int argc, char **argv)
{
	printf("Bienvenido al juego.\n\n");

	// Cargar juego
	GestorArranque GA;
	GA.cargaObjetos();
	GA.cargaLugares();

	// Iniciar juego
	GA.iniciaPartida();

	// Bucle del juego
	jugar();

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