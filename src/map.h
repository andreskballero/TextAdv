//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa el mapa y guarda toda la informaci�n necesaria de todas
// las zonas del juego
//    
//-----------------------------------------------------------------------------

#ifndef MAP_H
#define MAP_H

#include "descriptions.h"
#include "activeObject.h"
#include "passiveObject.h"


// struct que contiene un lugar y la direcci�n hacia
// la que girar para ir (estando en un lugar adyacente)
typedef struct {
	char* nextPlace;
	char* direction;
} placeRelations;

// struct para guardar todos los datos de un lugar
// y luego poder cargarlos f�cilmente
typedef struct {
	int					id;
	char*				name;

	// hay dos descripciones: [0] es la de entrada, [1] la normal
	char**				description;

	// como mucho, 4 objetos activos y pasivos por lugar
	activeObject**		objectsA;
	passiveObject**		objectsP;

	// struct para guardar las relaciones
	placeRelations*		nextPlaces;
} placeConfig;

class map
{
private:
	// array de structs que contienen todos los datos
	// necesarios que el mapa debe conocer de cada lugar
	placeConfig*		placesConfig[TOTAL_PLACES];

	// funci�n que permite crear una nueva struct y devolverla
	placeConfig* loadStruct(int newId, char* newName, char** newDescription, activeObject** newObjectsA, placeRelations* newRelations);

public:
	map();
	~map();

	// funci�n que crea todas las structs necesarias del juego
	// y las a�ade al array de places
	void loadObjectsPlaces(void);

	// funci�n llamada por el player que comprueba que, seg�n la 
	// posici�n actual del player, se puede mover en la direcci�n
	// deseada; devuelve true si cierto (TO-DO)
	bool callPlayerMovement(char* currentPosition, char* targetDirection);
	bool callPlayerPickUp(char* currentPosition, char* targetObject);

	placeConfig** getPlacesConfig(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------