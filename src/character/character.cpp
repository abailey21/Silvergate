#include "../main files/library.h"

Character::Character(){}
Character::~Character(){}

//accessor methods
float Character::get_health()
{
    return health;
}
float Character::get_baseAttack()
{
    return baseAttack;
}
float Character::get_armourValue()
{
    return armourValue;
}
float Character::get_weaponValue()
{
    return weaponValue;
}

float Character::get_strength()
{
    return strength;
}
float Character::get_dexterity()
{
    return dexterity;
}
float Character::get_intelligence()
{
    return intelligence;
}
float Character::get_constitution()
{
    return constitution;
}
float Character::get_perception()
{
    return perception;
}
float Character::get_luck()
{
    return luck;
}

bool Character::get_hasWeapon()
{
    return hasWeapon;
}
bool Character::get_hasCritical()
{
    return hasCritical;
}
bool Character::get_isDead()
{
    return isDead;
}

void Character::set_health(float newHealth)
{
    health = newHealth;
}
void Character::set_baseAttack(float newBaseAttack)
{
    baseAttack = newBaseAttack;
}
void Character::set_armourValue(float newArmourValue)
{
    armourValue = newArmourValue;
}
void Character::set_weaponValue(float newWeaponValue)
{
    if (!hasWeapon) weaponValue = 0;
    else weaponValue = newWeaponValue;
}

void Character::set_strength(float newStrength)
{
    strength = newStrength;
}
void Character::set_dexterity(float newDexterity)
{
    dexterity = newDexterity;
}
void Character::set_intelligence(float newIntelligence)
{
    intelligence = newIntelligence;
}
void Character::set_constitution(float newConstitution)
{
    constitution = newConstitution;
}
void Character::set_perception(float newPerception)
{
    perception = newPerception;
}
void Character::set_luck(float newLuck)
{
    luck = newLuck;
}

void Character::set_hasWeapon(bool newHasWeapon)
{
    hasWeapon = newHasWeapon;
}
void Character::set_hasCritical(bool newHasCritical)
{
    hasCritical = newHasCritical;
}
void Character::set_isDead(bool newIsDead)
{
    isDead = newIsDead;
}

//action methods
float Character::attack()
{
    float mul = 1.5;

    if (hasCritical)
    {
        // luck is had to be cast to an int otherwise I got a complie error
        mul *= (1 / ((11 - strength) + (rand() % (int)luck) + 1));
        hasCritical = false;
    }

    if (hasWeapon)
    {
        return (weaponValue + mul);
    }
    else
    {
        return (baseAttack * mul);
    }
}

void Character::takeDamage(float damage)
{
    int number = health;
    number -= (damage - armourValue);

    if (number < 0) number = 0;
    health = number;

    if (health <= 0) die();
}

bool Character::chanceCritical()
{
    float number = (rand() % 11) + 1;

    if (number <= dexterity)
    {
        hasCritical = true;
    }
    else hasCritical = false;

    return hasCritical;
}

void Character::die()
{
    isDead = true;
}
