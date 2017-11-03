//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Archivo donde guardar todas las macros y definiciones de textos.
//    
//-----------------------------------------------------------------------------
#include "descriptions.h"


char*				helpText = "GAME, SEND ME HELP!\n\n"\
								"There you go, my beautiful player.\n\n"\
								"There are 7 commands available. Anything different command typed "
								"is not even considered. The commands are:\n"\
								"- look around\n"\
								"- look at\n"\
								"- pick up\n"\
								"- go to\n"\
								"- talk to\n"\
								"- use\n"\
								"- give\n"\
								"\n\nApart from that, these things must be taken into consideration:\n\n"
								"- Capital letters are not to be used in any word\n"\
								"- The command must always be the first word\n"\
								"- No spaces are allowed before the command\n"\
								"- Only up to 4 words are expected to be part of the input\n"\
								"- Except for \"look around\", which can be casted independently, every command must be followed by a statement\n"\
								"- The statements are for the player to guess, obviously\n"\
								"- Did you think the game was going to be that easy?\n";

char*				welcomeText = "Welcome to \"Skeleton escape\".\n\n"\
									"This is just a personal project. If you stumble upon "\
									"any error, please, contact the programmer: you surely know who he is.\n\n"\
									"Okey, let's get to it.\n\n"\
									"Oh, yeah. I almost forgot. This is, you know, too good to leave it to the scavengers, so...\n\n"\
									"\tCopyright (c) Andres.\n\n"\
									"Now it's safe. Go.";

char*				contextText = "You are Murray McMurray, squishy 667-year-old skeleton who loves "\
									"low-sugar soda and Craig Ferguson's Late Late Show.\nToday is Davy's "\
									"birthday party, Murray's ol' friendo, and it's going to be a huge event.\n\n"\
									"What could go wrong?\n"\
									"Well, something. Obviously.\n\n"\
									"Apparently, Mom & Dad McMurray has left the house for a while and he has locked all the doors and "
									"taken with him all the house keys.\n\n"\
									"Why, you say? That's the twin sisters fault.\n\nYep, Murray has two twin sisters, "\
									"and they are the living hell. They love cooking brain cake, and in order "\
									"to do so, they enjoy very much hunting bums when Dad isn't home. Last week, "
									"Dad found some blood on the kitchen's floor, and now he is suspicious, "
									"and he feels bad for the hobos, so... since that moment, whenever he isn't home, he takes the "
									"keys with him and locks up every possible way out.\n\n"\
									"And now he's not home.\n\n"\
									"You see the problem, right?\n\n"\
									"...\n\n"\
									"Murray needs to go!\n\n"\
									"And YOU are MURRAY!\n\n"\
									"Hey! Stop! Hold your horses! Mom once told you they keep another keys "\
									"in the house, just in case something happens. So, finding those keys seems like a good idea.\n\n"\
									"The party is in an hour, HURRY UP! You are not going to achieve anything there, "\
									"in the lobby, gazing at the door.\n\nC'MON, FETCH!";




char*				lobbyText[] = { "Estoy en el recibidor.",
									"El recibidor es asi.\n\n" \
									"A la izquierda hay un pasillo, a la derecha el garaje, y las escaleras " \
									"llevan al piso de arriba." };

char*				downstairsCorridorText[] = {"Estoy en el pasillo del piso de abajo.", "El pasillo es recto, " \
											"como suelen ser los pasillos."};
char*				garageText[] = { "Estoy en el garaje de la casa.", "Menudo Ferrari tienen." };
char*				kitchenText[] = { "Estoy en la cocina.", "Es una cocina cálida, pero la de " \
										"mi abuela era mucho mejor."};
char*				bathroomText[] = { "Estoy en el WC.", "Es un " \
										"cuarto de bano pequeno. No sé cómo se las arreglan." };
char*				livingRoomText[] = { "Estoy en la sala de estar" /*"n espacioso salón comedor."*/, "En este salón se " \
										"podría celebrar una comida estupenda."};


char*				basementText[] = { "Estoy en el sotano", "" };


char*				upstairsHallText[]; // rellano primer piso
char*				upstairsCorridorText[]; // pasillo primer piso
char*				mainBedroomText[];
char*				twinsBedroomText[];
char*				ownBedroomText[];
char*				officeText[];


char*				garretText[];




char*				basketText = "Es un bonito cesto de mimbre.";
char*				basketName = "un cesto";
char*				fampicText = "Es una bonita foto de familia.";
char*				fampicName = "una foto de familia";
char*				mirrorText = "Es un espejo.";
char*				mirrorName = "un espejo";
char*				stairsupText = "Son las escaleras para subir a la primera planta.";
char*				stairsupName = "unas escaleras hacia arriba";


activeObject*		lobbyActiveObjects[MAX_ACTIVE_ITEMS_PLACE];
activeObject*		garageActiveObjects[MAX_ACTIVE_ITEMS_PLACE];

// lugares del juego

// hecho con array dinámico para poder eliminar con el delete los objetos
// contenidos reservados de forma dinámica
// está bien hacer esto aquí?
activeObject*		objectStack[TOTAL_OBJECTS];
// acuérdate de delete[] objectStack;

// input recibido, 4 palabras a lo sumo
char*				textWords[MAX_WORDS_INPUT];

char*				possibleCommands[] = {"look around", "look at", "pick up", "go", "talk to", "use", "give", "help"};

char*				possibleDirections[] = {"left", "right", "forward", "backward", "up", "down"};

char*				possiblePlaces[] = { "lobby", "garage", "downstairs corridor", "kitchen", "WC", "living room", "basement" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------