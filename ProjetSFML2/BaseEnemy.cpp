#include "BaseEnemy.h"



BaseEnemy::BaseEnemy(Vector2f basePos, Texture texture) : Ennemi(basePos, texture)
{
	speed = 4;
	health = 1;
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::Update()
{
	this->move(Vector2f(-speed, 0));
}
void BaseEnemy::Draw(RenderWindow &window)
{
	window.draw(*this);
}