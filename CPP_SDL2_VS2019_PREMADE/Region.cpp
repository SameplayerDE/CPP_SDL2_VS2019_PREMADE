#include "Region.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Region::Region()
{
	loaded = true;
}

Region::Region(const char* path)
{
	delete data;
	ifstream file(path, ios::in);
	string str;
	int line = 0;
	int x = 0, y = 0;
	if (file.fail()) {
		cout << "Karte wurde nicht gefunden." << endl;
	}
	else {
		while (getline(file, str)) {
			if (line == 0) {
				width = stoi(str);
			}
			else if (line == 1) {
				height = stoi(str);
				data = new int[width * height];
			}
			else {
				x = 0;
				for (char tile : str) {
					data[x + y * width] = (int)tile - 48;
					x++;
				}
				y++;
			}
			line++;
		}
		file.close();
		loaded = true;
	}
}

Region::Region(int width, int height)
{
	delete data;
	this->width = width;
	this->height = height;
	data = new int[width * height];
	for (int i = 0; i < width * height; i++) {
		data[i] = 0;
	}
	loaded = true;
}

Region::~Region()
{
}

void Region::render(SDL_Renderer* renderer, SpriteSheet* spriteSheet, int scale)
{
	renderBackground(renderer, spriteSheet, scale);
	for (Entity *entity : entities) {
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		if (entity->getType() == EntityType::PLAYER) {
			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		}else if (entity->getType() == EntityType::ITEM) {
			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		}
		SDL_RenderDrawPoint(renderer, entity->getPosition().x, entity->getPosition().y);
	}
}

void Region::renderBackground(SDL_Renderer* renderer, SpriteSheet* spriteSheet, int scale)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int tile = data[x + y * width];
			spriteSheet->drawSprite(x * spriteSheet->getTileSize() * scale, y * spriteSheet->getTileSize() * scale, scale, tile % spriteSheet->getTilesPerRow(), tile / spriteSheet->getTilesPerRow());
		}
	}
}

void Region::tick()
{
	for (Entity* entity : entities) {
		entity->tick();
	}
}

void Region::add(Entity* entity)
{
	if (entity->getType() != EntityType::NONE) {
		entities.push_back(entity);
	}
}

void Region::remove(Entity* entity)
{
}

void Region::setTile(int x, int y, int tile)
{
	if (x >= 0 && x < width && y >= 0 && y < height) {
		if (tile >= 0) {
			data[x + y * width] = tile;
		}
	}
}
