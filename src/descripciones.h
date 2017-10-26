//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Archivo de cabecera donde guardar todas las macros y declaraciones de textos.
//    
//-----------------------------------------------------------------------------

#ifndef DESCRIPCIONES_H
#define DESCRIPCIONES_H

// includes
#include <stdio.h>
#include <stdlib.h>

// identificadores de habitación (0-9)
#define RECIBIDOR			0

// identificadores de objeto activo (10-19)

// identificadores de objeto pasivo (20-29)
#define CESTO				20
#define FOTOFAM				21
#define ESPEJO				22
#define ESCALERASARRIBA		23

// textos de situación
extern char*				textoBienvenida;
extern char*				textoContexto;

// descripciones de lugar
extern char*				textoRecibidor[];
// como ponerlo en tabla sin que printe los tabs?
// COMO PRINTAR LA ü


// descripciones de objeto activo
	// recibidor
extern char*				textoCesto;
extern char*				nombreCesto;
extern char*				textoFotoFam;
extern char*				nombreFotoFam;
extern char*				textoEspejo;
extern char*				nombreEspejo;
extern char*				textoEscalerasArriba;
extern char*				nombreEscalerasArriba;

	// cocina


// descripciones de objeto pasivo

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------