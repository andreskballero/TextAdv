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
								"- look at <sth>\n"\
								"- pick up <sth>\n"\
								"- go <left/right/forward/backward/up/down>\n"\
								"- talk to <sbd>\n"\
								"- use <sth> [with <sth>]\n"\
								"- give <sth> to <sbd>\n"\
								"\n\nApart from that, these things must be taken into consideration:\n\n"
								"- Capital letters are not to be used in any word\n"\
								"- The command must always be the first word\n"\
								"- No spaces are allowed before the command\n"\
								"- Only up to 4 words are expected to be part of the input\n"\
								"- Except for \"look around\", which can be casted independently, every command must be followed by a statement\n"\
								"- The statements are for the player to guess, obviously\n"\
								"- Did you think the game was going to be that easy?\n";

char*				welcomeText = "Welcome to \"Skeleton Escape\".\n\n"\
									"This is just a personal project. If you stumble upon "\
									"any error, please, contact the programmer: you surely know who he is.\n\n"\
									"Okey, let's get to it.\n\n"\
									"Oh, yeah. I almost forgot. This is, you know, too good to leave it to the scavengers, so...\n\n"\
									"\tCopyright (c) Andres.\n\n"\
									"Now it's safe. Phew.";

char*				contextText = "You are Murray McMurray, a scrawny 667-year-old skeleton who loves low-sugar soda and Craig Ferguson's "\
									"Late Late Show.\nToday is Davy's birthday party, Murray's ol' friendo, and it's going to be huuuuge."\
									"\n\nWhat could go wrong?\nWell, something. Obviously.\n\nApparently, Mom & Dad McMurray have "\
									"left the house for a while and Dad has locked all the doors and taken with him all the house keys.\n\n"\
									"Why, you say? That's the twin sisters fault.\n\nYep, Murray has two twin sisters, and they are the "\
									"living hell. They love cooking brain cake, and in order to do so, they enjoy very much hunting bums "\
									"when Dad isn't at home. Last week, Dad found some blood on the kitchen's floor, and now he is suspicious, "\
									"and he wants to unveil the truth, so... until then, whenever he isn't at home, he takes the keys with "\
									"him and locks up every possible way out.\n\nAnd now he's not at home.\n\nYou see the problem, right?\n\n"\
									"...\n\nMurray needs to attend the party!\n\nAnd YOU are MURRAY!\n\nHey! Stop! Hold your horses! Mom once "\
									"told you they keep another keys in the house, just in case something happens. However, she didn't tell you where "
									"those keys are. So, finding them seems like a good idea.\n\nThe party is in an hour, HURRY UP! You are "\
									"not going to achieve anything there, in the lobby, gazing at the stairs.\n\nC'MON, FETCH!";




char*				lobbyText[] = { "I'm in the lobby.",
									"There is a red woolen carpet on the floor, Mommy's favourite piece of fabric in "\
									"the house. She says it's worthy of the Oscars. On my right there is the garage door, and just beside it, " \
									"the stairs to the next floor. Just in front of me rests a nice wooden commode. By the garage door, there's a peg. "\
									"On the left side, the door to the corridor and, hung on the wall, a picture and a golden commemorative plate. " };

char*				downstairsCorridorText[] = {"I'm in the corridor next to the lobby.",
												"I've never liked this corridor, it reminds me of the one from \"The Shining\", and I don't know why, there "\
												"is no resemblance. Lots of framed letters from Mommy's fans hung on both sides since I can remember. I've "\
												"never counted them, but there must be hundreds. The kitchen is on the right side, the bathroom on the left, "\
												"the living room at the end." };

char*				garageText[] = { "I'm in the garage.", 
									"This garage looks exactly like the one from \"The Simpsons\". Here's the car. Mom and Dad have probably taken "\
									"the bus, they are very concerned about pollution lately. There is a large shelf full of stuff and a workbench "\
									"on the door's opposite wall. On the right, the garage door, and the left belongs to the basement door. That place "\
									"creeps the hell out of me. Dad doesn't allow anyone to go down there, he keeps the place electronically locked. Why?" };

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
										"last, but not least, two sofas pointing to the TV and, behind the TV a big window to the garden." };

char*				basementText[] = { "I'm in the basement.", "Nothing yet." };


char*				upstairsHallText[]; // rellano primer piso
char*				upstairsCorridorText[]; // pasillo primer piso
char*				mainBedroomText[];
char*				twinsBedroomText[];
char*				ownBedroomText[];
char*				officeText[];


char*				garretText[];

// objetos normales que no se pueden coger

	// lobby

char*				lobbyPictureText[] = { { "A pirate in an epic stance appears in this picture. \"The mightiest pirate\" can be read carved in "\
											"the bottom of the wooden frame. Dad loves this Guy, I can't understand why." }, 
											{NULL} };

