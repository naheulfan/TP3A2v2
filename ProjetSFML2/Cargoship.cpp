#include "Cargoship.h"



Cargoship::Cargoship(Vector2f basePos, Texture texture, Color color) : Ennemi(basePos, texture, color)
{
	speed = 1;
	health = 5;
}

Cargoship::~Cargoship()
{
}

void Cargoship::Update()
{
	Ennemi::Update();
	this->move(Vector2f(-speed, 0));
}
void Cargoship::Draw(RenderWindow &window)
{
	window.draw(*this);
}