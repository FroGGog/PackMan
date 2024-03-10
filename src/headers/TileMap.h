#pragma once
class TileMap
{
public:
	TileMap(int _wW, int _wH);
	~TileMap();

	const std::vector<sf::RectangleShape*>& getTiles() const;
	std::vector<sf::CircleShape*>& getPoint();

	void render(sf::RenderTarget& target);

private:

	std::vector<std::vector<std::string>> gameField;
	std::vector<sf::RectangleShape*> fieldTiles;
	std::vector<sf::CircleShape*> pointTiles;

	sf::RectangleShape BaseShape;
	//get window size
	int wW, wH;

	void initField();
	void initShape();

};

