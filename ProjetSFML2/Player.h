#pragma once
#include <SFML\Graphics.hpp>
#include "BaseProjectile.h"
using namespace sf;
class Player : public Sprite
{
public:
	Player();
	~Player();
	void Init(Texture &playerTexture, Vector2f basePos);
	void Draw(RenderWindow &window);
	void Move(int command);
	Projectiles* Shoot();
	void SetCurrentWeapon(TypeProjectile newWeapon);
	bool CanShoot();
private:
	const float speed = 10;
	TypeProjectile currentWeapon;
	Clock fireRate;
	bool leftShot;
};

