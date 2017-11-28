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
	for (int i = 0; i < 5; i++)
	{
		if (!texturesEnnemis[i].loadFromFile("Ressources\\Enemy_" + std::to_string(i + 1) + ".png"))
		{
			return false;
		}
	}

	//Initie le spawner et le boss
	ennemies[0] = new Mothership(Vector2f(LARGEUR_ECRAN - (texturesEnnemis[0].getSize().x), HAUTEUR_ECRAN / 5), texturesEnnemis[0]);
	spawner.setRadius(25);
	spawner.setOrigin(25, 25);
	spawner.setFillColor(Color::Transparent);
	spawner.setOutlineColor(Color::Red);
	spawner.setOutlineThickness(3);
	spawner.setPosition(LARGEUR_ECRAN - (texturesEnnemis[0].getSize().x), texturesEnnemis[0].getSize().y / 2);

	//Charge les donn�es de la fabrique
	Fabrique::chargerData(&mainWin);
	
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
		(Keyboard::isKeyPressed(Keyboard::W)) ? haut = true : haut = false;
		(Keyboard::isKeyPressed(Keyboard::S)) ? bas = true : bas = false;
		(Keyboard::isKeyPressed(Keyboard::A)) ? gauche = true : gauche = false;
		(Keyboard::isKeyPressed(Keyboard::D)) ? droite = true : droite = false;

		//Permet de faire appara�tre l'ennemi d�sir� � l'aide des touches Num1, Num2, Num3 et Num4
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Num1)
			{
				spawnNumber = 1;
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				spawnNumber = 2;
			}

			else if (event.key.code == sf::Keyboard::Num3)
			{
				spawnNumber = 3;
			}

			else if (event.key.code == sf::Keyboard::Num4)
			{
				spawnNumber = 4;
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

	if (gauche) player.Move(4);
	if (droite) player.Move(3);
	if (haut) player.Move(1);
	if (bas) player.Move(2);

	ennemies[0]->Update();
	if (spawnNumber > 0)
	{
		Fabrique::setPosition(spawner.getPosition());
		switch (spawnNumber)
		{
		case 1:
			vecteurEnnemis.push_back(Fabrique::createEnemy(baseEnemy, texturesEnnemis[1]));
			break;
		case 2:
			vecteurEnnemis.push_back(Fabrique::createEnemy(fighter, texturesEnnemis[2]));
			break;
		case 3:
			vecteurEnnemis.push_back(Fabrique::createEnemy(stealthFighter, texturesEnnemis[3]));
			break;
		case 4:
			vecteurEnnemis.push_back(Fabrique::createEnemy(cargoship, texturesEnnemis[4]));
			break;
		}
		spawnNumber = 0;
	}
}

void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();
	mainWin.draw(background[0]);
	mainWin.draw(background[1]);
	ennemies[0]->Draw(mainWin);
	for (int i = 0; i < vecteurEnnemis.size(); i++)
	{
		vecteurEnnemis[i]->Draw(mainWin);
	}
	player.Draw(mainWin);
	mainWin.display();
}