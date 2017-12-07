#pragma once
#include <SFML\Graphics.hpp>
#include "CollisionSphere.h"
#include "Projectiles.h"
using namespace sf;
class Ennemi : public Sprite
{
public:
	Ennemi(Vector2f basePos, Texture texture, Color color);
	~Ennemi();
	virtual void Update() = 0;
	virtual void Draw(RenderWindow &window) = 0;
	void animation();
	IntRect getIntRect();
	void Damage(float damageValue);
	float GetHealth();
	TypeProjectile GetColor();
private:
	Texture texture;
	Color color;
	CollisionSphere collisionSphere;
protected:
	float health;
};

