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

#include <string.h>

#include "descriptions.h"
#include "player.h"
#include "normalObject.h"
#include "activeObject.h"

// struct que contiene un lugar y la direcci�n hacia
// la que girar para ir (estando en un lugar adyacente)
typedef struct {
	char *direction;
	char *nextPlace;
} placeRelations;

// struct para guardar todos los datos de un lugar
// y luego poder cargarlos f�cilmente
typedef struct {
	char				*name;

	// hay dos descripciones: [0] es la de entrada, [1] la normal
	char				**description;

	// si el lugar es accesible
	bool				accessible;

	// como mucho, X objetos activos y normales por lugar
	activeObject		**aObjects;
	normalObject		**nObjects;
	//accessCombination	*combination;

	// struct para guardar las relaciones
	placeRelations		**nextPlaces;
} placeConfig;

class map
{
private:
	// array de structs que contienen todos los datos
	// necesarios que el mapa debe conocer de cada lugar
	placeConfig					*placesConfig[TOTAL_PLACES];

	//environmentCombination			*combinations[MAX_COMBINATIONS];

	// funci�n que permite crear una nueva struct y devolverla
	placeConfig					*initPlace(char *newName, char **newDescription, bool newAccess = true);

public:
	map();
	~map();

	// funci�n que crea todas las structs necesarias del juego
	// y las a�ade al array de places
	void loadPlacesObjectsCombinations(void);

	bool searchPlaceItem(char *element, int currentPlace, int knownItems, char *typeObjects);

	placeConfig* getPlace(char *placeName);
	int getNextPlace(int currentPlace, char *direction);

	normalObject* getNormalObject(char *element, int currentPlace);
	activeObject* getActiveObject(char *element, int currentPlace); // doble puntero para poder ponerlo a null
	placeConfig** getPlacesConfig(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------