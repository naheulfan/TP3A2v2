#pragma once
#include <SFML\Graphics.hpp>
#include "CollisionSphere.h"
using namespace sf;
class Ennemi : public Sprite
{
public:
	Ennemi(Vector2f basePos, Texture texture);
	~Ennemi();
	virtual void Update() = 0;
	virtual void Draw(RenderWindow &window) = 0;
	IntRect getIntRect();
	void Damage(float damageValue);
	float GetHealth();
private:
	Texture texture;
	CollisionSphere collisionSphere;
protected:
	float health;
};

