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

char*				welcomeText = { "PERDON POR LA FALTA DE ACENTOS\n\n" \
									"Bienvenido a \"Skeleton Skape Skirmish\".\n\n"
									"PERDON, DE VERDAD.\n\nEste es " \
									"un software de prueba. Si encuentras algun error, " \
									"no dudes en ponerte en contacto con el " \
									"desarrollador: Andres (a secas), casual " \
									"programador de realidades y eterno mendigo.\n\n" \
									"Bueno, basta.\n\n" \
									"Un momento, que esto es demasiado bueno:\n\n" \
									"Copyright (c) Andres. A secas.\n\n" \
									"Ahora si.\n\n" \
									"PERDON\n" };

char*				contextText = { "A las dos de la tarde de un dia soleado, Murray McMurray, "
									"un escualido esqueleto de 667 primaveras que siente una ferviente pasion por " \
									"las bebidas bajas en azucar y bricomania, abre los ojos y se levanta " \
									"del sofa con la espalda hecha un cristo. Es la ultima vez que duerme en " \
									"el sofa, se dice.\n\nHoy es un gran dia: es la fiesta de aniversario de Clicli, " \
									"su amiguete de la infancia, y se va a liar gorda. Ha de empezar a arreglarse " \
									"si no quiere llegar tarde, asi que decide ir a la cocina a comer algo antes " \
									"de vestirse.\n\n" \
									"Al llegar a la cocina se encuentra con sus hermanas gemelas haciendo una tarta " \
									"de cerebelos. Coca y Cola le comentan que su padre ha salido y, harto de que, cuando " \
									"el no esta, salgan a matar vagabundos para hacer sus dichosas tartas, se ha " \
									"llevado todas las llaves y no hay manera de salir de la casa.\n\n" \
									"Presa del panico, Murray suelta su taza del club megatrix y corre hacia la puerta y "
									"zarandea el pomo con toda la fuerza que sus distroficos brazos le permiten. Cerrada.\n\n" \
									"Sus hermanas, camino de su habitacion, pasan por el rellano y deciden desvelarle un " \
									"secreto a su enjuto hermano: \"padre guarda otras llaves en algun sitio de la casa, " \
									"pero no sabemos donde\", susurran. " \
									"Recobrando la calma, deshace su postura acurrucada, se levanta del suelo, seca sus lagrimas " \
									"y decide buscarlas.\n\n" \
									"Bien. Tu eres Murray McMurray. Que sorpresa, eh?\n\n"
									"El tiempo corre en tu contra, la fiesta es dentro de una hora.\n\n" \
									"Explorar la casa parece la unica opcion para llegar a tiempo a la fiesta..." };

char*				lobbyText[] = { "Estoy en el recibidor.",
									"El recibidor es asi.\n\n" \
									"A la izquierda hay un pasillo, a la derecha el garaje, y las escaleras " \
									"llevan al piso de arriba." };

char*				corridor0Text[] = {"Estoy en el pasillo del piso de abajo.", "El pasillo es recto, " \
											"como suelen ser los pasillos."};
char*				garageText[] = { "Estoy en el garaje de la casa.", "Menudo Ferrari tienen." };
char*				kitchenText[] = { "Estoy en la cocina.", "Es una cocina cálida, pero la de " \
										"mi abuela era mucho mejor."};
char*				bathroomText[] = { "Estoy en el WC.", "Es un " \
										"cuarto de bano pequeno. No sé cómo se las arreglan." };
char*				livingRoomText[] = { "Estoy en la sala de estar" /*"n espacioso salón comedor."*/, "En este salón se " \
										"podría celebrar una comida estupenda."};


char*				basementText[] = { "Estoy en el sotano", "" };


char*				corridor1Text[]; // rellano primer piso
char*				corridor2Text[]; // pasillo primer piso
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

char*				possibleOrders[] = {"mirar", "coger", "ir", "hablar", "usar", "dar"};

char*				possibleDirections[] = {"izquierda", "derecha", "adelante", "atras", "arriba", "abajo"};

char*				possiblePlaces[] = { "lobby", "garaje", "pasillo de abajo", "cocina", "WC", "sala de estar", "sotano" };

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------