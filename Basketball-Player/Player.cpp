#include "Player.h"

/// <summary>
/// 
/// https://java2blog.com/read-csv-file-in-cpp/#:~:text=To%20read%20a%20CSV%20file%2C,variable%20as%20its%20second%20argument.
/// </summary>
/// <param name="players"></param>
/// <param name="filename"></param>
void readFile(vector<BasketballPlayer*>& players, string fname, ofstream &fout)
{
	string line, data;
	vector<string> playerStr;
	fstream file(fname, ios::in);
	if (file.is_open())
	{
		getline(file, line);
		while (getline(file, line))
		{
			playerStr.clear();
			BasketballPlayer* tempPlayer = nullptr;
			ProBasketballPlayer* tempPro = new ProBasketballPlayer();
			CollegeBasketballPlayer* tempCollege = new CollegeBasketballPlayer();
			stringstream str(line);
			while (getline(str, data, ','))
			{
				playerStr.push_back(data);
			}
			try
			{
				if (playerStr.size() > 11)
				{
					tempPlayer = new ProBasketballPlayer('P', playerStr[0], stoi(playerStr[1]),
						stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
						stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
						stoi(playerStr[8]), stoi(playerStr[10]), playerStr[11]);
				}
				else if (playerStr.size() > 9)
				{
					tempPlayer = new CollegeBasketballPlayer('C', playerStr[0], stoi(playerStr[1]),
						stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
						stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
						stoi(playerStr[8]), playerStr[9]);
				}
				players.push_back(tempPlayer);
			}
			catch (runtime_error err)
			{
				if (playerStr.size() > 11)
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "Pro Player";
					fout << setw(5) << ":\t" << setw(20) << err.what() << endl;
				}
				else if (playerStr.size() > 9)
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "NCAA Player";
					fout << setw(5) << ":\t" << setw(20) << err.what() << endl;
				}
			}
			catch (invalid_argument invalid)
			{
				if (playerStr.size() > 11)
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "Pro Player";
					fout << setw(5) << ":\t" << setw(20) << invalid.what() << endl;
				}
				else if (playerStr.size() > 9)
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "NCAA Player";
					fout << setw(5) << ":\t" << setw(20) << invalid.what() << endl;
				}
			}
			//tempPlayer->print();
		}
	}
	else
	{
		cout << "unable to open file " << fname << endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="players"></param>
/// <param name="teamSize"></param>
void allNCAA(vector<BasketballPlayer*> players, int teamSize)
{
	
	int playerNum = 0;
	vector<int> includedPlayers;
	
	while (playerNum < teamSize)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			if (players.at(i)->getPlayerType() == 'C' &&
				find(includedPlayers.begin(), includedPlayers.end(), i) ==
				includedPlayers.end())
			{
				if (players.at(i)->getValue() > players.at(highestVal)->getValue())
				{
					highestVal = i;
				}
				else if (players.at(i)->getValue() == players.at(highestVal)->getValue())
				{
					if (players.at(i)->getEffRating() > players.at(highestVal)->getEffRating())
					{
						highestVal = i;
					}
				}
				else if (players.at(highestVal)->getPlayerType() != 'C' )
				{
					highestVal = i;
				}
			}
		}
		includedPlayers.push_back(highestVal);
		players.at(highestVal)->print();
		playerNum++;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="players"></param>
void mixNCAAandPro(vector<BasketballPlayer*> players)
{
	
	searchPosition(players, "C", 2, 10);
	searchPosition(players, "F", 2, 10);
	searchPosition(players, "G", 2, 10);
	allNCAA(players, 6);
}

/// <summary>
/// 
/// </summary>
/// <param name="players"></param>
void allPro(vector<BasketballPlayer*> players)
{
	int contractVal = 0;
	contractVal += searchPosition(players, "C", 1, 10, contractVal);
	contractVal += searchPosition(players, "F", 2, 10, contractVal);
	contractVal += searchPosition(players, "G", 2, 10, contractVal);

	contractVal += searchPosition(players, "C", 1, 8, contractVal);

	contractVal += searchPosition(players, "F", 1, 8, contractVal);
	contractVal += searchPosition(players, "G", 1, 8, contractVal);

	contractVal += searchPosition(players, "G", 2, 5, contractVal);
	contractVal += searchPosition(players, "F", 2, 5, contractVal);
	
	cout << "Total Pay:";
	cout << setw(84) << contractVal << endl;
}

/// <summary>
/// 
/// </summary>
/// <param name="players"></param>
/// <param name="pos"></param>
/// <param name="maxPlayers"></param>
/// <param name="maxVal"></param>
/// <param name="teamSalary"></param>
/// <returns></returns>
int searchPosition(vector<BasketballPlayer*> players, string pos, int maxPlayers, int maxVal, int teamSalary)
{
	int playerNum = 0;
	vector<int> includedPlayers;
	int contractVal = 0;
	while (playerNum < maxPlayers)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			if (players.at(i)->getPlayerType() == 'P' && players.at(i)->getValue() <= maxVal)
			{
				if (dynamic_cast<ProBasketballPlayer*>(players.at(i))->getPosition() == pos
					&& find(includedPlayers.begin(), includedPlayers.end(), i) == includedPlayers.end())
				{
					if (players.at(i)->getValue() > players.at(highestVal)->getValue())
					{
						highestVal = i;
					}
					else if (players.at(i)->getValue() == players.at(highestVal)->getValue())
					{
						if (players.at(i)->getEffRating() > players.at(highestVal)->getEffRating())
						{
							highestVal = i;
						}
					}
					else if (players.at(highestVal)->getValue() > maxVal)
					{
						highestVal = i;
					}
				}
			}
		}
		if (contractVal + dynamic_cast<ProBasketballPlayer*>(players.at(highestVal))->getContractValue() + teamSalary < 98000000)
		{
			includedPlayers.push_back(highestVal);
			players.at(highestVal)->print();
			contractVal += dynamic_cast<ProBasketballPlayer*>(players.at(highestVal))->getContractValue();
			playerNum++;
		}
		else
		{
			maxVal--;
		}
	}
	return contractVal;
}

/// <summary>
/// 
/// </summary>
/// <param name="players"></param>
/// <param name="pos"></param>
/// <param name="maxPlayers"></param>
/// <param name="maxVal"></param>
void searchPosition(vector<BasketballPlayer*> players, string pos, int maxPlayers, int maxVal)
{
	int playerNum = 0;
	vector<int> includedPlayers;
	while (playerNum < maxPlayers)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			//if the player is a pro and the players value is lower than the max value:
			if (players.at(i)->getPlayerType() == 'P' && players.at(i)->getValue() <= maxVal)
			{
				//If the player's position is the position we are searching for and the player we are looking at isn't already in the included players
				if (dynamic_cast<ProBasketballPlayer*>(players.at(i))->getPosition() == pos
					&& find(includedPlayers.begin(), includedPlayers.end(), i) == includedPlayers.end())
				{
					if (players.at(i)->getValue() > players.at(highestVal)->getValue())
					{
						highestVal = i;
					}
					else if (players.at(i)->getValue() == players.at(highestVal)->getValue())
					{
						if (players.at(i)->getEffRating() > players.at(highestVal)->getEffRating())
						{
							highestVal = i;
						}
					}
					else if (players.at(highestVal)->getValue() > maxVal)
					{
						highestVal = i;
					}
				}
			}
		}
		includedPlayers.push_back(highestVal);
		players.at(highestVal)->print();
		playerNum++;
	}
}