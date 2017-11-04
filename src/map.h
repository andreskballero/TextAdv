//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa el mapa y guarda toda la información necesaria de todas
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

// struct que contiene un lugar y la dirección hacia
// la que girar para ir (estando en un lugar adyacente)
typedef struct {
	char* direction;
	char* nextPlace;
} placeRelations;

// struct para guardar todos los datos de un lugar
// y luego poder cargarlos fácilmente
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

	// función que permite crear una nueva struct y devolverla
	placeConfig*		loadStruct(char* newName, char** newDescription);

	void loadRelations(placeConfig* newPlace, placeRelations** newNextPlaces);

public:
	map();
	~map();

	// función que crea todas las structs necesarias del juego
	// y las añade al array de places
	void loadObjectsAndPlaces(void);

	// función llamada por el player que comprueba que, según la 
	// posición actual del player, se puede mover en la dirección
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