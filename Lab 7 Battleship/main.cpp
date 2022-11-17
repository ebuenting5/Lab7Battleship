#include <iostream>

using namespace std;
void iniboard(board Board);

typedef char board[10][10];

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

	return 0;
}
void iniboard(board Board)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i][j] = 0;
		}
	}
}
/*
* cout << "   ";
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << " ";
	}
	for (int i = 1; i <= 10; i++)
	{
		cout << endl << " " << i << " ";
		for (int i = 1; i <= 10; i++)
		{
			cout << " ~ ";
		}
	}
*/