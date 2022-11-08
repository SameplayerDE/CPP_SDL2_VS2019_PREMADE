#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include "Region.h"
#include "Player.h"
#include "SpriteSheet.h"

using namespace std;

class Input;

class Game
{
public:
	Game();

	void init();
	void start();
	void stop();

	bool hasFocus() { return true; }
	SpriteSheet* getSpriteSheet() { return spriteSheet; }
	void setRegion(Region* region) { this->region = region; }

private:
	void run();
	void tick();
	void render();
	void clear();

	bool running = false;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Input* input;
	Region* region;
	SpriteSheet *spriteSheet;
	

	int tickCount = 0;
	int gameTime = 0;
	int scale = 4;
};
#endif // !GAME_H