char*				lobbyPlateText[] = { { "This plate was given to Mom when she won that dumb hot-dog eating contest. She ate 89 hot-dogs in 5 "\
											"minutes and didn't even blink once. She's a beast, I thought she wasn't going to make it after that, "\
											"but she did, and the price money encouraged her to found that profitable company of hers: \"Electronical "\
											"Locks Inc.\"" },
											{ NULL } } ;

char*				lobbyPegText[] = { { "Dad's DIY uniform hangs there. He loves assembling up odd plastic sculptures, and he must protect himself "\
										"to do that. I've seen him making those, but never seen one around. I wonder where he stores them." },{ NULL } } ;

char*				lobbyCarpetText[] = { {"According to Mom, the best carpet in the world, although it seems quite normal to me. It used to be "
											"green, but carrying fresh cakes upstairs has consequences. When it started changing colour, Mom thought "\
											"it was a miracle and converted to Christianism... *sigh*" },
											{ NULL } } ;

char*				lobbyCommodeText[] = { { "It has some candy on top, for the guests. We keep our shoes in the lower part. Jeez, I wonder how 76 pairs "
											"of shoes fit in 1 square meter. I have a pair, Dad has two. The rest? Do the math. Women tricks." },
											{ NULL } };

char*				lobbyStairsText[] = { { "The stairs to the next floor." },
											{ NULL } } ;

	// corridor

char*				corridorLettersText[] = { { "Hundreds of letters from Mom's fans cover the walls! But they aren't what one could expect from fan letters. "\
												"I think they are a reminder of the time when Elelock Inc. Mom's company, had to overcome a difficult period, "\
												"having disappointed the customers with a non-waterproof door lock and needing to make it up for them with a new, "\
												"safer version of it. She likes to keep them around, and they taught me lots of bad language when I was a kid." },
												{ NULL } } ;

	// living room
char*					livingroomBookshelfText[] = { {"I've read every one of those books but two... The Bible and that stupid Necronomi-don't-know-what-else "\
														"gets on my nerves. And everybody has read it, why should I bother doing the same?" }, 
														{ "I've read every one of those books but one... That stupid Necronomi-don't-know-what-else "\
														"gets on my nerves. And everybody has read it, why should I bother doing the same?" } };


char*					livingroomTableText[] = { { "King Size Homer would be able to lie down on this table and it would still be room for the rest of Springfield. "\
													"But there's only a cracked vase on it. Such a wasted space." }, 
													{ "King Size Homer would be able to lie down on this table and it would still be room for the rest of Springfield. "\
													"But there's nothing on it. Such a wasted space." } };

char*					livingroomPianoText[] = { { "Just a grand piano. I wish my parents had made me take piano classes when I was a kid. I love how it sounds when "\
													"the twins play it together. What's a screwdriver doing on top of it?" }, 
													{ "Just a grand piano. I wish my parents had made me take piano classes when I was a kid. I love how it sounds when	"\
													"the twins play it together." } };

char*					livingroomBirdcageText[] = { { "Bigger than my room. This miserable parrot lives in better coniditions than me." }, 
													{NULL} };

char*					livingroomTVText[] = { { "The good ol' Grampa's WWII TV. It's always on playing that disgusting telemarketing channel. I mean, this ad? What the "\
												"hell? Who believes that a strip of duct tape can resist water and remain glued?" },
												{NULL} };

char*					livingroomSofasText[] = { {"A comfy pair of sofas for 3-hour naps. From the fourth hour on, the back starts hurting. Look! Two cents. They probably "
													"slipped out of my pocket while sleeping." }, { "A comfy pair of sofas for 3-hour naps. From the fourth hour on, the back starts hurting." } };

char*					livingroomWindowText[] = { { "The garden can be seen through the window. In fact, nothing can be seen through the window. We should mow the lawn "\
													"from time to time." }, 
													{NULL} };






//activeObject*		lobbyActiveObjects[MAX_ACTIVE_ITEMS_PLACE];
//activeObject*		garageActiveObjects[MAX_ACTIVE_ITEMS_PLACE];

// lugares del juego

// hecho con array dinámico para poder eliminar con el delete los objetos
// contenidos reservados de forma dinámica
// está bien hacer esto aquí?
//activeObject*		objectStack[TOTAL_OBJECTS];
// acuérdate de delete[] objectStack;

// input recibido, 4 palabras a lo sumo
char*				textWords[MAX_WORDS_INPUT];

// en estas tres es importante que el orden coincida con el valor de sus macros, todo está organizado para corresponder
char*				possibleCommands[] = {"look around", "look at", "pick up", "go", "talk to", "use", "give", "help", "inventory"};

//char*				possibleDirections[] = {"left", "right", "forward", "backward", "up", "down"};

//char*				possiblePlaces[] = { "lobby", "garage", "downstairs corridor", "kitchen", "WC", "living room", "basement" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------