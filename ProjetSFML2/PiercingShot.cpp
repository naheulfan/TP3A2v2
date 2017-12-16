#include "PiercingShot.h"



PiercingShot::PiercingShot(Vector2f basePosition, bool baseDirection) : Projectiles(basePosition, baseDirection)
{
	projectileType = TypeProjectile::piercing;
	speed = 10;
	damage = 10;
}
void PiercingShot::Update()
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

PiercingShot::~PiercingShot()
{
}
