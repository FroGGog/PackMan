#include "headers/stdafx.h"
#include "headers/Game.h"

Game::Game()
{
	this->initVars();

	this->initWindow();

}

Game::~Game()
{
	delete this->window;

	delete this->tileMap;

	delete this->player;

	delete this->saveTile;
}

void Game::update()
{
	this->updateEvents();

	this->updateCollisions();

	this->player->update();

}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
		default:
			break;
		}


	}

}

void Game::updateCollisions()
{
	if (this->player->stoped()) {
		if (this->player->getCollBox().intersects(this->saveTile->getGlobalBounds())) {
			this->player->setStop(true);
			return;
		}
	}

	for (auto& i : this->tileMap->getTiles()) {
		
		if (this->player->getCollBox().intersects(i->getGlobalBounds())) {
			this->saveTile = i;
			this->player->setZeroSpeed();
			break;
		}
	}

	this->player->setStop(false);


}

void Game::render()
{
	this->window->clear();

	this->tileMap->render(*this->window);

	this->player->render(*this->window);

	this->window->display();//14 18
}


void Game::initVars()
{
	//448 x 576
	//video mode
	this->Vmode.width = 448;
	this->Vmode.height = 700;

	//init game tileMap
	this->tileMap = new TileMap(this->Vmode.width, this->Vmode.height);

	//init player
	this->player = new Player();

	this->saveTile = nullptr;

}

void Game::initWindow()
{
	//init window settings	
	this->window = new sf::RenderWindow(this->Vmode, "PacMan", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}
