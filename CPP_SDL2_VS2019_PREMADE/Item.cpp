#include "Item.h"
#include <cmath>
#include <iostream>

Item::~Item()
{
}

void Item::tick()
{
	x += 0.5f;
	position.x -= (int)(std::cos(x) * 10);
	position.y += (int)(std::sin(x) * 10);
}

void Item::render()
{
}
