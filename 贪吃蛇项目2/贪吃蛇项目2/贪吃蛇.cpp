#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int mapWidth = 20; // ��ͼ���
const int mapHeight = 20; // ��ͼ�߶�

bool gameOver; // ��Ϸ������־

int x, y; // ��ͷ������
int fruitX, fruitY; // ʳ�������
int score; // �÷�

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN }; // ����ö������
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
    //system("cls"); // ��տ���̨��Ļ

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
    if (_kbhit()) // �����̰���
    {
        switch (_getch()) // ��ȡ���µļ�ֵ
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

    // ��¼��β��ǰһ��λ��
    prevX = tailX[0];
    prevY = tailY[0];

    // ����β��ǰһ��λ������Ϊ��ͷ��λ��
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLength; i++) {
        // ��¼��β֮ǰ��λ��
        prev2X = tailX[i];
        prev2Y = tailY[i];

        // ����β֮ǰ��λ������Ϊ��β֮ǰ��ǰһ��λ��
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
        gameOver = true; // ײǽ

    for (int i = 0; i < tailLength; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true; // ײ���Լ�
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

        Sleep(100); // ��ÿ��ѭ�����ӳ�100����
    }

    system("cls"); // ��տ���̨��Ļ

    cout << "Game Over! Your Score: " << score << endl;

    return 0;
}