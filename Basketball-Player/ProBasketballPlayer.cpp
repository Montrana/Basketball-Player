#include "ProBasketballPlayer.h"
ProBasketballPlayer::ProBasketballPlayer():BasketballPlayer()
{
    years = 0;
    pos = "unknown";
    contractValue = 0;
}
ProBasketballPlayer::ProBasketballPlayer(char playerType_,
    string playerName_, int games_, float efg_, int trb_, int ast_,
    int stl_, int blk_, int tov_, int pts_, int years_, string pos_) :
    BasketballPlayer(playerType_, playerName_, games_, efg_, trb_, 
        ast_, stl_, blk_, tov_, pts_)
{
    if (years_ > 0)
    {
        years = years_;
    }
    else
    {
        years = 0;
    }
    pos = pos_;
    setContractValue();
}

void ProBasketballPlayer::setYears(int years_)
{
    if (years_ > 0)
    {
        years = years_;
    }
    else
    {
        years = 0;
    }
}
void ProBasketballPlayer::setPosition(string pos_)
{
    pos = pos_;
}
void ProBasketballPlayer::setContractValue()
{
    if (value >= 10)
    {
        contractValue = 12000000;
    }
    else if (value >= 9)
    {
        contractValue = 10000000;
    }
    else if (value >= 8)
    {
        contractValue = 7500000;
    }
    else if (value >= 7)
    {
        contractValue = 6000000;
    }
    else if (value >= 5)
    {
        contractValue = 5000000;
    }
    else if (value >= 3)
    {
        contractValue = 2500000;
    }
    else 
    {
        contractValue = 500000;
    }
}

int ProBasketballPlayer::getYears()
{
    return years;
}
string ProBasketballPlayer::getPosition()
{
    return pos;
}
int ProBasketballPlayer::getContractValue()
{
    return contractValue;
}

void ProBasketballPlayer::print()
{
    cout << setw(25) << playerName;
    cout << setw(4) << playerType;
    cout << setw(8) << pos;
    cout << setw(8) << value;
    cout << setprecision(2) << setw(10) << effRating;
    cout << setprecision(2) << setw(8) << efg;
    cout << setw(10) << contractValue << endl;
}