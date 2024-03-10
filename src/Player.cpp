#include "headers/stdafx.h"
#include "headers/Player.h"

Player::Player()
{
	this->initVars();
	this->initShape();
}

Player::~Player()
{

}

const sf::FloatRect& Player::getCollBox() const
{
	return this->collisionBox.getGlobalBounds();
}

const bool Player::stoped() const
{
	return this->stop;
}

void Player::setZeroSpeed()
{
	this->moveDirs = sf::Vector2f{ 0,0 };
}

void Player::setPos(float x, float y)
{
	this->shape.setPosition(x, y);
}

void Player::setStop(bool _stop)
{
	this->stop = _stop;
}

void Player::update()
{
	

	this->updateCollBox();
	this->updateStopDir();

	this->updateMove();

	this->updateCollBox();

	this->shape.move(this->moveDirs);

}

void Player::updateCollBox()
{
	sf::Vector2f newPos{ this->shape.getPosition().x, this->shape.getPosition().y};
	//moves up or down

	//down
	if (this->dir == DIR::DOWN) {
		newPos.x = this->shape.getGlobalBounds().left + 7.f;
		newPos.y = this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height;
	}
	//up
	if (this->dir == DIR::TOP) {
		newPos.x = this->shape.getGlobalBounds().left + 7.f;
		newPos.y = this->shape.getGlobalBounds().top - 5.f;
	}

	if (this->dir == DIR::RIGHT) {
		newPos.x = this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width;
		newPos.y = this->shape.getGlobalBounds().top + 7.f;
	}

	if (this->dir == DIR::LEFT) {
		newPos.x = this->shape.getGlobalBounds().left - 5.f;
		newPos.y = this->shape.getGlobalBounds().top + 7.f;
	}

	this->collisionBox.setPosition(newPos);

}

void Player::updateStopDir()
{
	if (stop) {
		switch (this->dir)
		{
		case DIR::LEFT:
			this->stop_dir = "left";
			break;
		case DIR::RIGHT:
			this->stop_dir = "right";
			break;
		case DIR::TOP:
			this->stop_dir = "top";
			break;
		case DIR::DOWN:
			this->stop_dir = "down";
			break;
		default:
			break;
		}
	}
	else {
		this->stop_dir = "none";
		this->stop = false;
	}
}

void Player::updateMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->stop_dir != "left" && this->dir != DIR::LEFT ) {
		this->moveDirs.x = -this->speed;
		this->moveDirs.y = 0;
		this->dir = DIR::LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->stop_dir != "right" && this->dir != DIR::RIGHT ) {
		this->moveDirs.x = this->speed;
		this->moveDirs.y = 0;
		this->dir = DIR::RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->stop_dir != "top" && this->dir != DIR::TOP ) {
		this->moveDirs.y = -this->speed;
		this->moveDirs.x = 0;
		this->dir = DIR::TOP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->stop_dir != "down" && this->dir != DIR::DOWN ) {
		this->moveDirs.y = this->speed;
		this->moveDirs.x = 0;
		this->dir = DIR::DOWN;
	}
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

void Player::initVars()
{
	this->stop = false;
	this->dir = DIR::NONE;
	this->speed = 2.f;
}

void Player::initShape()
{
	this->shape.setRadius(10.f);
	this->shape.setFillColor(sf::Color::Yellow);
	this->shape.setPosition(sf::Vector2f(9 * 24.f, 15 * 28.f));

	this->collisionBox.setSize(sf::Vector2f(5.f, 10.f));
	this->collisionBox.setPosition(this->shape.getGlobalBounds().left, this->shape.getGlobalBounds().top);
	this->collisionBox.setFillColor(sf::Color::Black);
	this->collisionBox.setPosition(this->shape.getPosition().x, this->shape.getPosition().y);

}
