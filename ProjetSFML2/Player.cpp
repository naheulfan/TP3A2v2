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
	health = 5;
	shields.Push(Shield(this->getPosition()));
}
Player::~Player()
{
}
void Player::Draw(RenderWindow &window)
{
	window.draw(*this);
	shields.Top().Draw(window);
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
		return new BaseProjectile(Vector2f(getPosition().x + getTextureRect().width / 2, getPosition().y + getTextureRect().height / 2), true);
		
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
int Player::GetHealth()
{
	return health;
}
void Player::Damage(int damageValue)
{
	health -= damageValue;
}