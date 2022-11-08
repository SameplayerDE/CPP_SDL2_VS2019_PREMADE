#pragma once
#include <SDL.h>
#include "EntityType.h"

class Entity
{
public:
	Entity();
	Entity(EntityType type);
	Entity(EntityType type, int x, int y);
	Entity(EntityType type, SDL_Point position);
	~Entity();

	virtual void tick() = 0;
	virtual void render() = 0;

	SDL_Point getPosition() { return position; }
	int getX() { return position.x; }
	int getY() { return position.y; }
	void setPosition(SDL_Point position) { this->position = position; }
	void addPosition(SDL_Point position) { addX(position.x); addY(position.y); }
	void setX(int x) { position.x = x; }
	void addX(int x) { position.x += x; }
	void setY(int y) { position.y = y; }
	void addY(int y) { position.y += y; }
	EntityType getType() { return type; }

protected:
	SDL_Point position = { 0, 0 };
	EntityType type = EntityType::NONE;
};

