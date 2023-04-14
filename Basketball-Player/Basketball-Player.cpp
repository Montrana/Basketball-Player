// Basketball-Player.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Player.h"

int main()
{
    vector<BasketballPlayer*> players;

    ofstream fout("errorOutput.txt");
    readFile(players, "playerStatsPro.csv", fout);
    readFile(players, "playerStatsNCAA.csv", fout);
    
    fout.close();

    cout << endl;
    allNCAA(players);
    mixNCAAandPro(players);
}


