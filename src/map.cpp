#include "map.h"



map::map()
{
	// inicializar a null

	for (int init = 0; init < TOTAL_PLACES; ++init)
	{
		placesConfig[init] = NULL;
	}

	activePlace = NULL;
}


map::~map()
{
}


placeConfig* map::initPlace(char *newName, char **newDescription, int newAObjects, int newNObjects, int newNextPlaces, bool newAccess)
{
	//placeConfig *newPlace = (placeConfig*)malloc(sizeof(placeConfig) + 1);
	placeConfig *newPlace = new placeConfig(); // malloc no llama a constructor suyo ni de los objetos que contiene

	newPlace->name = newName;
	newPlace->description = newDescription;
	newPlace->totalActiveObjects = newAObjects;
	newPlace->totalNormalObjects = newNObjects;
	newPlace->totalNextPlaces = newNextPlaces;
	newPlace->accessible = newAccess;

	return newPlace;
}


void map::loadRelation(placeRelations *pr, char *direction, int nextPlace)
{
	pr->direction = direction;
	pr->nextPlace = nextPlace;
}


void map::loadPlacesObjectsCombinations(void)
{
	// antes todo esto se hacía con mallocs, ver vestigios

	//----------------------- PLACES -----------------------//
		// array auxiliar de carga
	placeRelations **placesLoad; // se hace nuevo malloc en para cada lugar

		// punteros auxiliares de carga de relaciones; se hacen mallocs si se necesita reservar espacio
		// para cada uno de ellos en cada sitio
	placeRelations *leftRelations;
	placeRelations *rightRelations;
	placeRelations *forwardRelations;
	placeRelations *backRelations;
	placeRelations *upRelations;
	placeRelations *downRelations;

		// carga de los lugares
	placesConfig[LOBBY] = initPlace("lobby", lobbyText, FOUR_ITEMS, TEN_ITEMS, THREE_PLACES);
	placesConfig[GARAGE] = initPlace("garage", garageText, FOUR_ITEMS, TEN_ITEMS, TWO_PLACES);
	placesConfig[DOWNSTAIRS_CORRIDOR] = initPlace("downstairs corridor", downstairsCorridorText, 0, ONE_ITEMS, FOUR_PLACES);
	placesConfig[KITCHEN] = initPlace("kitchen", kitchenText, FOUR_ITEMS, TEN_ITEMS, ONE_PLACE);
	placesConfig[WC] = initPlace("WC", bathroomText, FOUR_ITEMS, NINE_ITEMS, ONE_PLACE);
	placesConfig[LIVING_ROOM] = initPlace("living room", livingRoomText, FOUR_ITEMS, TEN_ITEMS, ONE_PLACE);
	placesConfig[BASEMENT] = initPlace("basement", basementText, 0, 0, ONE_PLACE, false);

		// place activa al principio es el lobby
	activePlace = placesConfig[LOBBY];


	//------------ LOBBY ------------//
	//placesLoad = (placeRelations**)malloc((sizeof(placeRelations*) * MAX_NEXT_PLACES) + 1);
	placesLoad = new placeRelations*[THREE_PLACES];

	//leftRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	//rightRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	//upRelations = (placeRelations*)malloc(sizeof(placeRelations) + 1);
	leftRelations = new placeRelations();
	rightRelations = new placeRelations(); // sobrecarga en una struct?
	upRelations = new placeRelations();

		// carga relaciones LOBBY
	loadRelation(leftRelations, "left", DOWNSTAIRS_CORRIDOR);
	loadRelation(rightRelations, "right", GARAGE);
	loadRelation(upRelations, "up", UPSTAIRS_HALL);

		// cargo las direcciones
	placesLoad[FIRST] = leftRelations;
	placesLoad[SECOND] = rightRelations;
	placesLoad[THIRD] = upRelations;

	placesConfig[LOBBY]->nextPlaces = placesLoad;


	//------------ GARAJE ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = new placeRelations*[TWO_PLACES];

	// reinicio de los punteros de dirección, reservar otros
	backRelations = new placeRelations();
	downRelations = new placeRelations();

	// carga relaciones
	loadRelation(backRelations, "backward", LOBBY);
	loadRelation(downRelations, "down", BASEMENT);

	// cargo las direcciones
	placesLoad[FIRST] = backRelations;
	placesLoad[SECOND] = downRelations;

	placesConfig[GARAGE]->nextPlaces = placesLoad;


	//------------ PASILLO DE ABAJO ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = new placeRelations*[FOUR_PLACES];

	// reinicio de los punteros de dirección, reservar otros
	leftRelations = new placeRelations();
	rightRelations = new placeRelations();
	forwardRelations = new placeRelations();
	backRelations = new placeRelations();

	// carga relaciones
	loadRelation(leftRelations, "left", WC);
	loadRelation(rightRelations, "right", KITCHEN);
	loadRelation(forwardRelations, "forward", LIVING_ROOM);
	loadRelation(backRelations, "backward", LOBBY);

	// cargo las direcciones
	placesLoad[FIRST] = leftRelations;
	placesLoad[SECOND] = rightRelations;
	placesLoad[THIRD] = forwardRelations;
	placesLoad[FOURTH] = backRelations;

	placesConfig[DOWNSTAIRS_CORRIDOR]->nextPlaces = placesLoad;


	//------------ COCINA ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = new placeRelations*[ONE_PLACE];

	// reinicio de los punteros de dirección, reservar otros
	backRelations = new placeRelations();

	// carga relaciones
	loadRelation(backRelations, "backward", DOWNSTAIRS_CORRIDOR);

	// cargo las direcciones
	placesLoad[FIRST] = backRelations;

	placesConfig[KITCHEN]->nextPlaces = placesLoad;


	//------------ WC ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = new placeRelations*[ONE_PLACE];

	// reinicio de los punteros de dirección, reservar otros
	backRelations = new placeRelations();

	// carga relaciones
	loadRelation(backRelations, "backward", DOWNSTAIRS_CORRIDOR);

	// cargo las direcciones
	placesLoad[FIRST] = backRelations;

	placesConfig[WC]->nextPlaces = placesLoad;


	//------------ SALA DE ESTAR ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = new placeRelations*[ONE_PLACE];

	// reinicio de los punteros de dirección, reservar otros
	backRelations = new placeRelations();

	// carga relaciones
	loadRelation(backRelations, "backward", DOWNSTAIRS_CORRIDOR);

	// cargo las direcciones
	placesLoad[FIRST] = backRelations;

	placesConfig[LIVING_ROOM]->nextPlaces = placesLoad;


	//------------ SOTANO ------------//

	// puntero apunta a otro nuevo array de placeRelations*
	placesLoad = new placeRelations*[ONE_PLACE];

	// reinicio de los punteros de dirección, reservar otros
	upRelations = new placeRelations();

	// carga relaciones
	loadRelation(upRelations, "up", GARAGE);

	// cargo las direcciones
	placesLoad[FIRST] = upRelations;

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

	normalObject **objects;

	normalObject *nObject0;
	normalObject *nObject1;
	normalObject *nObject2;
	normalObject *nObject3;
	normalObject *nObject4;
	normalObject *nObject5;
	normalObject *nObject6;
	normalObject *nObject7;
	normalObject *nObject8;
	normalObject *nObject9;

	//------------ OBJETOS LOBBY ------------//
	//objects = (normalObject**)malloc((sizeof(normalObject*) * MAX_NORMAL_ITEMS_PLACE) + 1);
	objects = new normalObject*[TEN_ITEMS];

	/*nObject0 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject1 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject2 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject3 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject4 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject5 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject6 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject7 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject8 = (normalObject*)malloc(sizeof(normalObject) + 1);
	nObject9 = (normalObject*)malloc(sizeof(normalObject) + 1);*/
	nObject0 = new normalObject("picture", lobbyPictureText);
	nObject1 = new normalObject("plate", lobbyPlateText);
	nObject2 = new normalObject("peg", lobbyPegText);
	nObject3 = new normalObject("carpet", lobbyCarpetText);
	nObject4 = new normalObject("commode", lobbyCommodeText);
	nObject5 = new normalObject("stairs", lobbyStairsText);
	nObject6 = new normalObject("candy", lobbyCandyText);
	nObject7 = new normalObject("flowerpot", lobbyFlowerpotText);
	nObject8 = new normalObject("clock", lobbyClockText);
	nObject9 = new normalObject("coats", lobbyCoatsText);

	/*nObject0->setMembers("picture", lobbyPictureText);
	nObject1->setMembers("plate", lobbyPlateText);
	nObject2->setMembers("peg", lobbyPegText);
	nObject3->setMembers("carpet", lobbyCarpetText);
	nObject4->setMembers("commode", lobbyCommodeText);
	nObject5->setMembers("stairs", lobbyStairsText);
	nObject6->setMembers("candy", lobbyCandyText);
	nObject7->setMembers("flowerpot", lobbyFlowerpotText);
	nObject8->setMembers("clock", lobbyClockText);
	nObject9->setMembers("coats", lobbyCoatsText);*/

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
	objects = new normalObject*[TEN_ITEMS];

	nObject0 = new normalObject("car", garageCarText);
	nObject1 = new normalObject("shelf", garageShelfText);
	nObject2 = new normalObject("workbench", garageWorkbenchText);
	nObject3 = new normalObject("boxes", garageBoxesText);
	nObject4 = new normalObject("chainsaw", garageChainsawText);
	nObject5 = new normalObject("bike", garageBikeText);
	nObject6 = new normalObject("door", garageDoorText);
	nObject7 = new normalObject("lock", garageElectricalLockText);
	nObject8 = new normalObject("signboard", garageSignboardText);
	nObject9 = new normalObject("gate", garageGateText);

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
	objects = new normalObject*[ONE_ITEMS];

	nObject0 = new normalObject("letters", corridorLettersText);

	objects[DOWNSTAIRS_CORRIDOR_LETTERS] = nObject0;

	placesConfig[DOWNSTAIRS_CORRIDOR]->nObjects = objects;


	//------------ OBJETOS COCINA ------------//
	objects = new normalObject*[TEN_ITEMS];

	nObject0 = new normalObject("tableboard", kitchenTableboardText);
	nObject1 = new normalObject("fridge", kitchenFridgeText);
	nObject2 = new normalObject("worktop", kitchenWorktopText);
	nObject3 = new normalObject("fitment", kitchenFitmentText);
	nObject4 = new normalObject("doorway", kitchenDoorwayText);
	nObject5 = new normalObject("milk", kitchenMilkText);
	nObject6 = new normalObject("flour", kitchenFlourText);
	nObject7 = new normalObject("eggs", kitchenEggsText);
	nObject8 = new normalObject("microwave", kitchenMicrowaveText);
	nObject9 = new normalObject("stove", kitchenStoveText);

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
	objects = new normalObject*[NINE_ITEMS];

	nObject0 = new normalObject("shower", wcShowerText);
	nObject1 = new normalObject("sink", wcSinkText);
	nObject2 = new normalObject("mirror", wcMirrorText);
	nObject3 = new normalObject("toilet", wcToiletText);
	nObject4 = new normalObject("furniture", wcFurnitureText);
	nObject5 = new normalObject("drawer", wcDrawerText);
	nObject6 = new normalObject("paper", wcPaperText);
	nObject7 = new normalObject("aspirin", wcAspirinText);
	nObject8 = new normalObject("bandage", wcBandageText);

	objects[WC_SHOWER] = nObject0;
	objects[WC_SINK] = nObject1;
	objects[WC_MIRROR] = nObject2;
	objects[WC_TOILET] = nObject3;
	objects[WC_FURNITURE] = nObject4;
	objects[WC_DRAWER] = nObject5;
	objects[WC_PAPER] = nObject6;
	objects[WC_ASPIRIN] = nObject7;
	objects[WC_BANDAGE] = nObject8;
	objects[9] = NULL;

	placesConfig[WC]->nObjects = objects;


	//------------ OBJETOS SALA DE ESTAR ------------//
	objects = new normalObject*[TEN_ITEMS];

	nObject0 = new normalObject("bookshelf", livingroomBookshelfText);
	nObject1 = new normalObject("table", livingroomTableText);
	nObject2 = new normalObject("piano", livingroomPianoText);
	nObject3 = new normalObject("birdcage", livingroomBirdcageText);
	nObject4 = new normalObject("TV", livingroomTVText);
	nObject5 = new normalObject("sofas", livingroomSofasText);
	nObject6 = new normalObject("window", livingroomWindowText);
	nObject7 = new normalObject("figure", livingroomFigureText);
	nObject8 = new normalObject("dish", livingroomDishText);
	nObject9 = new normalObject("stick", livingroomStickText);

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

	activeObject **activeObjects;

	activeObject *actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject *actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject *actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	activeObject *actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);

		// lobby
	//activeObjects = (activeObject**)malloc((sizeof(activeObject*)*MAX_ACTIVE_ITEMS_PLACE) + 1);
	activeObjects = new activeObject*[MAX_ACTIVE_ITEMS_PLACE];

	/*actObject0 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject1 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject2 = (activeObject*)malloc(sizeof(activeObject) + 1);
	actObject3 = (activeObject*)malloc(sizeof(activeObject) + 1);*/
	actObject0 = new activeObject("shoes", lobbyShoesText, "commode");
	actObject1 = new activeObject("battery", lobbyBatteryText, "uniform");
	actObject2 = new activeObject("leaflet", lobbyLeafletText, "carpet");
	actObject3 = new activeObject("plant", lobbyPlantText, "flowerpot");

	/*actObject0->setMembers("shoes", lobbyShoesText, "commode");
	actObject1->setMembers("battery", lobbyBatteryText, "uniform");
	actObject2->setMembers("leaflet", lobbyLeafletText, "carpet");
	actObject3->setMembers("plant", lobbyPlantText, "flowerpot");*/

	activeObjects[LOBBY_SHOES] = actObject0;
	activeObjects[LOBBY_BATTERY] = actObject1;
	activeObjects[LOBBY_LEAFLET] = actObject2;
	activeObjects[LOBBY_PLANT] = actObject3;

	placesConfig[LOBBY]->aObjects = activeObjects;


		// garage
	activeObjects = new activeObject*[FOUR_ITEMS];

	actObject0 = new activeObject("tape", garageTapeText, "bike");
	actObject1 = new activeObject("sawdust", garageSawdustText, "workbench");
	actObject2 = new activeObject("lighter", garageLighterText, "car");
	actObject3 = new activeObject("fireworks", garageFireworksText, "shelf");

	activeObjects[GARAGE_TAPE] = actObject0;
	activeObjects[GARAGE_SAWDUST] = actObject1;
	activeObjects[GARAGE_LIGHTER] = actObject2;
	activeObjects[GARAGE_FIREWORKS] = actObject3;

	placesConfig[GARAGE]->aObjects = activeObjects;

		// downstairs corridor (nothing, pero debe inicializarse a null igualmente para la búsqueda)
	/*activeObjects = new activeObject*[0];

	activeObjects[0] = NULL;
	activeObjects[1] = NULL;
	activeObjects[2] = NULL;
	activeObjects[3] = NULL;*/

	placesConfig[DOWNSTAIRS_CORRIDOR]->aObjects = NULL;

		// kitchen
	activeObjects = new activeObject*[FOUR_ITEMS];

	actObject0 = new activeObject("knife", kitchenKnifeText, "tableboard");
	actObject1 = new activeObject("beef", kitchenBeefText, "fridge");
	actObject2 = new activeObject("coffee", kitchenCoffeeText, "worktop");
	actObject3 = new activeObject("water", kitchenWaterText, "fitment");

	activeObjects[KITCHEN_KNIFE] = actObject0;
	activeObjects[KITCHEN_BEEF] = actObject1;
	activeObjects[KITCHEN_COFFEE] = actObject2;
	activeObjects[KITCHEN_WATER] = actObject3;

	placesConfig[KITCHEN]->aObjects = activeObjects;


		// WC
	activeObjects = new activeObject*[FOUR_ITEMS];

	actObject0 = new activeObject("soap", wcSoapText, "shower");
	actObject1 = new activeObject("toothpaste", wcToothpasteText, "sink");
	actObject2 = new activeObject("comb", wcCombText, "furniture");
	actObject3 = new activeObject("perfume", wcPerfumeText, "drawer");

	activeObjects[WC_SOAP] = actObject0;
	activeObjects[WC_TOOTHPASTE] = actObject1;
	activeObjects[WC_COMB] = actObject2;
	activeObjects[WC_PERFUME] = actObject3;

	placesConfig[WC]->aObjects = activeObjects;


		// living room
	activeObjects = new activeObject*[FOUR_ITEMS];

	actObject0 = new activeObject("bible", livingroomBibleText, "bookshelf");
	actObject1 = new activeObject("vase", livingroomVaseText, "table");
	actObject2 = new activeObject("screwdriver", livingroomScrewdriverText, "piano");
	actObject3 = new activeObject("cents", livingroomCentsText, "sofas");

	activeObjects[LIVING_ROOM_BIBLE] = actObject0;
	activeObjects[LIVING_ROOM_VASE] = actObject1;
	activeObjects[LIVING_ROOM_SCREWDRIVER] = actObject2;
	activeObjects[LIVING_ROOM_CENTS] = actObject3;

	placesConfig[LIVING_ROOM]->aObjects = activeObjects;


	//----------------------- NPCs -----------------------//

	placesConfig[LOBBY]->npce = NULL;
	placesConfig[GARAGE]->npce = NULL;
	placesConfig[DOWNSTAIRS_CORRIDOR]->npce = NULL;
	placesConfig[KITCHEN]->npce = NULL;
	placesConfig[WC]->npce = NULL;

	// grampa
	placesConfig[LIVING_ROOM]->npce = new NPC();
	placesConfig[LIVING_ROOM]->npce->initNPC("grampa", LIVING_ROOM, MAX_GRAMPA_DIALOGS, grampaDialog, grampaResponse);

	placesConfig[BASEMENT]->npce = NULL;

	
}


