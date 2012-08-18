#ifndef WORLD_H
#define WORLD_H

class World
{
    public:
        World();
        ~World();

        int get_levelNumber();
        void set_levelNumber(int);

        void play(Player*);

    private:
        DevilsCross *devilsCross;
        Arena *arena;
        WizardsTower *wizardsTower;
        DarkWoods *darkWoods;
        Silvergate *silvergate;
};

#endif
