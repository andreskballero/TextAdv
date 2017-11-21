#pragma once

#include "normalObject.h"

class activeObject : public normalObject
{
private:
	char *holder;
	bool pickedUp;
	bool used;
public:
	activeObject();
	~activeObject();

	void setMembers(char *newName, char **newDescription, char *newHolder, bool newPickedUp = false, bool newUsed = false);

	void setPickedUp(bool state);
	void setUsed(bool newUsed);

	char* getHolder(void);
	bool getPickedUp(void);
	bool getUsed(void);
};

