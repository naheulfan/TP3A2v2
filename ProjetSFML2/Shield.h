#pragma once
#include <SFML\Graphics.hpp>
#include "Projectiles.h"
using namespace sf;
class Shield : public Sprite
{
public:
	Shield(Vector2f position);
	~Shield();
	TypeProjectile GetColor();
	int GetHealth();
	void Damage(int damageValue);
	void Draw(RenderWindow &window);
private:
	int health;
	TypeProjectile shieldColor;
	Texture shieldTexture;
};

