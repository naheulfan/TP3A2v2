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
private:
	Sprite sprite;
};

