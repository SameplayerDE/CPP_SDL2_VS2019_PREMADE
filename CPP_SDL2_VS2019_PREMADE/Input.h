#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <vector>

using namespace std;

class Game;

class Input
{
public:
	Input(Game *game);
	void tick();
private:
	Game *game;
	vector<SDL_Event> events;
	vector<SDL_Keycode> keys;
	void handle();
	void handleInput();
	void handleGamePadInput();
};
#endif