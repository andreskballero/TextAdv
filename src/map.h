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

#include <string.h>

#include "descriptions.h"
#include "player.h"
#include "normalObject.h"
#include "activeObject.h"
#include "NPC.h"

// struct que contiene un lugar y la dirección hacia
// la que girar para ir (estando en un lugar adyacente)
typedef struct {
	char *direction;
	int nextPlace;
} placeRelations;

// struct para guardar todos los datos de un lugar
// y luego poder cargarlos fácilmente
typedef struct {
	char				*name;

	// hay dos descripciones: [0] es la de entrada, [1] la normal
	char				**description;

	// totales objetos
	int					totalNormalObjects;
	int					totalActiveObjects;
	int					totalNextPlaces;

	// si el lugar es accesible
	bool				accessible;

	// como mucho, X objetos activos y normales por lugar
	activeObject		**aObjects;
	normalObject		**nObjects;

	// NPC (1 max)
	NPC					*npce;

	// struct para guardar las relaciones
	placeRelations		**nextPlaces;
} placeConfig;

class map
{
private:
	// array de structs que contienen todos los datos
	// necesarios que el mapa debe conocer de cada lugar
	placeConfig					*placesConfig[TOTAL_PLACES];

	placeConfig					*activePlace;

	// función que permite crear una nueva struct y devolverla
	placeConfig					*initPlace(char *newName, char **newDescription, int newAObjects, int newNObjects, int newNextPlaces, bool newAccess = true);

	void loadRelation(placeRelations *pr, char *direction, int nextPlace);

public:
	map();
	~map();

	// función que crea todas las structs necesarias del juego
	// y las añade al array de places
	void loadPlacesObjectsCombinations(void);
	bool searchPlaceActiveItem(char *element);
	bool searchPlaceNormalItem(char *element);

	void setActivePlace(int newPlace);

	placeConfig* getActivePlace(void);
	placeConfig* getPlace(char *placeName);
	int getNextPlace(char *direction);

	normalObject* getNormalObject(char *element);
	activeObject* getActiveObject(char *element); // doble puntero para poder ponerlo a null
	placeConfig** getPlacesConfig(void);

	NPC* getNpc(char *npc);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------