//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Definiciones del gestor de acciones.
//    
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

#include "GestorAcciones.h"

GestorAcciones::GestorAcciones()
{
}


GestorAcciones::~GestorAcciones()
{
}

void GestorAcciones::analizarInput()
{
	// de momento vale, pero hay que asegurar que el input no sea mayor que el
	// buffer del array... si no... crec!
	// no hace falta memset porque aparentemente el scanf ya limpia el array
	// cuando se vuelve a usar

	printf("Introducir orden: ");
	//scanf_s("%s", textoInput, sizeof(char)*100);

	// en vez de fgets, usar sscanf??????????????
	fgets(textoInput, 100, stdin);

	//printf("%d, %d\n\n", textoInput[0], strlen(textoInput));
}

void GestorAcciones::parsear()
{
	this->parser.procesarTexto(textoInput);
}


//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------