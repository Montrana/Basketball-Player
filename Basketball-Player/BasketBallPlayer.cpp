#include "BasketballPlayer.h"
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

void BasketballPlayer::setPlayerType(char playerType_)
{
	playerType = playerType_;
}
void BasketballPlayer::setPlayerName(string playerName_)
{
	playerName = playerName_;
}
void BasketballPlayer::setGames(int games_)
{
	games = games_;
}
void BasketballPlayer::setEFG(float efg_)
{
	efg = efg_;
}
void BasketballPlayer::setTRB(int trb_)
{
	trb = trb_;
}
void BasketballPlayer::setAST(int ast_)
{
	ast = ast_;
}
void BasketballPlayer::setSTL(int stl_)
{
	stl = stl_;
}
void BasketballPlayer::setBLK(int blk_)
{
	blk = blk_;
}
void BasketballPlayer::setTOV(int tov_)
{
	tov = tov_;
}
void BasketballPlayer::setPoints(int pts_)
{
	pts = pts_;
}
void BasketballPlayer::setEffRating()
{
	effRating = (pts + trb + ast + stl + blk - (pts / efg - pts + tov)) / games;
}
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

char BasketballPlayer::getPlayerType() 
{
	return playerType;
}
string BasketballPlayer::getPlayerName() 
{
	return playerName;
}
int BasketballPlayer::getGames()
{
	return games;
}
float BasketballPlayer::getEFG()
{
	return efg;
}
int BasketballPlayer::getTRB() 
{
	return trb;
}
int BasketballPlayer::getAST()
{
	return ast;
}
int BasketballPlayer::getSTL()
{
	return stl;
}
int BasketballPlayer::getBLK()
{
	return blk;
}
int BasketballPlayer::getTOV()
{
	return tov;
}
int BasketballPlayer::getPoints()
{
	return pts;
}
float BasketballPlayer::getEffRating()
{
	return effRating;
}
int BasketballPlayer::getValue()
{
	return value;
}