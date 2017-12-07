#include "Ennemi.h"



Ennemi::Ennemi(Vector2f basePos, Texture texture, Color color)
{
	this->texture = texture;
	this->setColor(color);
	this->setTexture(this->texture);
	this->setPosition(basePos);
	collisionSphere = CollisionSphere(this->getTextureRect().width / 2, basePos.x, basePos.y);
}

Ennemi::~Ennemi()
{

}

IntRect Ennemi::getIntRect()
{
	return this->getTextureRect();
}
void Ennemi::Damage(float damageValue)
{
	health -= damageValue;
}
float Ennemi::GetHealth()
{
	return health;
}
TypeProjectile Ennemi::GetColor()
{
	TypeProjectile retval = TypeProjectile::boss;
	if (getColor() == Color::Red)
	{
		retval = TypeProjectile::red;
	}
	else if (getColor() == Color::Blue)
	{
		retval = TypeProjectile::blue;
	}
	else if (getColor() == Color::Green)
	{
		retval = TypeProjectile::green;
	}
	return retval;
}
