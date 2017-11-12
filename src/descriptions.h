//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Archivo de cabecera donde guardar todas las macros y declaraciones de textos.
//    
//-----------------------------------------------------------------------------

#ifndef DESCRIPCIONES_H
#define DESCRIPCIONES_H

// includes
#include <stdio.h>
#include <stdlib.h>

// defines genéricos
#define MAX_WORDS_INPUT			4
#define MAX_WORD_SIZE			20
#define MAX_INPUT_SIZE			80
#define MAX_ITEMS_INVENTORY		30
#define MAX_ACTIVE_ITEMS_PLACE	4
#define MAX_NORMAL_ITEMS_PLACE	10
#define MAX_NEXT_PLACES			6
#define MAX_PLACE_EVENTS		10
#define MAX_PLAYER_EVENTS		5

#define TOTAL_OBJECTS			100
#define TOTAL_CRAFTED_OBJECTS	5
#define TOTAL_COMMANDS			9
#define TOTAL_PLACES			7 // piso de abajo 7, finales son 14

#define PLACE_INITIAL_TEXT		0
#define PLACE_DESCRIPTION_TEXT	1

#define OBJECT0					0
#define OBJECT1					1
#define OBJECT2					2
#define OBJECT3					3

#define LEFT					0
#define RIGHT					1
#define FORWARD					2
#define	BACKWARD				3
#define UP						4
#define DOWN					5

// identificadores de orden
#define LOOK_AROUND				0
#define LOOK_AT					1
#define PICK_UP					2
#define GO						3
#define TALK_TO					4
#define USE						5
#define GIVE					6
#define HELP					7
#define INVENTORY				8

// identificadores de habitación
#define LOBBY					0
#define GARAGE					1
#define DOWNSTAIRS_CORRIDOR		2
#define KITCHEN					3
#define WC						4
#define LIVING_ROOM				5
#define BASEMENT				6
#define UPSTARIS_HALL			7 // rellano piso de arriba
#define UPSTAIRS_CORRIDOR		8 // pasillo piso de arriba
#define MAIN_BEDROOM			9
#define TWINS_BEDROOM			10
#define OWN_BEDROOM				11
#define OFFICE					12
#define GARRET					13

// identificadores de objeto normal
#define LOBBY_PICTURE			0
#define LOBBY_PLATE				1
#define LOBBY_PEG				2
#define LOBBY_CARPET			3
#define LOBBY_COMMODE			4
#define LOBBY_STAIRS			5
#define LOBBY_CANDY				6
#define LOBBY_FLOWERPOT			7
#define LOBBY_CLOCK				8
#define LOBBY_COATS				9

#define	GARAGE_CAR				0
#define	GARAGE_SHELF			1
#define	GARAGE_WORKBENCH		2
#define	GARAGE_BOXES			3
#define	GARAGE_CHAINSAW			4
#define	GARAGE_BIKE				5
#define	GARAGE_DOOR				6
#define	GARAGE_ELECTRICAL_LOCK	7
#define GARAGE_SIGNBOARD		8
#define GARAGE_GATE				9

#define DOWNSTAIRS_CORRIDOR_LETTERS		0

#define KITCHEN_TABLEBOARD		0
#define KITCHEN_FRIDGE			1
#define KITCHEN_WORKTOP			2
#define KITCHEN_FITMENT			3
#define KITCHEN_DOORWAY			4
#define KITCHEN_MILK			5
#define KITCHEN_FLOUR			6
#define KITCHEN_EGGS			7
#define KITCHEN_MICROWAVE		8
#define KITCHEN_STOVE			9

#define WC_SHOWER				0
#define WC_SINK					1
#define WC_MIRROR				2
#define WC_TOILET				3
#define WC_FURNITURE			4
#define WC_DRAWER				5
#define WC_PAPER				6
#define WC_ASPIRIN				7
#define WC_BANDAGE				8

#define LIVING_ROOM_BOOKSHELF	0
#define LIVING_ROOM_TABLE		1
#define LIVING_ROOM_PIANO		2
#define LIVING_ROOM_BIRDCAGE	3
#define LIVING_ROOM_TV			4
#define LIVING_ROOM_SOFAS		5
#define LIVING_ROOM_WINDOW		6
#define LIVING_ROOM_FIGURE		7
#define LIVING_ROOM_DISH		8
#define LIVING_ROOM_STICK		9


// identificadores de objeto activo
#define LOBBY_SHOES				0
#define LOBBY_BATTERY			1
#define LOBBY_LEAFLET			2
#define LOBBY_PLANT				3

#define GARAGE_TAPE				0
#define GARAGE_SAWDUST			1
#define GARAGE_LIGHTER			2
#define GARAGE_FIREWORKS		3

#define LIVING_ROOM_BIBLE		0
#define LIVING_ROOM_VASE		1
#define LIVING_ROOM_SCREWDRIVER	2
#define LIVING_ROOM_CENTS		3

