#pragma once
#include <SDL.h>
#include <vector>
#include "Entity.h"
#include "SpriteSheet.h"

using namespace std;

class Region
{
public:
	Region();
	Region(const char* path);
	Region(int width, int height);
	~Region();
	
	void render(SDL_Renderer *renderer, SpriteSheet *spriteSheet, int scale);
	void tick();
	void add(Entity *entity);
	void remove(Entity* entity);
	bool hasLoaded() { return loaded; }
	int getWidth() { return width; }
	int getHeight() { return height; }
private:
	int width = 100;
	int height = 100;
	int* data = new int[width * height];
	bool loaded = false;

	void setTile(int x, int y, int tile);
	void renderBackground(SDL_Renderer* renderer, SpriteSheet* spriteSheet, int scale);
	

	vector<Entity*> entities;

};

