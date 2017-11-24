#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Player : public Sprite
{
public:
	Player();
	Player(Vector2f basePos);
	~Player();
	void Init(Texture &playerTexture, Vector2f basePos);
	void Update();
	void Draw(RenderWindow &window);
	void Move(int command, int axis);
private:
	Sprite sprite;
	const float speed = 10;
};

