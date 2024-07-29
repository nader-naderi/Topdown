#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "AnimationSystem.hpp"
#include "Weapon.h"
#include "InputManager.h"

class Player
{
public:
    Player(int weaponIndex);

    void InitializeSprite();

    void Update(float deltaTime);

    void Render(sf::RenderWindow& window);

    void ChangeWeapon(const int id);

    void ChangeState(HumanState newState);

    void UpdatePlayerLook(float deltaTime);
    void UpdatePlayerMovement(float deltaTime);

private:
	void Init();
    sf::Sprite sprite;
    AnimationSystem animation;

    float playerMoveSpeed = 100;
    int currentWeaponIndex = -1;
	Weapon currentWeapon;
	HumanState currentState;
    InputManager* inputManager = InputManager::GetInstance();
	std::vector<Weapon> weapons;
};

