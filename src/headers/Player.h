#pragma once

enum DIR { LEFT, RIGHT, TOP, DOWN, NONE };

class Player
{
public:
	Player();
	~Player();

	const sf::FloatRect& getCollBox() const;
	const bool stoped() const;

	void setZeroSpeed();
	void setPos(float x, float y);
	void setStop(bool _stop);

	void update();
	void updateCollBox();
	void updateStopDir();
	void updateMove();

	void render(sf::RenderTarget& target);

private:
	
	sf::CircleShape shape;
	
	sf::RectangleShape collisionBox;

	sf::Vector2f moveDirs;

	bool stop;
	DIR dir;
	std::string stop_dir;
	float speed;

	void initVars();
	void initShape();
};

