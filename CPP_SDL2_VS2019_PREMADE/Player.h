#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    Player() : Entity(EntityType::PLAYER) {};
    Player(int x, int y) : Entity(EntityType::PLAYER, x, y) {};
    Player(SDL_Point position) : Entity(EntityType::PLAYER, position) {};
    ~Player();

    void tick();
    void render();
};

