#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
static class Collisions
{
public:
	static bool CheckCollision(IntRect firstObject, IntRect secondObject)
	{
		bool retval = false;
		if (firstObject.intersects(secondObject))
		{
			retval = true;
		}
		return retval;
	}
};
