/// Basketball-Player.cpp : This file contains the 'main' function. Program execution begins and ends there.
/// Name: Montana Nicholson
/// Date: April 5th, 2023
/// Summary: This project reads in two csvs, one for pro players, and the other for college players.
/// It takes the data from those CSVs, and makes a team that is the best NCAA players,
/// best players from both the NCAA and Pro teams, with 2 players in each position for the pros,
/// and a well rounded Pro team that takes into account salary cap.

#include "Player.h"

/// <summary>
/// Reads both files, manages output and creates three teams
/// </summary>
/// <returns>an exit int</returns>
int main()
{
    vector<BasketballPlayer*> players;

    ofstream fout("errorOutput.txt");
    readFile(players, "playerStatsPro.csv", fout);
    readFile(players, "playerStatsNCAA.csv", fout);
    
    fout.close();

    cout << "NCAA Team List" << endl;
    cout << setw(24) << "NCAA Player Name";
    cout << setw(6) << "Type";
    cout << setw(24) << "Player Value";
    cout << setw(12) << "Eff Rating";
    cout << setw(12) << "EFG Rating" << endl;
    allNCAA(players, 12);
    cout << endl;

    cout << "NCAA and Pro Team List" << endl;
    cout << setw(24) << "Player Name";
    cout << setw(6) << "Type";
    cout << setw(10) << "Position";
    cout << setw(14) << "Player Value";
    cout << setw(12) << "Eff Rating";
    cout << setw(12) << "EFG Rating";
    cout << setw(16) << "Contract Value" << endl;
    mixNCAAandPro(players);
    cout << endl;

    cout << "All Pro Team List" << endl;
    cout << setw(24) << "Player Name";
    cout << setw(6) << "Type";
    cout << setw(10) << "Position";
    cout << setw(14) << "Player Value";
    cout << setw(12) << "Eff Rating";
    cout << setw(12) << "EFG Rating";
    cout << setw(16) << "Contract Value" << endl;
    allPro(players);
}