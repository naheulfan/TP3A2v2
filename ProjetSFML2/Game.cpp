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
	for (int i = 0; i < 5; i++)
	{
		if (!texturesEnnemis[i].loadFromFile("Ressources\\Enemy_" + std::to_string(i + 1) + ".png"))
		{
			return false;
		}
	}

	//Initie le spawner et le boss
	ennemies[0] = new Mothership(Vector2f(LARGEUR_ECRAN - (texturesEnnemis[0].getSize().x), HAUTEUR_ECRAN / 5), texturesEnnemis[0]);
	ennemies[1] = new BaseEnemy(Vector2f(LARGEUR_ECRAN - (texturesEnnemis[0].getSize().x), HAUTEUR_ECRAN / 5), texturesEnnemis[2]);
	/*spawner.setRadius(25);
	spawner.setOrigin(25, 25);
	spawner.setFillColor(Color::Transparent);
	spawner.setOutlineColor(Color::Red);
	spawner.setOutlineThickness(3);
	spawner.setPosition(LARGEUR_ECRAN - (texturesEnnemis[0].getSize().x), texturesEnnemis[0].getSize().y / 2);
*/
	//Charge les données de la fabrique
	//Fabrique::chargerData(window);
	baseProjectileT.loadFromFile("Ressources\\BaseProjectile.png");
	baseProjectile.setTexture(baseProjectileT);
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
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			space = true;
		}
		else
		{
			space = false;
		}


		//Permet de faire apparaître l'ennemi désiré à l'aide des touches Num1, Num2 et Num3
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
	if (gauche) player.Move(4);
	if (droite) player.Move(3);
	if (haut) player.Move(1);
	if (bas) player.Move(2);
	if (space && player.CanShoot()) projectiles.push_back(player.Shoot());
#pragma endregion BackgroundUpdates
	ennemies[0]->Update();
	ennemies[1]->Update();
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles.at(i)->Update();
	}
	if (spawnNumber > 0)
	{
		//Fabrique::setPosition(spawner.getPosition());
		//switch (spawnNumber)
		//{
		//case 1:
		//	vecteurEnnemis.push_back(Fabrique::createEnemy(Walker));
		//	break;
		//case 2:
		//	vecteurEnnemis.push_back(Fabrique::createEnemy(Flyer));
		//	break;
		//case 3:
		//	vecteurEnnemis.push_back(Fabrique::createEnemy(Hanger));
		//	break;
		//case 4:
		//	vecteurEnnemis.push_back(Fabrique::createEnemy(Hanger));
		//	break;
		//}

		//spawnNumber = 0;
	}

}

void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();
	mainWin.draw(background[0]);
	mainWin.draw(background[1]);
	for (int i = 0; i < 2; i++)
	{
		ennemies[i]->Draw(mainWin);
	}
	player.Draw(mainWin);
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles.at(i)->Draw(baseProjectile, mainWin);
	}
	mainWin.display();
}