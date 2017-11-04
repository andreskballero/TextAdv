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

char*				contextText = "You are Murray McMurray, squishy 667-year-old skeleton who loves low-sugar soda and Craig Ferguson's "\
									"Late Late Show.\nToday is Davy's birthday party, Murray's ol' friendo, and it's going to be a huge "\
									"event.\n\nWhat could go wrong?\nWell, something. Obviously.\n\nApparently, Mom & Dad McMurray has "\
									"left the house for a while and he has locked all the doors and Taken with him all the house keys.\n\n"\
									"Why, you say? That's the twin sisters fault.\n\nYep, Murray has two twin sisters, and they are the "\
									"living hell. They love cooking brain cake, and in order to do so, they enjoy very much hunting bums "\
									"when Dad isn't at home. Last week, Dad found some blood on the kitchen's floor, and now he is suspicious, "\
									"and he feels bad for the hobos, so... since that moment, whenever he isn't at home, he takes the keys with "\
									"him and locks up every possible way out.\n\nAnd now he's not at home.\n\nYou see the problem, right?\n\n"\
									"...\n\nMurray needs to attend the party!\n\nAnd YOU are MURRAY!\n\nHey! Stop! Hold your horses! Mom once "\
									"told you they keep another keys in the house, just in case something happens. So, finding those keys seems "\
									"like a good idea.\n\nThe party is in an hour, HURRY UP! You are not going to achieve anything there, "\
									"in the lobby, gazing at the door.\n\nC'MON, FETCH!";




char*				lobbyText[] = { "I'm in the lobby.",
									"There is a red woolen carpet on the floor, Mommy's favourite piece of fabric in "\
									"the house. She says it's worthy of the Oscars. On my right there is the garage door, and just beside it, " \
									"the stairs to the next floor. Just in front of me rests a nice wooden commode. "\
									"On the left side, the door to the corridor and, hung on the wall, a picture and a golden commemorative plate. " };

char*				downstairsCorridorText[] = {"I'm in the corridor next to the lobby.",
												"I've never liked this corridor, it reminds me of the one from \"The Shining\", and I don't know why, there "\
												"is no resemblance. Lots of framed letters from Mommy's fans hung on both sides since I can remember. I've "\
												"never counted them, but there must be hundreds. The kitchen is on the right side, the bathroom on the left, "\
												"the living room at the end." };

char*				garageText[] = { "I'm in the garage.", 
									"This garage looks exactly like the one from \"The Simpsons\". Here's the car. Mom and Dad have probably taken "\
									"the bus, they are very concerned about pollution lately. There is a large shelf full of stuff on the door's  "\
									"opposite wall. On the right, the garage door, and the left belongs to the basement door. That place creeps the "\
									"hell out of me. Dad doesn't allow anyone to go down there, he keeps the place electronically locked. Why?" };

char*				kitchenText[] = { "I'm in the kitchen.", 
										"The twins' favourite place in the whole house, I can easily guess why. There is a big white table in the middle."\
										"On the right side stands the biggest fridge ever. I love it. On the front wall, the worktop, full of housewares."\
										"The left wall has another worktop, where the electrical appliances are placed, and, by its side, a door to the "\
										"garden with a screen door, for the dog." };

char*				bathroomText[] = { "I'm in the WC.", 
										"Nice and simple. A shower plate on the right, the sink and a big mirror, and the toilet "\
										"on the left side, beside a tall, narrow piece of furniture where we keep our hygiene... things." };

char*				livingRoomText[] = { "I'm in the living room.",
										"This living room is way too big for a 5-member family, a dog and a parrot. On the left side there's "\
										"a big bookshelf behind the dining table, the next wall holds a big piano and Gwaihir's birdcage, and, "\
										"on right side, the worst TV in the world. The On/Off button is broken and it has been on for ages. And "\
										"last, but not least, two sofas pointing to the TV and a small table in between occupy the centre of "\
										"the room." };

char*				basementText[] = { "I'm in the basement.", "Nothing yet." };


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


char*				guyPictureText = "kepassssa";


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

// en estas tres es importante que el orden coincida con el valor de sus macros, todo está organizado para corresponder
char*				possibleCommands[] = {"look around", "look at", "pick up", "go", "talk to", "use", "give", "help"};

char*				possibleDirections[] = {"left", "right", "forward", "backward", "up", "down"};

char*				possiblePlaces[] = { "lobby", "garage", "downstairs corridor", "kitchen", "WC", "living room", "basement" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------