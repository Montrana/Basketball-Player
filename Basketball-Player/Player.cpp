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
			BasketballPlayer* tempPlayer = new ProBasketballPlayer();
			stringstream str(line);
			while (getline(str, data, ','))
			{
				playerStr.push_back(data);
			}
			if (playerStr.size() > 11)
			{
				*tempPlayer = ProBasketballPlayer('P', playerStr[0], stoi(playerStr[1]),
					stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
					stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
					stoi(playerStr[8]), stoi(playerStr[9]), playerStr[10]);
			}
			else if (playerStr.size() > 10)
			{
				*tempPlayer = CollegeBasketballPlayer('C', playerStr[0], stoi(playerStr[1]),
					stof(playerStr[2]), stoi(playerStr[3]), stoi(playerStr[4]),
					stoi(playerStr[5]), stoi(playerStr[6]), stoi(playerStr[7]),
					stoi(playerStr[8]), playerStr[9]);
			}
			tempPlayer->print();


		}
	}
}