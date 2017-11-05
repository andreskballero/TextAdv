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
	newPlace->nextPlaces = newNextPlaces;
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



	//----------------------- OBJETOS NORMALES-----------------------//

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
	nObject0->description = lobbyPictureText;
	nObject1->name = "plate";
	nObject1->description = lobbyPlateText;
	nObject2->name = "peg";
	nObject2->description = lobbyPegText;
	nObject3->name = "carpet";
	nObject3->description = lobbyCarpetText;
	nObject4->name = "commode";
	nObject4->description = lobbyCommodeText;
	nObject5->name = "stairs";
	nObject5->description = lobbyStairsText;
	nObject6->name = NULL;
	nObject6->description = NULL;
	nObject7->name = NULL;
	nObject7->description = NULL;

	objects[LOBBY_PICTURE] = nObject0;
	objects[LOBBY_PLATE] = nObject1;
	objects[LOBBY_PEG] = nObject2;
	objects[LOBBY_CARPET] = nObject3;
	objects[LOBBY_COMMODE] = nObject4;
	objects[LOBBY_STAIRS] = nObject5;
	objects[6] = nObject6;
	objects[7] = nObject7;

	placesConfig[LOBBY]->nObjects = objects;


	//------------ OBJETOS CORRIDOR ------------//

	objects = (normalObject**)malloc((sizeof(normalObject*) * MAX_NORMAL_ITEMS_PLACE) + 1);

	nObject0 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject1 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject2 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject3 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject4 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject5 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject6 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject7 = (normalObject*)malloc(sizeof(normalObject) + 1);

	nObject0->name = "letters";
	nObject0->description = corridorLettersText;
	nObject1->name = NULL;
	nObject1->description = NULL;
	nObject2->name = NULL;
	nObject2->description = NULL;
	nObject3->name = NULL;
	nObject3->description = NULL;
	nObject4->name = NULL;
	nObject4->description = NULL;
	nObject5->name = NULL;
	nObject5->description = NULL;
	nObject6->name = NULL;
	nObject6->description = NULL;
	nObject7->name = NULL;
	nObject7->description = NULL;

	objects[DOWNSTAIRS_CORRIDOR_LETTERS] = nObject0;
	objects[1] = nObject1;
	objects[2] = nObject2;
	objects[3] = nObject3;
	objects[4] = nObject4;
	objects[5] = nObject5;
	objects[6] = nObject6;
	objects[7] = nObject7;

	placesConfig[DOWNSTAIRS_CORRIDOR]->nObjects = objects;


	//------------ OBJETOS SALA DE ESTAR ------------//

	objects = (normalObject**)malloc((sizeof(normalObject*) * MAX_NORMAL_ITEMS_PLACE) + 1);

	nObject0 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject1 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject2 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject3 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject4 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject5 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject6 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject7 = (normalObject*)malloc(sizeof(normalObject) + 1);

	nObject0->name = "bookshelf";
	nObject0->description = livingroomBookshelfText;
	nObject1->name = "table";
	nObject1->description = livingroomTableText;
	nObject2->name = "piano";
	nObject2->description = livingroomPianoText;
	nObject3->name = "birdcage";
	nObject3->description = livingroomBirdcageText;
	nObject4->name = "TV";
	nObject4->description = livingroomTVText;
	nObject5->name = "sofas";
	nObject5->description = livingroomSofasText;
	nObject6->name = "window";
	nObject6->description = livingroomWindowText;
	nObject7->name = NULL;
	nObject7->description = NULL;

	objects[LIVING_ROOM_BOOKSHELF] = nObject0;
	objects[LIVING_ROOM_TABLE] = nObject1;
	objects[LIVING_ROOM_PIANO] = nObject2;
	objects[LIVING_ROOM_BIRDCAGE] = nObject3;
	objects[LIVING_ROOM_TV] = nObject4;
	objects[LIVING_ROOM_SOFAS] = nObject5;
	objects[LIVING_ROOM_WINDOW] = nObject6;
	objects[7] = nObject7;

	placesConfig[LIVING_ROOM]->nObjects = objects;


	//----------------------- OBJETOS ACTIVOS -----------------------//

	activeObject** activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	activeObject* actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject* actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject* actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject* actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->name = "bible";
	actObject0->description = NULL;
	actObject0->picked = false;
	actObject0->holder = "bookshelf";

	actObject1->name = "vase";
	actObject1->description = NULL;
	actObject1->picked = false;
	actObject1->holder = "table";

	actObject2->name = "screwdriver";
	actObject2->description = NULL;
	actObject2->picked = false;
	actObject2->holder = "piano";

	actObject3->name = "cents";
	actObject3->description = NULL;
	actObject3->picked = false;
	actObject3->holder = "sofas";

	activeObjects[LIVING_ROOM_BIBLE] = actObject0;
	activeObjects[LIVING_ROOM_VASE] = actObject1;
	activeObjects[LIVING_ROOM_SCREWDRIVER] = actObject2;
	activeObjects[LIVING_ROOM_CENTS] = actObject3;

	placesConfig[LIVING_ROOM]->aObjects = activeObjects;

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
