#include "Player.h"



Player::Player()
{
}
Player::Player(Vector2f basePos)
{
	position = basePos;
}
void Player::Init(Texture &playerTexture)
{
	sprite.setTexture(playerTexture);
	sprite.setPosition(position);
}
Player::~Player()
{
}
void Player::Draw(RenderWindow &window)
{
	sprite.setPosition(position);
	window.draw(sprite);
}
void Player::SetPosition(Vector2f newpos)
{
	position = newpos;
}
Vector2f Player::GetPosition()
{
	return position;
}
