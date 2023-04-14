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
	fout.close();
}

void allNCAA(vector<BasketballPlayer*> players)
{
	cout << "NCAA Team List" << endl;
	cout << endl;
	cout << setw(22) << "NCAA Player Name";
	cout << setw(6) << "Type";
	cout << setw(16) << "Player Value";
	cout << setw(12) << "Eff Rating";
	cout << setw(12) << "EFG Rating" << endl;
	int playerNum = 0;
	vector<int> includedPlayers;
	
	while (playerNum < 12)
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

void mixNCAAandPro(vector<BasketballPlayer*> players)
{
	cout << "NCAA and Pro Team List" << endl;
	cout << endl;
	cout << setw(22) << "Player Name";
	cout << setw(6) << "Type";
	cout << setw(10) << "Position";
	cout << setw(16) << "Player Value";
	cout << setw(12) << "Eff Rating";
	cout << setw(12) << "EFG Rating" << endl;
	searchPosition(players, "C");
	searchPosition(players, "F");
	searchPosition(players, "G");
}

void allPro(vector<BasketballPlayer*> players)
{

}

void searchPosition(vector<BasketballPlayer*> players, string pos)
{
	int playerNum = 0;
	vector<int> includedPlayers;

	while (playerNum < 2)
	{
		int highestVal = 0;
		for (int i = 0; i < players.size(); i++)
		{
			if (players.at(i)->getPlayerType() == 'P')
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
				}
			}
		}
		includedPlayers.push_back(highestVal);
		players.at(highestVal)->print();
		playerNum++;
	}
}