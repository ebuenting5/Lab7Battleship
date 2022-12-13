#include <iostream>
#include <iomanip>

using namespace std;

const int boardsize = 10;
typedef char board[boardsize][boardsize][2];

void iniboard(board Board);
void outboard(board Board);
void Ushipplacement(board uFriendly, int &j, int &i);
void UserChoice(int &j, int &i);
void cShipplacement(board cFriendly);

int main(int &choice, int &Shipsize)
{
	
	int i = 0;
	int j = 0;

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

	Ushipplacement(uFriendly, i, j);
	cShipplacement(cFriendly);

	return 0;
}

void iniboard(board Board)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i][j][0] = '~';
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
			cout << Board[i][j][0] << " ";
		}
		cout << endl;
	}
}
void Ushipplacement(board uFriendly, int &j, int &i)
{
	int Shipsize = 0, choice, Shiptype;
	for (int c = 1; c < 6; c++)
	{
		bool print = true;
		switch (c)
		{
		case 1:
			Shipsize = 5;
			Shiptype = 5;
			cout << "You are placing Carrier (5 spaces)\n";
			break;
		case 2:
			Shipsize = 4;
			Shiptype = 4;
			cout << "You are placing Battleship (4 spaces)\n";
			break;
		case 3:
			Shipsize = 3;
			Shiptype = 3;
			cout << "You are placing Cruiser (3 spaces)\n";
			break;
		case 4:
			Shipsize = 3;
			Shiptype = 2;
			cout << "You are placing Submarine (3 spaces)\n";
			break;
		case 5:
			Shipsize = 2;
			Shiptype = 1;
			cout << "You are placing Destroyer (2 spaces)\n";
			break;
		}
		UserChoice(j, i);
		cout << "Do you want the ship to be placed up(1), down(2), right(3), or left(4) from current point?\n";
		cin >> choice;
		int y = j;
		int x = i;
		switch (choice)
		{
		case 1:
			for (int a = 0; a < Shipsize; a++)
			{
				if (uFriendly[y][x][0] == '#')
				{
					cout << "Ships overlap, reselect coordinates\n";
					c--;
					print = false;
					break;
				}
				y = y - 1;
			}
			break;
		case 2:
			for (int a = 0; a < Shipsize; a++)
			{
				if (uFriendly[y][x][0] == '#')
				{
					cout << "Ships overlap, reselect coordinates\n";
					c--;
					print = false;
					break;
				}
				y = y + 1;
			}
			break;
		case 3:
			for (int a = 0; a < Shipsize; a++)
			{
				if (uFriendly[y][x][0] == '#')
				{
					cout << "Ships overlap, reselect coordinates\n";
					c--;
					print = false;
					break;
				}
				x = x + 1;
			}
			break;
		case 4:
			for (int a = 0; a < Shipsize; a++)
			{
				if (uFriendly[y][x][0] == '#')
				{
					cout << "Ships overlap, reselect coordinates\n";
					c--;
					print = false;
					break;
				}
				x = x - 1;
			}
			break;
		}
		if (!print)
			continue;
		int test = 0;
		switch (choice)
		{
		case 1:
			test = j - Shipsize + 1;
			if (test < 0)
			{
				cout << "Boat went out of bounds, retry\n";
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				uFriendly[j][i][0] = '#';
				uFriendly[j][i][1] = Shiptype;
				j = j - 1;
			}
			break;
		case 2:
			test = j + Shipsize - 1;
			if (test > 9)
			{
				cout << "Boat went out of bounds, retry\n";
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				uFriendly[j][i][0] = '#';
				uFriendly[j][i][1] = Shiptype;
				j = j + 1;
			}
			break;
		case 3:
			test = i + Shipsize - 1;
			if (test > 9)
			{
				cout << "Boat went out of bounds, retry\n";
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				uFriendly[j][i][0] = '#';
				uFriendly[j][i][1] = Shiptype;
				i = i + 1;
			}
			break;
		case 4:
			test = i - Shipsize + 1;
			if (test < 0)
			{
				cout << "Boat went out of bounds, retry\n";
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				uFriendly[j][i][0] = '#';
				uFriendly[j][i][1] = Shiptype;
				i = i - 1;
			}
			break;
		}
		outboard(uFriendly);
	}
}
void UserChoice(int &j, int &i)
{
	i = 0;
	j = 0;
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

void cShipplacement(board cFriendly)
{
	int Shipsize = 0, choice, Shiptype, i, j;
	srand(time(NULL));
	for (int c = 1; c < 6; c++)
	{
		bool print = true;
		switch (c)
		{
		case 1:
			Shipsize = 5;
			Shiptype = 5;
			break;
		case 2:
			Shipsize = 4;
			Shiptype = 4;
			break;
		case 3:
			Shipsize = 3;
			Shiptype = 3;
			break;
		case 4:
			Shipsize = 3;
			Shiptype = 2;
			break;
		case 5:
			Shipsize = 2;
			Shiptype = 1;
			break;
		}
		i = 1 + (rand() % 10);
		j = 1 + (rand() % 10);
		choice = 1 + (rand() % 4);
		int y = j;
		int x = i;
		switch (choice)
		{
		case 1:
			for (int a = 0; a < Shipsize; a++)
			{
				if (cFriendly[y][x][0] == '#')
				{
					c--;
					print = false;
					break;
				}
				y = y - 1;
			}
			break;
		case 2:
			for (int a = 0; a < Shipsize; a++)
			{
				if (cFriendly[y][x][0] == '#')
				{
					c--;
					print = false;
					break;
				}
				y = y + 1;
			}
			break;
		case 3:
			for (int a = 0; a < Shipsize; a++)
			{
				if (cFriendly[y][x][0] == '#')
				{
					c--;
					print = false;
					break;
				}
				x = x + 1;
			}
			break;
		case 4:
			for (int a = 0; a < Shipsize; a++)
			{
				if (cFriendly[y][x][0] == '#')
				{
					c--;
					print = false;
					break;
				}
				x = x - 1;
			}
			break;
		}
		if (!print)
			continue;
		int test = 0;
		switch (choice)
		{
		case 1:
			test = j - Shipsize + 1;
			if (test < 0)
			{
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				cFriendly[j][i][0] = '#';
				cFriendly[j][i][1] = Shiptype;
				j = j - 1;
			}
			break;
		case 2:
			test = j + Shipsize - 1;
			if (test > 9)
			{
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				cFriendly[j][i][0] = '#';
				cFriendly[j][i][1] = Shiptype;
				j = j + 1;
			}
			break;
		case 3:
			test = i + Shipsize - 1;
			if (test > 9)
			{
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				cFriendly[j][i][0] = '#';
				cFriendly[j][i][1] = Shiptype;
				i = i + 1;
			}
			break;
		case 4:
			test = i - Shipsize + 1;
			if (test < 0)
			{
				c--;
				continue;
			}
			for (int a = 0; a < Shipsize; a++)
			{
				cFriendly[j][i][0] = '#';
				cFriendly[j][i][1] = Shiptype;
				i = i - 1;
			}
			break;
		}
	}
	outboard(cFriendly);
}