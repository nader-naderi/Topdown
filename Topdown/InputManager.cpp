#include "InputManager.h"

InputManager* InputManager::GetInstance()
{
	static InputManager* instance = new InputManager();
	return instance;
}

void InputManager::Update(sf::RenderWindow* window)
{
	PollEvents(window);
	UpdateMousePositions(window);
}

void InputManager::PollEvents(sf::RenderWindow* window)
{
	while (window->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			m_keysPressed.insert(m_event.key.code);
			break;
		case sf::Event::KeyReleased:
			m_keysPressed.erase(m_event.key.code);
			break;
		}
	}
}

 void InputManager::UpdateMousePositions(sf::RenderWindow* window)
{
	m_mousePositionWindow = sf::Mouse::getPosition(*window);
	m_mousePositionView = window->mapPixelToCoords(m_mousePositionWindow);
}

 bool InputManager::GetMouseButton(sf::Mouse::Button button) { return sf::Mouse::isButtonPressed(button); }

 bool InputManager::GetKeyDown(sf::Keyboard::Key key) { return m_keysPressed.find(key) != m_keysPressed.end(); }

 sf::Vector2i InputManager::GetMousePositionWindow() const { return m_mousePositionWindow; }

 sf::Vector2f InputManager::GetMousePositionView() const { return m_mousePositionView; }
