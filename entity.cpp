#include "entity.h"

#include "log.h"
#include "utility.h"

#include "debug.h"


const char* const entityTypeNames[] =
{
	STRINGIFY(ETYPE_PLAYER),
};



Entity::Entity(EntityType type)
{
	this->type = type;
	switch (type)
	{
	case ETYPE_PLAYER:
	{
		components.emplace_back(CPosition());
	}
		break;
	case ENTITY_COUNT:
		break;
	default:
		break;
	}
}



void Entity::Update()
{
	for (auto& component : components)
	{
		component.Update();
	}
}

void Entity::Render()
{
	for (auto& component : components)
	{
		component.Render();
	}
}



std::list<Entity> worldEntities;



void UpdateEntities()
{
	std::list<Entity>::iterator e;
	for (e = worldEntities.begin(); e != worldEntities.end(); e++)
	{
		e->Update();
	}
}

void RenderEntities()
{
	std::list<Entity>::iterator e;
	for (e = worldEntities.begin(); e != worldEntities.end(); e++)
	{
		e->Render();
	}
}



Entity& SpawnEntity(EntityType type, vector2 position)
{
	Entity* e = new Entity(type);
	if (!e)
	{
		cerr("Couldn't create new entity!");
		throw 0;
	}
	e->id = worldEntities.size();
	worldEntities.push_back(*e);
	return *e;
}
