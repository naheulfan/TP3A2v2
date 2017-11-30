#include "Player.h"



Player::Player()
{
}
void Player::Init(Texture &playerTexture, Vector2f basePos)
{
	setTexture(playerTexture);
	setPosition(basePos);
	currentWeapon = TypeProjectile::base;
	fireRate.restart();
}
Player::~Player()
{
}
void Player::Draw(RenderWindow &window)
{
	window.draw(*this);
}
void Player::Move(int command)
{
	if (command == 1)
	{
		move(0, -speed);
	}
	if (command == 2)
	{
		move(0, speed);
	}
	if (command == 3)
	{
		move(speed, 0);
	}
	if (command == 4)
	{
		move(-speed, 0);
	}

}

Projectiles* Player::Shoot()
{
	if (currentWeapon == TypeProjectile::base)
	{
		fireRate.restart();
		return new BaseProjectile(this->getPosition(), true);
	}
}
bool Player::CanShoot()
{
	if (fireRate.getElapsedTime() > seconds(0.25))
	{
		return true;
	}
	return false;
}