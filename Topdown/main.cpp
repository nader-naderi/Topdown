#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main()
{
    Game game;

    while (game.IsRunning())
    {
        game.Update();
        game.Render();
    }

    


    sf::RenderWindow window(sf::VideoMode(1280, 720), "Zombie Game");
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       

        window.clear();

        window.display();
    }

    return 0;
}