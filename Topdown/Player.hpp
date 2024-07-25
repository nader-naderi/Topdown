#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "AnimationSystem.hpp"
#include "AnimationData.hpp"

class AnimationSystem;

class Player
{
    enum class WeaponType { Flashlight, Handgun, Knife, Rifle, Shotgun };
    enum class PlayerState { Idle, MeleeAttack, Move, Reload, Shoot };

    struct Weapon {
        WeaponType type;
        std::map<PlayerState, AnimationData> animations;

        void setAnimation(PlayerState state, AnimationData animation) {
            animations.emplace(state, animation);
        }
    };

public:
    Player(int weaponIndex);

    void update(float deltaTime) {
        animation.update(deltaTime, currentWeapon.animations[currentState].frameDuration,
            currentWeapon.animations[currentState].frameCount);
    }

    

    void draw(sf::RenderWindow& window) {
        // Draw the current animation frame for the current state
        auto textureId = currentWeapon.animations[currentState].name + std::to_string(animation.getCurrentFrame());
        sf::Texture& texture = ResourceManager::getInstance().getTexture(textureId);

        // Set the sprite's position, scale, etc.
        sprite.setTexture(texture);
        window.draw(sprite);
    }

    void changeWeapon(const int id) {
        if (currentWeaponIndex >= 0 && currentWeaponIndex < weapons.size()) {
            currentWeaponIndex = id;
            currentWeapon = weapons[currentWeaponIndex];
        }
    }

    void changeState(PlayerState newState) {
        currentState = newState;
        // Reset the frame and frame timer when changing states
        animation.resetFrame();
    }

private:
	void init();
    sf::Sprite sprite;
    AnimationSystem animation;

    int currentWeaponIndex = -1;
	Weapon currentWeapon;
	PlayerState currentState;

	

	std::vector<Weapon> weapons;

};

