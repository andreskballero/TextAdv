#include "map.h"



map::map()
{
}


map::~map()
{
}


placeConfig* map::initPlace(char *newName, char **newDescription, bool newAccess)
{
	placeConfig *newPlace = (placeConfig*)malloc(sizeof(placeConfig) + 1);

	newPlace->name = newName;
	newPlace->description = newDescription;
	newPlace->accessible = newAccess;

	return newPlace;
}


void map::loadPlacesObjectsCombinations(void)
{

	//----------------------- PLACES -----------------------//
		// array auxiliar de carga
	placeRelations **placesLoad = (placeRelations**) malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1); 
		// punteros auxiliares de carga de relaciones
	placeRelations *leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations *rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations *backRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations *forwardRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations *upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	placeRelations *downRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);

		// carga de los lugares
	placesConfig[LOBBY] = initPlace("lobby", lobbyText);
	placesConfig[GARAGE] = initPlace("garage", garageText);
	placesConfig[DOWNSTAIRS_CORRIDOR] = initPlace("downstairs corridor", downstairsCorridorText);
	placesConfig[KITCHEN] = initPlace("kitchen", kitchenText);
	placesConfig[WC] = initPlace("WC", bathroomText);
	placesConfig[LIVING_ROOM] = initPlace("living room", livingRoomText);
	placesConfig[BASEMENT] = initPlace("basement", basementText);


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

	placesConfig[LOBBY]->nextPlaces = placesLoad;


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

	placesConfig[GARAGE]->nextPlaces = placesLoad;


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

	placesConfig[DOWNSTAIRS_CORRIDOR]->nextPlaces = placesLoad;


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
	
	placesConfig[KITCHEN]->nextPlaces = placesLoad;


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

	placesConfig[WC]->nextPlaces = placesLoad;


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

	placesConfig[LIVING_ROOM]->nextPlaces = placesLoad;


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

	placesConfig[BASEMENT]->nextPlaces = placesLoad;


	/*for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 6; ++j)
			if (placesConfig[i]->nextPlaces[j] != NULL)
				printf("%s\n%s\n%s\n%s\n\n\n", placesConfig[i]->name, placesConfig[i]->description[1], placesConfig[i]->nextPlaces[j]->direction, placesConfig[i]->nextPlaces[j]->nextPlace);
	}*/

	//printf("%s\n\n%s\n\n%s\n\n%s\n\n", placesConfig[LOBBY]->description[0], placesConfig[LOBBY]->description[1], placesConfig[LOBBY]->nextPlaces[LEFT]->nextPlace, placesConfig[LOBBY]->nextPlaces[LEFT]->direction);
	//printf("%s\n\n%s\n\n%s\n\n%s\n\n", placesConfig[GARAGE]->description[0], placesConfig[GARAGE]->description[1], placesConfig[GARAGE]->nextPlaces[BACKWARD]->nextPlace, placesConfig[GARAGE]->nextPlaces[BACKWARD]->direction);



	//----------------------- OBJETOS NORMALES-----------------------//

	normalObject **objects = (normalObject**)malloc((sizeof(normalObject*) * MAX_NORMAL_ITEMS_PLACE) + 1);

	normalObject *nObject0 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject1 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject2 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject3 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject4 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject5 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject6 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject7 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject8 = (normalObject*)malloc(sizeof(normalObject) + 1);
	normalObject *nObject9 = (normalObject*)malloc(sizeof(normalObject) + 1);

	//------------ OBJETOS LOBBY ------------//
	nObject0->setMembers("picture", lobbyPictureText);
	nObject1->setMembers("plate", lobbyPlateText);
	nObject2->setMembers("peg", lobbyPegText);
	nObject3->setMembers("carpet", lobbyCarpetText);
	nObject4->setMembers("commode", lobbyCommodeText);
	nObject5->setMembers("stairs", lobbyStairsText);
	nObject6->setMembers("candy", lobbyCandyText);
	nObject7->setMembers("flowerpot", lobbyFlowerpotText);
	nObject8->setMembers("clock", lobbyClockText);
	nObject9->setMembers("coats", lobbyCoatsText);

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


	//------------ OBJETOS GARAJE ------------//
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

	nObject0->setMembers("car", garageCarText);
	nObject1->setMembers("shelf", garageShelfText);
	nObject2->setMembers("workbench", garageWorkbenchText);
	nObject3->setMembers("boxes", garageBoxesText);
	nObject4->setMembers("chainsaw", garageChainsawText);
	nObject5->setMembers("bike", garageBikeText);
	nObject6->setMembers("door", garageDoorText);
	nObject7->setMembers("lock", garageElectricalLockText);
	nObject8->setMembers("signboard", garageSignboardText);
	nObject9->setMembers("gate", garageGateText);

	objects[GARAGE_CAR] = nObject0;
	objects[GARAGE_SHELF] = nObject1;
	objects[GARAGE_WORKBENCH] = nObject2;
	objects[GARAGE_BOXES] = nObject3;
	objects[GARAGE_CHAINSAW] = nObject4;
	objects[GARAGE_BIKE] = nObject5;
	objects[GARAGE_DOOR] = nObject6;
	objects[GARAGE_ELECTRICAL_LOCK] = nObject7;
	objects[GARAGE_SIGNBOARD] = nObject8;
	objects[GARAGE_GATE] = nObject9;

	placesConfig[GARAGE]->nObjects = objects;


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

	nObject0->setMembers("letters", corridorLettersText);
	nObject1->setMembers(NULL, NULL);
	nObject2->setMembers(NULL, NULL);
	nObject3->setMembers(NULL, NULL);
	nObject4->setMembers(NULL, NULL);
	nObject5->setMembers(NULL, NULL);
	nObject6->setMembers(NULL, NULL);
	nObject7->setMembers(NULL, NULL);
	nObject8->setMembers(NULL, NULL);
	nObject9->setMembers(NULL, NULL);

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

	nObject0->setMembers("tableboard", kitchenTableboardText);
	nObject1->setMembers("fridge", kitchenFridgeText);
	nObject2->setMembers("worktop", kitchenWorktopText);
	nObject3->setMembers("fitment", kitchenFitmentText);
	nObject4->setMembers("doorway", kitchenDoorwayText);
	nObject5->setMembers("milk", kitchenMilkText);
	nObject6->setMembers("flour", kitchenFlourText);
	nObject7->setMembers("eggs", kitchenEggsText);
	nObject8->setMembers("microwave", kitchenMicrowaveText);
	nObject9->setMembers("stove", kitchenStoveText);

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


	//------------ OBJETOS WC ------------//
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

	nObject0->setMembers("shower", wcShowerText);
	nObject1->setMembers("sink", wcSinkText);
	nObject2->setMembers("mirror", wcMirrorText);
	nObject3->setMembers("toilet", wcToiletText);
	nObject4->setMembers("furniture", wcFurnitureText);
	nObject5->setMembers("drawer", wcDrawerText);
	nObject6->setMembers("paper", wcPaperText);
	nObject7->setMembers("aspirin", wcAspirinText);
	nObject8->setMembers("bandage", wcBandageText);
	nObject9->setMembers(NULL, NULL);

	objects[WC_SHOWER] = nObject0;
	objects[WC_SINK] = nObject1;
	objects[WC_MIRROR] = nObject2;
	objects[WC_TOILET] = nObject3;
	objects[WC_FURNITURE] = nObject4;
	objects[WC_DRAWER] = nObject5;
	objects[WC_PAPER] = nObject6;
	objects[WC_ASPIRIN] = nObject7;
	objects[WC_BANDAGE] = nObject8;
	objects[9] = nObject9;

	placesConfig[WC]->nObjects = objects;


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

	nObject0->setMembers("bookshelf", livingroomBookshelfText);
	nObject1->setMembers("table", livingroomTableText);
	nObject2->setMembers("piano", livingroomPianoText);
	nObject3->setMembers("birdcage", livingroomBirdcageText);
	nObject4->setMembers("TV", livingroomTVText);
	nObject5->setMembers("sofas", livingroomSofasText);
	nObject6->setMembers("window", livingroomWindowText);
	nObject7->setMembers("figure", livingroomFigureText);
	nObject8->setMembers("dish", livingroomDishText);
	nObject9->setMembers("stick", livingroomStickText);

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
	activeObject **activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	activeObject *actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject *actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject *actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject *actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);


	actObject0->setMembers("shoes", lobbyShoesText, "commode");
	actObject1->setMembers("battery", lobbyBatteryText, "uniform");
	actObject2->setMembers("leaflet", lobbyLeafletText, "carpet");
	actObject3->setMembers("plant", lobbyPlantText, "flowerpot");

	activeObjects[LOBBY_SHOES] = actObject0;
	activeObjects[LOBBY_BATTERY] = actObject1;
	activeObjects[LOBBY_LEAFLET] = actObject2;
	activeObjects[LOBBY_PLANT] = actObject3;

	placesConfig[LOBBY]->aObjects = activeObjects;


		// garage
	activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->setMembers("tape", garageTapeText, "bike");
	actObject1->setMembers("sawdust", garageSawdustText, "workbench");
	actObject2->setMembers("lighter", garageLighterText, "car");
	actObject3->setMembers("fireworks", garageFireworksText, "shelf");

	activeObjects[GARAGE_TAPE] = actObject0;
	activeObjects[GARAGE_SAWDUST] = actObject1;
	activeObjects[GARAGE_LIGHTER] = actObject2;
	activeObjects[GARAGE_FIREWORKS] = actObject3;

	placesConfig[GARAGE]->aObjects = activeObjects;

		// downstairs corridor (nothing)


		// kitchen
	activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->setMembers("knife", kitchenKnifeText, "tableboard");
	actObject1->setMembers("beef", kitchenBeefText, "fridge");
	actObject2->setMembers("coffee", kitchenCoffeeText, "worktop");
	actObject3->setMembers("water", kitchenWaterText, "fitment");

	activeObjects[KITCHEN_KNIFE] = actObject0;
	activeObjects[KITCHEN_BEEF] = actObject1;
	activeObjects[KITCHEN_COFFEE] = actObject2;
	activeObjects[KITCHEN_WATER] = actObject3;

	placesConfig[KITCHEN]->aObjects = activeObjects;


		// WC
	activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->setMembers("soap", wcSoapText, "shower");
	actObject1->setMembers("toothpaste", wcToothpasteText, "sink");
	actObject2->setMembers("comb", wcCombText, "furniture");
	actObject3->setMembers("perfume", wcPerfumeText, "drawer");

	activeObjects[WC_SOAP] = actObject0;
	activeObjects[WC_TOOTHPASTE] = actObject1;
	activeObjects[WC_COMB] = actObject2;
	activeObjects[WC_PERFUME] = actObject3;

	placesConfig[WC]->aObjects = activeObjects;


		// living room
	activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);

	actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

	actObject0->setMembers("bible", livingroomBibleText, "bookshelf");
	actObject1->setMembers("vase", livingroomVaseText, "table");
	actObject2->setMembers("screwdriver", livingroomScrewdriverText, "piano");
	actObject3->setMembers("cents", livingroomCentsText, "sofas");

	activeObjects[LIVING_ROOM_BIBLE] = actObject0;
	activeObjects[LIVING_ROOM_VASE] = actObject1;
	activeObjects[LIVING_ROOM_SCREWDRIVER] = actObject2;
	activeObjects[LIVING_ROOM_CENTS] = actObject3;

	placesConfig[LIVING_ROOM]->aObjects = activeObjects;


	//----------------------- COMBINACIONES -----------------------//

	//accessCombination*	combination = (accessCombination*)malloc((sizeof(accessCombination) * MAX_COMBINATIONS) + 1);

	//combination->objectA = "shoes";
	//combination->objectB = "arm";

	//placesConfig[]
}



