#include "Ennemi.h"



Ennemi::Ennemi(Vector2f basePos, Texture texture)
{
	this->texture = texture;
	sprite.setTexture(this->texture);
	this->setPosition(basePos);
}

Ennemi::~Ennemi()
{
}
