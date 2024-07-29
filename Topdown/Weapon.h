#pragma once
#include <map>
#include "AnimationData.hpp"
#include "HumanState.h"

enum class WeaponType { Flashlight, Handgun, Knife, Rifle, Shotgun };

struct Weapon {
    WeaponType type;
    std::map<HumanState, AnimationData> animations;
    void setAnimation(HumanState state, AnimationData animation);
};