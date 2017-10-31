#include "map.h"



map::map()
{
}


map::~map()
{
}


placeConfig* map::loadStruct(int newId, char* newName, char** newDescription, activeObject** newObjectsA)
{
	placeConfig* newPlace = (placeConfig*)malloc(sizeof(placeConfig) + 1);

	newPlace->id = newId;
	newPlace->name = newName;
	newPlace->description = newDescription;
	newPlace->objectsA = newObjectsA;

	return newPlace;
}

void map::loadRelations(placeConfig* newPlace, placeRelations** newNextPlaces)
{
	newPlace->nextPlaces[LEFT] = newNextPlaces[LEFT];
	newPlace->nextPlaces[RIGHT] = newNextPlaces[RIGHT];
	newPlace->nextPlaces[FORWARD] = newNextPlaces[FORWARD];
	newPlace->nextPlaces[BACKWARD] = newNextPlaces[BACKWARD];
}


void map::loadObjectsAndPlaces(void)
{
		// array auxiliar de carga
	placeRelations** placesLoad = (placeRelations**) malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1); 

		// punteros auxiliares de carga de relaciones
	placeRelations* leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations* rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations* backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations* forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

		// carga de los lugares
	placesConfig[LOBBY] = loadStruct(LOBBY, "lobby", lobbyText, lobbyActiveObjects);
	placesConfig[GARAGE] = loadStruct(GARAGE, "garaje", garageText, garageActiveObjects);

		// carga relaciones LOBBY
	leftRelations->direction = "izquierda";
	leftRelations->nextPlace = "pasillo";
	rightRelations->direction = "derecha";
	rightRelations->nextPlace = "garaje";
	backRelations->direction = NULL;
	backRelations->nextPlace = NULL;
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;

	placesLoad[LEFT] = leftRelations;
	placesLoad[RIGHT] = rightRelations;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = NULL;
	loadRelations(placesConfig[LOBBY], placesLoad);

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

		// carga relaciones GARAJE
	backRelations->direction = "atras";
	backRelations->nextPlace = "lobby";

	placesLoad[LEFT] = NULL;
	placesLoad[RIGHT] = NULL;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = backRelations;
	loadRelations(placesConfig[GARAGE], placesLoad);


	//printf("%s\n\n%s\n\n%s\n\n%s\n\n", placesConfig[LOBBY]->description[0], placesConfig[LOBBY]->description[1], placesConfig[LOBBY]->nextPlaces[LEFT]->nextPlace, placesConfig[LOBBY]->nextPlaces[LEFT]->direction);
	//printf("%s\n\n%s\n\n%s\n\n%s\n\n", placesConfig[GARAGE]->description[0], placesConfig[GARAGE]->description[1], placesConfig[GARAGE]->nextPlaces[BACKWARD]->nextPlace, placesConfig[GARAGE]->nextPlaces[BACKWARD]->direction);

}


bool map::callPlayerMovement(char* currentPosition, char* targetDirection)
{
	bool isPossible = false;



	return isPossible;
}

bool map::callPlayerPickUp(char * currentPosition, char * targetObject)
{
	return false;
}

placeConfig** map::getPlacesConfig(void)
{
	return placesConfig;
}
