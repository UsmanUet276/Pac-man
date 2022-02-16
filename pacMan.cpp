#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <time.h>
using namespace std;
fstream file;
// array
char mazeA[24][71];

// function prototype
void maze();
void readFile();
void gotoxy(int x, int y);
char mainMenu();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUP();
void movePacmanDown();
void set_cursor(bool visible);
int ghostDirection();
void ghostMovement();
void gameBreak();
void ghost1Move();
void ghost2Move();
void moveGhostLeft();
void moveGhostRight();
void moveGhostUP();
void moveGhostDown();
void ghost3Move();
void winLooseF();
void head();

int pacmanX = 9;
int pacmanY = 31;
int ghostX = 19;
int ghostY = 25;
int ghost1X = 1;
int ghost1Y = 2;
int ghost2X = 22;
int ghost2Y = 2;
int ghost3X = 2;
int ghost3Y = 58;
int count = 0;
int loopCounter = 0;
int c1 = 0, c2 = 0;
int prevX, prevY;
char previousItem = ' ';
bool horizontal = true;
bool vertical = true;
bool x = true;
int c = 3;
int life = 0;
bool powerPills = false;
bool ghostBool = true;
bool ghost1Bool = true;
bool ghost2Bool = true;
bool ghost3Bool = true;
int winLoose = 0;
string temp;
main()
{
    char op;
    while (true)
    {
        system("color 0A");
        system("cls");
        set_cursor(true);
        op = mainMenu();
        if (op == '1')
        {
            system("cls");
            readFile();
            system("color 05");
            set_cursor(false);
            maze();
            gotoxy(pacmanX, pacmanY);
            cout << "P";
            gotoxy(ghostX, ghostY);
            cout << "G";
            gotoxy(ghost1X, ghost1Y);
            cout << "G";
            gotoxy(ghost2X, ghost2Y);
            cout << "G";
            gotoxy(ghost3X, ghost3Y);
            cout << "G";
            x = true;
            horizontal = true;
            vertical = true;
            c = 3;
            life = c;
            winLoose = 0;
            while (x)
            {
                if (powerPills == true)
                {
                    loopCounter++;
                    gotoxy(0, 71);
                    cout << "P";
                    gotoxy(1, 71);
                    cout << "O";
                    gotoxy(2, 71);
                    cout << "W";
                    gotoxy(3, 71);
                    cout << "E";
                    gotoxy(4, 71);
                    cout << "R";
                    gotoxy(5, 71);
                    cout << "P";
                    gotoxy(6, 71);
                    cout << "I";
                    gotoxy(7, 71);
                    cout << "L";
                    gotoxy(8, 71);
                    cout << "L";
                    if (loopCounter == 20)
                    {
                        powerPills = false;
                        loopCounter = 0;
                        gotoxy(25, 3);
                        gotoxy(0, 71);
                        cout << " ";
                        gotoxy(1, 71);
                        cout << " ";
                        gotoxy(2, 71);
                        cout << " ";
                        gotoxy(3, 71);
                        cout << " ";
                        gotoxy(4, 71);
                        cout << " ";
                        gotoxy(5, 71);
                        cout << " ";
                        gotoxy(6, 71);
                        cout << " ";
                        gotoxy(7, 71);
                        cout << " ";
                        gotoxy(8, 71);
                        cout << " ";
                    }
                }
                gameBreak();
                ghostMovement();
                gameBreak();
                ghost1Move();
                gameBreak();
                ghost2Move();
                gameBreak();
                Sleep(50);
                ghost3Move();
                gameBreak();
                Sleep(150);
                if (GetAsyncKeyState(VK_LEFT) && (mazeA[pacmanX][pacmanY - 1] == ' ' || mazeA[pacmanX][pacmanY - 1] == '.' || mazeA[pacmanX][pacmanY - 1] == '*'))
                {
                    if (mazeA[pacmanX][pacmanY - 1] == '.')
                    {
                        count = count + 10;
                    }
                    if (mazeA[pacmanX][pacmanY - 1] == '*')
                    {
                        powerPills = true;
                    }
                    movePacmanLeft();
                }
                gameBreak();
                if (GetAsyncKeyState(VK_RIGHT) && (mazeA[pacmanX][pacmanY + 1] == ' ' || mazeA[pacmanX][pacmanY + 1] == '.' || mazeA[pacmanX][pacmanY + 1] == '*'))
                {
                    if (mazeA[pacmanX][pacmanY + 1] == '.')
                    {
                        count = count + 10;
                    }
                    if (mazeA[pacmanX][pacmanY + 1] == '*')
                    {
                        powerPills = true;
                    }
                    movePacmanRight();
                }
                gameBreak();
                if (GetAsyncKeyState(VK_UP) && (mazeA[pacmanX - 1][pacmanY] == ' ' || mazeA[pacmanX - 1][pacmanY] == '.' || mazeA[pacmanX - 1][pacmanY] == '*'))
                {
                    if (mazeA[pacmanX - 1][pacmanY] == '.')
                    {
                        count = count + 10;
                    }
                    if (mazeA[pacmanX - 1][pacmanY] == '*')
                    {
                        powerPills = true;
                    }
                    movePacmanUP();
                }
                gameBreak();
                if (GetAsyncKeyState(VK_DOWN) && (mazeA[pacmanX + 1][pacmanY] == ' ' || mazeA[pacmanX + 1][pacmanY] == '.' || mazeA[pacmanX + 1][pacmanY] == '*'))
                {
                    if (mazeA[pacmanX + 1][pacmanY] == '.')
                    {
                        count = count + 10;
                    }
                    if (mazeA[pacmanX + 1][pacmanY] == '*')
                    {
                        powerPills = true;
                    }
                    movePacmanDown();
                }
                gameBreak();
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    gotoxy(pacmanX, pacmanY);
                    cout << " ";
                    gotoxy(ghostX, ghostY);
                    cout << " ";
                    gotoxy(ghost1X, ghost1Y);
                    cout << " ";
                    gotoxy(ghost2X, ghost2Y);
                    cout << " ";
                    gotoxy(ghost3X, ghost3Y);
                    cout << " ";
                    ghostX = 19;
                    ghostY = 25;
                    pacmanX = 9;
                    pacmanY = 31;
                    ghost1X = 1;
                    ghost1Y = 2;
                    ghost2X = 22;
                    ghost2Y = 2;
                    ghost3X = 2;
                    ghost3Y = 58;
                    count = 0;
                    c1 = 0;
                    c2 = 0;
                    previousItem = ' ';
                    horizontal = true;
                    vertical = true;
                    x = true;
                    c = 3;
                    life = 0;
                    break; // Stop the game
                }
                gameBreak();
                gotoxy(0, 30);
                cout << "-Score : " << count << "-";
                gotoxy(23, 30);
                cout << "-Life : " << life << "-";
                gameBreak();
            }
            system("cls");
        }
        else if (op == '2')
        {
            system("cls");
            system("color 01");
            head();
            cout << "Rules." << endl;
            cout << "-------------------" << endl;
            cout << "1. Up key to Go up." << endl;
            cout << "2. Down key to Go down. " << endl;
            cout << "3. Left key to go left." << endl;
            cout << "4. Right key to go righy." << endl;
            cout << "5. * are powerpills you can eat ghost." << endl;
            cout << "6. 10 point increase by eating dot(.)." << endl;
            cout << "7. Dodge the ghost(G) and eat dots." << endl;
            cout << "8. If you eat all dots you win." << endl
                 << endl;
            cout << "Press Enter to continue : ";
            getch();
        }
        else if (op == '3')
        {
            system("cls");
            head();
            system("color 09");
            cout << "Thank you for using!" << endl;
            break;
        }
        else
        {
            system("cls");
            head();
            system("color 04");
            cout << "You entered wrong option." << endl;
            cout << "Press Enter to continue : ";
            getch();
        }
        winLooseF();
    }
}
void head()
{
    cout << " ____   __    ___    __  __    __    _  _ " << endl;
    cout << "(  _ \\ /__\\  / __)  (  \\/  )  /__\\  ( \\( )" << endl;
    cout << " )___//(__)\\( (__    )    (  /(__)\\  )  (" << endl;
    cout << "(__) (__)(__)\\___)  (_/\\/\\_)(__)(__)(_)\\_)" << endl;
    cout << endl;
    cout << endl;
}
char mainMenu()
{
    char op;
    head();
    cout << "Menu." << endl;
    cout << "__________________" << endl;
    cout << "1. Start" << endl;
    cout << "2. Option" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter one option : ";
    cin >> op;
    return op;
}
void readFile()
{
    string line;
    int x = 0;
    file.open("maze.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        for (int y = 0; y < 71; y++)
        {
            mazeA[x][y] = line[y];
        }
        x++;
    }
    file.close();
}
void maze()
{
    for (int x = 0; x < 24; x++)
    {
        for (int y = 0; y < 71; y++)
        {
            cout << mazeA[x][y];
        }
        cout << endl;
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = y;
    coordinates.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void movePacmanLeft()
{
    mazeA[pacmanX][pacmanY] = ' ';
    gotoxy(pacmanX, pacmanY);
    cout << " ";
    pacmanY = pacmanY - 1;
    gotoxy(pacmanX, pacmanY);
    cout << 'P';
}
void movePacmanRight()
{
    mazeA[pacmanX][pacmanY] = ' ';
    gotoxy(pacmanX, pacmanY);
    cout << " ";
    pacmanY = pacmanY + 1;
    gotoxy(pacmanX, pacmanY);
    cout << 'P';
}
void movePacmanUP()
{
    mazeA[pacmanX][pacmanY] = ' ';
    gotoxy(pacmanX, pacmanY);
    cout << " ";
    pacmanX = pacmanX - 1;
    gotoxy(pacmanX, pacmanY);
    cout << 'P';
}
void movePacmanDown()
{
    mazeA[pacmanX][pacmanY] = ' ';
    gotoxy(pacmanX, pacmanY);
    cout << " ";
    pacmanX = pacmanX + 1;
    gotoxy(pacmanX, pacmanY);
    cout << 'P';
}
void set_cursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
int ghostDirection()
{
    int result;
    srand(time(0));
    result = 1 + (rand() % 4);
    return result;
}
void ghostMovement()
{
    if (ghostBool)
    {
        int value = ghostDirection();
        if (value == 1)
        {
            if (mazeA[ghostX][ghostY - 1] == ' ' || mazeA[ghostX][ghostY - 1] == '.' || mazeA[ghostX][ghostY - 1] == 'P' || mazeA[ghostX][ghostY - 1] == '*')
            {

                if (mazeA[ghostX][ghostY] == '.')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '.';
                }
                else if (mazeA[ghostX][ghostY] == ' ')
                {
                    gotoxy(ghostX, ghostY);
                    cout << ' ';
                }
                else if (mazeA[ghostX][ghostY] == '*')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '*';
                }
                ghostY = ghostY - 1;
                gotoxy(ghostX, ghostY);
                cout << 'G';
            }
        }
        if (value == 2)
        {
            if (mazeA[ghostX][ghostY + 1] == ' ' || mazeA[ghostX][ghostY + 1] == '.' || mazeA[ghostX][ghostY + 1] == 'P' || mazeA[ghostX][ghostY + 1] == '*')
            {

                if (mazeA[ghostX][ghostY] == '.')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '.';
                }
                else if (mazeA[ghostX][ghostY] == ' ')
                {
                    gotoxy(ghostX, ghostY);
                    cout << ' ';
                }
                else if (mazeA[ghostX][ghostY] == '*')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '*';
                }
                ghostY = ghostY + 1;
                gotoxy(ghostX, ghostY);
                cout << 'G';
            }
        }
        if (value == 3)
        {
            if (mazeA[ghostX - 1][ghostY] == ' ' || mazeA[ghostX - 1][ghostY] == '.' || mazeA[ghostX - 1][ghostY] == 'P' || mazeA[ghostX - 1][ghostY] == '*')
            {
                if (mazeA[ghostX][ghostY] == '.')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '.';
                }
                else if (mazeA[ghostX][ghostY] == ' ')
                {
                    gotoxy(ghostX, ghostY);
                    cout << ' ';
                }
                else if (mazeA[ghostX][ghostY] == '*')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '*';
                }
                ghostX = ghostX - 1;
                gotoxy(ghostX, ghostY);
                cout << 'G';
            }
        }
        if (value == 4)
        {
            if (mazeA[ghostX + 1][ghostY] == ' ' || mazeA[ghostX + 1][ghostY] == '.' || mazeA[ghostX + 1][ghostY] == 'P' || mazeA[ghostX + 1][ghostY] == '*')
            {
                if (mazeA[ghostX][ghostY] == '.')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '.';
                }
                else if (mazeA[ghostX][ghostY] == ' ')
                {
                    gotoxy(ghostX, ghostY);
                    cout << ' ';
                }
                else if (mazeA[ghostX][ghostY] == '*')
                {
                    gotoxy(ghostX, ghostY);
                    cout << '*';
                }
                ghostX = ghostX + 1;
                gotoxy(ghostX, ghostY);
                cout << 'G';
            }
        }
    }
}
void gameBreak()
{
    if (powerPills == false)
    {
        if ((ghostX == pacmanX && ghostY == pacmanY) || (ghost1X == pacmanX && ghost1Y == pacmanY) || (ghost2X == pacmanX && ghost2Y == pacmanY) || (ghost3X == pacmanX && ghost3Y == pacmanY))
        {
            gotoxy(pacmanX, pacmanY);
            cout << " ";
            gotoxy(ghostX, ghostY);
            cout << " ";
            gotoxy(ghost1X, ghost1Y);
            cout << " ";
            gotoxy(ghost2X, ghost2Y);
            cout << " ";
            gotoxy(ghost3X, ghost3Y);
            cout << " ";
            ghostX = 19;
            ghostY = 25;
            pacmanX = 9;
            pacmanY = 31;
            ghost1X = 1;
            ghost1Y = 2;
            ghost2X = 22;
            ghost2Y = 2;
            ghost3X = 2;
            ghost3Y = 58;
            c--;
        }
        if (c == 0)
        {
            count = 0;
            x = false;
            winLoose = 1;
        }
        if (count >= 4630)
        {
            gotoxy(pacmanX, pacmanY);
            cout << " ";
            gotoxy(ghostX, ghostY);
            cout << " ";
            gotoxy(ghost1X, ghost1Y);
            cout << " ";
            gotoxy(ghost2X, ghost2Y);
            cout << " ";
            gotoxy(ghost3X, ghost3Y);
            cout << " ";
            ghostX = 19;
            ghostY = 25;
            pacmanX = 9;
            pacmanY = 31;
            ghost1X = 1;
            ghost1Y = 2;
            ghost2X = 22;
            ghost2Y = 2;
            ghost3X = 2;
            ghost3Y = 58;
            count = 0;
            c1 = 0;
            c2 = 0;
            previousItem = ' ';
            horizontal = true;
            vertical = true;
            c = 3;
            life = 0;
            x = false;
            winLoose = 2;
        }
        if (life == c + 1)
        {
            Sleep(300);
            gotoxy(pacmanX, pacmanY);
            cout << "P";
            life--;
        }
    }
    else if (powerPills == true)
    {
        if (pacmanX == ghostX && pacmanY == ghostY)
        {
            ghostBool = false;
            ghostX = 0;
            ghostY = 0;
        }
        if (pacmanX == ghost1X && pacmanY == ghost1Y)
        {
            ghost1Bool = false;
            ghost1X = 0;
            ghost1Y = 0;
        }
        if (pacmanX == ghost2X && pacmanY == ghost2Y)
        {
            ghost2Bool = false;
            ghost2X = 0;
            ghost2Y = 0;
        }
        if (pacmanX == ghost3X && pacmanY == ghost3Y)
        {
            ghost3Bool = false;
            ghost3X = 0;
            ghost3Y = 0;
        }
    }
}
void ghost1Move()
{
    if (ghost1Bool)
    {
        if (vertical)
        {

            if (mazeA[ghost1X + 1][ghost1Y] == '#')
            {
                vertical = false;
            }
            if (mazeA[ghost1X + 1][ghost1Y] == ' ' || mazeA[ghost1X + 1][ghost1Y] == '.' || mazeA[ghost1X + 1][ghost1Y] == 'P' || mazeA[ghost1X + 1][ghost1Y] == '*')
            {
                if (mazeA[ghost1X][ghost1Y] == '.')
                {
                    gotoxy(ghost1X, ghost1Y);
                    cout << '.';
                }
                else if (mazeA[ghost1X][ghost1Y] == ' ')
                {
                    gotoxy(ghost1X, ghost1Y);
                    cout << ' ';
                }
                else if (mazeA[ghost1X][ghost1Y] == '*')
                {
                    gotoxy(ghost1X, ghost1Y);
                    cout << '*';
                }
                ghost1X = ghost1X + 1;
                gotoxy(ghost1X, ghost1Y);
                cout << 'G';
            }
        }
        else
        {
            if (mazeA[ghost1X - 1][ghost1Y] == '#')
            {
                vertical = true;
            }
            if (mazeA[ghost1X - 1][ghost1Y] == ' ' || mazeA[ghost1X - 1][ghost1Y] == '.' || mazeA[ghost1X - 1][ghost1Y] == 'P' || mazeA[ghost1X - 1][ghost1Y] == '*')
            {

                if (mazeA[ghost1X][ghost1Y] == '.')
                {
                    gotoxy(ghost1X, ghost1Y);
                    cout << '.';
                }
                else if (mazeA[ghost1X][ghost1Y] == ' ')
                {
                    gotoxy(ghost1X, ghost1Y);
                    cout << ' ';
                }
                else if (mazeA[ghost1X][ghost1Y] == '*')
                {
                    gotoxy(ghost1X, ghost1Y);
                    cout << '*';
                }
                ghost1X = ghost1X - 1;
                gotoxy(ghost1X, ghost1Y);
                cout << 'G';
            }
        }
    }
}
void ghost2Move()
{
    if (ghost2Bool)
    {
        if (horizontal)
        {

            if (mazeA[ghost2X][ghost2Y + 1] == '|')
            {
                horizontal = false;
            }
            if ((mazeA[ghost2X][ghost1Y + 1] == ' ' || mazeA[ghost2X][ghost2Y + 1] == '.' || mazeA[ghost2X][ghost2Y + 1] == 'P' || mazeA[ghost2X][ghost2Y + 1] == '*') && mazeA[ghost2X][ghost2Y + 1] != '|')
            {
                if (mazeA[ghost2X][ghost2Y] == '.')
                {
                    gotoxy(ghost2X, ghost2Y);
                    cout << '.';
                }
                else if (mazeA[ghost2X][ghost2Y] == ' ')
                {
                    gotoxy(ghost2X, ghost2Y);
                    cout << ' ';
                }
                else if (mazeA[ghost2X][ghost2Y] == '*')
                {
                    gotoxy(ghost2X, ghost2Y);
                    cout << '*';
                }
                ghost2Y = ghost2Y + 1;
                gotoxy(ghost2X, ghost2Y);
                cout << 'G';
            }
        }
        else
        {
            if (mazeA[ghost2X][ghost2Y - 1] == '|')
            {
                horizontal = true;
            }
            if (mazeA[ghost2X][ghost2Y - 1] == ' ' || mazeA[ghost2X][ghost2Y - 1] == '.' || mazeA[ghost2X][ghost2Y - 1] == 'P' || mazeA[ghost2X][ghost2Y - 1] == '*')
            {

                if (mazeA[ghost2X][ghost2Y] == '.')
                {
                    gotoxy(ghost2X, ghost2Y);
                    cout << '.';
                }
                else if (mazeA[ghost2X][ghost2Y] == ' ')
                {
                    gotoxy(ghost2X, ghost2Y);
                    cout << ' ';
                }
                else if (mazeA[ghost2X][ghost2Y] == '*')
                {
                    gotoxy(ghost2X, ghost2Y);
                    cout << '*';
                }
                ghost2Y = ghost2Y - 1;
                gotoxy(ghost2X, ghost2Y);
                cout << 'G';
            }
        }
    }
}
void moveGhostDown()
{
    if (mazeA[ghost3X][ghost3Y] == '.')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '.';
    }
    else if (mazeA[ghost3X][ghost3Y] == ' ')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << ' ';
    }
    else if (mazeA[ghost3X][ghost3Y] == '*')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '*';
    }
    ghost3X++;
    gotoxy(ghost3X, ghost3Y);
    cout << 'G';
}
void moveGhostUP()
{
    if (mazeA[ghost3X][ghost3Y] == '.')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '.';
    }
    else if (mazeA[ghost3X][ghost3Y] == ' ')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << ' ';
    }
    else if (mazeA[ghost3X][ghost3Y] == '*')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '*';
    }
    ghost3X--;
    gotoxy(ghost3X, ghost3Y);
    cout << 'G';
}
void moveGhostRight()
{
    if (mazeA[ghost3X][ghost3Y] == '.')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '.';
    }
    else if (mazeA[ghost3X][ghost3Y] == ' ')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << ' ';
    }
    else if (mazeA[ghost3X][ghost3Y] == '*')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '*';
    }
    ghost3Y++;
    gotoxy(ghost3X, ghost3Y);
    cout << 'G';
}
void moveGhostLeft()
{
    if (mazeA[ghost3X][ghost3Y] == '.')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '.';
    }
    else if (mazeA[ghost3X][ghost3Y] == ' ')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << ' ';
    }
    else if (mazeA[ghost3X][ghost3Y] == '*')
    {
        gotoxy(ghost3X, ghost3Y);
        cout << '*';
    }
    ghost3Y--;
    gotoxy(ghost3X, ghost3Y);
    cout << 'G';
}
void ghost3Movement()
{
    if (ghost3Bool)
    {
        int value = ghostDirection();
        if (value == 1)
        {
            if (mazeA[ghost3X][ghost3Y - 1] == ' ' || mazeA[ghost3X][ghost3Y - 1] == '.' || mazeA[ghost3X][ghost3Y - 1] == 'P' || mazeA[ghost3X][ghost3Y - 1] == '*')
            {

                if (mazeA[ghost3X][ghost3Y] == '.')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '.';
                }
                else if (mazeA[ghost3X][ghost3Y] == ' ')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << ' ';
                }
                else if (mazeA[ghost3X][ghost3Y] == '*')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '*';
                }
                ghost3Y = ghost3Y - 1;
                gotoxy(ghost3X, ghost3Y);
                cout << 'G';
            }
        }
        if (value == 2)
        {
            if (mazeA[ghost3X][ghost3Y + 1] == ' ' || mazeA[ghost3X][ghost3Y + 1] == '.' || mazeA[ghost3X][ghost3Y + 1] == 'P' || mazeA[ghost3X][ghost3Y + 1] == '*')
            {

                if (mazeA[ghost3X][ghost3Y] == '.')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '.';
                }
                else if (mazeA[ghost3X][ghost3Y] == ' ')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << ' ';
                }
                else if (mazeA[ghost3X][ghost3Y] == '*')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '*';
                }
                ghost3Y = ghost3Y + 1;
                gotoxy(ghost3X, ghost3Y);
                cout << 'G';
            }
        }
        if (value == 3)
        {
            if (mazeA[ghost3X - 1][ghost3Y] == ' ' || mazeA[ghost3X - 1][ghost3Y] == '.' || mazeA[ghost3X - 1][ghost3Y] == 'P' || mazeA[ghost3X - 1][ghost3Y] == '*')
            {
                if (mazeA[ghost3X][ghost3Y] == '.')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '.';
                }
                else if (mazeA[ghost3X][ghost3Y] == ' ')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << ' ';
                }
                else if (mazeA[ghost3X][ghost3Y] == '*')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '*';
                }
                ghost3X = ghost3X - 1;
                gotoxy(ghost3X, ghost3Y);
                cout << 'G';
            }
        }
        if (value == 4)
        {
            if (mazeA[ghost3X + 1][ghost3Y] == ' ' || mazeA[ghost3X + 1][ghost3Y] == '.' || mazeA[ghost3X + 1][ghost3Y] == 'P' || mazeA[ghost3X + 1][ghost3Y] == '*')
            {
                if (mazeA[ghost3X][ghost3Y] == '.')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '.';
                }
                else if (mazeA[ghost3X][ghost3Y] == ' ')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << ' ';
                }
                else if (mazeA[ghost3X][ghost3Y] == '*')
                {
                    gotoxy(ghost3X, ghost3Y);
                    cout << '*';
                }
                ghost3X = ghost3X + 1;
                gotoxy(ghost3X, ghost3Y);
                cout << 'G';
            }
        }
    }
}
void ghost3Move()
{
    if (ghost3Bool)
    {
        if (c1 > 5)
        {
            for (int x = 0; x < 6; x++)
            {
                ghost3Movement();
            }
        }
        c2 = 1;
        if (ghost3X > pacmanX && (mazeA[ghost3X - 1][ghost3Y] == ' ' || mazeA[ghost3X - 1][ghost3Y] == '.' || mazeA[ghost3X - 1][ghost3Y] == '*'))
        {
            moveGhostUP();
            c2 = 0;
        }
        if (ghost3Y > pacmanY && (mazeA[ghost3X][ghost3Y - 1] == ' ' || mazeA[ghost3X][ghost3Y - 1] == '.' || mazeA[ghost3X][ghost3Y - 1] == '*'))
        {
            moveGhostLeft();
            c2 = 0;
        }
        if (ghost3X < pacmanX && (mazeA[ghost3X + 1][ghost3Y] == ' ' || mazeA[ghost3X + 1][ghost3Y] == '.' || mazeA[ghost3X + 1][ghost3Y] == '*'))
        {
            moveGhostDown();
            c2 = 0;
        }
        if (ghost3Y < pacmanY && (mazeA[ghost3X][ghost3Y + 1] == ' ' || mazeA[ghost3X][ghost3Y + 1] == '.' || mazeA[ghost3X][ghost3Y + 1] == '*'))
        {
            moveGhostRight();
            c2 = 0;
        }
        if (c2 == 1)
        {
            c1++;
        }
        else if (c2 == 0)
        {
            c1 = 0;
        }
    }
}
void winLooseF()
{
    system("cls");
    if (winLoose == 1)
    {
        system("color 04");
        cout << "You Lose!" << endl;
        cout << "Press Enter to continue : ";
        cin >> temp;
    }
    if (winLoose == 2)
    {
        system("color 02");
        cout << "You win!" << endl;
        cout << "Press Enter to continue : ";
        cin >> temp;
    }
    winLoose = 0;
}
