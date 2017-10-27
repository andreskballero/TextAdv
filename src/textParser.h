//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa un parser que permita analizar el texto para que
// las acciones a realizar puedan leerse adecuadamente
//    
//-----------------------------------------------------------------------------

#ifndef PARSER_H
#define PARSER_H

class textParser
{
private:
	// comprueba que el input recibido tiene formato y tamaño correctos
	bool checkCorrect(char* receivedOrder);
public:
	textParser();
	~textParser();

	// separa la orden del elemento al que va dirigida la acción
	// devuelve true si el parseo  ha resultado correcto
	bool processText(char* receivedOrder);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------