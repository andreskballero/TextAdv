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


char					*helpText = "GAME, SEND ME HELP!\n\n"\
									"There you go, beautiful player.\n\n"\
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

char					*welcomeText = "Welcome to \"Skeleton Escape\".\n\n"\
										"This is just a personal project. If you stumble upon "\
										"any error, please, contact the programmer: you surely know who he is.\n\n"\
										"Okey, let's get to it.\n\n"\
										"Oh, yeah. I almost forgot. This is, you know, too good to leave it to the scavengers, so...\n\n"\
										"\tCopyright (c) Andres.\n\n"\
										"Now it's safe. Phew.";

char					*contextText = "You are Murray McMurray, a young scrawny skeleton who loves low-sugar soda and Craig Ferguson's "\
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



char					*lookAroundErrorText = "Look around what?";
char					*lookAtErrorText[] = { {"There's no such thing here."}, {"We don't have anything like that."} };
char					*pickUpErrorText[] = { {"There is no such thing in the room."}, {"I can't pick that up."} };
char					*goErrorText[] = { {"I'm not going through a wall, sorry."}, {"Floors are to walk on, not to go through."} , {"Can't jump through the ceiling... Yet."} ,
											{"I can't enter yet."} };
char					*useErrorText[] = { { "I don't have that." },{ "Either I don't have the object or there is no such thing in the room." },
											{ "I've already used that." }, {"I have no use for that."} };
char					*useActivesErrorText[] = { { "I'm not sure about that." },{ "That won't result in anything useful." } };
char					*useReactionErrorText[] = { { "That won't work." },{ "Nope." } };
char					*talkToErrorText[] = { {"There's no one here."}, {"That person isn't here."} };
char					*lockedPlaces[] = { {"The basement is locked. I have to find some way to open or disable this electrical lock."}, {"Garreeeettttt!"} };




char					*lobbyText[] = { "I'm in the lobby.",
										"There is a red woolen carpet on the floor, Mommy's favourite piece of fabric in "\
										"the house. She says it's worthy of the Oscars. On my right there is the garage door, and just beside it, " \
										"the stairs to the next floor. Just in front of me rests a nice wooden commode. By the garage door, there's a peg. "\
										"On the left side, the door to the corridor and, hung on the wall, a picture and a golden commemorative plate. " };

char					*downstairsCorridorText[] = {"I'm in the corridor next to the lobby.",
													"I've never liked this corridor, it reminds me of the one from \"The Shining\", and I don't know why, there "\
													"is no resemblance. Lots of framed letters from Mommy's fans hung on both sides since I can remember. I've "\
													"never counted them, but there must be hundreds. The kitchen is on the right side, the bathroom on the left, "\
													"the living room at the end." };

char					*garageText[] = { "I'm in the garage.",
										"This garage looks almost like the one from \"The Simpsons\". Here's the car and that supid signboard. There is a "\
										"large shelf and a workbench on the door's opposite wall. On the right, the garage gate, and the left "\
										"belongs to the basement door. Oh! And my... bike?" };

char					*kitchenText[] = { "I'm in the kitchen.", 
											"The twins' favourite place in the whole house, I can easily guess why. There is a big white tableboard in the middle."\
											"On the right side stands the biggest fridge ever. I love it. On the front wall, the worktop, full of housewares."\
											"The left wall has a fitment, where the electrical appliances are placed, and, by its side, a doorway to the "\
											"garden with a screen dog door, for the... yes, dog." };

char					*bathroomText[] = { "I'm in the WC.", 
											"Nice and simple. A shower plate on the right, the sink and a big mirror, and the toilet "\
											"on the left side, beside a tall, narrow piece of furniture where we keep our hygiene stuff." };

char					*livingRoomText[] = { "I'm in the living room.",
											"This living room is way too big for a 5-member family, a dog and a parrot. On the left side there's "\
											"a big bookshelf behind the dining table, the next wall holds a big piano and Gwaihir's birdcage, and, "\
											"on right side, the worst TV in the world. The On/Off button is broken and it has been on for ages. And "\
											"last, but not least, two sofas pointing to the TV and, behind the TV a big window to the garden." };

char					*basementText[] = { "I'm in the basement.", "Nothing yet." };


char					*upstairsHallText[]; // rellano primer piso
char					*upstairsCorridorText[]; // pasillo primer piso
char					*mainBedroomText[];
char					*twinsBedroomText[];
char					*ownBedroomText[];
char					*officeText[];


