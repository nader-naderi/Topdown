#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_set>

class InputManager
{
private:
	InputManager() = default;
	InputManager(const InputManager& c) = delete;

public:
	static InputManager* GetInstance();

	void Update(sf::RenderWindow* window);

	void PollEvents(sf::RenderWindow* window);

	void UpdateMousePositions(sf::RenderWindow* window);

	bool GetMouseButton(sf::Mouse::Button button);
	bool GetKeyDown(sf::Keyboard::Key key);

	sf::Vector2i GetMousePositionWindow() const;
	sf::Vector2f GetMousePositionView() const;


private:
	std::unordered_set<sf::Keyboard::Key> m_keysPressed;
	sf::Event m_event;
	sf::Vector2i m_mousePositionWindow;
	sf::Vector2f m_mousePositionView;
};

