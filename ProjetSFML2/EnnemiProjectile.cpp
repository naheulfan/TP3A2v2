#include "EnnemiProjectile.h"



EnnemiProjectile::EnnemiProjectile(Vector2f basePosition, bool direction, TypeProjectile projectileType) : Projectiles(basePosition, direction)
{
	this->projectileType = projectileType;
	if (projectileType == TypeProjectile::boss)
	{
		damage = 5;
		speed = 10;
	}
	else
	{
		damage = 1;
		speed = 12;
	}
}


EnnemiProjectile::~EnnemiProjectile()
{
}
void EnnemiProjectile::Update()
{
	if (direction)
	{
		this->move(Vector2f(speed, 0));
	}
	else
	{
		this->move(Vector2f(-speed, 0));
	}
}
