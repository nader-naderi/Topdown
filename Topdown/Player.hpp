#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "AnimationSystem.hpp"
#include "Weapon.h"

class Player
{
public:
    Player(int weaponIndex);

    void Update(float deltaTime);

    void Render(sf::RenderWindow& window);

    void ChangeWeapon(const int id);

    void ChangeState(HumanState newState);

    void UpdateLookToMousePosition(float deltaTime);

private:
	void Init();
    sf::Sprite sprite;
    AnimationSystem animation;

    int currentWeaponIndex = -1;
	Weapon currentWeapon;
	HumanState currentState;

	std::vector<Weapon> weapons;

};

