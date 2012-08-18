#include "library.h"

GameObj::GameObj()
{
    player = new Player();
    world = new World();
    io = new LoadSave();
}
GameObj::~GameObj()
{
    delete player;
    delete world;
    delete io;
}

bool GameObj::createNewPlayer(string &name)
{
    char choice;

    int points = 10;
    int dex = 2;
    int str = 2;
    int intel = 2;
    int cons = 2;
    int per = 2;
    int luck = 2;

    // created a reference to each so I can return two values from the stat change method.
    int &rDex = dex;
    int &rStr = str;
    int &rIntel = intel;
    int &rCons = cons;
    int &rPer = per;
    int &rLuck = luck;

    do
    {
        #ifdef WINDOWS
        system("cls");
        #else
        system("clear");
        #endif

        cout << "\tThis is the player creation screen\n\n";
        cout << "You have " << points << " points remaining\n\n";
        cout << "S: Strength " << str << " - Atack damage\n";
        cout << "D: Dexterity " << dex << " - Lock picking\n";
        cout << "I: Intelligence " << intel << " - Magic\n";
        cout << "C: Constitution " << cons << " - Health\n";
        cout << "P: Perception " << per << " - Stealth\n";
        cout << "L: Luck " << luck << " - Critical hits\n\n";
        cout << "F: Finished\n";
        cout << "B: Back\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'S':
            case 's':
                points = statChange(rStr, points);
                break;

            case 'd':
            case 'D':
                points = statChange(rDex, points);
                break;

            case 'i':
            case 'I':
                points = statChange(rIntel, points);
                break;

            case 'c':
            case 'C':
                points = statChange(rCons, points);
                break;

            case 'p':
            case 'P':
                points = statChange(rPer, points);
                break;

            case 'l':
            case 'L':
                points = statChange(rLuck, points);
                break;

            case 'f':
            case 'F':
                #ifdef WINDOWS
                system("cls");
                #else
                system("clear");
                #endif
                cout << "Enter your characters name: ";
                cin >> name;

                cout << "\n\nCreating your new character...\n";
                #ifdef WINDOWS
                Sleep(1000);
                #else
                sleep(1);
                #endif
                player->init(str, dex, intel, cons, per, luck, name);
                player->set_currentLocation("Devils Cross");
                player->clearProgress();
                io->savePlayer(player);
                return true;
                break;

            case 'b':
            case 'B':
                cout << "Exiting...";
                #ifdef WINDOWS
                Sleep(500);
                #else
                sleep(0.5);
                #endif
                return false;
                break;

            default:
                cout << "\nThat was not an option\n";
                #ifdef WINDOWS
                Sleep(500);
                #else
                sleep(0.5);
                #endif
        }

    } while (1);
}

int GameObj::statChange(int &stat, int points)
{
    char choice;

    do
    {
        cout << "\nA: Add point\n";
        cout << "S: Subtract point\n";
        cout << "> ";

        cin >> choice;

        switch(choice)
        {
            case 'A':
            case 'a':
                if (points == 0)
                {
                    cout << "\nSorry no points remining\n";
                    #ifdef WINDOWS
                    Sleep(1000);
                    #else
                    sleep(1);
                    #endif
                    return 0;
                }
                stat += 1;
                points -= 1;
                return points;
                break;

            case 's':
            case 'S':
                stat -= 1;
                points += 1;
                return points;
                break;

            default:
                break;
        }

    } while (1);

    return 0;
}

void GameObj::startGame()
{
    world->play(player);
    io->savePlayer(player);
}

Player* GameObj::get_player()
{
    return player;
}
LoadSave* GameObj::get_io()
{
    return io;
}
