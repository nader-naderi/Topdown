#pragma once
#include<SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event m_event;

	sf::Vector2i m_mousePositionWindow;
	sf::Vector2f m_mousePositionView;
	bool mouseHeld;
	sf::Clock clock;
	sf::Time elapsedTime;
	float deltaTime;
	sf::Sprite tile;
	Player player = { 0 };
	Enemy enemy;

	void InitVariables();
	void InitWindow();

public:
	Game();
	virtual ~Game();

	const bool IsRunning() const;
	void UpdateMousePositions();
	void HandlePlayerClickCheck();

	void PollEvents();
	
	void Update();
	void Render();
};

