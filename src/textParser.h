//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa un parser que permita analizar el texto para que
// las acciones a realizar puedan leerse adecuadamente. De un input, debe generar
// algo comprensible por el programa (como un �rbol o una lista) y, en este caso,
// las palabras del input las almacena en una lista
//    
//-----------------------------------------------------------------------------

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>

#include "descriptions.h"

class textParser
{
private:
	// comprueba que el input recibido tiene formato y tama�o correctos
	bool checkCorrect(char* receivedInput);
public:
	textParser();
	~textParser();

	// comprueba que el input cumpla con, al menos, los requisitos
	// base para que pueda procesarse la orden
	bool processText(char* commandElements);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------