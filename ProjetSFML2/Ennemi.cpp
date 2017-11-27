#include "Ennemi.h"



Ennemi::Ennemi(Vector2f basePos, Texture texture)
{
	this->setTexture(texture);
	this->setPosition(basePos);
}

Ennemi::~Ennemi()
{
}
