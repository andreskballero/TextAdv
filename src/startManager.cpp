#include "startManager.h"



startManager::startManager()
{
}


startManager::~startManager()
{
}

// deber�a cargar todos los objetos autom�ticamente, mediante 
// referencias claras y ordenadas
void startManager::objectLoader(void)
{
	// revisar esto... es necesario el new porque, si no, los objetos se destruyen al
	// terminar la funci�n y se pierden las referencias

	activeObject* cesto = new activeObject(BASKET, basketName, basketText);
	activeObject* fotoFam = new activeObject(FAMPIC, fampicName, fampicText);
	activeObject* espejo = new activeObject(MIRROR, mirrorName, mirrorText);
	activeObject* escalerasArriba = new activeObject(STAIRSUP, stairsupName, fampicText);

	// esto ser�a otra soluci�n, con un init, para no llamar al constructor manualmente
	//activeObject* cesto = (activeObject*) malloc(sizeof(activeObject));
	//cesto->init(BASKET, basketName, basketText);
	
	//printf("%s\n", cesto.getDescripcion());

	objectStack[0] = *cesto;
	objectStack[1] = *fotoFam;
	objectStack[2] = *espejo;
	objectStack[3] = *escalerasArriba;
}

// deber�a cargar todos los lugares autom�ticamente, mediante 
// referencias claras y ordenadas, adem�s de a�adir los objetos
// a los lugares
void startManager::placeLoader(void)
{
	// inicializar lugares
	place* lobby = new place(LOBBY, lobbyText);
	placeStack[LOBBY] = *lobby;
	printf("%s\n\n%s\n\n", lobby->getDescription()[PLACE_INITIAL], lobby->getDescription()[PLACE_DESCRIPTION]);

	// cargar objetos inicializados
	lobby->setActiveObjects(&objectStack[0], &objectStack[1], &objectStack[2], &objectStack[3]);
	//activeObject** aux = lobby->getActiveObjects();
	//printf("%s\n\n", aux[1]->getDescription());
	//printf("%s\n", recibidor.getObjetosActivo()[1]->getDescripcion());
	//printf("%s\n", recibidor.getObjetosActivo()[2]->getDescripcion());
	//printf("%s\n", recibidor.getObjetosActivo()[3]->getDescripcion());
}

void startManager::gameStart(void)
{
	printf("%s\n\n%s\n\n", welcomeText, contextText);
}
