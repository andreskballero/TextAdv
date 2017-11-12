#pragma once

#include <stdlib.h>
#include <string.h>

class normalObject
{
protected:
	char *name;
	char **description;
public:
	normalObject();
	~normalObject();

	//The member function area has been declared as virtual in the base class because it is
	//later redefined in each of the derived classes.Non - virtual members can also be 
	//redefined in derived classes, but non - virtual members of derived classes cannot be accessed
	//through a reference of the base class : i.e., if virtual is removed from the declaration of area 
	//in the example above, all three calls to area would return zero, because in all cases, the 
	//version of the base class would have been called instead.
	void setMembers(char *newName, char **newDescription);

	char* getName(void);
	char** getDescription(void);
};

