#include <iostream>
#include <stdlib.h>
#include <cmath>
#include<conio.h>
#include<sstream>
#include <fstream>
using namespace std;
void tttDisplay();                     // display board
bool update(char position, char sign); // update board
int move(char position, char sign, int idx);
bool checkDiagonals(char symbol);
bool checkColumns(char symbol);
bool checkRows(char symbol);
void processTTT();
string getParse(string abc, int num);
void storeInArray();
void storeInFile(int a);

const int SIZE = 3;
char ttt[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
fstream newfile;
int indx = 0;
main()
{
    system("cls");
    char saved;
    system("color B");
    cout << "New game or saved(n or s) : ";
    cin >> saved;
    if(saved == 's')
    storeInArray();
    processTTT();
}
void tttDisplay()
{
    cout << "$$$-TIC TAC TOE-$$$" << endl;
    cout << "-------------------" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << ttt[0][0] << "  |  " << ttt[0][1] << "  |  " << ttt[0][2] << "  |" << endl;
    cout << "|     |     |     |" << endl;
    cout << "-------------------" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << ttt[1][0] << "  |  " << ttt[1][1] << "  |  " << ttt[1][2] << "  |" << endl;
    cout << "|     |     |     |" << endl;
    cout << "-------------------" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << ttt[2][0] << "  |  " << ttt[2][1] << "  |  " << ttt[2][2] << "  |" << endl;
    cout << "|     |     |     |" << endl;
    cout << "-------------------" << endl;
}
bool update(char position, char sign)
{
    bool tf = false;
    if (position == '1')
    {
        if (ttt[0][0] != 'O' && ttt[0][0] != 'X')
        {
            ttt[0][0] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '2')
    {
        if (ttt[0][1] != 'O' && ttt[0][1] != 'X')
        {
            ttt[0][1] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '3')
    {
        if (ttt[0][2] != 'O' && ttt[0][2] != 'X')
        {
            ttt[0][2] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '4')
    {
        if (ttt[1][0] != 'O' && ttt[1][0] != 'X')
        {
            ttt[1][0] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '5')
    {
        if (ttt[1][1] != 'O' && ttt[1][1] != 'X')
        {
            ttt[1][1] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '6')
    {
        if (ttt[1][2] != 'O' && ttt[1][2] != 'X')
        {
            ttt[1][2] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '7')
    {
        if (ttt[2][0] != 'O' && ttt[2][0] != 'X')
        {
            ttt[2][0] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '8')
    {
        if (ttt[2][1] != 'O' && ttt[2][1] != 'X')
        {
            ttt[2][1] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else if (position == '9')
    {
        if (ttt[2][2] != 'O' && ttt[2][2] != 'X')
        {
            ttt[2][2] = sign;
            tf = true;
        }
        else
        {
            cout << "Already filled." << endl;
            cout << "Enter any key to continue : ";
            getch();
        }
    }
    else
    {
        cout << "Enter option Again(1 to 9)." << endl;
    }
    return tf;
}
int move(char position, char sign, int idx)
{
    bool tf;
    tf = update(position, sign);
    if (tf == false)
    {
        idx = idx - 1;
    }
    return idx;
}
bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < SIZE; idx = idx + 1)
    {
        if (ttt[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == SIZE)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < SIZE; row++, col--)
    {
        if (ttt[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == SIZE)
    {
        return 1;
    }
    return 0;
}
bool checkColumns(char symbol)
{
    int count = 0;
    for (int col = 0; col < SIZE; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < SIZE; row = row + 1)
        {
            if (ttt[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == SIZE)
        {
            return 1;
        }
    }
    return 0;
}
bool checkRows(char symbol)
{
    int count = 0;
    for (int row = 0; row < SIZE; row++)
    {
        count = 0;
        for (int col = 0; col < SIZE; col++)
        {
            if (ttt[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == SIZE)
        {
            return 1;
        }
    }
    return 0;
}
void processTTT()
{
    char position, sign;
    for (int i = indx; i < pow(SIZE, 2); i++)
    {
        indx = i;
        
        tttDisplay();
        if (checkColumns('O') || checkRows('O') || checkDiagonals('O'))
        {
            system("color A");
            cout << endl;
            cout << "Player 2 wins!" << endl;
            break;
        }
        else if (checkColumns('X') || checkRows('X') || checkDiagonals('X'))
        {
            system("color A");
            cout << endl;
            cout << "Player 1 wins!" << endl;
            break;
        }
        if (i % 2 == 0)
        {
            cout << "Sign for player 1 : X" << endl;
            cout << "Enter position or S to save : ";
            cin >> position;
            if (position == 'S')
            {
                storeInFile(i);
                break;
            }
            i = move(position, 'X', i);
            system("cls");
        }
        else
        {
            cout << "Sign for player 2 : O" << endl;
            cout << "Enter position or S to save : ";
            cin >> position;
            if (position == 'S')
            {
                storeInFile(i);
                break;
            }
            i = move(position, 'O', i);
            system("cls");
        }
        if (i == pow(SIZE, 2)-1)
        {
            system("color C");
            tttDisplay();
            cout << "Draw!" << endl;
        }
    }
}
string getParse(string abc, int num)
{
    int commaCount = 0;
    string item;
    for (int y = 0; y < abc.length(); y++)
    {
        if (abc[y] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == num)
        {
            item = item + abc[y];
        }
    }
    return item;
}
void storeInArray()
{
    string line;
    string b;
    int x =0 ;
    newfile.open("tictactoe.txt", ios::in);
    getline(newfile, line);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b = getParse(line, x);
            ttt[i][j] = b[0];
            x++;
        }
    }
    stringstream abc(getParse(line , 9));
    abc >> indx;
    cout << indx;
    newfile.close();
}
void storeInFile(int a)
{
    newfile.open("tictactoe.txt", ios::out);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            newfile << ttt[i][j] << ',';
        }
    }
    newfile << indx;
}
