#include "BaseEnemy.h"



BaseEnemy::BaseEnemy(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType) : Ennemi(basePos, texture, color, enemyType)
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