#pragma once

#include "normalObject.h"

class activeObject : public normalObject
{
private:
	char *holder;
	bool used;
public:
	activeObject();
	~activeObject();

	void setMembers(char *newName, char **newDescription, char *newHolder, bool newUsed = false);

	void setUsed(bool newUsed);

	char* getHolder(void);
	bool getUsed(void);
};

