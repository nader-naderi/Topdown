#include "Enemy.hpp"
#include "ResourceManager.hpp"

Enemy::Enemy()
{
    init();

    sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));  // Adjust the origin as needed
    sprite.setPosition(1280 / 4, 720 / 4);  // Set the player's position (x, y)
    sprite.setScale(0.5f, 0.5f);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
	animation.update(deltaTime, 
        currentAnimaitonData().frameDuration,
        currentAnimaitonData().frameCount);
}

AnimationData& Enemy::currentAnimaitonData() { return stateAnimations[currentState]; }

void Enemy::draw(sf::RenderWindow& window)
{
    // Draw the current animation frame for the current state
    auto textureId = currentAnimaitonData().name + std::to_string(animation.getCurrentFrame());
    sf::Texture& texture = ResourceManager::getInstance().getTexture(textureId);

    // Set the sprite's position, scale, etc.
    sprite.setTexture(texture);
    window.draw(sprite);
}

void Enemy::changeState(ZombieState newState)
{
    currentState = newState;
    animation.resetFrame();
}

void Enemy::init()
{
    for (int i = 0; i < 9; ++i) {
        std::string textureId = "skeleton-attack" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Enemy/Attack/skeleton-attack_" + std::to_string(i) + ".png",
            textureId
        );
    }

    for (int i = 0; i < 17; ++i) {
        std::string textureId = "skeleton-idle" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Enemy/Idle/skeleton-idle_" + std::to_string(i) + ".png",
            textureId
        );
    }

    for (int i = 0; i < 17; ++i) {
        std::string textureId = "skeleton-move" + std::to_string(i);
        ResourceManager::getInstance().load(
            "assets/textures/Enemy/Move/skeleton-move_" + std::to_string(i) + ".png",
            textureId
        );
    }

    AnimationData idle = { "skeleton-idle", 17, 0.05 };
    AnimationData move = { "skeleton-move", 17, 0.1 };
    AnimationData attack = { "skeleton-attack", 9, 0.1 };

    stateAnimations.emplace(ZombieState::Idle, idle);
    stateAnimations.emplace(ZombieState::Move, move);
    stateAnimations.emplace(ZombieState::Attack, attack);
}
