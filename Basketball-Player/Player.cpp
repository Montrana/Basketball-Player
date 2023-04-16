#include "Player.h"

/// <summary>
/// Reads a file of players
/// https://java2blog.com/read-csv-file-in-cpp/#:~:text=To%20read%20a%20CSV%20file%2C,variable%20as%20its%20second%20argument.
/// </summary>
/// <param name="players">the vector of players to store the data in</param>
/// <param name="filename">the filename of the input file</param>
/// <param name="fout">error file stream to output errors to</param>
void readFile(vector<BasketballPlayer*>& players, string fname, ofstream& fout)
{
	string line, data;
	vector<string> playerStr;
	fstream file(fname);
	if (file.is_open())
	{
		getline(file, line); //throwaway line to clear the stat labels
		while (getline(file, line))
		{
			playerStr.clear();
			BasketballPlayer* tempPlayer = nullptr;
			stringstream str(line);
			while (getline(str, data, ','))
			{
				playerStr.push_back(data);
			}
			try
			{
				if (playerStr.size() > 11) // checks if it's a college player
				{
					tempPlayer = new ProBasketballPlayer('P', playerStr[0], stoi(playerStr[1]),
						stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
						stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
						stoi(playerStr[8]), stoi(playerStr[10]), playerStr[11]);
				}
				else if (playerStr.size() > 9) // checks if player is a College player
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
				if (playerStr.size() > 11) // checks if it's a college player
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "Pro Player";
					fout << setw(5) << ":\t" << setw(20) << err.what() << endl;
				}
				else if (playerStr.size() > 9) // checks if player is a College player
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "NCAA Player";
					fout << setw(5) << ":\t" << setw(20) << err.what() << endl;
				}
			}
			catch (invalid_argument invalid)
			{
				if (playerStr.size() > 11) // checks if it's a college player
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "Pro Player";
					fout << setw(5) << ":\t" << setw(20) << invalid.what() << endl;
				}
				else if (playerStr.size() > 9) // checks if player is a College player
				{
					fout << setw(22) << playerStr[0];
					fout << setw(15) << "NCAA Player";
					fout << setw(5) << ":\t" << setw(20) << invalid.what() << endl;
				}
			}
		}
	}
	else
	{
		cout << "unable to open file " << fname << endl;
	}
}

/// <summary>
/// creates an All NCAA team
/// </summary>
/// <param name="players">the list of players to search for</param>
/// <param name="teamSize">the size of the team</param>
void allNCAA(vector<BasketballPlayer*> players, int teamSize)
{
	vector<int> includedPlayers; // vector of the indexes of the included players

	while (includedPlayers.size() < teamSize)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			// if player is a college player and isn't already included in the team
			if (players.at(i)->getPlayerType() == 'C' &&
				find(includedPlayers.begin(), includedPlayers.end(), i) ==
				includedPlayers.end())
			{
				// if player's value at index i > player's value at index of highest value
				if (players.at(i)->getValue() > players.at(highestVal)->getValue())
				{
					highestVal = i;
				}
				// if player's value at index i = player's value at index of highest value
				else if (players.at(i)->getValue() == players.at(highestVal)->getValue())
				{
					// if player's efficiency rating at index i > player's efficiency rating at index of highest value
					if (players.at(i)->getEffRating() > players.at(highestVal)->getEffRating())
					{
						highestVal = i;
					}
				}
				// if player at highest val is not a college player
				else if (players.at(highestVal)->getPlayerType() != 'C')
				{
					highestVal = i;
				}
			}
		}
		includedPlayers.push_back(highestVal);
		players.at(highestVal)->print();
	}
}

/// <summary>
/// creates a team with a mix of NCAA players an pro players
/// </summary>
/// <param name="players">the list of players to search for</param>
void mixNCAAandPro(vector<BasketballPlayer*> players)
{
	searchPosition(players, "C", 2, 10);
	searchPosition(players, "F", 2, 10);
	searchPosition(players, "G", 2, 10);
	allNCAA(players, 6);
}

/// <summary>
/// Composes an all pro team
/// </summary>
/// <param name="players">the list of players to search for</param>
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
/// Search for players at the given position and prints them
/// </summary>
/// <param name="players">the list of players to search through</param>
/// <param name="pos">the position to look for</param>
/// <param name="maxPlayers">the amount of players that will be found</param>
/// <param name="maxVal">the max allotted value of a player</param>
/// <param name="teamSalary">the current team salary</param>
/// <returns>how much got added to the team salary</returns>
int searchPosition(vector<BasketballPlayer*> players, string pos, int maxPlayers, int maxVal, int teamSalary)
{
	vector<int> includedPlayers;
	int contractVal = 0;
	while (includedPlayers.size() < maxPlayers)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			//if the player is a pro and the players value is lower than the max value
			if (players.at(i)->getPlayerType() == 'P' && players.at(i)->getValue() <= maxVal)
			{
				// if the player's position is the position we are searching for and the player we are looking at isn't already in the included players
				if (dynamic_cast<ProBasketballPlayer*>(players.at(i))->getPosition() == pos
					&& find(includedPlayers.begin(), includedPlayers.end(), i) == includedPlayers.end())
				{
					// if player at I's value is higher than the value at the current tracked highest value
					if (players.at(i)->getValue() > players.at(highestVal)->getValue())
					{
						highestVal = i;
					}
					// if player at I's value is higher than the value at the current tracked highest value
					else if (players.at(i)->getValue() == players.at(highestVal)->getValue())
					{
						if (players.at(i)->getEffRating() > players.at(highestVal)->getEffRating())
						{
							highestVal = i;
						}
					}
					// if player at the highest value is higher than the max value.
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
		}
		else
		{
			maxVal--;
		}
	}
	return contractVal;
}

/// <summary>
/// Search for players at the given position and prints them
/// </summary>
/// <param name="players">the list of players to search through</param>
/// <param name="pos">the position to look for</param>
/// <param name="maxPlayers">the amount of players that will be found</param>
/// <param name="maxVal">the max allotted value of a player</param>
void searchPosition(vector<BasketballPlayer*> players, string pos, int maxPlayers, int maxVal)
{
	vector<int> includedPlayers;
	while (includedPlayers.size() < maxPlayers)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			//if the player is a pro and the players value is lower than the max value
			if (players.at(i)->getPlayerType() == 'P' && players.at(i)->getValue() <= maxVal)
			{
				// if the player's position is the position we are searching for and the player we are looking at isn't already in the included players
				if (dynamic_cast<ProBasketballPlayer*>(players.at(i))->getPosition() == pos
					&& find(includedPlayers.begin(), includedPlayers.end(), i) == includedPlayers.end())
				{
					// if player at I's value is higher than the value at the current tracked highest value
					if (players.at(i)->getValue() > players.at(highestVal)->getValue())
					{
						highestVal = i;
					}
					// if player at I's value is higher than the value at the current tracked highest value
					else if (players.at(i)->getValue() == players.at(highestVal)->getValue())
					{
						if (players.at(i)->getEffRating() > players.at(highestVal)->getEffRating())
						{
							highestVal = i;
						}
					}
					// if player at the highest value is higher than the max value.
					else if (players.at(highestVal)->getValue() > maxVal)
					{
						highestVal = i;
					}
				}
			}
		}
		includedPlayers.push_back(highestVal);
		players.at(highestVal)->print();
	}
}