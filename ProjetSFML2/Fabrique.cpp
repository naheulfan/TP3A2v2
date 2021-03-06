#include "Fabrique.h"
Vector2f Fabrique::position;
RenderWindow* Fabrique::renderWindow;

void Fabrique::chargerData(RenderWindow* renderWindow)
{
	Fabrique::renderWindow = renderWindow;
}

void Fabrique::setPosition(const Vector2f& position)
{
	Fabrique::position = position;
}

Ennemi* Fabrique::createEnemy(TypeEnnemi enemyType, Texture texture, Color enemyColor)
{
	if (enemyType == baseEnemy)
	{
		Ennemi* enemy = new BaseEnemy(Vector2f(position.x, position.y), texture, enemyColor, baseEnemy);
		return enemy;
	}

	else if (enemyType == fighter)
	{
		Ennemi* enemy = new Fighter(Vector2f(position.x, position.y), texture, enemyColor, fighter);
		return enemy;
	}

	else if (enemyType == stealthFighter)
	{
		Ennemi* enemy = new StealthFighter(Vector2f(position.x, position.y), texture, enemyColor, stealthFighter);
		return enemy;
	}

	else if (enemyType == cargoship)
	{
		Ennemi* enemy = new Cargoship(Vector2f(position.x, position.y), texture, enemyColor, cargoship);
		return enemy;
	}
	return nullptr;
}