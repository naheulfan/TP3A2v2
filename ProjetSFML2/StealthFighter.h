#pragma once
#include "Ennemi.h"
#include "EnnemiProjectile.h"

class StealthFighter : public Ennemi
{
public:
	StealthFighter(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType);
	~StealthFighter();
	void Update();
	void Draw(RenderWindow &window);
	EnnemiProjectile* Shoot();
private:
	float speed;
};