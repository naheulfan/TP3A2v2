#include "Player.h"



Player::Player()
{
}
void Player::Init(Texture &playerTexture, Vector2f basePos)
{
	sprite.setTexture(playerTexture);
	sprite.setPosition(basePos);
}
Player::~Player()
{
}
void Player::Draw(RenderWindow &window)
{
	window.draw(sprite);
}
void Player::Move(int command)
{
	if (command == 1)
	{
		sprite.move(0, -speed);
	}
	if (command == 2)
	{
			sprite.move(0, speed);
	}
	if (command == 3)
	{
			sprite.move(speed, 0);
	}
	if (command == 4)
	{
		sprite.move(-speed, 0);
	}

}