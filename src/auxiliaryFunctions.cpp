#include <stdio.h>
#include "descriptions.h"
#include "gameManager.h"
#include "auxiliaryFunctions.h"


// hay un problema, al partir desarrollador, se printa el char y luego el -
// eso no deberia ser asi
void printText(char *text)
{
	for (signed int letter = 0, line = 0; text[letter] != '\0'; ++letter, ++line)
	{
		if (line < CHARS_PER_LINE) // si estoy a media linea
		{
			//Sleep(5);
			printf("%c", text[letter]);
			if (text[letter] == '\n')
			{
				line = -1;
			}
		}
		else { // si es el último char de la línea
			if (/*((welcomeText[letter] > LETRA_A) && (welcomeText[letter] < LETRA_z))*//*(text[letter] != ' ')*/((text[letter] > LETRA_A) && (text[letter] < LETRA_z)) && ((text[letter - 1] > LETRA_A) && (text[letter - 1] < LETRA_z)))
			{
				printf("-\n");
				--letter;
				//--line;
			}
			else {
				//Sleep(5);
				printf("%c\n", text[letter]);

			}

			if (text[letter + 1] == ' ')
			{
				++letter;
			}

			line = -1;
		}
	}

	printf("\n\n//====================================================================//\n\n");
}


void play(void)
{
	char skipIntroduction[MAX_INPUT_SIZE];
	gameManager GM;

	// cargar elementos del juego
	GM.gameLoad();

	printText(welcomeText);
	printText("< Press enter to start playing >"); fgets(skipIntroduction, MAX_INPUT_SIZE, stdin);
	printText(contextText);
	printText("(type help to know the basics if you don't know them already)");

	while (1)
	{
		GM.getInput();
		if (GM.parsing()) // orden de ejecución a derechas, no?
		{
			//AM.generateAnswer();
			GM.act();
		}
		else {
			// ver cómo se responde que no se puede hacer nada
			printText("Input not allowed.");
		}
	}	
}