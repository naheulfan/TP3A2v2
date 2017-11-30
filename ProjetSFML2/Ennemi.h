#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
class Ennemi : public Sprite
{
public:
	Ennemi(Vector2f basePos, Texture texture);
	~Ennemi();
	virtual void Update() = 0;
	virtual void Draw(RenderWindow &window) = 0;
	IntRect getIntRect();
private:
	Texture texture;
	Sprite sprite;
protected:
	float health;
};

