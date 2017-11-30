#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Player : public Sprite
{
public:
	Player();
	~Player();
	void Init(Texture &playerTexture, Vector2f basePos);
	void Draw(RenderWindow &window);
	void Move(int command);
private:
	const float speed = 10;
};

