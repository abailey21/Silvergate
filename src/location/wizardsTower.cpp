#include "../main files/library.h"

WizardsTower::WizardsTower(){}
WizardsTower::~WizardsTower(){}

bool WizardsTower::menu(Player *player)
{
    char choice;

    set_locationTitle("Wizards' Tower");
    set_description("You stand before the colossus tower,\nevery hair standing on end at the very thought of the\nmagical essences that radiate from this brick and mortar\ngiant; penetrating the very skyline and into the realm of the gods.\nA sinister realisation begins to flushes over you;\nyou are being observed.\n\n");

    do

    {
        print_description();


        cout << "E: Enter Tower Anyway\n";
        cout << "H: Attempt to Hide\n";
        cout << "O: Search for Observer\n";
        cout << "L: Leave\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'e':
            case 'E':
                //entertower();
                return false;
                break;

            case 'h':
            case 'H':
                //hide();
                return false;
                break;

            case 'o':
            case 'O':
                //searchforobserver();
                return false;
                break;

            case 'l':
            case 'L':
                player->set_currentLocation("Devils Cross");
                return false;
                break;

            case 'q':
            case 'Q':
                return true;
                break;
        }

    } while (true);
}



