#pragma once
#include<SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "InputManager.h"

class Game
{
private:
	sf::RenderWindow* window;

	
	sf::Clock clock;
	sf::Time elapsedTime;
	float deltaTime;
	sf::Sprite tile;
	Player player;
	Enemy enemy;

	void InitVariables();
	void InitWindow();

public:
	Game();
	virtual ~Game();

	const bool IsRunning() const;
	
	void Update();
	void Render();
};

