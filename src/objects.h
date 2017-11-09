#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct {
	char* name;
	char** description;
} normalObject;

typedef struct : normalObject {
	char* holder;
	bool used;
} activeObject;

void loadNormalObject(normalObject* object, char* newName, char** newDescription);

void loadActiveObject(activeObject* object, char* newName, char** newDescription, char* newHolder);

#endif
