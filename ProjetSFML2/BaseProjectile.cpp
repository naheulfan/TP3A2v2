#include "BaseProjectile.h"

BaseProjectile::BaseProjectile(Vector2f basePosition, bool baseDirection) : Projectiles(basePosition, baseDirection)
{
	projectileType = TypeProjectile::base;
	speed = 15;
}


BaseProjectile::~BaseProjectile()
{
}
void BaseProjectile::Update()
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
