#pragma once
#include <SFML\Graphics.hpp>
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
protected:
	bool direction; //true = right, false = leftno u

};

