#include "StealthFighter.h"



StealthFighter::StealthFighter(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType) : Ennemi(basePos, texture, color, enemyType)
{
	speed = 3;
	health = 3;
	shootClock.restart();
}

StealthFighter::~StealthFighter()
{
}

void StealthFighter::Update()
{
    Ennemi::Update();
	this->move(Vector2f(speed, 0));
}
void StealthFighter::Draw(RenderWindow &window)
{
	window.draw(*this);
}
EnnemiProjectile* StealthFighter::Shoot()
{
	shootClock.restart();
	return new EnnemiProjectile(this->getPosition(), true, this->GetColor());
}