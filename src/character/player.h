#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character
{
    public:
        Player();
        ~Player();

        void init(int, int, int, int, int, int, std::string); // used to initialise all stats and values

        std::string get_name();
        std::string get_currentLocation();

        void set_name(std::string);
        void set_currentLocation(std::string);

        void clearProgress();

    private:
        std::string playerName;
        std::string currentLocation;
};

#endif
