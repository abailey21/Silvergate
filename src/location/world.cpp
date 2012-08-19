#include "../main files/library.h"

World::World()
{
    devilsCross = new DevilsCross;
    arena = new Arena;
    wizardsTower = new WizardsTower;
    darkWoods = new DarkWoods;
    silvergate = new Silvergate;
    silvergateMerchants = new SilvergateMerchants;
}

World::~World()
{
    delete devilsCross;
    delete arena;
    delete wizardsTower;
    delete darkWoods;
    delete silvergate;
    delete silvergateMerchants;
}

void World::play(Player *player)
{
    bool exit = false;

    do
    {
        if (player->get_currentLocation() == "Devils Cross")
        {
            exit = devilsCross->menu(player);
        }

        else if (player->get_currentLocation() == "Arena")
        {
            exit = arena->menu(player);
        }
        else if (player->get_currentLocation() == "Wizards Tower")
        {
            exit = wizardsTower->menu(player);
        }
        else if (player->get_currentLocation() == "Dark Woods")
        {
            exit = darkWoods->menu(player);
        }

        else if (player->get_currentLocation() == "Silvergate")
        {
            exit = silvergate->menu(player);
        }

         else if (player->get_currentLocation() == "Silvergate Merchant Quarter")
        {
            exit = silvergateMerchants->menu(player);
        }

    } while(!exit);
}
