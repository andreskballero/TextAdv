#include <stdio.h>
#include <new>

#include "GestorArranque.h"

GestorArranque::GestorArranque()
{
}


GestorArranque::~GestorArranque()
{
	// hecho con array dinámico para poder eliminar con el delete los objetos
	// contenidos reservados de forma dinámica
	delete[] colaObjetos;
}

// debería cargar todos los objetos automáticamente, mediante 
// referencias claras y ordenadas
void GestorArranque::cargaObjetos()
{
	// revisar esto... es necesario el new porque, si no, los objetos se destruyen al
	// terminar la función y se pierden las referencias
	objetoActivo* cesto = new objetoActivo(CESTO, nombreCesto, textoCesto);
	objetoActivo* fotoFam = new objetoActivo(FOTOFAM, nombreFotoFam, textoFotoFam);
	objetoActivo* espejo = new objetoActivo(ESPEJO, nombreEspejo, textoEspejo);
	objetoActivo* escalerasArriba = new objetoActivo(ESCALERASARRIBA, nombreEscalerasArriba, textoFotoFam);
	//printf("%s\n", cesto.getDescripcion());

	colaObjetos[0] = *cesto;
	colaObjetos[1] = *fotoFam;
	colaObjetos[2] = *espejo;
	colaObjetos[3] = *escalerasArriba;
}

// debería cargar todos los lugares automáticamente, mediante 
// referencias claras y ordenadas, además de añadir los objetos
// a los lugares
void GestorArranque::cargaLugares()
{
	// inicializar lugares
	lugar recibidor(RECIBIDOR, textoRecibidor);
	printf("%s\n\n%s\n\n", recibidor.getDescripcion()[0], recibidor.getDescripcion()[1]);

	// cargar objetos inicializados
	recibidor.setObjetosActivo(&colaObjetos[0], &colaObjetos[1], &colaObjetos[2], &colaObjetos[3]);
	objetoActivo** aux = recibidor.getObjetosActivo();
	printf("%s\n\n", aux[0]->getNombre());
	//printf("%s\n", recibidor.getObjetosActivo()[1]->getDescripcion());
	//printf("%s\n", recibidor.getObjetosActivo()[2]->getDescripcion());
	//printf("%s\n", recibidor.getObjetosActivo()[3]->getDescripcion());
}

void GestorArranque::iniciaPartida()
{
	printf("%s\n\n%s\n\n", textoBienvenida, textoContexto);
}