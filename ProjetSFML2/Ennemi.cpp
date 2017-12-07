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

void Ennemi::Update()
{
	
}