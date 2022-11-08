#pragma once
#include "Entity.h"
class Item :
    public Entity
{
public:
    Item() : Entity(EntityType::ITEM) {};
    Item(int x, int y) : Entity(EntityType::ITEM, x, y){};
    Item(SDL_Point position) : Entity(EntityType::ITEM, position){};
    ~Item();

    void tick();
    void render();
    float x = 0;
};

