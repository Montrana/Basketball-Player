#pragma once
#include "Basketball-Player.h"
class BasketBallPlayer
{
protected:
	char playerType;
	string playerName;
	int games;
	float efg;
	int trb;
	int ast;
	int stl;
	int blk;
	int tov;
	int pts;
	float effRating;
	int value;
public:
	BasketBallPlayer();
	BasketBallPlayer(char playerType_, string playerName_, int games_, float efg_,
		int trb_, int ast_, int stl_, int blk_, int tov_, int pts_);

	void setPlayerType(char playerType_);
	void setPlayerName(string playerName_);
	void setGames(int games_);
	void setEFG(float efg_);
	void setTRB(int trb_);
	void setAST(int ast_);
	void setSTL(int stl_);
	void setBLK(int blk_);
	void setTOV(int tov_);
	void setPoints(int pts_);
	void setEffRating();
	void setValue();

	char getPlayerType();

	void print();
};

