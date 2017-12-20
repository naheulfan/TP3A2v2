#pragma once
#include <SFML\Graphics.hpp>
#include "Observer.h"
enum BonusType
{
	explosiveShot,
	empShot,
	shield,
	bomb,
	empBomb,
	piercingBonus,
	empoweredBonus
};
using namespace sf;
class Bonus : public Sprite
{
public:
	Bonus(Vector2f position, Texture &bonusTexture, BonusType bonus);
	~Bonus();
	void Deactivate();
	void Activate(Vector2f position);
	bool IsActive();
	BonusType GetBonusType();
private:
	BonusType typeOfBonus;
	bool activated;
};

