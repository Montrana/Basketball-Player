#include "ProBasketballPlayer.h"
/// <summary>
/// Default pro basketball constructor
/// </summary>
ProBasketballPlayer::ProBasketballPlayer():BasketballPlayer()
{
    years = 0;
    pos = "Unknown";
    contractValue = 0;
}
/// <summary>
/// override pro basketball player constructor
/// </summary>
/// <param name="playerType_">if the player is a pro or college player</param>
/// <param name="playerName_">The name of the player</param>
/// <param name="games_">number of games</param>
/// <param name="efg_">Effective Field Goal Percentage</param>
/// <param name="trb_">total rebounds</param>
/// <param name="ast_">assists</param>
/// <param name="stl_">steals</param>
/// <param name="blk_">blocks</param>
/// <param name="tov_">turnovers</param>
/// <param name="pts_">points</param>
/// <param name="years_">years that player has been a pro</param>
/// <param name="pos_">Position player plays</param>
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
    pos = pos_.back();
    setContractValue();
}
/// <summary>
/// sets the years player has been playing in the NBA
/// </summary>
/// <param name="years_">years that player has been a pro</param>
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
/// <summary>
/// Sets the player's position
/// </summary>
/// <param name="pos_">The player's position on the team</param>
void ProBasketballPlayer::setPosition(string pos_)
{
    pos = pos_;
}
/// <summary>
/// sets the contract value based on the player's value
/// </summary>
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
/// <summary>
/// Gets the years the player has been a pro
/// </summary>
/// <returns>years that player has been a pro</returns>
int ProBasketballPlayer::getYears()
{
    return years;
}
/// <summary>
/// gets the player's position
/// </summary>
/// <returns>Position player plays</returns>
string ProBasketballPlayer::getPosition()
{
    return pos;
}
/// <summary>
/// gets the value of the players contract
/// </summary>
/// <returns>how much the player's contract is worth</returns>
int ProBasketballPlayer::getContractValue()
{
    return contractValue;
}
/// <summary>
/// Prints the stats for the player
/// </summary>
void ProBasketballPlayer::print()
{
    cout << setw(24) << playerName;
    cout << setw(6) << playerType;
    cout << setw(10) << pos;
    cout << setw(14) << value;
    cout << setprecision(2) << setw(12) << effRating;
    cout << setprecision(2) << setw(12) << efg;
    cout << setw(16) << contractValue << endl;
}