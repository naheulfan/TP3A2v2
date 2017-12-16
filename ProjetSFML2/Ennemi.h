#pragma once
#include <SFML\Graphics.hpp>
#include "CollisionSphere.h"
#include "Projectiles.h"
#include "TypeEnnemi.h"
#include "EnnemiProjectile.h"

using namespace sf;
class Ennemi : public Sprite
{
public:
	Ennemi(Vector2f basePos, Texture texture, Color color, TypeEnnemi enemyType);
	~Ennemi();
	virtual void Update() = 0;
	virtual void Draw(RenderWindow &window) = 0;
	void Damage(float damageValue);
	float GetHealth();
	TypeProjectile GetColor();
	TypeEnnemi getTypeEnnemi();
	virtual EnnemiProjectile* Shoot();
	bool CanShoot();
private:
	Texture texture;
	Color color;
	CollisionSphere collisionSphere;
	TypeEnnemi enemyType;
protected:
	float health;
	Clock shootClock;
};

