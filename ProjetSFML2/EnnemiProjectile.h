#pragma once
#include "Projectiles.h"

class EnnemiProjectile : public Projectiles
{
public:
	EnnemiProjectile(Vector2f basePosition, bool direction, TypeProjectile projectileType);
	~EnnemiProjectile();
	void Update();
};

