#include "Ennemi.h"



Ennemi::Ennemi(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType)
{
	this->texture = texture;
	this->setColor(color);
	this->setTexture(this->texture);
	this->setPosition(basePos);
	this->enemyType = enemyType;
	collisionSphere = CollisionSphere(this->getTextureRect().width / 2, basePos.x, basePos.y);
}

Ennemi::~Ennemi()
{
}


void Ennemi::Damage(float damageValue)
{
	health -= damageValue;
}

float Ennemi::GetHealth()
{
	return health;
}

TypeEnnemi Ennemi::getTypeEnnemi()
{
	return enemyType;
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


void Ennemi::Update()
{

}