#include "NPC.h"



NPC::NPC()
{
	name = NULL;
	room = -1;
	diagLines = 0;
}


NPC::~NPC()
{
}


char* NPC::getName(void)
{
	return name;
}


int NPC::getRoom(void)
{
	return room;
}

int NPC::getDiagLines(void)
{
	return diagLines;
}


dialog** NPC::getDialog(void)
{
	return conversation;
}


void NPC::initNPC(char *newName, int currentRoom, int totalDiag, char **lines, char **responses)
{
	//conversation = (dialog**)malloc((sizeof(dialog*) * totalDiag) + 1);
	conversation = new dialog*[totalDiag];

	name = newName;
	room = currentRoom;
	diagLines = totalDiag;

	for (int dialogs = 0; dialogs < totalDiag; ++dialogs)
	{
		if (NULL != lines[dialogs]) // si hay lines, hay response
		{
			dialog *auxDialog = (dialog*)malloc(sizeof(dialog) + 1);

			auxDialog->textLine = lines[dialogs];
			auxDialog->textResponse = responses[dialogs];

			if (dialogs < (totalDiag * 0.5))
			{
				auxDialog->said = false;
			}
			else {
				auxDialog->said = true;
			}

			conversation[dialogs] = auxDialog;
		}
		else {
			conversation[dialogs] = NULL;
		}
	}
}