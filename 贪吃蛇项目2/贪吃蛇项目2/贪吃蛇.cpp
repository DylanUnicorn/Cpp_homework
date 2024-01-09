#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int mapWidth = 20; // 地图宽度
const int mapHeight = 20; // 地图高度

bool gameOver; // 游戏结束标志

int x, y; // 蛇头的坐标
int fruitX, fruitY; // 食物的坐标
int score; // 得分

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN }; // 方向枚举类型
Direction dir;

int tailX[100], tailY[100];
int tailLength;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = mapWidth / 2;
    y = mapHeight / 2;
    fruitX = rand() % mapWidth;
    fruitY = rand() % mapHeight;
    score = 0;
}

void Draw()
{
    //system("cls"); // 清空控制台屏幕

    //for (int i = 0; i < mapWidth + 2; i++)
    //    cout << "#";

    //cout << endl;
    COORD pos;
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    for (int row = 0; row < mapHeight; row++)
    {
        for (int col = 0; col < mapWidth; col++)
        {
            if (col == 0)
                cout << "#";
            if (row == y && col == x)
                cout << "O";
            else if (row == fruitY && col == fruitX)
                cout << "F";
            else
            {
                bool printTail = false;
                for (int k = 0; k < tailLength; k++)
                {
                    if (tailX[k] == col && tailY[k] == row)
                    {
                        cout << "o";
                        printTail = true;
                        break;
                    }
                }

                if (!printTail)
                    cout << " ";
            }

            if (col == mapWidth - 1)
                cout << "#";
        }

        cout << endl;
    }

    for (int i = 0; i < mapWidth + 2; i++)
        cout << "#";

    cout << endl;

    cout << "Score:" << score << endl;
}

void Input()
{
    if (_kbhit()) // 检测键盘按键
    {
        switch (_getch()) // 获取按下的键值
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;

        case 'x':
            gameOver = true;
            break;

        }
    }
}

void Logic()
{
    int prevX, prevY, prev2X, prev2Y;

    // 记录蛇尾的前一个位置
    prevX = tailX[0];
    prevY = tailY[0];

    // 将蛇尾的前一个位置设置为蛇头的位置
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLength; i++) {
        // 记录蛇尾之前的位置
        prev2X = tailX[i];
        prev2Y = tailY[i];

        // 将蛇尾之前的位置设置为蛇尾之前的前一个位置
        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    }

    if (x >= mapWidth || x < 0 || y >= mapHeight || y < 0)
        gameOver = true; // 撞墙

    for (int i = 0; i < tailLength; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true; // 撞到自己
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % mapWidth;
        fruitY = rand() % mapHeight;
        tailLength++;
    }
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();

        Sleep(100); // 在每次循环后延迟100毫秒
    }

    system("cls"); // 清空控制台屏幕

    cout << "Game Over! Your Score: " << score << endl;

    return 0;
}