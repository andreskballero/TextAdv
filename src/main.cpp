//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// Primer intento de juego text adventure.
//
// DESCRIPCI�N:
// Funci�n principal del juego.
//    
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "auxiliaryFunctions.h"

int main(int argc, char **argv)
{
	//printf("Bienvenido al juego.\n\n");

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