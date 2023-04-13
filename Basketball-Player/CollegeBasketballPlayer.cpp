#include "CollegeBasketballPlayer.h"
CollegeBasketballPlayer::CollegeBasketballPlayer() :BasketballPlayer()
{
    team = "unknown";
}
CollegeBasketballPlayer::CollegeBasketballPlayer(char playerType_, string playerName_, int games_,
    float efg_, int trb_, int ast_, int stl_, int blk_, int tov_,
    int pts_, string team_) :BasketballPlayer(playerType_, playerName_,
        games_, efg_, trb_, ast_, stl_, blk_, tov_, pts_)
{
    team = team_;
}

void CollegeBasketballPlayer::setTeam(string team_)
{
    team = team_;
}
string CollegeBasketballPlayer::getTeam()
{
    return team;
}

void CollegeBasketballPlayer::print()
{
    cout << setw(25) << playerName;
    cout << setw(4) << playerType;
    cout << setw(8) << value;
    cout << setprecision(2) << setw(10) << effRating;
    cout << setprecision(2) << setw(8) << efg << endl;
}