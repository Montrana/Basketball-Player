#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "CollegeBasketballPlayer.h"
#include "ProBasketballPlayer.h"
using namespace std;


void readFile(vector<BasketballPlayer*>& players, string fname);

void allNCAA(vector<BasketballPlayer*> players);

void mixNCAAandPro(vector<BasketballPlayer*> players);

void allPro(vector<BasketballPlayer*> players);