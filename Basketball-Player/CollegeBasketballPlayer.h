#pragma once
#include "BasketballPlayer.h"
class CollegeBasketballPlayer :
    public BasketballPlayer
{
private:
    string team;
    
public:
    CollegeBasketballPlayer();
    CollegeBasketballPlayer(char playerType_, string playerName_, int games_,
        float efg_, int trb_, int ast_, int stl_, int blk_, int tov_,
        int pts_, string team_);
    void setTeam(string team_);
    string getTeam();

    void print();
};

