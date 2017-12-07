#pragma once
#include <SFML/Graphics.hpp>
#include "Cargoship.h"
#include "BaseEnemy.h"
#include "Fighter.h"
#include "StealthFighter.h"
#include "TypeEnnemi.h"
using namespace sf;

class Fabrique
{
public:
	static void chargerData(RenderWindow* renderWindow);
	static void setPosition(const Vector2f& position);
	static Ennemi* createEnemy(TypeEnnemi enemyType, Texture texture, Color enemyColor);
private:
	Fabrique();
	static Vector2f position;
	static RenderWindow* renderWindow;
};