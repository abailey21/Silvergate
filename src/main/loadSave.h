#ifndef LOADSAVE_H
#define LOADSAVE_H

class LoadSave
{
    public:
        LoadSave();
        ~LoadSave();

        bool loadPlayer(std::string&, Player*);
        bool loadStats(std::string&, Player*);
        bool loadLogic(std::string&, Player*);
        bool loadLocation(std::string&, Player*);

        void savePlayer(Player*);
        void saveStats(std::string&, Player*);
        void saveLogic(std::string&, Player*);
        void saveLocation(std::string&, Player*);

    private:
        // stats
        float health;
        float baseAttack;
        float armourValue;
        float dexterity;
        float intelligence;
        float constitution;
        float perception;
        float luck;

        // logic
        bool hasWeapon;
        bool hasCritical;
        bool isDead;

        // location
        std::string currentLocation;

        // file variables
        std::string extension;
        std::string path;
        std::string fileName;
};

#endif
