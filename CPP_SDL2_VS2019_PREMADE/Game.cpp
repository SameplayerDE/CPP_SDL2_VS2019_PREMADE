#include "Game.h"
#include "Player.h"
#include "Item.h"
#include "Input.h"

Game::Game()
{
}

void Game::init()
{
	//create SDL_Window and SDL_Renderer
	window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//creates input and loads a map
	input = new Input(this);
}

void Game::start()
{
	if (!running) {
		running = true;
	}
	run();
}

void Game::stop()
{
	running = false;
}

void Game::run()
{

	int lastTime = SDL_GetTicks();
	int lastTimer = SDL_GetTicks(); //to output the ticks and fps in the console
	double unprocessed = 0; //counts unprocessed ticks to compensate
	double msPerTick = 1000 / 60; //frames per seconds
	int frames = 0;
	int ticks = 0;

	init();


	while (running) {

		int now = SDL_GetTicks();
		unprocessed += (now - lastTime) / msPerTick; //calculates unprocessed time
		lastTime = now;
		bool shouldRender = true;

		//if game skipped updates, compensate for that 
		while (unprocessed >= 1) {
			ticks++;
			tick();
			unprocessed -= 1;
			shouldRender = true;
		}

		SDL_Delay(2);

		if (shouldRender) {
			frames++;
			render();
		}

		if (SDL_GetTicks() - lastTimer > 1000) {
			lastTimer += 1000;
			cout << ticks << " ticks, " << frames << " f/s" << endl;
			frames = 0;
			ticks = 0;
		}

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

}

void Game::tick()
{
	tickCount++; //future use?
	if (!hasFocus()) {
		
	}
	else {
		input->tick();
		if (false) {
			//menu.tick();
		}
		else {
		}
	}

}

void Game::render()
{
	clear();
	//Begin
	
	//End
	SDL_RenderPresent(renderer);
}

void Game::clear()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(renderer);
}
