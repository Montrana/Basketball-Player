#include "BasketballPlayer.h"

/// <summary>
/// Basketball Player constructor
/// </summary>
BasketballPlayer::BasketballPlayer()
{
	playerType = 'P';
	playerName = "Unknown";
	games = 0;
	efg = 0;
	trb = 0;
	ast = 0;
	stl = 0;
	blk = 0;
	tov = 0;
	pts = 0;
	effRating = 0;
	value = 0;
}

/// <summary>
/// override basketball player constructor
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
BasketballPlayer::BasketballPlayer(char playerType_, 
	string playerName_, int games_, float efg_, int trb_, 
	int ast_, int stl_, int blk_, int tov_, int pts_)
{
	playerType = playerType_;
	playerName = playerName_;
	games = games_;
	efg = efg_;
	trb = trb_;
	ast = ast_;
	stl = stl_;
	blk = blk_;
	tov = tov_;
	pts = pts_;
	setEffRating();
	setValue();
}

/// <summary>
/// Sets the player type
/// </summary>
/// <param name="playerType_">if the player is a pro or college player</param>
void BasketballPlayer::setPlayerType(char playerType_)
{
	playerType = playerType_;
}
/// <summary>
/// Sets the player's name
/// </summary>
/// <param name="playerName_">The name of the player</param>
void BasketballPlayer::setPlayerName(string playerName_)
{
	playerName = playerName_;
}
/// <summary>
/// sets the amount of games the player has played
/// </summary>
/// <param name="games_">number of games player has played</param>
void BasketballPlayer::setGames(int games_)
{
	games = games_;
}
/// <summary>
/// sets the efg
/// </summary>
/// <param name="efg_">Effective Field Goal Percentage</param>
void BasketballPlayer::setEFG(float efg_)
{
	efg = efg_;
}
/// <summary>
/// sets the total rebounds
/// </summary>
/// <param name="trb_">total rebounds player has made</param>
void BasketballPlayer::setTRB(int trb_)
{
	trb = trb_;
}
/// <summary>
/// sets the amount of assists
/// </summary>
/// <param name="ast_">assists player has made</param>
void BasketballPlayer::setAST(int ast_)
{
	ast = ast_;
}
/// <summary>
/// sets the amount of steals
/// </summary>
/// <param name="stl_">steals player has made</param>
void BasketballPlayer::setSTL(int stl_)
{
	stl = stl_;
}
/// <summary>
/// sets the amount of blocks
/// </summary>
/// <param name="blk_">blocks player has made</param>
void BasketballPlayer::setBLK(int blk_)
{
	blk = blk_;
}
/// <summary>
/// sets the amount of turnovers
/// </summary>
/// <param name="tov_">turnovers player has committed</param>
void BasketballPlayer::setTOV(int tov_)
{
	tov = tov_;
}
/// <summary>
/// sets the amount of points
/// </summary>
/// <param name="pts_">points the player has scored</param>
void BasketballPlayer::setPoints(int pts_)
{
	pts = pts_;
}
/// <summary>
/// calculates and sets the player's efficiency rating
/// </summary>
void BasketballPlayer::setEffRating()
{
	if (games > 5)
	{
		effRating = (pts + trb + ast + stl + blk - (pts / efg - pts + tov)) / games;
	}
	else
	{
		throw runtime_error("Insufficient game count: " + games);
	}
}
/// <summary>
/// calculates and sets the player's value
/// </summary>
void BasketballPlayer::setValue()
{
	if (efg > .70 || effRating > 20)
	{
		value = 10;
	}
	else if (efg > .65 || effRating > 15)
	{
		value = 9;
	}
	else if (efg > .60 || effRating > 13)
	{
		value = 8;
	}
	else if (efg > .55 || effRating > 10)
	{
		value = 7;
	}
	else if (efg > .55 && static_cast<float>(blk) / games > 3 &&
		static_cast<float>(pts) / games > 10 && static_cast<float>(trb) / games > 4)
	{
		value = 6;
	}
	else if (efg > .45 && static_cast<float>(pts) / games > 10 &&
		static_cast<float>(trb) / games > 4)
	{
		value = 5;
	}
	else if (efg > .40 && static_cast<float>(pts) / games > 5 &&
		static_cast<float>(trb) / games > 3)
	{
		value = 3;
	}
	else if (efg > .35 && static_cast<float>(pts) / games > 5 &&
		static_cast<float>(trb) / games > 3)
	{
		value = 2;
	}
	else
	{
		value = 0;
	}
}

/// <summary>
/// gets the players type
/// </summary>
/// <returns>the player type</returns>
char BasketballPlayer::getPlayerType() 
{
	return playerType;
}
/// <summary>
/// gets the name of the player
/// </summary>
/// <returns>the name of the player</returns>
string BasketballPlayer::getPlayerName() 
{
	return playerName;
}

/// <summary>
/// gets the number of games
/// </summary>
/// <returns>the number of games</returns>
int BasketballPlayer::getGames()
{
	return games;
}
/// <summary>
/// gets the Effective Field Goal Percentage
/// </summary>
/// <returns>Effective Field Goal Percentage</returns>
float BasketballPlayer::getEFG()
{
	return efg;
}

/// <summary>
/// gets the total rebounds
/// </summary>
/// <returns>total rebounds</returns>
int BasketballPlayer::getTRB() 
{
	return trb;
}
/// <summary>
/// gets the assists
/// </summary>
/// <returns>steals</returns>
int BasketballPlayer::getAST()
{
	return ast;
}
/// <summary>
/// gets the assists
/// </summary>
/// <returns>steals</returns>
int BasketballPlayer::getSTL()
{
	return stl;
}
/// <summary>
/// gets the blocks
/// </summary>
/// <returns>blocks</returns>
int BasketballPlayer::getBLK()
{
	return blk;
}
/// <summary>
/// gets the turnovers
/// </summary>
/// <returns>turnovers</returns>
int BasketballPlayer::getTOV()
{
	return tov;
}
/// <summary>
/// gets the points
/// </summary>
/// <returns>points</returns>
int BasketballPlayer::getPoints()
{
	return pts;
}
/// <summary>
/// gets the player's efficiency rating
/// </summary>
/// <returns>the player's efficiency rating</returns>
float BasketballPlayer::getEffRating()
{
	return effRating;
}
/// <summary>
/// gets the player's value
/// </summary>
/// <returns>the player's value</returns>
int BasketballPlayer::getValue()
{
	return value;
}