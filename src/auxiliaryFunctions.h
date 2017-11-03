//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// .cpp que contiene funciones individuales.
//    
//-----------------------------------------------------------------------------

#ifndef FUNCAUX_H
#define FUNCAUX_H

#include <Windows.h>

#include "descriptions.h"

// funci�n que hace las reservas de memoria necesarias
// antes de empezar a cargar los elementos de juego
void allocateSpace(void);

// funci�n que hace un print justificado y con ms entre
// letras
void printText(char* text);

// funci�n principal del bucle del juego
void play(void);

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------