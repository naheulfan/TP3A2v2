#pragma once
#include "Projectiles.h"
class EmpoweredShot : public Projectiles
{
public:
	EmpoweredShot(Vector2f basePosition, bool baseDirection);
	void Update();
	~EmpoweredShot();
};
