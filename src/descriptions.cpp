//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Archivo donde guardar todas las macros y definiciones de textos.
//    
//-----------------------------------------------------------------------------
#include "descriptions.h"


char*					helpText = "GAME, SEND ME HELP!\n\n"\
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

char*					welcomeText = "Welcome to \"Skeleton Escape\".\n\n"\
										"This is just a personal project. If you stumble upon "\
										"any error, please, contact the programmer: you surely know who he is.\n\n"\
										"Okey, let's get to it.\n\n"\
										"Oh, yeah. I almost forgot. This is, you know, too good to leave it to the scavengers, so...\n\n"\
										"\tCopyright (c) Andres.\n\n"\
										"Now it's safe. Phew.";

char*					contextText = "You are Murray McMurray, a young scrawny skeleton who loves low-sugar soda and Craig Ferguson's "\
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



char*					lookAroundErrorText = "Look around what ? Just look around!";
char*					lookAtErrorText[] = { {"I can't see that."}, {"I don't think that exists here."}, {"We don't have anything like that."} };
char*					pickUpErrorText[] = { {"I can't pick that up."}, {"No way."}, {"Did you type that right?"} };
char*					goErrorText[] = { { "I'm not going through a wall, sorry." }, { "Floors are to walk on, not to go through." } , { "Can't jump through the ceiling... Yet." } };



char*					lobbyText[] = { "I'm in the lobby.",
										"There is a red woolen carpet on the floor, Mommy's favourite piece of fabric in "\
										"the house. She says it's worthy of the Oscars. On my right there is the garage door, and just beside it, " \
										"the stairs to the next floor. Just in front of me rests a nice wooden commode. By the garage door, there's a peg. "\
										"On the left side, the door to the corridor and, hung on the wall, a picture and a golden commemorative plate. " };

char*					downstairsCorridorText[] = {"I'm in the corridor next to the lobby.",
													"I've never liked this corridor, it reminds me of the one from \"The Shining\", and I don't know why, there "\
													"is no resemblance. Lots of framed letters from Mommy's fans hung on both sides since I can remember. I've "\
													"never counted them, but there must be hundreds. The kitchen is on the right side, the bathroom on the left, "\
													"the living room at the end." };

char*					garageText[] = { "I'm in the garage.", 
										"This garage looks exactly like the one from \"The Simpsons\". Here's the car. Mom and Dad have probably taken "\
										"the bus, they are very concerned about pollution lately. There is a large shelf full of stuff and a workbench "\
										"on the door's opposite wall. On the right, the garage door, and the left belongs to the basement door. That place "\
										"creeps the hell out of me. Dad doesn't allow anyone to go down there, he keeps the place electronically locked. Why?" };

char*					kitchenText[] = { "I'm in the kitchen.", 
											"The twins' favourite place in the whole house, I can easily guess why. There is a big white tableboard in the middle."\
											"On the right side stands the biggest fridge ever. I love it. On the front wall, the worktop, full of housewares."\
											"The left wall has a fitment, where the electrical appliances are placed, and, by its side, a doorway to the "\
											"garden with a screen dog door, for the... yes, dog." };

char*					bathroomText[] = { "I'm in the WC.", 
											"Nice and simple. A shower plate on the right, the sink and a big mirror, and the toilet "\
											"on the left side, beside a tall, narrow piece of furniture where we keep our hygiene... things." };

char*					livingRoomText[] = { "I'm in the living room.",
											"This living room is way too big for a 5-member family, a dog and a parrot. On the left side there's "\
											"a big bookshelf behind the dining table, the next wall holds a big piano and Gwaihir's birdcage, and, "\
											"on right side, the worst TV in the world. The On/Off button is broken and it has been on for ages. And "\
											"last, but not least, two sofas pointing to the TV and, behind the TV a big window to the garden." };

char*					basementText[] = { "I'm in the basement.", "Nothing yet." };


char*					upstairsHallText[]; // rellano primer piso
char*					upstairsCorridorText[]; // pasillo primer piso
char*					mainBedroomText[];
char*					twinsBedroomText[];
char*					ownBedroomText[];
char*					officeText[];


char*					garretText[];

// objetos normales	que no se pueden coger

	// lobby

char*					lobbyPictureText[] = { { "A pirate in an epic stance appears in this picture. \"The mightiest pirate\" can be read carved in "\
												"the bottom of the wooden frame. Dad loves this Guy, who is he?" }, 
												{NULL} };

char*					lobbyPlateText[] = { { "This plate was given to Mom when she won that dumb hot-dog eating contest. She ate 89 hot-dogs in 5 "\
												"minutes and didn't even blink once. She's a beast, I thought she wasn't going to make it after that, "\
												"but she did, and the price money encouraged her to found that profitable company of hers: \"Electronical "\
												"Locks Inc.\"" },
												{ NULL } } ;

