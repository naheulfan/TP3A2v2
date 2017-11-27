#pragma once
#include "BaseEnemy.h"
#include "Mothership.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"

using namespace sf;

class Game
{
public:
	Game();
	int run();

private:
	const int LARGEUR_ECRAN = 1280;
	const int HAUTEUR_ECRAN = 720;

	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;
	Texture backgroundT;
	Texture enemyTexture;
	Texture enemyTexture2;
	Sprite background[2];
	Texture playerTexture;
	Player player;
	int interfaceCommande;
	Ennemi* ennemies[3];
};