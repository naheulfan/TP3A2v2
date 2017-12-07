#include "Fighter.h"



Fighter::Fighter(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType) : Ennemi(basePos, texture, color, enemyType)
{
	speed = 3;
}

Fighter::~Fighter()
{
}

void Fighter::Update()
{
	Ennemi::Update();
	this->move(Vector2f(-speed, 0));
}
void Fighter::Draw(RenderWindow &window)
{
	window.draw(*this);
}