#include "Ennemi.h"



Ennemi::Ennemi(Vector2f basePos, Texture texture)
{
	this->texture = texture;
	this->setTexture(this->texture);
	this->setPosition(basePos);
}

Ennemi::~Ennemi()
{

}

IntRect Ennemi::getIntRect()
{
	return this->getTextureRect();
}