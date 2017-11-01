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

void play(void)
{
	gameManager GM;

	// cargar elementos del juego
	GM.gameLoad();
	
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