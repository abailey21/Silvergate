#include "library.h"

void mainMenu();

int main()
{
    srand(time(0));
    mainMenu();

    return 0;
}

void mainMenu()
{
    char choice;
    string name = "player";
    GameObj *game = new GameObj();
    bool characterCreated = false;

    do
    {
        #ifdef WINDOWS
        system("cls");
        #else
        system("clear");
        #endif

        cout << "\tWelcome " << name << "\n\n";
        cout << "N: New Character\n";
        cout << "L: Load Character\n\n";
        cout << "S: Start Game\n\n";
        cout << "Q: Quit\n\n";
        cout << "> ";

        cin >> choice;

        switch (choice)
        {
            case 'N':
            case 'n':
                characterCreated = game->createNewPlayer(name);
                break;

            case 'L':
            case 'l':
                // ugly java style access
                characterCreated = game->get_io()->loadPlayer(name, game->get_player());
                break;

            case 'S':
            case 's':
                if(!characterCreated)
                {
                    cout << "You must create a character first";
                    #ifdef WINDOWS
                    Sleep(700);
                    #else
                    sleep(0.7);
                    #endif
                    break;
                }

                game->startGame();
                break;

            case 'Q':
            case 'q':
                delete game;
                return;
                break;

            default:
                cout << "\nThat was not an option\n";
                #ifdef WINDOWS
                Sleep(1000);
                #else
                sleep(1);
                #endif
                break;
        }

    } while (choice != 'Q' || choice != 'q');
}
