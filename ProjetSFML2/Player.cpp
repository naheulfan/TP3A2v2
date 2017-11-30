#include "Player.h"



Player::Player()
{
}
void Player::Init(Texture &playerTexture, Vector2f basePos)
{
	sprite.setTexture(playerTexture);
	sprite.setPosition(basePos);
	this->setPosition(basePos);
	currentWeapon = TypeProjectile::base;
	fireRate.restart();
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
		this->move(0, -speed);
	}
	if (command == 2)
	{
			sprite.move(0, speed);
			this->move(0, speed);
	}
	if (command == 3)
	{
			sprite.move(speed, 0);
			this->move(speed, 0);
	}
	if (command == 4)
	{
		sprite.move(-speed, 0);
		this->move(-speed, 0);
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