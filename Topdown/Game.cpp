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

void Game::Update()
{
	auto InputManager = InputManager::GetInstance();

	InputManager->Update(window);

	elapsedTime = clock.restart();
	deltaTime = elapsedTime.asSeconds();

	player.Update(deltaTime);
	enemy.Update(deltaTime);

	if(InputManager->GetKeyDown(sf::Keyboard::Escape))
		window->close();
}

void Game::Render()
{
	this->window->clear();
	
	player.Render(*window);
	enemy.draw(*window);

	this->window->display();
}
