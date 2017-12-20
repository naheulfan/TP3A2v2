#include "EmpoweredShot.h"



EmpoweredShot::EmpoweredShot(Vector2f basePosition, bool baseDirection) : Projectiles(basePosition, baseDirection)
{
	projectileType = TypeProjectile::empowered;
	speed = 15;
	damage = 3;
}


EmpoweredShot::~EmpoweredShot()
{
}
void EmpoweredShot::Update()
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