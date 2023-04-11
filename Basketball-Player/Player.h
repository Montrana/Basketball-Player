#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "CollegeBasketballPlayer.h"
#include "ProBasketballPlayer.h"
using namespace std;


void readFile(vector<BasketballPlayer*> players, string fname);