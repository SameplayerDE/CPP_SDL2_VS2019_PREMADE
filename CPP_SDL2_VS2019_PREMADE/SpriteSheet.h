#pragma once
#include <SDL.h>

class SpriteSheet
{
public:
	SpriteSheet();
	SpriteSheet(SDL_Renderer *renderer);
	~SpriteSheet();

	void setTexture(SDL_Renderer *renderer, const char* path, int tilesPerRow);
	void setTexture(const char* path, int tilesPerRow);
	SDL_Texture* getTexture() { return texture; }
	int getTileSize() { return tileSize; }
	int getTilesPerRow() { return tilesPerRow; }

	void drawSprite(int x, int y, int scale, int col, int row);
private:
	int width, height, tilesPerRow, tileSize;

	SDL_Texture *texture;
	SDL_Renderer* renderer;
};