char					*garretText[];

// objetos normales	que no se pueden coger

	// lobby

char					*lobbyPictureText[] = { { "A pirate in an epic stance appears in this picture. \"The mightiest pirate\" can be read carved in "\
												"the bottom of the wooden frame. Dad loves this Guy, who is he?" }, 
												{NULL} };

char					*lobbyPlateText[] = { { "This plate was given to Mom when she won that dumb hot-dog eating contest. She ate 89 hot-dogs in 5 "\
												"minutes and didn't even blink once. She's a beast, I thought she wasn't going to make it after that, "\
												"but she did, and the price money encouraged her to found that profitable company of hers: \"Electronical "\
												"Locks Inc.\"" },
												{ NULL } } ;

char					*lobbyPegText[] = { { "A couple of coats and Dad's DIY uniform hangs there. It has a battery inside the left pocket. He loves "\
											"assembling up odd plastic sculptures, and he must protect himself to do that. I've seen him making those, "\
											"but never seen one around. I wonder where he stores them." },
											{ "A couple of coats and Dad's DIY uniform hangs there. He loves "\
												"assembling up odd plastic sculptures, and he must protect himself to do that. I've seen him making those, "\
												"but never seen one around. I wonder where he stores them." } } ;

char					*lobbyCarpetText[] = { {"According to Mom, the best carpet in the world, although it seems quite normal to me. It used to be "\
												"green, but carrying fresh cakes upstairs has consequences. When it started changing colour, Mom thought "\
												"it was a miracle and converted to Christianism... *sigh* Is that a leaflet peeking from beneath?" },
												{ "According to Mom, the best carpet in the world, although it seems quite normal to me. It used to be "\
													"green, but carrying fresh cakes upstairs has consequences. When it started changing colour, Mom thought "\
													"it was a miracle and converted to Christianism... *sigh*" } } ;

char					*lobbyCommodeText[] = { { "It has some candy on top, for the guests, a flowerpot, for the sake of the lobby appearance, and a clock 10 "\
												"minutes ahead, for the people who wait for us. We keep our shoes in the lower part. Jeez, I wonder how tall "\
												"are these pair of shoes. How can women wear heels?" },
												{ "It has some candy on top, for the guests, a flowerpot, for the sake of the lobby appearance, and a clock 10 "\
													"minutes ahead, for the people who wait for us. We keep our shoes in the lower part."} };

char					*lobbyStairsText[] = { { "The stairs to the next floor." },
												{ NULL } } ;

char					*lobbyCandyText[] = { { "Dentists love candy." },
											{ NULL } };
char					*lobbyFlowerpotText[] = { { "Until the twins brough this home, I thoroughly believed carnivorous plants ate people." },
												{ "I 've taken the plant with me." } };
char					*lobbyClockText[] = { { "God, now it's quiet, but, during the night, this is noisier than a bulldozer." },
											{ NULL } };
char					*lobbyCoatsText[] = { { "Yellow coats, you know, for the cold." },
											{ NULL } };


char					*garageCarText[] = { { "Dad's 1968 Ford. I think he loves this car more than me and my sisters. There's a lighter inside. Oh, and "\
											"that upholstery looks like it could really use a good cleanup." },
											{ "Dad's 1968 Ford. I think he loves this car more than me and my sisters. That upholstery looks like it could really "\
											"use a good cleanup." } };

char					*garageShelfText[] = { { "Illegal fireworks, old car pieces and empty Special-K boxes. What a strange mixture." },
											{ "It's full of old car pieces and empty Special-K boxes. What a strange mixture." } };

char					*garageWorkbenchText[] = { { "Here's where Dad builds his unique pieces of... art. I mean, do you really need a chainsaw to make sculptures? "\
													"This is a mess, there's sawdust all around! I truly hope the twins never find out about this. " },
												{ "Here's where Dad builds his unique pieces of... art. I mean, do you really need a chainsaw to make sculptures? "\
													"I truly hope the twins never find out about this. " } };

char					*garageBoxesText[] = { { "Plain brown boxes from the box factory. The owner and Dad are close friends. He always sends us boxes filled with chocolates "
												"for Christmas. It might seem good, but we spend half a year eating chocolates. Half. A. Year. I'm diabetic now." },
												{ NULL } };

