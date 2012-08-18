#include "../main files/library.h"

DevilsCross::DevilsCross(){}
DevilsCross::~DevilsCross(){}

bool DevilsCross::menu(Player *player)
{
    char choice;

    set_locationTitle("Devils Cross");
    set_description("you reach the beaten path of the devil's cross,\nwind beating you from all directions. You feel\nslightly overwhelmed at the vastness of it all\nas you look from North to South and back again,\ncontemplating where to go next.\n\n");

    do
    {
        print_description();

        cout << "N: North - Silvergate\n";
        cout << "S: South - The Arena\n";
        cout << "E: East - Dark Woods\n";
        cout << "W: West - The Wizard's Tower\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'n':
            case 'N':
                player->set_currentLocation("Silvergate");
                return false;
                break;

            case 's':
            case 'S':
                player->set_currentLocation("Arena");
                return false;
                break;

            case 'e':
            case 'E':
                player->set_currentLocation("Dark Woods");
                return false;
                break;

            case 'w':
            case 'W':
                player->set_currentLocation("Wizards Tower");
                return false;
                break;

            case 'q':
            case 'Q':
                return true;
                break;
        }

    } while (true);
}
