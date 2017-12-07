#pragma once
#include "Ennemi.h"

class StealthFighter : public Ennemi
{
public:
	StealthFighter(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType);
	~StealthFighter();
	void Update();
	void Draw(RenderWindow &window);
private:
	float speed;
};