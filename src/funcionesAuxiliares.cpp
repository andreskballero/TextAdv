#include <stdio.h>
#include "GestorAcciones.h"
#include "funcionesAuxiliares.h"

void jugar(void)
{
	GestorAcciones GA;

	GA.analizarInput();
	GA.parsear();
}