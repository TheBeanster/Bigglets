#pragma once

#include "vector2.h"



enum EntityType
{
	ETYPE_NULL,
	ETYPE_PLAYER,
	NUM_ENTITYTYPES
};

extern const char* const EntityTypeNames[];



class Entity
{
public:

	int type;
	vector2 position;
	unsigned int flags;

private:

};
