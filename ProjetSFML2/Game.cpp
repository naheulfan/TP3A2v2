#include "Game.h"
#include "Collisions.h"
#include <iostream>

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

	baseProjectileT.loadFromFile("Ressources\\BaseProjectile.png");
	baseProjectile.setTexture(baseProjectileT);
	if (!bonusesT[0].loadFromFile("Ressources\\PiercingBonus.png"))
	{
		return false;
	}
	if (!bonusesT[1].loadFromFile("Ressources\\EmpoweredBonus.png"))
	{
		return false;
	}
	if (!bonusesT[2].loadFromFile("Ressources\\BombBonus.png"))
	{
		return false;
	}
	if (!bonusesT[3].loadFromFile("Ressources\\EmpBonus.png"))
	{
		return false;
	}
	if (!bonusesT[4].loadFromFile("Ressources\\Bomb.png"))
	{
		return false;
	}
	if (!bonusesT[5].loadFromFile("Ressources\\EmpBomb.png"))
	{
		return false;
	}
	if (!bonusesT[6].loadFromFile("Ressources\\ShieldBonus.png"))
	{
		return false;
	}
	BonusType bonusTypes[7]{ BonusType::piercingBonus, BonusType::empoweredBonus, BonusType::explosiveShot, BonusType::empShot, BonusType::bomb, BonusType::empBomb, BonusType::shield };
	for (int i = 0; i < 7; i++)
	{
		bonuses[i] = new Bonus(Vector2f(0, 0), bonusesT[i], bonusTypes[i]);
	}
	font.loadFromFile("Ressources\\Peric.ttf");
	hud.Init(&font);
	return true;
}

void Game::getInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�us
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
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			space = true;
		}
		else
		{
			space = false;
		}
		
		//Permet de faire appara�tre l'ennemi d�sir� � l'aide des touches Num1, Num2, Num3 et Num4
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Num1)
			{
				player.SetCurrentWeapon(TypeProjectile::base);
				hud.SetWeaponText("Arme Actuelle: Base");
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				player.SetCurrentWeapon(TypeProjectile::piercing);
				hud.SetWeaponText("Arme Actuelle: Percante");
			}

			else if (event.key.code == sf::Keyboard::Num3)
			{
				player.SetCurrentWeapon(TypeProjectile::empowered);
				hud.SetWeaponText("Arme Actuelle: Empowered");
			}

			else if (event.key.code == sf::Keyboard::Num4)
			{
				player.SetCurrentWeapon(TypeProjectile::base);
				hud.SetWeaponText("Arme Actuelle: Base");
			}
			else if (event.key.code == sf::Keyboard::Num5)
			{
				player.SetCurrentWeapon(TypeProjectile::base);
				hud.SetWeaponText("Arme Actuelle: Base");

			}
		}
	}
}

void Game::backgroundUpdate()
{
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
}

void Game::playerUpdate()
{
	//On v�rifie que le joueur ne sort pas de l'�cran
	if (player.getPosition().x <= 0)
		gauche = false;
	if (player.getPosition().x >= LARGEUR_ECRAN - ennemies[0]->getGlobalBounds().width - player.getGlobalBounds().width)
		droite = false;

	//Si le joueur atteint le haut de l'�cran, va r�appara�tre au bas de l'�cran
	if (player.getPosition().y <= 0 - player.getGlobalBounds().height)
		player.setPosition(player.getPosition().x, HAUTEUR_ECRAN);
	//Sinon, si le joueur atteint le bas de l'�cran, va r�appara�tre au haut de l'�cran
	else if (player.getPosition().y >= HAUTEUR_ECRAN)
		player.setPosition(player.getPosition().x, 0 - player.getGlobalBounds().height);

	if (gauche) player.Move(4);
	if (droite) player.Move(3);
	if (haut) player.Move(1);
	if (bas) player.Move(2);
	if (space && player.CanShoot()) projectiles.push_back(player.Shoot());
	for (int i = 0; i < 7; i++)
	{
		if (bonuses[i]->IsActive() && player.getGlobalBounds().intersects(bonuses[i]->getGlobalBounds()))
		{
			bonuses[i]->Deactivate();
			if (bonuses[i]->GetBonusType() == BonusType::shield)
			{
				player.AddShield();
			}
			else if (bonuses[i]->GetBonusType() == BonusType::piercingBonus)
			{
				player.AddAmmo(TypeProjectile::piercing);
			}
			else if (bonuses[i]->GetBonusType() == BonusType::empoweredBonus)
			{
				player.AddAmmo(TypeProjectile::empowered);
			}
		}
	}
}

