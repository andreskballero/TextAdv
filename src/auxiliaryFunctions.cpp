#include <stdio.h>
#include "descriptions.h"
#include "gameManager.h"
#include "auxiliaryFunctions.h"


void allocateSpace(void)
{
	textWords[0] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1); // 21 bytes (+1 por el \0, la orden más larga tendrá siempre menos
	textWords[1] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1);
	textWords[2] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1);
	textWords[3] = (char*)malloc((sizeof(char) * MAX_WORD_SIZE) + 1);
	//memset(textWords[0], 0, 10);
	//strcpy_s(textWords[0], 10, "mima");
	//printf("%s\n", textWords[0]);
}


// hay un problema, al partir desarrollador, se printa el char y luego el -
// eso no deberia ser asi
void printText(char* text)
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
	printText("< Pulsa enter >"); fgets(skipIntroduction, MAX_INPUT_SIZE, stdin);
	printText(contextText);

	while (1)
	{
		GM.getInput();
		if (GM.parsing() && GM.checkExistance()) // orden de ejecución a derechas, no?
		{
			//AM.generateAnswer();
			GM.act();
		}
		else {
			// ver cómo se responde que no se puede hacer nada
			printf("Introduce una orden correcta.\n\n");
		}
	}	
}