#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"

class TransformComponent : public Component
{
public:
    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;

    TransformComponent(float x, float y, float rotation = 0.f, float scaleX = 1.f, float scaleY = 1.f)
        : position(x, y), rotation(rotation), scale(scaleX, scaleY) {}
};
