#include "entity.h"

#include "log.h"
#include "utility.h"



const char* const EntityTypeNames[] =
{
	STRINGIFY(player),
};



Entity::Entity(EntityType type)
{
	this->type = type;
	
}



void Entity::Update()
{
	for (auto& component : components)
	{
		component.Update();
	}
}



std::list<Entity> worldEntities;



Entity& SpawnEntity(EntityType type, vector2 position)
{
	Entity* e = new Entity(type);
	if (!e)
	{
		cerr("Couldn't create new entity!");
		throw 0;
	}
	worldEntities.push_back(*e);
	return *e;
}
