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
	normalObject* nObject8 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject* nObject9 = (normalObject*)malloc(sizeof(normalObject) + 1);

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
	nObject6->name = "candy";
	nObject6->description = lobbyCandyText;
	nObject7->name = "flowerpot";
	nObject7->description = lobbyFlowerpotText;
	nObject8->name = "clock";
	nObject8->description = lobbyClockText;
	nObject9->name = "coats";
	nObject9->description = lobbyCoatsText;

	objects[LOBBY_PICTURE] = nObject0;
	objects[LOBBY_PLATE] = nObject1;
	objects[LOBBY_PEG] = nObject2;
	objects[LOBBY_CARPET] = nObject3;
	objects[LOBBY_COMMODE] = nObject4;
	objects[LOBBY_STAIRS] = nObject5;
	objects[LOBBY_CANDY] = nObject6;
	objects[LOBBY_FLOWERPOT] = nObject7;
	objects[LOBBY_CLOCK] = nObject8;
	objects[LOBBY_COATS] = nObject9;

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
	nObject8 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject9 = (normalObject*)malloc(sizeof(normalObject) + 1);

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
	nObject8->name = NULL;
	nObject8->description = NULL;
	nObject9->name = NULL;
	nObject9->description = NULL;

	objects[DOWNSTAIRS_CORRIDOR_LETTERS] = nObject0;
	objects[1] = nObject1;
	objects[2] = nObject2;
	objects[3] = nObject3;
	objects[4] = nObject4;
	objects[5] = nObject5;
	objects[6] = nObject6;
	objects[7] = nObject7;
	objects[8] = nObject8;
	objects[9] = nObject9;

	placesConfig[DOWNSTAIRS_CORRIDOR]->nObjects = objects;


	//------------ OBJETOS COCINA ------------//

	objects = (normalObject**)malloc((sizeof(normalObject*) * MAX_NORMAL_ITEMS_PLACE) + 1);

	nObject0 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject1 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject2 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject3 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject4 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject5 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject6 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject7 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject8 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject9 = (normalObject*)malloc(sizeof(normalObject) + 1);

	nObject0->name = "tableboard";
	nObject0->description = kitchenTableboardText;
	nObject1->name = "fridge";
	nObject1->description = kitchenFridgeText;
	nObject2->name = "worktop";
	nObject2->description = kitchenWorktopText;
	nObject3->name = "fitment";
	nObject3->description = kitchenFitmentText;
	nObject4->name = "doorway";
	nObject4->description = kitchenDoorwayText;
	nObject5->name = "milk";
	nObject5->description = kitchenMilkText;
	nObject6->name = "flour";
	nObject6->description = kitchenFlourText;
	nObject7->name = "eggs";
	nObject7->description = kitchenEggsText;
	nObject8->name = "microwave";
	nObject8->description = kitchenMicrowaveText;
	nObject9->name = "stove";
	nObject9->description = kitchenStoveText;

	objects[KITCHEN_TABLEBOARD] = nObject0;
	objects[KITCHEN_FRIDGE] = nObject1;
	objects[KITCHEN_WORKTOP] = nObject2;
	objects[KITCHEN_FITMENT] = nObject3;
	objects[KITCHEN_DOORWAY] = nObject4;
	objects[KITCHEN_MILK] = nObject5;
	objects[KITCHEN_FLOUR] = nObject6;
	objects[KITCHEN_EGGS] = nObject7;
	objects[KITCHEN_MICROWAVE] = nObject8;
	objects[KITCHEN_STOVE] = nObject9;

	placesConfig[KITCHEN]->nObjects = objects;

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
	nObject8 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject9 = (normalObject*)malloc(sizeof(normalObject) + 1);

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
	nObject7->name = "figure";
	nObject7->description = livingroomFigureText;
	nObject8->name = "dish";
	nObject8->description = livingroomDishText;
	nObject9->name = "stick";
	nObject9->description = livingroomStickText;

	objects[LIVING_ROOM_BOOKSHELF] = nObject0;
	objects[LIVING_ROOM_TABLE] = nObject1;
	objects[LIVING_ROOM_PIANO] = nObject2;
	objects[LIVING_ROOM_BIRDCAGE] = nObject3;
	objects[LIVING_ROOM_TV] = nObject4;
	objects[LIVING_ROOM_SOFAS] = nObject5;
	objects[LIVING_ROOM_WINDOW] = nObject6;
	objects[LIVING_ROOM_FIGURE] = nObject7;
	objects[LIVING_ROOM_DISH] = nObject8;
	objects[LIVING_ROOM_STICK] = nObject9;

	placesConfig[LIVING_ROOM]->nObjects = objects;


	//----------------------- OBJETOS ACTIVOS -----------------------//

		// lobby
	activeObject** activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	activeObject* actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject* actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject* actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject* actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->name = "shoes";
	actObject0->description = lobbyShoesText;
	actObject0->holder = "commode";

	actObject1->name = "battery";
	actObject1->description = lobbyBatteryText;
	actObject1->holder = "uniform";

	actObject2->name = "leaflet";
	actObject2->description = lobbyLeafletText;
	actObject2->holder = "carpet";

	actObject3->name = "plant";
	actObject3->description = lobbyPlantText;
	actObject3->holder = "flowerpot";

	activeObjects[LOBBY_SHOES] = actObject0;
	activeObjects[LOBBY_BATTERY] = actObject1;
	activeObjects[LOBBY_LEAFLET] = actObject2;
	activeObjects[LOBBY_PLANT] = actObject3;

	placesConfig[LOBBY]->aObjects = activeObjects;

		// kitchen
	activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->name = "knife";
	actObject0->description = kitchenKnifeText;
	actObject0->holder = "tableboard";

	actObject1->name = "beef";
	actObject1->description = kitchenBeefText;
	actObject1->holder = "fridge";

	actObject2->name = "coffee";
	actObject2->description = kitchenCoffeeText;
	actObject2->holder = "worktop";

	actObject3->name = "water";
	actObject3->description = kitchenWaterText;
	actObject3->holder = "fitment";

	activeObjects[KITCHEN_KNIFE] = actObject0;
	activeObjects[KITCHEN_BEEF] = actObject1;
	activeObjects[KITCHEN_COFFEE] = actObject2;
	activeObjects[KITCHEN_WATER] = actObject3;

	placesConfig[KITCHEN]->aObjects = activeObjects;

		//living room
	activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->name = "bible";
	actObject0->description = livingroomBibleText;
	actObject0->holder = "bookshelf";

	actObject1->name = "vase";
	actObject1->description = livingroomVaseText;
	actObject1->holder = "table";

	actObject2->name = "screwdriver";
	actObject2->description = livingroomScrewdriverText;
	actObject2->holder = "piano";

	actObject3->name = "cents";
	actObject3->description = livingroomCentsText;
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
