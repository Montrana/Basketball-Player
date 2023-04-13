#include "Player.h"

/// <summary>
/// 
/// https://java2blog.com/read-csv-file-in-cpp/#:~:text=To%20read%20a%20CSV%20file%2C,variable%20as%20its%20second%20argument.
/// </summary>
/// <param name="players"></param>
/// <param name="filename"></param>
void readFile(vector<BasketballPlayer*>& players, string fname)
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
			ProBasketballPlayer* tempPro = new ProBasketballPlayer();
			CollegeBasketballPlayer* tempCollege = new CollegeBasketballPlayer();
			stringstream str(line);
			while (getline(str, data, ','))
			{
				playerStr.push_back(data);
			}
			if (playerStr.size() > 11)
			{
				*tempPro = ProBasketballPlayer('P', playerStr[0], stoi(playerStr[1]),
					stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
					stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
					stoi(playerStr[8]), stoi(playerStr[10]), playerStr[11]);
				players.push_back(tempPro);
			}
			else if (playerStr.size() > 9)
			{
				try {
					*tempCollege = CollegeBasketballPlayer('C', playerStr[0], stoi(playerStr[1]),
						stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
						stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
						stoi(playerStr[8]), playerStr[9]);
					players.push_back(tempCollege);
				}
				catch (...)
				{
					cout << playerStr[0] << " NCAA Player : Invalid stoi argument\n";
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

void allNCAA(vector<BasketballPlayer*> players)
{
	int playerNum = 0;
	vector<int> includedPlayers;
	while (playerNum < 12)
	{
		int highestVal;
		for (int i = 0; i < players.size(); i++)
		{
			if ((players.at(i)->getValue() > players.at(i)->getValue() || i == 0) 
				&& find(includedPlayers.begin(), includedPlayers.end(), i) == includedPlayers.end())
			{
				highestVal = i;
				includedPlayers.push_back(i);
			}
		}
		players.at(highestVal)->print();
		playerNum++;
	}
}

void mixNCAAandPro(vector<BasketballPlayer*> players)
{

}

void allPro(vector<BasketballPlayer*> players)
{

}
