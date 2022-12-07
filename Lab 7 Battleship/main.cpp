#include <iostream>
#include <iomanip>

using namespace std;

enum direction
{	
	up = 1,
	down = 2,
	right = 3,
	left = 4,
};

const int boardsize = 10;
typedef char board[boardsize][boardsize];

void iniboard(board Board);
void outboard(board Board);
void shipplacement(board uFriendly);
void UserChoice();

int main()
{
	board uFriendly;
	board uEnemy;
	board cFriendly;
	board cEnemy;

	iniboard(uFriendly);
	iniboard(uEnemy);
	iniboard(cFriendly);
	iniboard(cEnemy);
	
	outboard(uFriendly);
	outboard(uEnemy);

	shipplacement(uFriendly);

	return 0;
}

void iniboard(board Board)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i][j] = '~';
		}
	}
}

void outboard(board Board)
{
	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(3) << i + 1 << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
}
void shipplacement(board uFriendly)
{
	int Shipsize = 0;
	for (int c = 1; c < 6; c++)
	{
		switch (c)
		{
		case 1:
			Shipsize = 5;
		case 2:
			Shipsize = 4;
		case 3:
			Shipsize = 3;
		case 4:
			Shipsize = 3;
		case 5:
			Shipsize = 2;
		}
	}
	UserChoice();
	cout << "Do you want the ship to be placed up, down, right, or left from current point?\n";
}
void UserChoice()
{
	int i, j;
	do
	{
		cout << "Enter an x coordinate 1-10:" << endl;
		cin >> i;
		if (i < 1 || i > 10)
		{
			cout << "Answer is not a valid coordinate" << endl;
			continue;
		}
		i = i - 1;
		cout << "Enter a y coordinate 1-10:\n";
		cin >> j;
		if (j < 1 || j > 10)
		{
			cout << "Answer is not a valid corrdinate" << endl;
			continue;
		}
		j = j - 1;
	} while (i > 10 || i < 0 || j > 10 || j < 0);
}