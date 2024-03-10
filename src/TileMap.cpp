#include "headers/stdafx.h"
#include "headers/TileMap.h"

TileMap::TileMap(int _wW, int _wH): wW(_wW),  wH(_wH)
{
	this->initField();
	this->initShape();

}

TileMap::~TileMap()
{
	for (int i{ 0 }; i < this->fieldTiles.size(); i++) {
			delete this->fieldTiles[i];
			this->fieldTiles[i] = nullptr;
	}

}

const std::vector<sf::RectangleShape*>& TileMap::getTiles() const
{
	return this->fieldTiles;
}

void TileMap::render(sf::RenderTarget& target)
{
	for (auto& i : this->fieldTiles) {
		target.draw(*i);
	}
}

void TileMap::initField()
{
	this->gameField = {
		{ "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*" },
		{ "*", " ", " ", " ", " ", " ", " ", " ", " ", "*", " ", " ", " ", " ", " ", " ", " ", " ", "*" },
		{ "*", " ", "*", "*", " ", "*", "*", "*", " ", "*", " ", "*", "*", "*", " ", "*", "*", " ", "*" },
		{ "*", " ", " ", " ", " ", " ", " ", " ", " ", "*", " ", " ", " ", " ", " ", " ", " ", " ", "*" },
		{ "*", " ", "*", "*", " ", "*", " ", "*", "*", "*", "*", "*", " ", "*", " ", "*", "*", " ", "*" },
		{ "*", " ", " ", " ", " ", "*", " ", " ", " ", "*", " ", " ", " ", "*", " ", " ", " ", " ", "*" },
		{ "*", "*", "*", "*", " ", "*", "*", "*", " ", "*", " ", "*", "*", "*", " ", "*", "*", "*", "*" },
		{ " ", " ", " ", "*", " ", "*", "X", "X", "X", "X", "X", "X", "X", "*", " ", "*", " ", " ", " " },
		{ "*", "*", "*", "*", " ", "*", "X", "*", "*", " ", "*", "*", "X", "*", " ", "*", "*", "*", "*" },
		{ " ", " ", " ", " ", " ", " ", "X", "*", " ", " ", " ", "*", "X", " ", " ", " ", " ", " ", " " },
		{ "*", "*", "*", "*", " ", "*", "X", "*", "*", "*", "*", "*", "X", "*", " ", "*", "*", "*", "*" },
		{ " ", " ", " ", "*", " ", "*", "X", "X", "X", "X", "X", "X", "X", "*", " ", "*", " ", " ", " " },
		{ "*", "*", "*", "*", " ", "*", "X", "*", "*", "*", "*", "*", "X", "*", " ", "*", "*", "*", "*" },
		{ "*", " ", " ", " ", " ", " ", " ", " ", " ", "*", " ", " ", " ", " ", " ", " ", " ", " ", "*" },
		{ "*", " ", "*", "*", " ", "*", "*", "*", " ", "*", " ", "*", "*", "*", " ", "*", "*", " ", "*" },
		{ "*", " ", " ", "*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*", " ", " ", "*" },
		{ "*", "*", " ", "*", " ", "*", " ", "*", "*", "*", "*", "*", " ", "*", " ", "*", " ", "*", "*" },
		{ "*", " ", " ", " ", " ", "*", " ", " ", " ", "*", " ", " ", " ", "*", " ", " ", " ", " ", "*" },
		{ "*", " ", "*", "*", "*", "*", "*", "*", " ", "*", " ", "*", "*", "*", "*", "*", "*", " ", "*" },
		{ "*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*" },
		{ "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*" }

	};
	//19 21
	//w 24 h 28
	for (int row{ 0 }; row < this->gameField.size(); row++) {
		for (int collumn{ 0 }; collumn < this->gameField[row].size(); collumn++) {
			if (this->gameField[row][collumn] == "*") {
				sf::RectangleShape* tempRect = new sf::RectangleShape(sf::Vector2f(24.f, 28.f));
				tempRect->setPosition(24.f * collumn, 28.f * row);
				tempRect->setFillColor(sf::Color::Blue);
				this->fieldTiles.push_back(tempRect);
			}
			else {

			}
			else {
				continue;
			}
		}
	}
}

void TileMap::initShape()
{
	this->BaseShape.setSize(sf::Vector2f(24.f, 28.f));
	this->BaseShape.setFillColor(sf::Color::Blue);
}
