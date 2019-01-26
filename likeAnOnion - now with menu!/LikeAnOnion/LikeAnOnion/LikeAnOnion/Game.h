#pragma once



#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Enums.h"
#include "MyVector3.h"
#include "Xbox360Controller.h"

#include "Player.h"
#include "collision.h"

#include "Scenery.h"
#include "Menu.h"
#include "AboutScreen.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	static GameMode m_gameMode;

protected:

	Scenery m_forest;

	void intialize();
	void update(sf::Time t_deltaTime);
	void processInput();
	void render();

	sf::RenderWindow m_renderWin;
	Xbox360Controller m_gameControllerPad;
	Player m_player;
	sf::View m_gameCamera;

	MainMenu m_menuScreen;

	AboutScreen m_aboutScreen;
};