void Game::projectileUpdate()
{
	PileVector<int> indexOfProjectilesToDelete;
	for (int i = 0; i < projectiles.size(); i++)
	{
		baseProjectile.setPosition(projectiles.at(i)->getPosition());
		
		projectiles.at(i)->Update();
		if (projectiles.at(i)->getPosition().x > LARGEUR_ECRAN)
		{
			indexOfProjectilesToDelete.Push(i);
		}
		if (projectiles.at(i)->IsPlayerProjectile())
		{
			for (int j = 0; j < vecteurEnnemis.size(); j++)
			{
				if (vecteurEnnemis.at(j)->getGlobalBounds().intersects(baseProjectile.getGlobalBounds()))
				{
					vecteurEnnemis.at(j)->Damage(projectiles.at(i)->GetDamage());
					if (projectiles.at(i)->GetProjectileType() != TypeProjectile::piercing)
					{
						indexOfProjectilesToDelete.Push(i);
					}
					if (vecteurEnnemis.at(j)->GetHealth() <= 0)
					{
						int bonusDrop = rand() % 100;
						if (bonusDrop <= 6)
						{
							if (!bonuses[bonusDrop]->IsActive())
							{
								bonuses[bonusDrop]->Activate(vecteurEnnemis.at(j)->getPosition());
							}
						}
						vecteurEnnemis.erase(vecteurEnnemis.begin() + j);
						--activeEnemies;
					}
				}
			}
		}
		else if (!projectiles.at(i)->IsPlayerProjectile())
		{
			if (player.getGlobalBounds().intersects(baseProjectile.getGlobalBounds()))
			{
				player.Damage(projectiles.at(i)->GetDamage(), projectiles.at(i)->GetProjectileType());
				indexOfProjectilesToDelete.Push(i);
			}
		}
			if (ennemies[0]->getGlobalBounds().intersects(baseProjectile.getGlobalBounds()))
			{
				ennemies[0]->Damage(projectiles.at(i)->GetDamage());
				indexOfProjectilesToDelete.Push(i);
			}
	}
	while (!indexOfProjectilesToDelete.IsEmpty())
	{
		projectiles.erase(projectiles.begin() + indexOfProjectilesToDelete.Top());
		indexOfProjectilesToDelete.Pop();
	}
}

