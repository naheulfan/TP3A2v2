#include "Bonus.h"



Bonus::Bonus(Vector2f position, Texture &bonusTexture, BonusType bonus)
{
	this->setPosition(position);
	this->setTexture(bonusTexture);
	typeOfBonus = bonus;
	activated = false;
}


Bonus::~Bonus()
{
}
void Bonus::Activate(Vector2f position)
{
	activated = true;
	setPosition(position);
}
void Bonus::Deactivate()
{
	activated = false;
}
bool Bonus::IsActive()
{
	return activated;
}
BonusType Bonus::GetBonusType()
{
	return typeOfBonus;
}
