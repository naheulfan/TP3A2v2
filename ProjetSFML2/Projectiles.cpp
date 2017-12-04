#include "Projectiles.h"



Projectiles::Projectiles(Vector2f position, bool baseDirection)
{
	this->setPosition(position);
	direction = baseDirection;
}
void Projectiles::Draw(Sprite &sprite, RenderWindow &window)
{
	sprite.setPosition(this->getPosition());
	window.draw(sprite);
}

Projectiles::~Projectiles()
{
}
TypeProjectile Projectiles::GetProjectileType()
{
	return this->projectileType;
}
float Projectiles::GetDamage()
{
	return damage;
}