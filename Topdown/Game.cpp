#include "Game.hpp"
#include "StaticFiles.hpp"

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::IsRunning() const
{
	return this->window->isOpen();
}

void Game::InitVariables()
{
	this->window = nullptr;
	ResourceManager::init();

	ResourceManager::getInstance().load("assets/textures/Tiles/backgrounddetailed1.png", "tile1");
	tile.setTexture(ResourceManager::getInstance().getTexture("tile1"));
	tile.setPosition(0, 0);

}

void Game::InitWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}


void Game::PollEvents()
{
	while (this->window->pollEvent(this->m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->m_event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::UpdateMousePositions()
{
	this->m_mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->m_mousePositionView = this->window->mapPixelToCoords(this->m_mousePositionWindow);
}


void Game::HandlePlayerClickCheck()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->mouseHeld)
		{

		}
	}
	else
		this->mouseHeld = false;
}

void Game::Update()
{
	elapsedTime = clock.restart();
	deltaTime = elapsedTime.asSeconds();

	player.update(deltaTime);
	enemy.update(deltaTime);

	this->PollEvents();
	this->UpdateMousePositions();
}

void Game::Render()
{
	this->window->clear();
	
	player.draw(*window);
	enemy.draw(*window);

	this->window->display();
}
