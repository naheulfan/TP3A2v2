#include "Game.h"

Game::Game()
{
	//On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner

	mainWin.create(VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32), "TP3 Side scroller");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
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
	enemyTexture.loadFromFile("Ressources\\pant.png");
	ennemies[0] = new BaseEnemy(Vector2f(LARGEUR_ECRAN, HAUTEUR_ECRAN / 2), enemyTexture);
	return true;
}

void Game::getInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�u!
	while (mainWin.pollEvent(event))
	{
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
		interfaceCommande = 0;
		if (event.type == Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				interfaceCommande = 4;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				interfaceCommande = 3;
			}
			player.Move(interfaceCommande, 1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				interfaceCommande = 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				interfaceCommande = 1;
			}
			player.Move(interfaceCommande, 2);
		}
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
#pragma endregion BackgroundUpdates
	ennemies[0]->Update();

}

void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();
	mainWin.draw(background[0]);
	mainWin.draw(background[1]);
	ennemies[0]->Draw(mainWin);
	player.Draw(mainWin);
	mainWin.display();
}