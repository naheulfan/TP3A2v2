#include "Mothership.h"



Mothership::Mothership(Vector2f basePos, Texture texture) : Ennemi(basePos, texture, Color::White)
{
	health = 5000;
}

Mothership::~Mothership()
{

}

void Mothership::Update()
{
	
}

void Mothership::Draw(RenderWindow &window)
{
	window.draw(*this);
}