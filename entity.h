#pragma once

#include "vector2.h"
#include <list>
#include <vector>
#include <typeinfo>

#include "component.h"




enum EntityType
{
	ETYPE_PLAYER,
	ENTITY_COUNT
};

extern const char* const entityTypeNames[];



class Entity
{
public:

	EntityType type;
	unsigned int id;

	Entity(EntityType type);

	void Update();
	void Render();

	inline Component* GetComponent(ComponentType type)
	{
		std::list<Component>::iterator e;
		for (e = components.begin(); e != components.end(); e++)
		{
			if (type == e->type) 
				return &*e;
		}
		return nullptr;
	}

private:
	
	std::list<Component> components;

};



extern std::list<Entity> worldEntities;

void UpdateEntities();
void RenderEntities();

Entity& SpawnEntity(EntityType type, vector2 position);
