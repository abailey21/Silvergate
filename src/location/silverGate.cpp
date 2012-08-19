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

        cout << "M: Visit Merchant Quarter\n";
        cout << "I: Stay at Inn\n";
        cout << "G: Head to Great Hall\n";
        cout << "L: Leave\n\n";
        cout << "Q: Quit Game\n\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'm':
            case 'M':
                player->set_currentLocation("Silvergate Merchant Quarter");
                return false;
                break;

            case 'i':
            case 'I':
                //inn();
                return false;
                break;

            case 'g':
            case 'G':
                //greathall();
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


       
