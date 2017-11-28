#pragma once
#include "Fabrique.h"
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

	CircleShape spawner;
	int spawnNumber;

	//Notre vecteur de pointeurs de la super-classe
	std::vector<Ennemi*> vecteurEnnemis;

	//To remove
	int compteurGlobal = 1;
	//To remove

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
};