char					*garageChainsawText[] = { { "I dread these things. I've seen too many horror movies." },
												{ NULL } };

char					*garageBikeText[] = { { "My bike! What has Dad done to you? Did he really need your pieces? Why is there a duct tape roll on your seat? "\
												"Does he use you just as a duct tape holder? No! Don't breathe, don't breathe, I'll seek out help, don't move!" },
											{ "My bike! What has Dad done to you? Did he really need your pieces? No! Don't breathe, don't breathe, I'll seek out help, "\
											"don't move!" } };

char					*garageDoorText[] = { { "The door to the basement. It's locked. An electrical lock prevents anyone from stepping in without permission or the key. "\
												"I crave answers, I want to know what lies within those walls. And I will." },
											{ "The door to the basement. Woah, when Mom sees what happened, she's going to have me killed. Lucky I can't die again." } };

char					*garageElectricalLockText[] = { { "I can't open the door because of this weird electrical lock. It looks older than Methuselah. There must be some way "\
														"to brake it."},
														{ "Now it's useless. I hope it wasn't the last version of an old series. Jinx." } };

char					*garageSignboardText[] = { { "It reads: \"DIY. Follow your dreams and don't stop even if you make something explode in the process.\". I hope Dad "\
													"to survive the mid-forties crysis he's going through. Does that exist for skeletons?" },
												{ NULL } };

char					*garageGateText[] = { { "The door! Wait. The electrical circuitry is broken and I can't lift up the door without muscles. Damn it." },
											{ NULL } };

	// corridor

char					*corridorLettersText[] = { { "Hundreds of letters from Mom's fans cover the walls! But they aren't what one could expect from fan letters. "\
													"I think they are a reminder of the time when Elelock Inc. Mom's company, had to overcome a difficult period, "\
													"having disappointed the customers with a non-waterproof door lock and needing to make it up for them with a new, "\
													"safer version of it. She likes to keep them around, and they taught me lots of bad language when I was a kid." },
													{ NULL } } ;


	// kitchen
char					*kitchenTableboardText[] = { {"The knife on top is so sharp. I can picture beheaded hobos laying here, I swear."},
													{ "I can picture beheaded hobos laying here, I swear." } };

char					*kitchenFridgeText[] = { { "We should go to the groceries. There's only beef, milk and eggs. Beh, if I'm hungry I can ask Coca and Cola for a "\
												"piece of cake." },{ "We should go to the groceries. There's only milk and eggs. Beh, if I'm hungry I can ask Coca "
												"and Cola for a piece of cake." } };

char					*kitchenWorktopText[] = { { "Here is where Mom cooks... and the twins too. Someone has poured coffee here and hasn't even bothered in cleaning it." },
												{ "Here is where Mom cooks... and the twins too." } };

char					*kitchenFitmentText[] = { { "Here's the microwave and the magic it contains. How does it work? I wasn't paying attention in school the day that was "\
													"explained. Well, the thing next to it I can surely explain. I love you, bottle of water."},
													{ "Here's the microwave and the magic it contains. How does it work? I wasn't paying attention in school the day that was "
													"explained." } };

char					*kitchenDoorwayText[] = { { "It has a nice mini screen door at the bottom. Fang uses it to go out to the garden." },
													{ NULL } };

char					*kitchenMilkText[] = { { "No animal should drink another species' milk. It's unnatural." },
												{ NULL } };

char					*kitchenFlourText[] = { { "Making cakes leaves footprints, sisters. More, I mean." },
												{ NULL } };

char					*kitchenEggsText[] = { { "How can stomach holders eat something that pops out of a hen's hole?" },
												{ NULL } };

char					*kitchenMicrowaveText[] = { { "I remember Mom warming milk up in the stewpan when this thing didn't exist." },
												{ NULL } };

char					*kitchenStoveText[] = { { "Touching this is forbidden to me. Dad says I'm so dumb I could set the house on fire without even turning it on." },
												{ NULL } };


	// WC
char					*wcShowerText[] = { {"The shower plate. Oops, we should replace the soap, there's little left."}, 
											{ "The shower plate." } };

char					*wcSinkText[] = { {"Here we leave the mouth related stuff, such as the toothpaste. Also, apparently my sisters leave all "\
											"their hair in here."},
											{ "Here we leave the mouth related stuff. Also, apparently my sisters leave all "\
												"their hair in here." } };

