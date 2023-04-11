// Basketball-Player.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Player.h"

int main()
{
    vector<BasketballPlayer *> players;
    readFile(players, "playerStatsPro.csv");
    //readFile(players, "playerStatsNCAA.csv");
    
    for (int i = 0; i < players.size(); i++)
    {
        players.at(i)->print();
    }
}


