#pragma once
#include<SFML/Graphics.hpp>
#include "AnimationSystem.hpp"
#include "AnimationData.hpp"

class Enemy
{
    enum class ZombieState { Idle, Move, Attack };

public:
    Enemy();
    ~Enemy();
    void update(float deltaTime);
    AnimationData& currentAnimaitonData();
    void draw(sf::RenderWindow& window);

private:
    void init();
    sf::Sprite sprite;
    std::map<ZombieState, AnimationData> stateAnimations;

    AnimationSystem animation;
    ZombieState currentState;
};