char					*wcMirrorText[] = { {"God, I'm uglier than I remembered. I wonder if this happens to you too. Wait, who am I talking to?"},
											{ NULL } };

char					*wcToiletText[] = { {"This stupid white rock feels like the best sofa in the world when the occasion comes. No! I think that toilet paper "\
											"is from the coarse type. Humans don't like that. Smooth is better, they say."},
											{ "This stupid white rock feels like the best sofa in the world when the occasion comes. I wish I had the chance to use it." } };

char					*wcFurnitureText[] = { {"Here we keep a comb, aspirins and bandages... and there's a hidden drawer in here, but it stands out blatantly."},
											{ "Here we keep aspirins and bandages... and there's a hidden drawer in here, but it stands out blatantly." } };

char					*wcDrawerText[] = { { "Perfectly hidden. Mom hides here her 800-coin feminine perfume. She thinks we don't... I mean, the sisters don't know." },
											{ "Perfectly hidden. Empty now." } };

char					*wcPaperText[] = { {"Coarse."},
											{ NULL } };

char					*wcAspirinText[] = { {"This little things... They have never proved useful to me."},
											{ NULL } };

char					*wcBandageText[] = { {"I wish I could bleed."},
											{ NULL } };

	// living room
char					*livingroomBookshelfText[] = { {"I've read every one of those books but two... The Bible and that stupid Necronomi-don't-know-what-else "\
														"gets on my nerves. And everybody has read it, why should I bother doing the same? Oh, and that strange "\
														"voodoo figure Grampa likes so much. It emits power waves, I can sense them. Nah, just kidding."}, 
														{ "I've read every one of those books but one... That stupid Necronomi-don't-know-what-else "\
														"gets on my nerves. And everybody has read it, why should I bother doing the same? Oh, and that strange "\
														"voodoo figure Grampa likes so much. It emits power waves, I can sense them. Nah, just kidding." } };


char					*livingroomTableText[] = { { "King Size Homer would be able to lie down on this table and it would still be room for the rest of Springfield. "\
													"But there are only a cracked vase and a decor dish on it. Such a wasted space." }, 
													{ "King Size Homer would be able to lie down on this table and it would still be room for the rest of Springfield. "\
													"But there's only a decor dish on it. Such a wasted space." } };

char					*livingroomPianoText[] = { { "Just a grand piano. I wish my parents had made me take piano classes when I was a kid. I love how it sounds when "\
													"the twins play it together. What's a screwdriver doing on top of it?" }, 
													{ "Just a grand piano. I wish my parents had made me take piano classes when I was a kid. I love how it sounds when	"\
													"the twins play it together." } };

char					*livingroomBirdcageText[] = { { "Bigger than my room. This miserable parrot lives in better coniditions than me. There's a stick on the bottom." }, 
													{NULL} };

char					*livingroomTVText[] = { { "The good ol' Grampa's WWII TV. It's always on playing that disgusting telemarketing channel. I mean, this ad? What the "\
												"hell? Who believes that a strip of duct tape can resist water and remain glued?" },
												{NULL} };

char					*livingroomSofasText[] = { {"A comfy pair of sofas for 3-hour naps. From the fourth hour on, the back starts hurting. Look! Two cents. They probably "\
													"slipped out of my pocket while sleeping. There's grampa, taking full advantage of the sofas' potential." }, 
													{ "A comfy pair of sofas for 3-hour naps. From the fourth hour on, the "\
													"back starts hurting. There's grampa, taking full advantage of the sofas' potential." } };

char					*livingroomWindowText[] = { { "The garden can be seen through the window. In fact, nothing can be seen through the window. We should mow the lawn "\
													"from time to time." }, 
													{NULL} };

char					*livingroomFigureText[] = { {"A big chubby woman representing... Gaia? It's weird, I can feel something... I think I need to take a WC-break."}, 
													{NULL} };
char					*livingroomDishText[] = { {"It reads: \"Recuerdo de Cuenca\". This is something Granma brought from her trip around Spain."},
													{NULL} };
char					*livingroomStickText[] = { {"It's covered in... GWAIHIR! You dirty fowl."},
													{NULL} };



// objetos activos
	
	//lobby
char					*lobbyShoesText[] = { { "My god. The Heels. They're so tall." },
												{ NULL } };
