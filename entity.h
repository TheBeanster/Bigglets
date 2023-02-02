#pragma once

#include "vector2.h"
#include <list>

#include "component.h"




enum class EntityType
{
	player,
	typecount
};

extern const char* const EntityTypeNames[];



class Entity
{
public:

	EntityType type;
	vector2 position;
	unsigned int flags;

	Entity(EntityType type);

	void Update();
	void Render();

private:

	Component* components;

};



extern std::list<Entity> worldEntities;

Entity& SpawnEntity(EntityType type, vector2 position);
