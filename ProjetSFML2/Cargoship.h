#pragma once
#include "Ennemi.h"

class Cargoship : public Ennemi
{
public:
	Cargoship(Vector2f basePos, Texture texture);
	~Cargoship();
	void Update();
	void Draw(RenderWindow &window);
private:
	float speed;
};