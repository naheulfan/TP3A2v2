#include "Game.h"

Game::Game()
{
	//On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
}

int Game::testTest()
{
	return 0;
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
	backgroundT.loadFromFile("Ressources\\starfieldSprite.png");
	background[0].setTexture(backgroundT);
	background[0].setPosition(0, 0);
	background[1].setTexture(backgroundT);
	background[1].setPosition(2560, 0);
	playerTexture.loadFromFile("Ressources\\Spaceship.png");
	player.Init(playerTexture);
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
		if (event.type == Event::KeyPressed)
		{
			Vector2f position = player.GetPosition();
			if (Keyboard::isKeyPressed(Keyboard::Key::W))
			{
				player.SetPosition(Vector2f(position.x, position.y - 8));
			}
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


}

void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();
	mainWin.draw(background[0]);
	mainWin.draw(background[1]);
	player.Draw(mainWin);
	mainWin.display();
}