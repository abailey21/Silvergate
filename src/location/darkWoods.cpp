#include "../main files/library.h"

DarkWoods::DarkWoods(){}
DarkWoods::~DarkWoods(){}

bool DarkWoods::menu(Player *player)
{
    char choice;

    set_locationTitle("Dark Woods");
    set_description("The woods hold a mysterious aura, that\nmakes you feel uncomfortable as you enter the dark\nlabyrinth of gnarled beast like trees and barbed grass\nblades. No one knows what resides in these woods,\nbut once inside you can never feel alone they say\n\n");

    do
    {
        print_description();

        cout << "S: Murky Swamp\n";
        cout << "C: Strange Cabin\n";
        cout << "O: Unusal Formation\n";
        cout << "L: Leave\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 's':
            case 'S':
                //murkyswamp();
                return false;
                break;

            case 'c':
            case 'C':
                //strangecabin();
                return false;
                break;

            case 'o':
            case 'O':
                //unusualformation();
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


