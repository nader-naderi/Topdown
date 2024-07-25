#include "Player.hpp"

Player::Player(int weaponIndex)
{
    init();

    currentWeaponIndex = weaponIndex;

    if (currentWeaponIndex >= 0 && currentWeaponIndex < weapons.size()) {
        currentWeapon = weapons[currentWeaponIndex];
    }
    else {
        // Handle invalid index, e.g., throw an exception, assign a default weapon, or log an error.
    }

    sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));  // Adjust the origin as needed
    sprite.setPosition(1280 / 2, 720 / 2);  // Set the player's position (x, y)
}

void Player::init()
{
    for (int i = 0; i < 20; ++i) {
        std::string textureId = "handgun_idle" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_" + std::to_string(i) + ".png",
            textureId
        );
    }

    for (int i = 0; i < 15; ++i) {
        std::string textureId = "handgun_melee_attack" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Top_Down_Survivor/handgun/meleeattack/survivor-meleeattack_handgun_" + std::to_string(i) + ".png",
            textureId
        );
    }

    for (int i = 0; i < 20; ++i) {
        std::string textureId = "handgun_move" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Top_Down_Survivor/handgun/move/survivor-move_handgun_" + std::to_string(i) + ".png",
            textureId
        );
    }

    for (int i = 0; i < 15; ++i) {
        std::string textureId = "handgun_reload" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Top_Down_Survivor/handgun/reload/survivor-reload_handgun_" + std::to_string(i) + ".png",
            textureId
        );
    }

    for (int i = 0; i < 3; ++i) {
        std::string textureId = "handgun_shoot" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_" + std::to_string(i) + ".png",
            textureId
        );
    }


    Weapon handgun = { WeaponType::Handgun };

    handgun.setAnimation(PlayerState::Idle, { "handgun_idle", 20, 0.1 });
    handgun.setAnimation(PlayerState::MeleeAttack, { "handgun_melee_attack", 15, 0.1 });
    handgun.setAnimation(PlayerState::Move, { "handgun_move", 20, 0.1 });
    handgun.setAnimation(PlayerState::Reload, { "handgun_reload", 15, 0.1 });
    handgun.setAnimation(PlayerState::Shoot, { "handgun_shoot", 3, 0.1 });
    
    weapons.push_back(handgun);
}