char*					lobbyPegText[] = { { "A couple of coats and Dad's DIY uniform hangs there. It has a battery inside the left pocket. He loves "\
											"assembling up odd plastic sculptures, and he must protect himself to do that. I've seen him making those, "\
											"but never seen one around. I wonder where he stores them." },
											{ "A couple of coats and Dad's DIY uniform hangs there. He loves "\
												"assembling up odd plastic sculptures, and he must protect himself to do that. I've seen him making those, "\
												"but never seen one around. I wonder where he stores them." } } ;

char*					lobbyCarpetText[] = { {"According to Mom, the best carpet in the world, although it seems quite normal to me. It used to be "\
												"green, but carrying fresh cakes upstairs has consequences. When it started changing colour, Mom thought "\
												"it was a miracle and converted to Christianism... *sigh* Is that a leaflet peeking from beneath?" },
												{ "According to Mom, the best carpet in the world, although it seems quite normal to me. It used to be "\
													"green, but carrying fresh cakes upstairs has consequences. When it started changing colour, Mom thought "\
													"it was a miracle and converted to Christianism... *sigh*" } } ;

char*					lobbyCommodeText[] = { { "It has some candy on top, for the guests, a flowerpot, for the sake of the lobby appearance, and a clock 10 "\
												"minutes ahead, for the people who wait for us. We keep our shoes in the lower part. Jeez, I wonder how tall "\
												"are these pair of shoes. How can women wear heels?" },
												{ "It has some candy on top, for the guests, a flowerpot, for the sake of the lobby appearance, and a clock 10 "\
													"minutes ahead, for the people who wait for us. We keep our shoes in the lower part."} };

char*					lobbyStairsText[] = { { "The stairs to the next floor." },
												{ NULL } } ;

char*					lobbyCandyText[] = { { "Dentists love candy." },
											{ NULL } };
char*					lobbyFlowerpotText[] = { { "Until the twins brough this home, I thoroughly believed carnivorous plants ate people." },
												{ "I 've taken the plant with me." } };
char*					lobbyClockText[] = { { "God, now it's quiet, but, during the night, this is noisier than a bulldozer." },
											{ NULL } };
char*					lobbyCoatsText[] = { { "Yellow coats, you know, for the cold." },
											{ NULL } };

	// corridor

char*					corridorLettersText[] = { { "Hundreds of letters from Mom's fans cover the walls! But they aren't what one could expect from fan letters. "\
													"I think they are a reminder of the time when Elelock Inc. Mom's company, had to overcome a difficult period, "\
													"having disappointed the customers with a non-waterproof door lock and needing to make it up for them with a new, "\
													"safer version of it. She likes to keep them around, and they taught me lots of bad language when I was a kid." },
													{ NULL } } ;


	// kitchen
char*					kitchenTableboardText[] = { {"The knife on top is so sharp. I can picture beheaded hobos laying here, I swear."},
													{ "I can picture beheaded hobos laying here, I swear." } };
char*					kitchenFridgeText[] = { { "We should go to the groceries. There's only beef, milk and eggs. Beh, if I'm hungry I can ask Coca and Cola for a "\
												"piece of cake." },{ "We should go to the groceries. There's only milk and eggs. Beh, if I'm hungry I can ask Coca "
												"and Cola for a piece of cake." } };
char*					kitchenWorktopText[] = { { "Here is where Mom cooks... and the twins too. Someone has poured coffee here and hasn't even bothered in cleaning it." },
												{ "Here is where Mom cooks... and the twins too." } };
char*					kitchenFitmentText[] = { { "Here's the microwave and the magic it contains. How does it work? I wasn't paying attention in school the day that was "\
													"explained. Well, the thing next to it I can surely explain. I love you, bottle of water."},
													{ "Here's the microwave and the magic it contains. How does it work? I wasn't paying attention in school the day that was explained." } };
char*					kitchenDoorwayText[] = { { "It has a nice mini screen door at the bottom. Fang uses it to go out to the garden." },{ NULL } };
char*					kitchenMilkText[] = { { "No animal should drink another species' milk. It's unnatural." },{ NULL } };
char*					kitchenFlourText[] = { { "Making cakes leaves footprints, sisters. More, I mean." },{ NULL } };
char*					kitchenEggsText[] = { { "How can stomach holders eat something that pops out of a hen's hole?" },{ NULL } };
char*					kitchenMicrowaveText[] = { { "I remember Mom warming milk up in the stewpan when this thing didn't exist." },{ NULL } };
char*					kitchenStoveText[] = { { "Touching this is forbidden to me. Dad says I'm so dumb I could set the house on fire without even turning it on." },{ NULL } };

	// living room
char*					livingroomBookshelfText[] = { {"I've read every one of those books but two... The Bible and that stupid Necronomi-don't-know-what-else "\
														"gets on my nerves. And everybody has read it, why should I bother doing the same? Oh, and that strange "\
														"voodoo figure Grampa likes so much. It emits power waves, I can sense them. Nah, just kidding."}, 
														{ "I've read every one of those books but one... That stupid Necronomi-don't-know-what-else "\
														"gets on my nerves. And everybody has read it, why should I bother doing the same? Oh, and that strange "\
														"voodoo figure Grampa likes so much. It emits power waves, I can sense them. Nah, just kidding." } };


