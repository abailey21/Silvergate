#include "../main files/library.h"

Arena::Arena(){}
Arena::~Arena(){}

bool Arena::menu(Player *player)
{
    char choice;

    set_locationTitle("Arena");
    set_description("You arrive at the arena's entrance\nand are greeted by the smell of stagnant blood, and\nlabyrinth of gnarled beast like trees and barbed grass\nthe sounds of vicious men brutalising each other echoing\ndown the cold stone corridor.\n\n");

    do
    {
        print_description();

        cout << "A: Armoury\n";
        cout << "B: Barracks\n";
        cout << "S: Spectator Balcony\n";
        cout << "L: Leave\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'a':
            case 'A':
                //armoury();
                return false;
                break;

            case 'b':
            case 'B':
                //barracks();
                return false;
                break;

            case 's':
            case 'S':
                //spectatorbalcony();
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



