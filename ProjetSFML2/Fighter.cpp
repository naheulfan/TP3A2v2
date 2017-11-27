#include "Fighter.h"



Fighter::Fighter(Vector2f basePos, Texture texture) : Ennemi(basePos, texture)
{
	speed = 3;
}

Fighter::~Fighter()
{
}

void Fighter::Update()
{
	this->move(Vector2f(-speed, 0));
}
void Fighter::Draw(RenderWindow &window)
{
	window.draw(*this);
}