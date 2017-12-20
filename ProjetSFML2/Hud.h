#pragma once
#include<SFML\Graphics.hpp>
#include <string>
using namespace sf;
class Hud
{
public:
	Hud();
	void Init(Font *font);
	void Draw(RenderWindow &window);
	void SetWeaponText(std::string weaponString);
	void SetAmmoText(std::string ammoString);
	void SetLifeText(std::string lifeString);
	void SetScoreText(std::string scoreString);
	~Hud();
private:
	Text weaponText;
	Text ammoText;
	Text lifeText;
	Text score;
};

