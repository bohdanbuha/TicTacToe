#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char site, pos;
int availablePos = 9;
string player1, player2;
char player1Symbol, player2Symbol;

void drawField(char arr[3][3]);
void initPlayers();
void choosePosition(char arr[3][3]);
void ClearScreen();
char nextPlayer();
string checkPlayerSymbol();
bool checkWin(char arr[3][3]);
int main()
{
	char positionArr[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
	drawField(positionArr);
	initPlayers();
	choosePosition(positionArr);

	return 0;
}

void drawField(char arr[3][3])
{
	cout << "*************" << endl;
	cout << "* " << arr[0][0] << " * " << arr[0][1] << " * " << arr[0][2] << " *" << endl;
	cout << "*************" << endl;
	cout << "* " << arr[1][0] << " * " << arr[1][1] << " * " << arr[1][2] << " *" << endl;
	cout << "*************" << endl;
	cout << "* " << arr[2][0] << " * " << arr[2][1] << " * " << arr[2][2] << " *" << endl;
	cout << "*************" << endl;
}

void initPlayers()
{
	cout << "Player One choose your name : ";
	cin >> player1;
	cout << endl << player1 << " choose a site you want to play on ? (O/X) : ";
	cin >> site;
	site = toupper(site);
	player1Symbol = site;
	player2Symbol = nextPlayer();
	nextPlayer();
	cout << endl << "Player two choose your name : ";
	cin >> player2;
}
void choosePosition(char arr[3][3])
{
	while (availablePos != 0)
	{
		ClearScreen();
		drawField(arr);
		cout << checkPlayerSymbol() << " type number of available position :";
		cin >> pos;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (pos == arr[i][j])
				{
					arr[i][j] = site;
					availablePos--;
					site = nextPlayer();
					if (checkWin(arr))
					{
						goto exit;
					}
					break;
				}
				else if (pos != arr[i][j] && (site == arr[i][j] || site != arr[i][j]))
				{
					cout << "This position is taken, please choose another one" << endl;

					if (checkWin(arr))
					{
						goto exit;
					}

					break;
				}
			}
			if (i == 2)
				break;
		}
	}

exit:
	ClearScreen();
	drawField(arr);
	nextPlayer();
	cout << endl << checkPlayerSymbol() << " is a winner : ";
}

void ClearScreen()
{
	cout << string(100, '\n');
}

char nextPlayer()
{
	if (site == 'X')
		return site = 'O';
	else
		return site = 'X';
}
string checkPlayerSymbol()
{
	if (site == player1Symbol)
		return player1;
	else
		return player2;
}
bool checkWin(char arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
		{
			return true;
		}
		else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[i][2])
		{
			return true;
		}
		else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
		{
			return true;
		}
		else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
		{
			return true;
		}
	}
	return false;
}
