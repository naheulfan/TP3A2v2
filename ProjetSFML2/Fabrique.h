#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Fabrique
{
public:
	static void chargerData(RenderWindow* renderWindow)
	{
		Fabrique::renderWindow = renderWindow;
	}

	static void setPosition(const Vector2f& position)
	{
		Fabrique::position = position;
	}

	/*static Enemies* createEnemy()
	{
		return nullptr;
	}*/

private:
	Fabrique();
	static Vector2f position;
	static RenderWindow* renderWindow;
};

Vector2f Fabrique::position;
RenderWindow* Fabrique::renderWindow;