#include "Hud.h"



Hud::Hud()
{
}


Hud::~Hud()
{
}
void Hud::SetWeaponText(std::string weaponString)
{
	weaponText.setString(weaponString);
}
void Hud::SetAmmoText(std::string ammoString)
{
	ammoText.setString(ammoString);
}
void Hud::SetLifeText(std::string lifeString)
{
	lifeText.setString(lifeString);
}
void Hud::SetScoreText(std::string scoreString)
{
	score.setString(scoreString);
}
void Hud::Draw(RenderWindow &window)
{
	window.draw(weaponText);
	window.draw(ammoText);
	window.draw(lifeText);
	window.draw(score);
}
void Hud::Init(Font *font)
{
	weaponText.setFont(*font);
	weaponText.setPosition(10, 10);
	weaponText.setColor(Color::White);
	weaponText.setString("Arme Actuelle: Base");
	ammoText.setFont(*font);
	ammoText.setPosition(10, 30);
	ammoText.setColor(Color::White);
	ammoText.setString("ammo: inf");
	lifeText.setFont(*font);
	lifeText.setPosition(10, 50);
	lifeText.setColor(Color::White);
	lifeText.setString("vie: 5");
	score.setFont(*font);
	score.setPosition(10, 70);
	score.setColor(Color::White);
	score.setString("score: 0");
}