// con polimorfismo, esta función podría hacerse con un único for
bool map::searchPlaceItem(char *element, int currentPlace, int knownItems, char *typeObjects)
{
	/*normalObject **objects;

	if (0 == strcmp(typeObjects, "normal")) WHY NOT?
	{
		objects = placesConfig[player->getCurrentPlace()]->nObjects;
	}
	else {
		objects = placesConfig[player->getCurrentPlace()]->aObjects;
	}*/

	if (0 == strcmp(typeObjects, "normal"))
	{
		// busco el objeto entre los normales // esto podría ser una función de búsqueda
		for (int item = 0; item < knownItems; ++item)
		{
			// si hay algún objeto ahi, y si lo introducido 
			if ((placesConfig[currentPlace]->nObjects[item] != NULL) &&
				((0 == strcmp(element, placesConfig[currentPlace]->nObjects[item]->getName()))))
			{
				printText(placesConfig[currentPlace]->nObjects[item]->getDescription()[VALID_TEXT]);
				return FOUND;
			}
		}
	}
	else if (0 == strcmp(typeObjects, "active")) {
		// busco el objeto entre los normales // esto podría ser una función de búsqueda
		for (int item = 0; item < knownItems; ++item)
		{
			// si hay algún objeto ahi, y si lo introducido 
			if ((placesConfig[currentPlace]->aObjects[item] != NULL) &&
				((0 == strcmp(element, placesConfig[currentPlace]->aObjects[item]->getName()))))
			{
				printText(placesConfig[currentPlace]->aObjects[item]->getDescription()[VALID_TEXT]);
				return FOUND;
			}
		}
	}

	return NOT_FOUND; // esto no puede ir en un else porque si no lo encuentra debe devolver algo igualmente
}


