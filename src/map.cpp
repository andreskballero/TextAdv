#include "map.h"



map::map()
{
}


map::~map()
{
}


placeConfig* map::loadStruct(char* newName, char** newDescription)
{
	placeConfig* newPlace = (placeConfig*)malloc(sizeof(placeConfig) + 1);

	newPlace->name = newName;
	newPlace->description = newDescription;

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

	//----------------------- PLACES -----------------------//
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
	placesConfig[LOBBY] = loadStruct("lobby", lobbyText);
	placesConfig[GARAGE] = loadStruct("garage", garageText);
	placesConfig[DOWNSTAIRS_CORRIDOR] = loadStruct("downstairs corridor", downstairsCorridorText);
	placesConfig[KITCHEN] = loadStruct("kitchen", kitchenText);
	placesConfig[WC] = loadStruct("WC", bathroomText);
	placesConfig[LIVING_ROOM] = loadStruct("living room", livingRoomText);
	placesConfig[BASEMENT] = loadStruct("basement", basementText);


	//------------ LOBBY ------------//

		// carga relaciones LOBBY
	leftRelations->direction = "left";
	leftRelations->nextPlace = "downstairs corridor";
	rightRelations->direction = "right";
	rightRelations->nextPlace = "garage";
	forwardRelations->direction = NULL;
	forwardRelations->nextPlace = NULL;
	backRelations->direction = NULL;
	backRelations->nextPlace = NULL;
	upRelations->direction = "up";
	upRelations->nextPlace = "hall"; // hall es el descansillo de arriba
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
	backRelations->direction = "backward";
	backRelations->nextPlace = "lobby";
	upRelations->direction = NULL;
	upRelations->nextPlace = NULL;
	downRelations->direction = "down";
	downRelations->nextPlace = "basement";

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
	leftRelations->direction = "left";
	leftRelations->nextPlace = "WC";
	rightRelations->direction = "right";
	rightRelations->nextPlace = "kitchen";
	forwardRelations->direction = "forward";
	forwardRelations->nextPlace = "living room";
	backRelations->direction = "backward";
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
	loadRelations(placesConfig[DOWNSTAIRS_CORRIDOR], placesLoad);


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
	backRelations->direction = "backward";
	backRelations->nextPlace = "downstairs corridor";
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
	backRelations->direction = "backward";
	backRelations->nextPlace = "downstairs corridor";
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
	backRelations->direction = "backward";
	backRelations->nextPlace = "downstairs corridor";
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
	upRelations->direction = "up";
	upRelations->nextPlace = "garage";
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



	//----------------------- OBJECTS -----------------------//

	normalObject** objects = (normalObject**)malloc((sizeof(normalObject*) * MAX_NORMAL_ITEMS_PLACE) + 1);

	normalObject* nObject0 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject1 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject2 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject3 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject4 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject5 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject6 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject7 = (normalObject*)malloc(sizeof(normalObject) + 1);

	//------------ OBJETOS LOBBY ------------//

	nObject0->name = "picture";
	nObject0->description = guyPictureText;

	objects[GUY_PICTURE] = nObject0;
	objects[1] = NULL;
	objects[2] = NULL;
	objects[3] = NULL;
	objects[4] = NULL;
	objects[5] = NULL;
	objects[6] = NULL;
	objects[7] = NULL;

	placesConfig[LOBBY]->nObjects = objects;
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
