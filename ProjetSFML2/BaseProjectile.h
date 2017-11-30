#pragma once
#include "Projectiles.h"
using namespace sf;
class BaseProjectile : public Projectiles
{
public:
	BaseProjectile(Vector2f basePosition, bool baseDirection);
	void Update();
	~BaseProjectile();
};

