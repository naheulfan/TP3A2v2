#pragma once
#include "Ennemi.h"

class Fighter : public Ennemi
{
public:
	Fighter(Vector2f basePos, Texture texture);
	~Fighter();
	void Update();
	void Draw(RenderWindow &window);
private:
	float speed;
};