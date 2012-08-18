#include "../main files/library.h"

WizardsTower::WizardsTower(){}
WizardsTower::~WizardsTower(){}

bool WizardsTower::menu(Player *player)
{
    char choice;

    set_locationTitle("Wizards Tower");
    set_description("You stand before the colossus tower,\nyour hairs standing on end at the very thought of the\nmagical essences that radiate from this brick and motor\nplace is more homely than even the most bustling\ngiant which penetrates the very skyline and into the realm of the gods.\n\n");

    do
    {
        print_description();

        cout << "E: Arcane Enchanter Room\n";
        cout << "I: Rejuvenation Temple\n";
        cout << "G: Alchemist Chamber\n";
        cout << "L: Leave\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'e':
            case 'E':
                //arcaneEnchanterRoom();
                return false;
                break;

            case 'r':
            case 'R':
                //rejuvenationtemple();
                return false;
                break;

            case 'a':
            case 'A':
                //alchemistchamber();
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