int map::getNextPlace(int currentPlace, char *direction)
{
	for (int nextDirection = 0; nextDirection < MAX_NEXT_PLACES; ++nextDirection) // busco la dirección en el lugar actual
	{
		if ((NULL != placesConfig[currentPlace]->nextPlaces[nextDirection]) &&
			(0 == strcmp(direction, placesConfig[currentPlace]->nextPlaces[nextDirection]->direction))) // si existe
		{
			for (int nextPlace = 0; nextPlace < TOTAL_PLACES; ++nextPlace) // miro a qué sitio lleva
			{
				if (0 == strcmp(placesConfig[currentPlace]->nextPlaces[nextDirection]->nextPlace, placesConfig[nextPlace]->name))
				{
					//printf("%s, %s, %s, %s\n", direction, placesConfig[currentPlace]->nextPlaces[nextDirection]->direction, placesConfig[currentPlace]->nextPlaces[nextDirection]->nextPlace, placesConfig[nextPlace]->name);
					return nextPlace; // devuelvo la habitación objetivo
				}
			}
		}
	}

	return PLACE_NOT_FOUND;
}



normalObject* map::getNormalObject(char *element, int currentPlace)
{
	for (int item = 0; item < MAX_NORMAL_ITEMS_PLACE; ++item)
	{
		if ((NULL != placesConfig[currentPlace]->nObjects[item]) &&
			(0 == strcmp(element, placesConfig[currentPlace]->nObjects[item]->getName())))
		{
			return placesConfig[currentPlace]->nObjects[item];
		}
	}

	return NULL;
}



activeObject** map::getActiveObject(char *element, int currentPlace)
{
	for (int item = 0; item < MAX_ACTIVE_ITEMS_PLACE; ++item)
	{
		if ((NULL != placesConfig[currentPlace]->aObjects[item]) &&
			(0 == strcmp(element, placesConfig[currentPlace]->aObjects[item]->getName())))
		{
			return &placesConfig[currentPlace]->aObjects[item];
		}
	}

	return NULL;
}



placeConfig** map::getPlacesConfig(void)
{
	return placesConfig;
}