/*normalObject **objects;

if (0 == strcmp(typeObjects, "normal")) WHY NOT? PORQUE EL POLIMORFISMO ES CON PUNTEROS, NO CON DOBLES PUNTEROS
{
objects = placesConfig[player->getCurrentPlace()]->nObjects;
}
else {
objects = placesConfig[player->getCurrentPlace()]->aObjects;
}*/

bool map::searchPlaceActiveItem(char *element)
{
	for (int item = 0; item < activePlace->totalActiveObjects; ++item)
	{
		if (0 == strcmp(element, activePlace->aObjects[item]->getName()))
		{
			printText(activePlace->aObjects[item]->getDescription()[VALID_TEXT]);
			return FOUND;
		}
	}

	return NOT_FOUND;
}


bool map::searchPlaceNormalItem(char *element)
{
	for (int item = 0; item < activePlace->totalNormalObjects; ++item)
	{
		if (0 == strcmp(element, activePlace->nObjects[item]->getName()))
		{
			printText(activePlace->nObjects[item]->getDescription()[VALID_TEXT]);
			return FOUND;
		}
	}

	return NOT_FOUND;
}


void map::setActivePlace(int newPlace)
{
	activePlace = placesConfig[newPlace];
}


placeConfig * map::getActivePlace(void)
{
	return activePlace;
}


