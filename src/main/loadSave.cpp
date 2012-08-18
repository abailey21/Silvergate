#include "library.h"

LoadSave::LoadSave(){}
LoadSave::~LoadSave(){}


bool LoadSave::loadPlayer(string &name, Player *player)
{
    ifstream file;

    bool stats;
    bool logic;
    bool location;

    cout << "Enter your characters name: ";
    cin >> name;

    player->set_name(name);

    for (unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }

    extension = "_save.dat";
    #ifdef WINDOWS
    path = "save\\" + name + "\\";
    #else
    path = "save/" + name + "/";
    #endif

    cout << "\nLoading...";
    #ifdef WINDOWS
    Sleep(700);
    #else
    sleep(0.7);
    #endif

    stats = loadStats(name, player);
    logic = loadLogic(name, player);
    location = loadLocation(name, player);

    if (stats == false && logic == false && location == false) return false;
    else return true;
}

bool LoadSave::loadStats(string &name, Player *player)
{
    fstream file;

    fileName = path + name + "_stats" + extension;
    file.open(fileName.c_str(), ios::binary | ios::in);
    if (file.good())
    {
        file.read((char*)(&health), sizeof(float));
        file.read((char*)(&baseAttack), sizeof(float));
        file.read((char*)(&armourValue), sizeof(float));
        file.read((char*)(&dexterity), sizeof(float));
        file.read((char*)(&intelligence), sizeof(float));
        file.read((char*)(&constitution), sizeof(float));
        file.read((char*)(&perception), sizeof(float));
        file.read((char*)(&luck), sizeof(float));

        player->set_health(health);
        player->set_baseAttack(baseAttack);
        player->set_armourValue(armourValue);
        player->set_dexterity(dexterity);
        player->set_intelligence(intelligence);
        player->set_constitution(constitution);
        player->set_perception(perception);
        player->set_luck(luck);

        if (file.fail())
        {
            file.close();
            cout << "\ncouldn't read the save file\n";
            #ifdef WINDOWS
            Sleep(700);
            #else
            sleep(0.7);
            #endif

            name = "player";
            return false;
        }
        file.close();

        return true;
    }
    else
    {
        file.close();
        cout << "\nCouldn't open the save file\n";
        #ifdef WINDOWS
        Sleep(1000);
        #else
        sleep(1);
        #endif

        name = "player";
        return false;
    }
}

bool LoadSave::loadLogic(string &name, Player *player)
{
    fstream file;

    fileName = path + name + "_logic" + extension;
    file.open(fileName.c_str(), ios::binary | ios::in);
    if (file.good())
    {
        file.read((char*)(&hasWeapon), sizeof(bool));
        file.read((char*)(&hasCritical), sizeof(bool));
        file.read((char*)(&isDead), sizeof(bool));

        player->set_hasWeapon(hasWeapon);
        player->set_hasCritical(hasCritical);
        player->set_isDead(isDead);

        if (file.fail())
        {
            file.close();
            cout << "\ncouldn't read the save file\n";
            #ifdef WINDOWS
            Sleep(700);
            #else
            sleep(0.7);
            #endif

            name = "player";
            return false;
        }
        file.close();

        return true;
    }
    else
    {
        file.close();
        cout << "\nCouldn't open the save file\n";
        #ifdef WINDOWS
        Sleep(1000);
        #else
        sleep(1);
        #endif

        name = "player";
        return false;
    }
}

bool LoadSave::loadLocation(string &name, Player *player)
{
    fstream file;

    fileName = path + name + "_location" + extension;
    file.open(fileName.c_str(), ios::in);
    if (file.good())
    {

        if (file.is_open())
        {
            while (file.good())
            {
                getline (file, currentLocation);
            }
            file.close();
        }

        player->set_currentLocation(currentLocation);

        file.close();

        return true;
    }
    else
    {
        file.close();
        cout << "\nCouldn't open the save file\n";
        #ifdef WINDOWS
        Sleep(1000);
        #else
        sleep(1);
        #endif

        name = "player";
        return false;
    }
}

/*
    Saving
*/

void LoadSave::savePlayer(Player *player)
{
    string name = player->get_name();

    for (unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }

    cout << "Saving...\n";
    #ifdef WINDOWS
    Sleep(1000);
    #else
    sleep(1);
    #endif

    #ifdef WINDOWS
    path = "save\\" + name + "\\";
    string mkdir = "mkdir " + path;
    if (system(mkdir.c_str()) != 0);
    #else
    path = "save/" + name + "/";
    string mkdir = "mkdir " + path;
    system(mkdir.c_str());
    #endif
    extension = "_save.dat";

    saveStats(name, player);
    saveLogic(name, player);
    saveLocation(name, player);
}

void LoadSave::saveStats(string &name, Player *player)
{
    fstream file;

    fileName = path + name + "_stats" + extension;
    file.open(fileName.c_str(), ios::binary | ios::trunc | ios::out);
    if (file.is_open())
    {
        health = player->get_health();
        baseAttack = player->get_baseAttack();
        armourValue = player->get_armourValue();
        dexterity = player->get_dexterity();
        intelligence = player->get_intelligence();
        constitution = player->get_constitution();
        perception  = player->get_perception();
        luck = player->get_luck();

        file.write((char*)(&health), sizeof(float));
        file.write((char*)(&baseAttack), sizeof(float));
        file.write((char*)(&armourValue), sizeof(float));
        file.write((char*)(&dexterity), sizeof(float));
        file.write((char*)(&intelligence), sizeof(float));
        file.write((char*)(&constitution), sizeof(float));
        file.write((char*)(&perception), sizeof(float));
        file.write((char*)(&luck), sizeof(float));

        file.close();

        cout << "\nCharacter " << name << " stats saved";
        #ifdef WINDOWS
        Sleep(500);
        #else
        sleep(0.5);
        #endif
    }
    else
    {
        file.close();
        cout << "\nCouldn't save the file\n";
        #ifdef WINDOWS
        Sleep(700);
        #else
        sleep(0.7);
        #endif
    }
}

void LoadSave::saveLogic(string &name, Player *player)
{
    fstream file;

    fileName = path + name + "_logic" + extension;
    file.open(fileName.c_str(), ios::binary | ios::trunc | ios::out);
    if (file.is_open())
    {
        hasWeapon = player->get_hasWeapon();
        hasCritical = player->get_hasCritical();
        isDead = player->get_isDead();

        file.write((char*)(&hasWeapon), sizeof(bool));
        file.write((char*)(&hasCritical), sizeof(bool));
        file.write((char*)(&isDead), sizeof(bool));

        file.close();

        cout << "\nCharacter " << name << " logic saved";
        #ifdef WINDOWS
        Sleep(500);
        #else
        sleep(0.5);
        #endif
    }
    else
    {
        file.close();
        cout << "\nCouldn't save the file\n";
        #ifdef WINDOWS
        Sleep(700);
        #else
        sleep(0.7);
        #endif
    }
}

void LoadSave::saveLocation(string &name, Player *player)
{
    fstream file;

    fileName = path + name + "_location" + extension;
    file.open(fileName.c_str(), ios::trunc | ios::out);
    if (file.is_open())
    {
        currentLocation = player->get_currentLocation();

        file << currentLocation;

        file.close();

        cout << "\nCharacter " << name << " location saved";
        #ifdef WINDOWS
        Sleep(500);
        #else
        sleep(0.5);
        #endif
    }
    else
    {
        file.close();
        cout << "\nCouldn't save the file\n";
        #ifdef WINDOWS
        Sleep(700);
        #else
        sleep(0.7);
        #endif
    }
}
