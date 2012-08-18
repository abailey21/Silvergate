#ifndef GAMEOBJ_H
#define GAMEOBJ_H

class GameObj
{
  public:
    GameObj();
    ~GameObj();

    bool createNewPlayer(std::string&);
    int statChange(int&, int);

    void startGame();

    bool loadPlayer(std::string&);

    Player* get_player();
    LoadSave* get_io();


  private:
    Player *player;
    World *world;
    LoadSave *io;
};

#endif
