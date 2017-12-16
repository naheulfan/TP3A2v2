#pragma once
#include "Ennemi.h"
#include "EnnemiProjectile.h"

class Fighter : public Ennemi
{
public:
	Fighter(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType);
	~Fighter();
	void Update();
	void Draw(RenderWindow &window);
	EnnemiProjectile* Shoot();
	bool CanShoot();
private:
	float speed;
	Clock shootClock;
};