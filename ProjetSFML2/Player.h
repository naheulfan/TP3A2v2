#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Player
{
public:
	Player();
	Player(Vector2f basePos);
	~Player();
	void Init(Texture &playerTexture);
	void Update();
	void Draw(RenderWindow &window);
	void SetPosition(Vector2f newpos);
	Vector2f GetPosition();
private:
	Vector2f position;
	Sprite sprite;
};

