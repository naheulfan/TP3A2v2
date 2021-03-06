#include "Fighter.h"



Fighter::Fighter(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType) : Ennemi(basePos, texture, color, enemyType)
{
	speed = 3;
	health = 2;
	shootClock.restart();
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
EnnemiProjectile* Fighter::Shoot()
{
	shootClock.restart();
	return new EnnemiProjectile(this->getPosition(), false, this->GetColor());
}
bool Fighter::CanShoot()
{
	if (shootClock.getElapsedTime() >= seconds(2))
	{
		return true;
	}
	else
	{
		return false;
	}
}