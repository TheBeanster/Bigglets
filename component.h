#pragma once

#include "vector2.h"



enum ComponentType
{
	CTYPE_TESTCOMPONENT,

};



class Component
{
public:

	ComponentType type;

	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};





class CPosition : public Component
{
public:
	vector2 position;

	void Render();
};

