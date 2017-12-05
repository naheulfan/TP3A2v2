#include "StealthFighter.h"



StealthFighter::StealthFighter(Vector2f basePos, Texture texture, Color color) : Ennemi(basePos, texture, color)
{
	speed = 3;
}

StealthFighter::~StealthFighter()
{
}

void StealthFighter::Update()
{
	this->move(Vector2f(-speed, 0));
}
void StealthFighter::Draw(RenderWindow &window)
{
	window.draw(*this);
}