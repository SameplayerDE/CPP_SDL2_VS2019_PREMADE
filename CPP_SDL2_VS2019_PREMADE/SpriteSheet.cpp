#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::SpriteSheet(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::setTexture(SDL_Renderer *renderer, const char* path, int tilesPerRow)
{
	SDL_Surface *surface = SDL_LoadBMP(path); //loads texture
	SDL_SetColorKey(surface, -1, 0xff00ff); //sets a color that is used for alpha 0xff00ff
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height); //gets dimensions of texture
	this->tilesPerRow = tilesPerRow; //tiles per row
	tileSize = (width / tilesPerRow); //size of a tile
	SDL_FreeSurface(surface); //free memory
}

void SpriteSheet::setTexture(const char* path, int tilesPerRow)
{
	setTexture(renderer, path, tilesPerRow);
}

void SpriteSheet::drawSprite(int x, int y, int scale, int col, int row)
{
	SDL_Rect s = { col * tileSize, row * tileSize, tileSize, tileSize }; //area in spritesheet
	SDL_Rect d = { x, y, tileSize * scale, tileSize * scale }; //area on screen
	SDL_RenderCopy(renderer, texture, &s, &d);
}
