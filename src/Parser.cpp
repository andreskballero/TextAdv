//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Definiciones del parser.
//    
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include "Parser.h"

void Parser::obtenerOrdenElemento(char* ordenElemento)
{
	bool tengoOrden = false;
	unsigned int i = 0, j = 0;
	printf("%d\n", strlen(ordenElemento));

	while (i < strlen(ordenElemento))
	{
		if (!tengoOrden)
		{
			if (ordenElemento[i] != ' ')
			{
				orden[i] = ordenElemento[i];
				printf("%c\n", orden[i]);
				++i;
			}
			else {
				tengoOrden = true;
				++i;
			}
		}
		else {
			//printf("A");
			if (ordenElemento[i++] != '\n')
			{
				//printf("B");
				elemento[j++] = ordenElemento[i];
				printf("%c\n", elemento[(j-1)]);
				//++j;
			}
		}
		//printf("%d, %d\n", i, strlen(ordenElemento));

	}
}

Parser::Parser()
{
}


Parser::~Parser()
{
}

int Parser::procesarTexto(char* ordenRecibida)
{
	int tipoOrden = -1;
	
	obtenerOrdenElemento(ordenRecibida);

	switch (tipoOrden)
	{
	case 0:
		// blabla+
		break;
	case 1:
		// bleble
		break;
	default:
		break;
	}
	//printf("%s", orden);

	return tipoOrden;
}

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------