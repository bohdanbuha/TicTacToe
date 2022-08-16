#include<iostream>
using namespace std;

void ShowImage(char mas[][3], int size);
void Cross(char mas[][3], int size);
void Zero(char mas[][3], int size);
bool FieldFilling(char mas[][3], int size, char possCross, char possZero);
bool CheckWin(char mas[][3], int size);
bool EndGame(char mas[][3], int size);

int main()
{
    const int HEIGHT = 3;
    const int WIDTH = 3;
    char arr[HEIGHT][WIDTH] = { { '1','2','3' }, { '4', '5','6' }, { '7','8','9' } };
    ShowImage(arr, 3);
    Cross(arr,3);
	return 0;
}

void ShowImage(char mas[][3], int size) // Вивід поточного поля
{
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << "    " << mas[i][j] << "     |    " << mas[i][j + 1] << "     |    " << mas[i][j + 2] << "    \n" << "----------|----------|---------\n";
                break;
            }
        }
}

void Cross(char mas[][3], int size) 
{
    char possCross;
    cout << " Player 1(X), please enter the number of the position where you want to put a cross: ";
    cin >> possCross;
    if (!FieldFilling(mas, 3, possCross, '15')) // якщо за номером введеної позиції вже стоїть нолик
    {
        cout << "Please try again!\n ";
        Cross(mas, 3);
    }
    
    ShowImage(mas, 3);
    if (CheckWin(mas, 3)) //Перевірка чи є виграшна комбінація
    {
        cout << " Player 1(X) you are Winner!" << endl;
        EndGame(mas, 3);
    }
    else if (!EndGame(mas,3)) //Перевірка чи всі комірки заповнені Х або О
    {
        Zero(mas, 3);
    }
    else
        cout << "GAME OVER!!!!!!" << endl;
}

void Zero(char mas[][3], int size)
{
    char possZero;
    cout << " Player 2(O), please enter the number of the position where you want to put a cross: ";
    cin >> possZero;
    if (!FieldFilling(mas, 3, '15' ,possZero))
    {
        cout << "Please try again!\n ";
        Cross(mas, 3);
    }

    ShowImage(mas, 3);
    if (CheckWin(mas, 3))
    {
        cout << " Player 2(O) you are Winner!" << endl;
        EndGame(mas, 3);
    }
    else if (!EndGame(mas, 3))
    {
        Cross(mas, 3);
    }
    else
        cout << "GAME OVER!!!!!!" << endl;
}

bool FieldFilling(char mas[][3], int size, char possCross, char possZero)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (possCross == mas[i][j])
            {
                mas[i][j] = 'X';
                return true;
            }
            else if (possZero == mas[i][j])
            {
                mas[i][j] = 'O';
                return true;
            }
        }
    }
    return false;
}

bool CheckWin(char mas[][3], int size)
{
    for (int i = 0; i < 3; i++)
    {
        if (mas[i][0] == mas[i][1] && mas[i][1] == mas[i][2])
        {
            return true;
        }
        if (mas[0][i] == mas[1][i] && mas[1][i] == mas[2][i])
        {
            return true;
        }
        if (mas[0][0] == mas[1][1] && mas[1][1] == mas[2][2] || mas[2][0] == mas[1][1] && mas[1][1] == mas[0][2])
        {
            return true;
        }
    }  
    return false;
}

bool EndGame(char mas[][3], int size)
{
    int k = 0; //кількість заповнених комірок
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (mas[i][j] == 'X' && k < 9 || mas[i][j] == 'O' && k < 9)
            {
                k++;
            }
            else
                return false;
        }
    }
    return true;
}

