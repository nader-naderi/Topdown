#include "Player.hpp"
#include "StaticFiles.hpp"
#include "Mathf.h"

Player::Player(int weaponIndex)
{
	Init();

	currentWeaponIndex = weaponIndex;

	if (currentWeaponIndex >= 0 && currentWeaponIndex < weapons.size()) {
		currentWeapon = weapons[currentWeaponIndex];
	}
	else {
		// Handle invalid index, e.g., throw an exception, assign a default weapon, or log an error.
	}

	InitializeSprite();
}

void Player::InitializeSprite()
{
	sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);  // Set the player's position (x, y)
	sprite.setScale(0.5f, 0.5f);

	auto textureId = currentWeapon.animations[currentState].name + std::to_string(animation.getCurrentFrame());
	sf::Texture& texture = ResourceManager::getInstance().getTexture(textureId);

	// Set the sprite's position, scale, etc.
	sprite.setTexture(texture);

	sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x / 2,
		sprite.getTexture()->getSize().y / 2));  // Adjust the origin as needed
}

void Player::Update(float deltaTime)
{
	animation.update(deltaTime, currentWeapon.animations[currentState].frameDuration,
		currentWeapon.animations[currentState].frameCount);

	UpdatePlayerLook(deltaTime);
	UpdatePlayerMovement(deltaTime);
}

void Player::Render(sf::RenderWindow& window)
{
	// Draw the current animation frame for the current state
	auto textureId = currentWeapon.animations[currentState].name + std::to_string(animation.getCurrentFrame());
	sf::Texture& texture = ResourceManager::getInstance().getTexture(textureId);

	// Set the sprite's position, scale, etc.
	sprite.setTexture(texture);
	window.draw(sprite);
	
}

void Player::ChangeWeapon(const int id) {
	if (currentWeaponIndex >= 0 && currentWeaponIndex < weapons.size()) {
		currentWeaponIndex = id;
		currentWeapon = weapons[currentWeaponIndex];
	}
}

void Player::ChangeState(HumanState newState) {
	currentState = newState;
	// Reset the frame and frame timer when changing states
	animation.resetFrame();
}

void Player::UpdatePlayerLook(float deltaTime)
{
	// Get the player's sprite position.
	sf::Vector2f playerPosition = sprite.getPosition();

	// Get the mouse position releative to the view.
	sf::Vector2f mousePosition = inputManager->GetMousePositionView();
	mousePosition.y = WINDOW_HEIGHT - mousePosition.y;

	float angle = calculateRotationAngle(playerPosition, mousePosition);
	sprite.setRotation(-angle);
}

void Player::UpdatePlayerMovement(float deltaTime)
{
	sf::Vector2f moveDirection = inputManager->GetAxis("Horizontal") + inputManager->GetAxis("Vertical");
	std::cout << moveDirection.x << ", " << moveDirection.y << std::endl;

	sprite.move(moveDirection * deltaTime * playerMoveSpeed);
}

void Player::Init()
{
	// Import Handgun Animation Sets
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

	// Initialize Handgun Weapon
	Weapon handgun = { WeaponType::Handgun };

	handgun.setAnimation(HumanState::Idle, { "handgun_idle", 20, 0.1 });
	handgun.setAnimation(HumanState::MeleeAttack, { "handgun_melee_attack", 15, 0.1 });
	handgun.setAnimation(HumanState::Move, { "handgun_move", 20, 0.1 });
	handgun.setAnimation(HumanState::Reload, { "handgun_reload", 15, 0.1 });
	handgun.setAnimation(HumanState::Shoot, { "handgun_shoot", 3, 0.1 });

	weapons.push_back(handgun);
}
