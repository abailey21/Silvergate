#include "../main files/library.h"

Silvergate::Silvergate(){}
Silvergate::~Silvergate(){}

bool Silvergate::menu(Player *player)
{
    char choice;

    set_locationTitle("Silvergate");
    set_description("You feel the warmth of civilisation hit you before\nyou've even arrived. Silver Gate, a small sparse\ntown, but to your world weary sensibilities this\nplace is more homely than even the most bustling\nof metropolises.\n\n");

    do
    {
        print_description();

        cout << "B: Blacksmith\n";
        cout << "I: Inn\n";
        cout << "G: General Store\n";
        cout << "L: Leave\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'b':
            case 'B':
                //blacksmith();
                return false;
                break;

            case 'i':
            case 'I':
                //inn();
                return false;
                break;

            case 'g':
            case 'G':
                //generalStore();
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

