#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Player
{
public:
	Player();
	~Player();
	void Init(Texture playerTexture);
	void Update();
	void Draw();
private:
	Vector2f position;
};

