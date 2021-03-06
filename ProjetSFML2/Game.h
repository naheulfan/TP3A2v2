#pragma once
#include "Fabrique.h"
#include "Mothership.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "BaseEnemy.h"
#include "BaseProjectile.h"
#include "EnnemiProjectile.h"
#include "PileVector.h"
#include "Bonus.h"
#include "Hud.h"

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
	void backgroundUpdate();
	void playerUpdate();
	void enemiesUpdate();
	void projectileUpdate();
	void update();
	void draw();

	CircleShape spawner;
	int spawnNumber;

	//Notre vecteur de pointeurs de la super-classe
	std::vector<Ennemi*> vecteurEnnemis;

	Color color;
	Clock spawnRate;
	int activeEnemies = 0;

	int randomEnemy;
	int randomSpawn;
	int randomColor;

	RenderWindow mainWin;
	View view;
	Event event;
	Texture backgroundT;
	Texture texturesEnnemis[5];
	Sprite background[2];
	Texture playerTexture;
	Player player;
	int interfaceCommande;
	Ennemi* ennemies[3];
	bool gauche = false;
	bool droite = false;
	bool haut = false;
	bool bas = false;
	bool space = false;
	std::vector<Projectiles*> projectiles;
	Sprite baseProjectile;
	Texture baseProjectileT;
	Texture bonusesT[7];
	Bonus* bonuses[7];
	Hud hud;
	Font font;

};