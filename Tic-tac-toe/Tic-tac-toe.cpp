#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;
char square[9] = { '1','2','3','4','5','6','7','8','9' };

enum ConsoleColor
{
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(HANDLE hConsoleHandle, ConsoleColor text)
{
	SetConsoleTextAttribute(hConsoleHandle, text);
}

int checkwin()
{
	if (square[0] == square[1] && square[1] == square[2])
	{
		if (square[0] == 'X')
			return 1;
		else
			return 2;
	}
	else
		if (square[3] == square[4] && square[4] == square[5])
		{
			if (square[3] == 'X')
				return 1;
			else
				return 2;
		}
		else
			if (square[6] == square[7] && square[7] == square[8])
			{
				if (square[6] == 'X')
					return 1;
				else
					return 2;
			}
			else
				if (square[0] == square[3] && square[3] == square[6])
				{
					if (square[0] == 'X')
						return 1;
					else
						return 2;
				}
				else
					if (square[1] == square[4] && square[4] == square[7])
					{
						if (square[1] == 'X')
							return 1;
						else
							return 2;
					}
					else
						if (square[2] == square[5] && square[5] == square[8])
						{
							if (square[2] == 'X')
								return 1;
							else
								return 2;
						}
						else
							if (square[0] == square[4] && square[4] == square[8])
							{
								if (square[0] == 'X')
									return 1;
								else
									return 2;
							}
							else
								if (square[2] == square[4] && square[4] == square[6])
								{
									if (square[2] == 'X')
										return 1;
									else
										return 2;
								}
								else
									if (square[0] == square[3] && square[3] == square[6])
									{
										if (square[0] == 'X')
											return 1;
										else
											return 2;
									}
									else
										return 0;
}

void mark(int player, int box)
{
	if (player == 1)
	{

		square[box-1] = 'X';
	}
	else
		square[box-1] = 'O';
}

void display()
{
	for (int i = 0;i < 9;i++)
	{
		cout << square[i] << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << "\n\n";
	}
}

int main()
{
	int player1 = 1, player2 = 2;

	int box, result = 0, flag = 0;

	string playerName1;
	string playerName2;

	int color = 15;
	string colorStream;
	ofstream colorSettingOut;
	ifstream colorSettingIn;
	colorSettingIn.open("setting.txt");
	if (colorSettingIn)
	{
		while (!colorSettingIn.eof())
		{
			colorSettingIn >> color;
		}
		colorSettingIn.close();
	}
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetColor(hConsoleHandle, ConsoleColor(color));
	while (true) {
		string inputMenu;
		cout << "Enter 's' to open settings or 'r' to open reference\nTo start the game, press 'P'!\n";
		cin >> inputMenu;
		if (inputMenu == "r" || inputMenu == "R") {
			cout << "\033[2J\033[1;1H";
			cout << "Elizarov Daniil Ri-190006\nIrit - RTF 2020\nVersion 1.0\n\n";
		}
		else if (inputMenu == "s" || inputMenu == "S") {
			cout << "\033[2J\033[1;1H";
			cout << "Colors for changing text color:\n";
			cout << "Blue 1, Green 2, Cyan 3, Red 4, MagentaBrown 5, LightGray 6, DarkGray 7, LightBlue 8,\n LightGreen 9, LightCyan 10, LightRed 11, LightMagenta 12, Yellow 13, White 14";
			cout << "\nEnter the numer of color\n";
			colorSettingOut.open("setting.txt");
			cin >> color;
			colorSettingOut << color;
			colorSettingOut.close();
			colorSettingIn.open("setting.txt");
			if (colorSettingIn)
			{
				while (!colorSettingIn.eof())
				{
					colorSettingIn >> color;
				}
				colorSettingIn.close();
			}
			SetColor(hConsoleHandle, ConsoleColor(color));
			cout << "\033[2J\033[1;1H";
		}
		else if (inputMenu == "p" || inputMenu == "P") break;
	}

	cout << "\033[2J\033[1;1H";
	cout << "Please, enter name of the first player:\n";
	cin >> playerName1;
	cout << "Please, enter name of the second player:\n";
	cin >> playerName2;
	cout << "\033[2J\033[1;1H";

	for (int i = 1;i < 5;i++)
	{
		cout << "\033[2J\033[1;1H";
		cout << "\033[2J\033[1;1H";
		cout << "Player " << playerName1 << " Enter the Box\n\n";
		display();
		cin >> box;
		cout << "\033[2J\033[1;1H";
		mark(player1, box);

		result = checkwin();
		if (result == 1)
		{
			cout << "\n Congratualtions! player " << playerName1 << " has Won ";
			flag = 1;
			break;
		}
		else
			if (result == 2)
			{
				cout << "\n Congratualtions! player " << playerName2 << " has Won ";
				flag = 1;
				break;
			}
		cout << "\033[2J\033[1;1H";
		cout << "\033[2J\033[1;1H";	

		cout << "Player " << playerName2 << " Enter the Box\n\n";
		display();
		cin >> box;
		cout << "\033[2J\033[1;1H";
		mark(player2, box);

		result = checkwin();
		display();
		if (result == 1)
		{
			cout << "\nCongratualtions! player " << playerName1 << " has Won!";
			flag = 1;
			break;
		}
		else
			if (result == 2)
			{
				cout << "\nCongratualtions! player " << playerName2 << " has Won!";
				flag = 1;
				break;
			}
	}
	if (flag == 0)
		cout << "\nSorry, The game is a draw!";

	return 0;
}