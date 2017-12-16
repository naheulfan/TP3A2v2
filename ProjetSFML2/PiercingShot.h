#pragma once
#include "Projectiles.h"
class PiercingShot : public Projectiles
{
public:
	PiercingShot(Vector2f basePosition, bool baseDirection);
	PiercingShot();
	~PiercingShot();
	void Update();
};

