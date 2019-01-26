#include "Game.h"


GameMode Game::m_gameMode{ GameMode::Licence };

// Contructor

Game::Game() :

	m_renderWin{ sf::VideoMode{ 1600, 1600, 1 }, "Like An Onion" },
	m_forest(5)
	
{
	// Textures
	m_floorTexture.loadFromFile("floor.png");
	m_floor.setTexture(m_floorTexture);
	m_floor.setOrigin(m_floor.getGlobalBounds().width/ 2, m_floor.getGlobalBounds().height / 2);

	m_standngFloorTexture.loadFromFile("doubleSky.jpg");
	m_standngFloor.setTexture(m_standngFloorTexture);
	m_standngFloor.setOrigin(m_standngFloor.getGlobalBounds().width / 2, m_standngFloor.getGlobalBounds().height / 2);
	m_standngFloor.setPosition(m_floor.getPosition().x, m_floor.getPosition().y - (m_floor.getGlobalBounds().height / 2 + m_standngFloor.getGlobalBounds().height / 2) + 1);
	m_gameCamera.setSize(1600, 1600);
}

/// Destructor
Game::~Game()
{
}


// Loop designed to work at equal speed on all PCs
// If a PC is slower, it will update the same amount of times
// And render less often
void Game::run()
{
	sf::Clock gameClock;											// Game clock
	sf::Time timeTakenForUpdate = sf::Time::Zero;					// No lag on first input
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);				// 60 frames per second
	while (m_renderWin.isOpen())									// Loop
	{
		processInput();												// Check for input
		timeTakenForUpdate += gameClock.restart();					// Returns time take to do the loop
		while (timeTakenForUpdate > timePerFrame)					// Update enough times to catch up on updates missed during the lag time
		{
			timeTakenForUpdate -= timePerFrame;						// Decrement lag
			processInput();											// More checks, more accuracte input to display will be
			update(timePerFrame);									// Update
		}
		render();
	}
}


// Process PC input
void Game::processInput()
{
	sf::Event event;
	while (m_renderWin.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_renderWin.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_renderWin.close();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
		}
	}
}

// Updates Game
void Game::update(sf::Time t_deltaTime)
{
	m_gameControllerPad.update();

	switch(m_gameMode)					// Switch to control the screens
	{
	case GameMode::Licence:
		m_player.update(t_deltaTime, &m_gameControllerPad);
		m_gameCamera.setCenter(sf::Vector2f{ m_player.getPosition().x, m_player.getPosition().y - 300 });
		break;
	case GameMode::Splash:
		break;
	case GameMode::Menu:
		break;
	case GameMode::Gameplay:
		break;
	default:
		break;
	}
	//m_forest.update(t_deltaTime, m_player.getBody(), m_player.getCurrentLayer());
	if (collision::isCollided(m_floor, *m_player.getBody()))
	{
		m_player.getBody()->setPosition(sf::Vector2f{ m_player.getBody()->getPosition().x,
			m_floor.getPosition().y - (m_floor.getGlobalBounds().height / 2 + m_player.getBody()->getGlobalBounds().height / 2)});
	//	std::cout << "hit" << std::endl;
	}

}

// Renders
void Game::render()
{
	m_renderWin.clear();
	switch (m_gameMode)					// Swtich to control the screens
	{
	case GameMode::Licence:
		break;
	case GameMode::Splash:
		break;
	case GameMode::Menu:
		break;
	case GameMode::Gameplay:
		break;
	default:
		break;
	}
	m_renderWin.draw(m_floor);
	m_renderWin.draw(m_standngFloor);
	m_renderWin.setView(m_gameCamera);
	for (int i = 0; i < 3; i++)
	{
		m_forest.render(m_renderWin, static_cast<Layers>(i));
		m_player.render(m_renderWin, static_cast<Layers>(i));  // Player after items becuase it needs to be on top it's current layer 
	}

	m_renderWin.display();
}

void Game::intialize()
{
}