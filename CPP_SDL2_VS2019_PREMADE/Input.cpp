#include "Input.h"
#include "Game.h"
#include <algorithm>


Input::Input(Game *game)
{
	this->game = game;
}


void Input::tick() 
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) { //checks if SDL has a event
		events.push_back(event); //push event to vector
	}

	handle(); //handle events

	events.clear(); //free memory
}

void Input::handle() 
{
	//loop through queued events in vector
	for (SDL_Event event : events) {
		SDL_KeyboardEvent keyboardEvent = event.key;
		SDL_Keycode keyCode = keyboardEvent.keysym.sym;
		switch (event.type) {
		case SDL_QUIT:
			game->stop(); //stops programm when window is closed
			break;
		case SDL_KEYDOWN:
			if (find(keys.begin(), keys.end(), keyCode) == keys.end()) { // checks if key is NOT in vector
				keys.push_back(keyCode); //pushes key in vector
			}
			break;
		case SDL_KEYUP:
			if (find(keys.begin(), keys.end(), keyCode) != keys.end()) { // checks if key is in vector
				int i = 0; //index in vector
				for (SDL_Keycode keycode : keys) {
					if (keycode == keyCode) {
						break; //key was found
					}
					i++;
				}
				keys.erase(keys.begin() + i); //remove released key from vector
			}
			break;
		}
	}
	handleInput();
}

void Input::handleGamePadInput()
{
}

void Input::handleInput()
{
	for (SDL_Keycode keyCode : keys) {
		switch (keyCode) {
		case SDLK_ESCAPE:
			game->stop(); //stops when pressing Escape key
			break;
		case SDLK_DOWN:
			//Down
			break;
		case SDLK_UP:
			//Up
			break;
		case SDLK_LEFT:
			//Left
			break;
		case SDLK_RIGHT:
			//Right
			break;
		}
		
	}
}
