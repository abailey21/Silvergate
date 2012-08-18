#include "../main files/library.h"

Enemy::Enemy(){}
Enemy::~Enemy(){}

void Enemy::init(float armourValue, float weaponValue, int statLevel)
{
    if (statLevel <= 0) statLevel = 1;

    set_armourValue(armourValue);
    set_weaponValue(weaponValue);

    set_strength((float)statLevel);
    set_dexterity((float)statLevel);

    set_baseAttack(10 + ((float)statLevel / 2));
    set_health(100 + ((float)statLevel * 5));

    set_hasCritical(false);
    set_isDead(false);

    if (weaponValue > 0) set_hasWeapon(true);
    else set_hasWeapon(false);
}
