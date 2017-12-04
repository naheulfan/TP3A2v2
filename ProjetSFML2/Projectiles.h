#pragma once
#include <SFML\Graphics.hpp>
enum TypeProjectile
{
	base,
	piercing,
	emp,
	explosive,
	empowered,//les 5 premiers types appartiennent au joueur
	red,
	blue,
	green,//les couleurs des projectiles
	boss//les projectiles du boss ignorent la couleur du bouclier actif
};
using namespace sf;
class Projectiles : public Sprite
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Projectiles"/> class.
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="baseDirection">if set to <c>true</c> [right] else [left].</param>
	Projectiles(Vector2f position, bool baseDirection);
	~Projectiles();
	virtual void Update() = 0;
	void Draw(Sprite &sprite, RenderWindow &window);
	float GetDamage();
	TypeProjectile GetProjectileType();
protected:
	bool direction; //true = right, false = left
	TypeProjectile projectileType;
	float speed;
	float damage;
};

