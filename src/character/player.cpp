#include "../main files/library.h"

Player::Player(){}
Player::~Player(){}

void Player::init(int newStrength, int newDexterity, int newIntelligence, int newConstitution, int newPerception, int newLuck, string newName)
{
    // the name will be used to refer to the player during game and for saving/loading purposes
    set_name(newName);

    // check to make sure the values are not lower than zero
    if (newStrength > 0) newStrength = 0;
    if (newDexterity > 0) newDexterity = 0;

    // players start the game with no armour or weapons
    set_armourValue(0);
    set_weaponValue(0);

    // set the stats
    set_strength((float)newStrength);
    set_dexterity((float)newDexterity);
    set_intelligence((float)newIntelligence);
    set_constitution((float)newConstitution);
    set_perception((float)newPerception);
    set_luck((float)newLuck);

    //create a base attack and health value based off of the strength value
    set_baseAttack(10 + ((float)newStrength / 2));
    set_health(100 + ((float)newConstitution * 5));

    // these will always be false at the begining
    set_hasCritical(false);
    set_hasWeapon(false);
    set_isDead(false);
}

string Player::get_name()
{
    return playerName;
}
string Player::get_currentLocation()
{
    return currentLocation;
}

void Player::set_name(string newName)
{
    playerName = newName;
}
void Player::set_currentLocation(string newLocation)
{
    currentLocation = newLocation;
}

void Player::clearProgress()
{
    // clear the boolean values for completed quests
}
