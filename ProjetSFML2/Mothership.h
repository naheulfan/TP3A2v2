#pragma once
#include "Ennemi.h"

class Mothership : public Ennemi
{
public:
	Mothership(Vector2f basePos, Texture texture);
	~Mothership();
	void Update();
	void Draw(RenderWindow &window);
private:
	
};