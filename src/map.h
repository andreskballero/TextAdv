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

typedef struct {
	char* name;
	char* description;
} normalObject;

// struct que contiene un lugar y la direcci�n hacia
// la que girar para ir (estando en un lugar adyacente)
typedef struct {
	char* direction;
	char* nextPlace;
} placeRelations;

// struct para guardar todos los datos de un lugar
// y luego poder cargarlos f�cilmente
typedef struct {
	char*				name;

	// hay dos descripciones: [0] es la de entrada, [1] la normal
	char**				description;

	// como mucho, X objetos activos y normales por lugar
	activeObject**		aObjects;
	normalObject**		nObjects;

	// struct para guardar las relaciones
	placeRelations**	nextPlaces;
} placeConfig;

class map
{
private:
	// array de structs que contienen todos los datos
	// necesarios que el mapa debe conocer de cada lugar
	placeConfig*		placesConfig[TOTAL_PLACES];

	// funci�n que permite crear una nueva struct y devolverla
	placeConfig*		loadStruct(char* newName, char** newDescription);

	void loadRelations(placeConfig* newPlace, placeRelations** newNextPlaces);

public:
	map();
	~map();

	// funci�n que crea todas las structs necesarias del juego
	// y las a�ade al array de places
	void loadObjectsAndPlaces(void);

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