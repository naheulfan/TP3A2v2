#pragma once
#include "Ennemi.h"

class BaseEnemy : public Ennemi
{
public:
	BaseEnemy(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType);
	~BaseEnemy();
	void Update();
	void Draw(RenderWindow &window);
private:
	float speed;
};

