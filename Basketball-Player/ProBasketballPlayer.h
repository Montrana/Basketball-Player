#pragma once
#include "BasketballPlayer.h"
class ProBasketballPlayer :
    public BasketballPlayer
{
private:
    int years;
    string pos;
    int contractValue;
public:
    ProBasketballPlayer();
    ProBasketballPlayer(char playerType_, string playerName_,
        int games_, float efg_, int trb_, int ast_, int stl_,
        int blk_, int tov_, int pts_, int years_, string pos_);

    void setYears(int years_);
    void setPosition(string pos_);
    void setContractValue();

    int getYears();
    string getPosition();
    int getContractValue();

    void print();
};

