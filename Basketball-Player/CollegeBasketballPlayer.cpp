#include "CollegeBasketballPlayer.h"
/// <summary>
/// default constructor for college basketball player
/// </summary>
CollegeBasketballPlayer::CollegeBasketballPlayer():BasketballPlayer()
{
    team = "unknown";
}
/// <summary>
/// override college basketball player constructor
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
/// <param name="team_">the team that the player plays on</param>
CollegeBasketballPlayer::CollegeBasketballPlayer(char playerType_, string playerName_, int games_,
    float efg_, int trb_, int ast_, int stl_, int blk_, int tov_,
    int pts_, string team_) :BasketballPlayer(playerType_, playerName_,
        games_, efg_, trb_, ast_, stl_, blk_, tov_, pts_)
{
    team = team_;
}
/// <summary>
/// Sets player's team
/// </summary>
/// <param name="team_">the team of player</param>
void CollegeBasketballPlayer::setTeam(string team_)
{
    team = team_;
}
/// <summary>
/// Gets the team that the player is on
/// </summary>
/// <returns>the team</returns>
string CollegeBasketballPlayer::getTeam()
{
    return team;
}
/// <summary>
/// Prints the stats for the player
/// </summary>
void CollegeBasketballPlayer::print()
{
    cout << setw(24) << playerName;
    cout << setw(6) << playerType;
    cout << setw(24) << value;
    cout << setprecision(2) << setw(12) << effRating;
    cout << setprecision(2) << setw(12) << efg << endl;
}