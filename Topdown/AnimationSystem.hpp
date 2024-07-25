#pragma once
#include <string>
class AnimationSystem
{
public:
    AnimationSystem();
    ~AnimationSystem();

    void update(float deltaTime, double endFrame, int frameCount) {
        frameTimer += deltaTime;

        if (frameTimer >= endFrame) {
            currentFrame = (currentFrame + 1) % frameCount;
            frameTimer = 0;
        }
    }

    void resetFrame()
    {
        currentFrame = 0;
        frameTimer = 0;
    }

    int getCurrentFrame()
    {
        return currentFrame;
    }

private:
    int currentFrame;
    double frameTimer;
};

