//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andrés K.
//
// DESCRIPCIÓN:
// Clase que representa los objetos que puede guardarse el personaje.
//    
//-----------------------------------------------------------------------------

// guard de compilación para prevenir redefinición de la clase
#ifndef OBJETOACT_H
#define OBJETOACT_H


class activeObject
{
private:
	int					id;
	char*				name;
	char*				description;
	// el estado determina si el objeto ya ha sido cogido (true) o no (false)
	bool				pickedUp;
public:
	activeObject();
	activeObject(int id, char* name, char* description);
	~activeObject();

	int getID(void);
	char* getName(void);
	char* getDescription(void);
	bool getState(void);
	void interact(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------