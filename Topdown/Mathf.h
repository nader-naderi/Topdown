#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <corecrt_math_defines.h>

#pragma once
float calculateRotationAngle(const sf::Vector2f& playerPosition, const sf::Vector2f& mousePosition)
{
    float angle = std::atan2(mousePosition.y - playerPosition.y, mousePosition.x - playerPosition.x);
    angle = angle * 180 / M_PI;
    return angle;
}