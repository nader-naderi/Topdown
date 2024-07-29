#pragma once
#include <SFML/Graphics.hpp>

class SpriteComponent
{
public:
    sf::Sprite sprite;

    SpriteComponent(sf::Texture& texture) : sprite(texture) {}
};

