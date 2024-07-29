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
 bool InputManager::GetKey(sf::Keyboard::Key key) { return sf::Keyboard::isKeyPressed(key); }

 sf::Vector2f InputManager::GetAxis(const std::string& axis)
 {
     sf::Vector2f value;

     if (axis == "Horizontal")
     {
         value.x = 0.f;
         if (GetKeyDown(sf::Keyboard::A))
         {
             value.x -= 1.f;
         }
         else if (GetKeyDown(sf::Keyboard::D))
         {
             value.x += 1.f;
         }
     }
     else if (axis == "Vertical")
     {
         value.y = 0.f;
         if (GetKeyDown(sf::Keyboard::W))
         {
             value.y -= 1.f;
         }
         else if (GetKeyDown(sf::Keyboard::S))
         {
             value.y += 1.f;
         }
     }

     return value;
 }


 sf::Vector2i InputManager::GetMousePositionWindow() const { return m_mousePositionWindow; }

 sf::Vector2f InputManager::GetMousePositionView() const { return m_mousePositionView; }
