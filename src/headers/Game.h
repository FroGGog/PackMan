#pragma once
#include "TileMap.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void updateEvents();
	void updateCollisions();
	void updatePointColl();

	void render();


private:

	sf::VideoMode Vmode;
	sf::RenderWindow* window;

	sf::Event event;
	TileMap* tileMap;

	sf::RectangleShape* saveTile;

	Player* player;

	void initVars();
	void initWindow();

};

