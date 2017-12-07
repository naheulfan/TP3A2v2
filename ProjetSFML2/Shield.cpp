#include "Shield.h"



Shield::Shield(Vector2f position)
{
	shieldTexture.loadFromFile("Ressources\\shield.png");
	this->setTexture(shieldTexture);
	setPosition(position);
	health = 5;
	int shieldRandomColor = rand() % 4;
	if (shieldRandomColor == 1)
	{
		shieldColor = TypeProjectile::green;
		this->setColor(Color::Green);
	}
	else if (shieldRandomColor == 2)
	{
		shieldColor = TypeProjectile::red;
		this->setColor(Color::Red);
	}
	else if (shieldRandomColor == 3)
	{
		shieldColor = TypeProjectile::blue;
		this->setColor(Color::Blue);
	}
}
TypeProjectile Shield::GetColor()
{
	return shieldColor;
}
int Shield::GetHealth()
{
	return health;
}
void Shield::Damage(int damageValue)
{
	health = health - damageValue;
}

Shield::~Shield()
{
}
void Shield::Draw(RenderWindow &window)
{
	window.draw(*this);
}