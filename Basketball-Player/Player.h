#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "CollegeBasketballPlayer.h"
#include "ProBasketballPlayer.h"
using namespace std;


void readFile(vector<BasketballPlayer*>& players, string fname, ofstream &fout);

void allNCAA(vector<BasketballPlayer*> players, int teamSize);

void mixNCAAandPro(vector<BasketballPlayer*> players);

void allPro(vector<BasketballPlayer*> players);

int searchPosition(vector<BasketballPlayer*> players, string pos, int maxPlayers, int maxVal, int teamSalary);
void searchPosition(vector<BasketballPlayer*> players, string pos, int maxPlayers, int maxVal);