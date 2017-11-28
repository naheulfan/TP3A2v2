#include "Game.h"

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32), "TP3 Side scroller");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
}

int Game::run()
{
	if (!init())
	{
		return EXIT_FAILURE;
	}

	while (mainWin.isOpen())
	{
		getInputs();
		update();
		draw();
	}

	return EXIT_SUCCESS;
}

bool Game::init()
{
	if(!backgroundT.loadFromFile("Ressources\\starfieldSprite.png"))
	{
		return false;
	}
	background[0].setTexture(backgroundT);
	background[0].setPosition(0, 0);
	background[1].setTexture(backgroundT);
	background[1].setPosition(2560, 0);

	if(!playerTexture.loadFromFile("Ressources\\Spaceship.png"))
	{
		return false;
	}
	player.Init(playerTexture, Vector2f(0, HAUTEUR_ECRAN / 2));
	enemyTexture.loadFromFile("Ressources\\Ennemi1.png");
	enemyTexture2.loadFromFile("Ressources\\Mothership.png");
	ennemies[0] = new BaseEnemy(Vector2f(LARGEUR_ECRAN, HAUTEUR_ECRAN / 5), enemyTexture);
	ennemies[1] = new Mothership(Vector2f(LARGEUR_ECRAN - (enemyTexture2.getSize().x), HAUTEUR_ECRAN / 5), enemyTexture2);
	ennemies[2] = new BaseEnemy(Vector2f(LARGEUR_ECRAN, HAUTEUR_ECRAN - (HAUTEUR_ECRAN / 3)), enemyTexture);
	return true;
}

void Game::getInputs()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
		(Keyboard::isKeyPressed(Keyboard::W)) ? haut = true : haut = false;
		(Keyboard::isKeyPressed(Keyboard::S)) ? bas = true : bas = false;
		(Keyboard::isKeyPressed(Keyboard::A)) ? gauche = true : gauche = false;
		(Keyboard::isKeyPressed(Keyboard::D)) ? droite = true : droite = false;
		
	}
}

void Game::update()
{
#pragma region BackgroundUpdates
	background[0].setPosition(Vector2f(background[0].getPosition().x - 2, background[0].getPosition().y));
	background[1].setPosition(Vector2f(background[1].getPosition().x - 2, background[1].getPosition().y));
	if (background[0].getPosition().x <= -1280 && (background[1].getPosition().x > 1280 || background[1].getPosition().x <= -1280))
	{
		background[1].setPosition(Vector2f(1280, 0));

	}
	else if (background[0].getPosition().x <= -2560)
	{
		background[0].setPosition(1280, 0);
	}
	if (gauche) player.Move(4);
	if (droite) player.Move(3);
	if (haut) player.Move(1);
	if (bas) player.Move(2);
#pragma endregion BackgroundUpdates
	ennemies[0]->Update();
	ennemies[2]->Update();

}

void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();
	mainWin.draw(background[0]);
	mainWin.draw(background[1]);
	for (int i = 0; i < 3; i++)
	{
		ennemies[i]->Draw(mainWin);
	}
	player.Draw(mainWin);
	mainWin.display();
}