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
	ammo[0] = -1; //baseshot non géré
	for (int i = 1; i < 5; i++)
	{
		ammo[i] = 0; //on commence avec 0 balle des armes spéciales
	}
	shields.Push(Shield(this->getPosition()));
}
Player::~Player()
{
}
void Player::Draw(RenderWindow &window)
{
	window.draw(*this);
	if (!shields.IsEmpty())
	{
		shields.Top().Draw(window);
	}
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
	if (!shields.IsEmpty())
	{
		shields.Top().setPosition(getPosition());
	}

}

Projectiles* Player::Shoot()
{
	fireRate.restart();
	if (currentWeapon == TypeProjectile::base)
	{
		return new BaseProjectile(Vector2f(getPosition().x + getTextureRect().width / 2, getPosition().y + getTextureRect().height / 2), true);
	}
	else if (currentWeapon == TypeProjectile::piercing)
	{
		ammo[1]--;
		return new PiercingShot(Vector2f(getPosition().x + getTextureRect().width / 2, getPosition().y + getTextureRect().height / 2), true);
	}
	else if (currentWeapon == TypeProjectile::empowered)
	{
		ammo[2]--;
		return new EmpoweredShot(Vector2f(getPosition().x + getTextureRect().width / 2, getPosition().y + getTextureRect().height / 2), true);
	}
	
}
bool Player::CanShoot()
{
	bool retval = false;
	if (currentWeapon == TypeProjectile::base && fireRate.getElapsedTime() > seconds(0.25))
	{
		retval = true;
	}
	else if (currentWeapon == TypeProjectile::piercing && fireRate.getElapsedTime() > seconds(2))
	{
		if (ammo[1] > 0)
		{
			retval = true;
		}
	}
	else if (currentWeapon == TypeProjectile::empowered && fireRate.getElapsedTime() > seconds(0.25))
	{
		if (ammo[2] > 0)
		{
			retval = true;
		}
	}
	else if (currentWeapon == TypeProjectile::explosive && fireRate.getElapsedTime() > seconds(1))
	{
		if (ammo[3] > 0)
		{
			retval = true;
		}
	}
	else if (currentWeapon == TypeProjectile::emp && fireRate.getElapsedTime() > seconds(0.125))
	{
		if (ammo[4] > 0)
		{
			retval = true;
		}
	}
	return retval;
}
int Player::GetHealth()
{
	return health;
}
void Player::Damage(int damageValue, TypeProjectile damageColor)
{
	while (!shields.IsEmpty() && damageValue > 0)
	{
		if (shields.Top().GetColor() == damageColor)
		{
			damageValue = 0;
		}
			int shieldRemaining = shields.Top().GetHealth() - damageValue;
			if (shieldRemaining > 0)
			{
				shields.Top().Damage(damageValue);
				damageValue = 0;
			}
			if(damageValue > 0)
			{
				damageValue = shieldRemaining * -1; // donc le dommage est égal au dégat "d'overkill" infligés au bouclier;
				shields.Pop();
			}
	}
	if (damageValue > 0)
	{
		health -= damageValue;
	}
}
void Player::AddShield()
{
	shields.Push(Shield(this->getPosition()));
}
void Player::SetCurrentWeapon(TypeProjectile newProjectile)
{
	this->currentWeapon = newProjectile;
}
void Player::AddAmmo(TypeProjectile typeOfAmmo)
{
	if (typeOfAmmo == TypeProjectile::piercing)
	{
		ammo[1] += 3;
	}
	else if (typeOfAmmo == TypeProjectile::empowered)
	{
		ammo[2] += 20;
	}
	else if (typeOfAmmo == TypeProjectile::explosive)
	{
		ammo[3] += 10;
	}
	else if (typeOfAmmo == TypeProjectile::emp)
	{
		ammo[4] += 50;
	}
}
int Player::GetAmmo()
{
	if (currentWeapon == TypeProjectile::base)
	{
		return -1;
	}
	else if (currentWeapon == TypeProjectile::piercing)
	{
		return ammo[1];
	}
	else if (currentWeapon == TypeProjectile::empowered)
	{
		return ammo[2];
	}
	else if (currentWeapon == TypeProjectile::explosive)
	{
		return ammo[3];
	}
	else if (currentWeapon == TypeProjectile::emp)
	{
		return ammo[4];
	}
}