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
	newPlace->nextPlaces[UP] = newNextPlaces[UP];
	newPlace->nextPlaces[DOWN] = newNextPlaces[DOWN];

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
	placeRelations* upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations* downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

		// carga de los lugares
	placesConfig[LOBBY] = loadStruct(LOBBY, "lobby", lobbyText, NULL);
	placesConfig[GARAGE] = loadStruct(GARAGE, "garaje", garageText, NULL);
	placesConfig[CORRIDOR_0] = loadStruct(CORRIDOR_0, "pasillo de abajo", corridor0Text, NULL);
	placesConfig[KITCHEN] = loadStruct(KITCHEN, "cocina", kitchenText, NULL);
	placesConfig[WC] = loadStruct(WC, "WC", bathroomText, NULL);
	placesConfig[LIVING_ROOM] = loadStruct(LIVING_ROOM, "sala de estar", livingRoomText, NULL);
	placesConfig[BASEMENT] = loadStruct(BASEMENT, "sotano", basementText, NULL);


	//------------ LOBBY ------------//

		// carga relaciones LOBBY
	leftRelations->direction = "izquierda";
	leftRelations->nextPlace = "pasillo de abajo";
	rightRelations->direction = "derecha";
	rightRelations->nextPlace = "garaje";
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = NULL;
	backRelations->nextPlace = NULL;
	upRelations->direction = "arriba";
	upRelations->nextPlace = "piso de arriba";
	downRelations->direction = NULL;
	downRelations->nextPlace = NULL;

		// cargo las direcciones
	placesLoad[LEFT] = leftRelations;
	placesLoad[RIGHT] = rightRelations;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = NULL;
	placesLoad[UP] = upRelations;
	placesLoad[DOWN] = NULL;
	loadRelations(placesConfig[LOBBY], placesLoad);


	//------------ GARAJE ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

	// carga relaciones
	leftRelations->direction = NULL;
	leftRelations->nextPlace = NULL;
	rightRelations->direction = NULL;
	rightRelations->nextPlace = NULL;
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = "atras";
	backRelations->nextPlace = "lobby";
	upRelations->direction = NULL;
	upRelations->nextPlace = NULL;
	downRelations->direction = "abajo";
	downRelations->nextPlace = "sotano";

	// cargo las direcciones
	placesLoad[LEFT] = NULL;
	placesLoad[RIGHT] = NULL;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = backRelations;
	placesLoad[UP] = NULL;
	placesLoad[DOWN] = downRelations;
	loadRelations(placesConfig[GARAGE], placesLoad);


	//------------ PASILLO DE ABAJO ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

	// carga relaciones
	leftRelations->direction = "izquierda";
	leftRelations->nextPlace = "WC";
	rightRelations->direction = "derecha";
	rightRelations->nextPlace = "cocina";
	forwardRelations->direction = "adelante";
	forwardRelations->nextPlace = "sala de estar";
	backRelations->direction = "atras";
	backRelations->nextPlace = "lobby";
	upRelations->direction = NULL;
	upRelations->nextPlace = NULL;
	downRelations->direction = NULL;
	downRelations->nextPlace = NULL;

	// cargo las direcciones
	placesLoad[LEFT] = leftRelations;
	placesLoad[RIGHT] = rightRelations;
	placesLoad[FORWARD] = forwardRelations;
	placesLoad[BACKWARD] = backRelations;
	placesLoad[UP] = NULL;
	placesLoad[DOWN] = NULL;
	loadRelations(placesConfig[CORRIDOR_0], placesLoad);


	//------------ COCINA ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

	// carga relaciones
	leftRelations->direction = NULL;
	leftRelations->nextPlace = NULL;
	rightRelations->direction = NULL;
	rightRelations->nextPlace = NULL;
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = "atras";
	backRelations->nextPlace = "pasillo de abajo";
	upRelations->direction = NULL;
	upRelations->nextPlace = NULL;
	downRelations->direction = NULL;
	downRelations->nextPlace = NULL;

	// cargo las direcciones
	placesLoad[LEFT] = NULL;
	placesLoad[RIGHT] = NULL;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = backRelations;
	placesLoad[UP] = NULL;
	placesLoad[DOWN] = NULL;
	loadRelations(placesConfig[KITCHEN], placesLoad);


	//------------ WC ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

	// carga relaciones
	leftRelations->direction = NULL;
	leftRelations->nextPlace = NULL;
	rightRelations->direction = NULL;
	rightRelations->nextPlace = NULL;
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = "atras";
	backRelations->nextPlace = "pasillo de abajo";
	upRelations->direction = NULL;
	upRelations->nextPlace = NULL;
	downRelations->direction = NULL;
	downRelations->nextPlace = NULL;

	// cargo las direcciones
	placesLoad[LEFT] = NULL;
	placesLoad[RIGHT] = NULL;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = backRelations;
	placesLoad[UP] = NULL;
	placesLoad[DOWN] = NULL;
	loadRelations(placesConfig[WC], placesLoad);


	//------------ SALA DE ESTAR ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

	// carga relaciones
	leftRelations->direction = NULL;
	leftRelations->nextPlace = NULL;
	rightRelations->direction = NULL;
	rightRelations->nextPlace = NULL;
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = "atras";
	backRelations->nextPlace = "pasillo de abajo";
	upRelations->direction = NULL;
	upRelations->nextPlace = NULL;
	downRelations->direction = NULL;
	downRelations->nextPlace = NULL;

	// cargo las direcciones
	placesLoad[LEFT] = NULL;
	placesLoad[RIGHT] = NULL;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = backRelations;
	placesLoad[UP] = NULL;
	placesLoad[DOWN] = NULL;
	loadRelations(placesConfig[LIVING_ROOM], placesLoad);


	//------------ SOTANO ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

	// carga relaciones
	leftRelations->direction = NULL;
	leftRelations->nextPlace = NULL;
	rightRelations->direction = NULL;
	rightRelations->nextPlace = NULL;
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = NULL;
	backRelations->nextPlace = NULL;
	upRelations->direction = "arriba";
	upRelations->nextPlace = "garaje";
	downRelations->direction = NULL;
	downRelations->nextPlace = NULL;

	// cargo las direcciones
	placesLoad[LEFT] = NULL;
	placesLoad[RIGHT] = NULL;
	placesLoad[FORWARD] = NULL;
	placesLoad[BACKWARD] = NULL;
	placesLoad[UP] = upRelations;
	placesLoad[DOWN] = NULL;
	loadRelations(placesConfig[BASEMENT], placesLoad);


	/*for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 6; ++j)
			if (placesConfig[i]->nextPlaces[j] != NULL)
				printf("%s\n%s\n%s\n%s\n\n\n", placesConfig[i]->name, placesConfig[i]->description[1], placesConfig[i]->nextPlaces[j]->direction, placesConfig[i]->nextPlaces[j]->nextPlace);
	}*/

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