char*					livingroomTableText[] = { { "King Size Homer would be able to lie down on this table and it would still be room for the rest of Springfield. "\
													"But there are only a cracked vase and a decor dish on it. Such a wasted space." }, 
													{ "King Size Homer would be able to lie down on this table and it would still be room for the rest of Springfield. "\
													"But there's only a decor dish on it. Such a wasted space." } };

char*					livingroomPianoText[] = { { "Just a grand piano. I wish my parents had made me take piano classes when I was a kid. I love how it sounds when "\
													"the twins play it together. What's a screwdriver doing on top of it?" }, 
													{ "Just a grand piano. I wish my parents had made me take piano classes when I was a kid. I love how it sounds when	"\
													"the twins play it together." } };

char*					livingroomBirdcageText[] = { { "Bigger than my room. This miserable parrot lives in better coniditions than me. There's a stick on the bottom." }, 
													{NULL} };

char*					livingroomTVText[] = { { "The good ol' Grampa's WWII TV. It's always on playing that disgusting telemarketing channel. I mean, this ad? What the "\
												"hell? Who believes that a strip of duct tape can resist water and remain glued?" },
												{NULL} };

char*					livingroomSofasText[] = { {"A comfy pair of sofas for 3-hour naps. From the fourth hour on, the back starts hurting. Look! Two cents. They probably "
													"slipped out of my pocket while sleeping." }, { "A comfy pair of sofas for 3-hour naps. From the fourth hour on, the back starts hurting." } };

char*					livingroomWindowText[] = { { "The garden can be seen through the window. In fact, nothing can be seen through the window. We should mow the lawn "\
													"from time to time." }, 
													{NULL} };

char*					livingroomFigureText[] = { {"A big chubby woman representing... Gaia? It's weird, I can feel something... I think I need to take a WC-break."}, 
													{NULL} };
char*					livingroomDishText[] = { {"It reads: \"Recuerdo de Cuenca\". This is something Granma brought from her trip around Spain."},
													{NULL} };
char*					livingroomStickText[] = { {"It's covered in... GWAIHIR! You dirty fowl."},
													{NULL} };



// objetos activos
	
	//lobby
char*					lobbyShoesText[] = { { "My god. The Heels. They're so tall." },
												{ NULL } };
char*					lobbyBatteryText[] = { { "Is this one of those old batteries? I hadn't seen one yet. How do you charge this antique cylinder?" },
												{ NULL } };
char*					lobbyLeafletText[] = { { "The recipee for making a... bomb? I should talk to Dad, he might be planning world domination and I want to take part. "\
												"I NEED WHAT?" },
												{ NULL } };
char*					lobbyPlantText[] = { { "It seems hungry." },
												{ NULL } };

	//downstairscorridor (nada)
	
	// kitchen
char*					kitchenKnifeText[] = { { "I could cut everything with it. Well, not everything I suppose." },
												{ NULL } };
char*					kitchenBeefText[] = { { "It looks nearly rotten, no skeleton or human would eat this." },
												{ NULL } };
char*					kitchenCoffeeText[] = { { "It stinks." },
												{ NULL } };
char*					kitchenWaterText[] = { { "I wish I could drink it. It's hard without a stomach." },
												{ NULL } };

	//living room
char*					livingroomBibleText[] = { { "This bible seems to be hollow. Wow, a booze flask. Someone's hitting it hard and it's not me. I hope." },
												{NULL} };
char*					livingroomVaseText[] = { { "So transparent. So broken. This vase has a tiny crack on its side." },
												{ NULL } };
char*					livingroomScrewdriverText[] = { { "There was a time when I thought this was something every man has." },
												{ NULL } };
char*					livingroomCentsText[] = { { "I'm rich!" },
												{ NULL } };



//activeObject*		lobbyActiveObjects[MAX_ACTIVE_ITEMS_PLACE];
//activeObject*		garageActiveObjects[MAX_ACTIVE_ITEMS_PLACE];

// lugares del juego

// hecho con array din�mico para poder eliminar con el delete los objetos
// contenidos reservados de forma din�mica
// est� bien hacer esto aqu�?
//activeObject*		objectStack[TOTAL_OBJECTS];
// acu�rdate de delete[] objectStack;

// input recibido, 4 palabras a lo sumo
char*				textWords[MAX_WORDS_INPUT];

// en estas tres es importante que el orden coincida con el valor de sus macros, todo est� organizado para corresponder
char*				possibleCommands[] = {"look around", "look at", "pick up", "go", "talk to", "use", "give", "help", "inventory"};

//char*				possibleDirections[] = {"left", "right", "forward", "backward", "up", "down"};

//char*				possiblePlaces[] = { "lobby", "garage", "downstairs corridor", "kitchen", "WC", "living room", "basement" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------