placeConfig* map::getPlace(char *placeName)
{
	for (int place = 0; place < TOTAL_PLACES; ++place)
	{
		if (0 == strcmp(placeName, placesConfig[place]->name))
		{
			return placesConfig[place];
		}
	}
}


int map::getNextPlace(char *direction)
{
	for (int nextDirection = 0; nextDirection < activePlace->totalNextPlaces; ++nextDirection) // busco la dirección en el lugar actual
	{
		if ((NULL != activePlace->nextPlaces[nextDirection]) &&
			(0 == strcmp(direction, activePlace->nextPlaces[nextDirection]->direction))) // si existe
		{
			return activePlace->nextPlaces[nextDirection]->nextPlace;
		}
	}

	return PLACE_NOT_FOUND;
}



normalObject* map::getNormalObject(char *element)
{
	for (int item = 0; item < activePlace->totalNormalObjects; ++item)
	{
		if ((NULL != activePlace->nObjects[item]) &&
			(0 == strcmp(element, activePlace->nObjects[item]->getName())))
		{
			return activePlace->nObjects[item];
		}
	}

	return NULL;
}



activeObject* map::getActiveObject(char *element)
{
	for (int item = 0; item < activePlace->totalActiveObjects; ++item)
	{
		if ((NULL != activePlace->aObjects[item]) &&
			(0 == strcmp(element, activePlace->aObjects[item]->getName())))
		{
			return activePlace->aObjects[item];
		}
	}

	return NULL;
}



placeConfig** map::getPlacesConfig(void)
{
	return placesConfig;
}



NPC* map::getNpc(char *npc)
{
	if ((NULL != activePlace->npce) &&
		(0 == strcmp(npc, activePlace->npce->getName())))
	{
		return activePlace->npce;
	}

	return NULL;
}