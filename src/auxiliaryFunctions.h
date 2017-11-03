//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// .cpp que contiene funciones individuales.
//    
//-----------------------------------------------------------------------------

#ifndef FUNCAUX_H
#define FUNCAUX_H

#include <Windows.h>

#include "descriptions.h"

// función que hace las reservas de memoria necesarias
// antes de empezar a cargar los elementos de juego
void allocateSpace(void);

// función que hace un print justificado y con ms entre
// letras
void printText(char* text);

// función principal del bucle del juego
void play(void);

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------