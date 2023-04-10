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
    cout << playerName << "\t" << playerType << "\t" << pos << "\t" <<
        value << "\t" << effRating << "\t" << efg << "\t" << contractValue;
}