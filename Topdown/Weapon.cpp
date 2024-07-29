#include "Weapon.h"

void Weapon::setAnimation(HumanState state, AnimationData animation) {
    animations.emplace(state, animation);
}
