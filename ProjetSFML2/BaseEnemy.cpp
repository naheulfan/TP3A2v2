#include "BaseEnemy.h"



BaseEnemy::BaseEnemy(Vector2f basePos, Texture texture, Color color) : Ennemi(basePos, texture, color)
{
	speed = 4;
	health = 1;
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::Update()
{
	Ennemi::Update();
	this->move(Vector2f(-speed, 0));
}
void BaseEnemy::Draw(RenderWindow &window)
{
	window.draw(*this);
}