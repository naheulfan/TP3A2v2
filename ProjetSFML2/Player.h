#pragma once
#include <SFML\Graphics.hpp>
#include "BaseProjectile.h"
#include "Shield.h"
#include "PileVector.h"
#include "PiercingShot.h"
#include "EmpoweredShot.h"
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
	int GetHealth();
	void Damage(int damageValue, TypeProjectile damageColor);
	void AddShield();
	void AddAmmo(TypeProjectile typeOfAmmo);
	int GetAmmo();
private:
	PileVector<Shield> shields;
	const float speed = 10;
	TypeProjectile currentWeapon;
	Clock fireRate;
	bool leftShot;
	int health;
	int ammo[5];
};