char					*lobbyBatteryText[] = { { "Is this one of those old batteries? I hadn't seen one yet. How do you charge this antique cylinder?" },
												{ NULL } };
char					*lobbyLeafletText[] = { { "The recipee for making a... bomb? I should talk to Dad, he might be planning world domination and I want to take part. "\
												"I NEED WHAT?" },
												{ NULL } };
char					*lobbyPlantText[] = { { "It seems hungry." },
												{ NULL } };

	// garage

char					*garageTapeText[] = { { "\"Unbreakable\", Dad says every time he brings this out in a conversation." },
											{ NULL } };
char					*garageSawdustText[] = { { "Granma used to say that most people's heads are filled with sawdust. Granma talked oddly sometimes." },
											{ NULL } };
char					*garageLighterText[] = { { "I remember this lighter. There was a time when I found a sprite in the garden. He told me to burn things. I started with him." },
											{ NULL } };
char					*garageFireworksText[] = { { "\"Caution: enough power to blow a little safe. Keep away from mad adults.\"" },
											{ NULL } };

	//downstairscorridor (nada)
	
	// kitchen
char					*kitchenKnifeText[] = { { "I could cut everything with it. Well, not everything I suppose." },
												{ NULL } };
char					*kitchenBeefText[] = { { "It looks nearly rotten, no skeleton or human would eat this." },
												{ NULL } };
char					*kitchenCoffeeText[] = { { "It stinks." },
												{ NULL } };
char					*kitchenWaterText[] = { { "I wish I could drink it. It's hard without a stomach." },
												{ NULL } };

	// WC
char					*wcSoapText[] = { {"Slippery."}, 
										{ NULL } };
char					*wcToothpasteText[] = { {"Strawberry flavour! Yummy!"},
												{ NULL } };
char					*wcCombText[] = { {"It's electrified."},
										{ NULL } };
char					*wcPerfumeText[] = { {"Smells like teen spirit."},
											{ NULL } };

	//living room
char					*livingroomBibleText[] = { { "This bible seems to be hollow. Wow, there's a booze flask inside. Someone's hitting it hard and it's not me. I hope." },
												{NULL} };
char					*livingroomVaseText[] = { { "So transparent. So broken. This vase has a tiny crack on its side." },
												{ NULL } };
char					*livingroomScrewdriverText[] = { { "There was a time when I thought this was something every man has." },
												{ NULL } };
char					*livingroomCentsText[] = { { "I'm rich!" },
												{ NULL } };



// objetos crafteados

char					*fixedVase[] = { {"Now this vase can hoard up water."}, 
										{NULL} };


// dialogs

char					*grampaDialog[] = { {"Hey, grampa."}, 
											{"Grampa!"},
											{"*SCREAMING* GRAMPA!"}, 
											// comienzo de testos que aparecen al decir algo
											{ NULL },
											{ NULL },
											{ "Are you dead?" } };

char					*grampaResponse[] = { {"Zzzzzzzz..."},
												{"ZzZzzZzZZzzZz..."},
												{ "ZzZz...*cough*...*hawk*...zZzZzZzzzZZZzzZ..." },
												{ NULL },
												{ NULL },
												{ "I've been dead for 77 years, you know that. Now, let me sleep." } };



//activeObject		*lobbyActiveObjects[MAX_ACTIVE_ITEMS_PLACE];
//activeObject		*garageActiveObjects[MAX_ACTIVE_ITEMS_PLACE];

// lugares del juego

// hecho con array dinámico para poder eliminar con el delete los objetos
// contenidos reservados de forma dinámica
// está bien hacer esto aquí?
//activeObject		*objectStack[TOTAL_OBJECTS];
// acuérdate de delete[] objectStack;

// input recibido, 4 palabras a lo sumo
char				*textWords[MAX_WORDS_INPUT];

// en estas tres es importante que el orden coincida con el valor de sus macros, todo está organizado para corresponder
char				*possibleCommands[] = {"look around", "look at", "pick up", "go", "talk to", "use", "give", "help", "inventory"};

//char				*possibleDirections[] = {"left", "right", "forward", "backward", "up", "down"};

char				*possiblePlaces[] = { "lobby", "garage", "downstairs_corridor", "kitchen", "WC", "living room", "basement", "upstairs_hall", "upstairs_corridor",
											"main_bedroom", "twins_bedroom", "own_bedroom", "office", "garret" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------