#include "map.h"



map::map()
{
}


map::~map()
{
}


placeConfig* map::loadStruct(int newId, char* newName, char** newDescription, activeObject** newObjectsA, placeRelations* newRelations)
{
	placeConfig* newPlace = (placeConfig*)malloc(sizeof(placeConfig) + 1);

	newPlace->id = newId;
	newPlace->name = newName;
	newPlace->description = newDescription;
	newPlace->objectsA = newObjectsA;
	newPlace->nextPlaces = newRelations;

	return newPlace;
}


void map::loadObjectsPlaces(void)
{
	placeRelations* relationsLobby = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	relationsLobby->nextPlace = "kitchen";
	relationsLobby->direction = "izquierda";

	// cargar cada lugar con sus datos ya incorporados
	placesConfig[LOBBY] = loadStruct(LOBBY, "lobby", lobbyText, lobbyActiveObjects, relationsLobby);

	printf("%s\n\n%s\n\n%s\n\n%s\n\n", placesConfig[LOBBY]->description[0], placesConfig[LOBBY]->description[1], placesConfig[LOBBY]->nextPlaces->nextPlace, placesConfig[LOBBY]->nextPlaces->direction);
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
