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

class Parser
{
private:
	char				orden[10];
	char				elemento[20];

	// separa la orden del elemento al que va dirigida la acción
	void obtenerOrdenElemento(char* ordenElemento);
public:
	Parser();
	~Parser();

	// devuelve -1 si la orden es incorrecta
	// 0 si es mirar
	// 1 si usar
	int procesarTexto(char* orden);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------