#define KITCHEN_KNIFE			0
#define KITCHEN_BEEF			1
#define KITCHEN_COFFEE			2
#define KITCHEN_WATER			3

#define WC_SOAP					0
#define WC_TOOTHPASTE			1
#define WC_COMB					2
#define WC_PERFUME				3


// identificadores de combinación
#define PUT_SHOES				0

// otros
#define LETRA_A					64
#define LETRA_z					123
#define CHARS_PER_LINE			70

#define BAD_INPUT				false
#define GOOD_INPUT				true

#define VALID_TEXT				0
#define AUX_TEXT				1

// texto de ayuda
extern char						*helpText;

// textos de situación
extern char						*welcomeText;
extern char						*contextText;

// textos de error
extern char						*lookAroundErrorText;
extern char						*lookAtErrorText[];
extern char						*pickUpErrorText[];
extern char						*goErrorText[];
extern char						*useErrorText[];

// descripciones de lugar
	// planta baja
extern char						*lobbyText[];
extern char						*downstairsCorridorText[]; // pasillo planta baja
extern char						*garageText[];
extern char						*kitchenText[];
extern char						*bathroomText[];
extern char						*livingRoomText[];

	// sótano
extern char						*basementText[];

	// primera planta
extern char						*upstairsHallText[]; // rellano primer piso
extern char						*upstairsCorridorText[]; // pasillo primer piso
extern char						*mainBedroomText[];
extern char						*twinsBedroomText[];
extern char						*ownBedroomText[];
extern char						*officeText[];

	// desván
extern char						*garretText[];
	




// descripciones de objeto normal

	// recibidor
extern char						*lobbyPictureText[];
extern char						*lobbyPlateText[];
extern char						*lobbyPegText[];
extern char						*lobbyCarpetText[];
extern char						*lobbyCommodeText[];
extern char						*lobbyStairsText[];
extern char						*lobbyCandyText[];
extern char						*lobbyFlowerpotText[];
extern char						*lobbyClockText[];
extern char						*lobbyCoatsText[];

	// garage
extern char						*garageCarText[];
extern char						*garageShelfText[];
extern char						*garageWorkbenchText[];
extern char						*garageBoxesText[];
extern char						*garageChainsawText[];
extern char						*garageBikeText[];
extern char						*garageDoorText[];
extern char						*garageElectricalLockText[];
extern char						*garageSignboardText[];
extern char						*garageGateText[];

	// corridor
extern char						*corridorLettersText[];

	// kitchen
extern char						*kitchenTableboardText[];
extern char						*kitchenFridgeText[];
extern char						*kitchenWorktopText[];
extern char						*kitchenFitmentText[];
extern char						*kitchenDoorwayText[];
extern char						*kitchenMilkText[];
extern char						*kitchenFlourText[];
extern char						*kitchenEggsText[];
extern char						*kitchenMicrowaveText[];
extern char						*kitchenStoveText[];

	// WC
extern char						*wcShowerText[];
extern char						*wcSinkText[];
extern char						*wcMirrorText[];
extern char						*wcToiletText[];
extern char						*wcFurnitureText[];
extern char						*wcDrawerText[];
extern char						*wcPaperText[];
extern char						*wcAspirinText[];
extern char						*wcBandageText[];

	// living room
extern char						*livingroomBookshelfText[];
extern char						*livingroomTableText[];
extern char						*livingroomPianoText[];
extern char						*livingroomBirdcageText[];
extern char						*livingroomTVText[];
extern char						*livingroomSofasText[];
extern char						*livingroomWindowText[];
extern char						*livingroomFigureText[];
extern char						*livingroomDishText[];
extern char						*livingroomStickText[];



// descripciones de objeto activo

	// lobby
extern char						*lobbyShoesText[];
extern char						*lobbyBatteryText[];
extern char						*lobbyLeafletText[];
extern char						*lobbyPlantText[];

	// garage
extern char						*garageTapeText[];
extern char						*garageSawdustText[];
extern char						*garageLighterText[];
extern char						*garageFireworksText[];

	// kitchen
extern char						*kitchenKnifeText[];
extern char						*kitchenBeefText[];
extern char						*kitchenCoffeeText[];
extern char						*kitchenWaterText[];

	// WC
extern char						*wcSoapText[];
extern char						*wcToothpasteText[];
extern char						*wcCombText[];
extern char						*wcPerfumeText[];

	// living room
extern char						*livingroomBibleText[];
extern char						*livingroomVaseText[];
extern char						*livingroomScrewdriverText[];
extern char						*livingroomCentsText[];





// variables globales
	// objetos activos de los lugares
//extern activeObject			*lobbyActiveObjects[];
//extern activeObject			*garageActiveObjects[];

// lista que usa el parser para guardar el input
extern char						*textWords[];

// órdenes que existen en el juego
extern char						*possibleCommands[];

// posibles direcciones que	se contemplan en las
// diversas zonas del juego
//extern char					*possibleDirections[];

// posibles lugares del juego
//extern char					*possiblePlaces[];

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------