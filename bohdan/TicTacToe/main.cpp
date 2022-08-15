#include <iostream>
#include <cctype>
using namespace std;

char site, pos;
int availablePos = 9;
string player1, player2;

void drawField(char arr[3][3]);
void initPlayers();
void choosePosition(char arr[3][3]);
void ClearScreen();
int main()
{
	char arr[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
	char positionArr[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
	drawField(arr);
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
	cout << endl << "Player two choose your name : ";
	cin >> player2;
}
void choosePosition(char arr[3][3])
{
	do
	{
		ClearScreen();
		drawField(arr);
		cout << player1 << " type number of available position :";
		cin >> pos;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (pos == arr[i][j])
				{
					arr[i][j] = site;
					availablePos--;
					break;
				}
				else if (pos == arr[i][j] && site == arr[i][j])
				{
					cout << "error " << endl;
					break;
				}
			}
			if (i == 2)
				break;
		}

	} while (availablePos != 0);
	cout << endl << player1 << " choose a site you want to play on ? (O/X) : ";
	cin >> site;
	site = toupper(site);
	cout << endl << "Player two choose your name : ";
	cin >> player2;
}
void ClearScreen()
{
	cout << string(100, '\n');
}
