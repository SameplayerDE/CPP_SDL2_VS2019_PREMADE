#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(EntityType type)
{
	this->type = type;
}

Entity::Entity(EntityType type, int x, int y)
{
	this->type = type;
	position.x = x;
	position.y = y;
}

Entity::Entity(EntityType type, SDL_Point position)
{
	this->type = type;
	this->position = position;
}

Entity::~Entity()
{
}