void Game::enemiesUpdate()
{
	ennemies[0]->Update();
	randomEnemy = rand() % 100;
	if (activeEnemies <= 15)
	{
		if (spawnRate.getElapsedTime() > seconds(0.4))
		{
			if ((randomEnemy >= 0 && randomEnemy < 50))
			{
				spawnNumber = 1;
			}
			else if ((randomEnemy >= 50 && randomEnemy < 80))
			{
				spawnNumber = 2;
			}

			else if ((randomEnemy >= 80 && randomEnemy < 90))
			{
				spawnNumber = 3;
			}

			else if ((randomEnemy >= 95 && randomEnemy < 100))
			{
				spawnNumber = 4;
			}
			++activeEnemies;
			spawnRate.restart();
		}
	}

	if (spawnNumber > 0)
	{
		randomSpawn = rand() % 650;
		randomColor = rand() % 3;
		if (randomColor == 0)
		{
			color = Color::Red;
		}
		else if (randomColor == 1)
		{
			color = Color::Blue;
		}
		else if (randomColor == 2)
		{
			color = Color::Green;
		}

		spawner.setPosition(LARGEUR_ECRAN - (texturesEnnemis[0].getSize().x)+100, randomSpawn);
		Fabrique::setPosition(spawner.getPosition());
		switch (spawnNumber)
		{
		case 1:
			vecteurEnnemis.push_back(Fabrique::createEnemy(baseEnemy, texturesEnnemis[1], color));
			break;
		case 2:
			vecteurEnnemis.push_back(Fabrique::createEnemy(fighter, texturesEnnemis[2], color));
			break;
		case 3:
			vecteurEnnemis.push_back(Fabrique::createEnemy(stealthFighter, texturesEnnemis[3], color));
			break;
		case 4:
			vecteurEnnemis.push_back(Fabrique::createEnemy(cargoship, texturesEnnemis[4], color));
			break;
		}
		spawnNumber = 0;

	}

	for (int i = 0; i < vecteurEnnemis.size(); i++)
	{
		if (vecteurEnnemis.at(i)->getPosition().x < 0 - vecteurEnnemis.at(i)->getGlobalBounds().width && vecteurEnnemis[i]->getTypeEnnemi() != stealthFighter)
		{
			vecteurEnnemis.erase(vecteurEnnemis.begin() + i);
			--activeEnemies;
		}
		if (vecteurEnnemis.at(i)->getPosition().x >= LARGEUR_ECRAN && vecteurEnnemis[i]->getTypeEnnemi() == stealthFighter)
		{
			vecteurEnnemis.at(i)->setPosition(0 - vecteurEnnemis.at(i)->getGlobalBounds().width, vecteurEnnemis.at(i)->getPosition().y);
		}
	}
	for (int i = 0; i < vecteurEnnemis.size(); i++)
	{
		vecteurEnnemis[i]->Update();

		if (vecteurEnnemis.at(i)->getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			player.Damage(vecteurEnnemis.at(i)->GetHealth(),vecteurEnnemis.at(i)->GetColor());
			vecteurEnnemis.erase(vecteurEnnemis.begin() + i);
			--activeEnemies;
		}
	}
	for (int i = 0; i < vecteurEnnemis.size(); i++)
	{
		if (vecteurEnnemis.at(i)->getTypeEnnemi() == TypeEnnemi::fighter || vecteurEnnemis.at(i)->getTypeEnnemi() == TypeEnnemi::stealthFighter)
		{
			if (vecteurEnnemis.at(i)->CanShoot())
			{
				projectiles.push_back(vecteurEnnemis.at(i)->Shoot());
			}
		}
	}
	std::cout << "Ennemis actifs: " << activeEnemies << std::endl;
}

void Game::update()
{
	backgroundUpdate();
	playerUpdate();
	projectileUpdate();
	enemiesUpdate();
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

	for (int i = 0; i < projectiles.size(); i++)
	{
		if (projectiles.at(i)->GetProjectileType() == TypeProjectile::blue)
		{
			baseProjectile.setColor(Color::Blue);
		}
		else if (projectiles.at(i)->GetProjectileType() == TypeProjectile::green)
		{
			baseProjectile.setColor(Color::Green);
		}
		else if (projectiles.at(i)->GetProjectileType() == TypeProjectile::red)
		{
			baseProjectile.setColor(Color::Red);
		}
		else
		{
			baseProjectile.setColor(Color::White);
		}
		projectiles.at(i)->Draw(baseProjectile, mainWin);
	}
	for (int i = 0; i < 7; i++)
	{
		if (bonuses[i]->IsActive())
		{
			mainWin.draw(*bonuses[i]);
		}
	}
	if (player.GetAmmo() == -1)
	{
		hud.SetAmmoText("ammo: inf");
	}
	else
	{
		hud.SetAmmoText("ammo: " + std::to_string(player.GetAmmo()));
	}
	hud.SetLifeText("vie: " + std::to_string(player.GetHealth()));
	hud.Draw(mainWin);
	mainWin.display();
}