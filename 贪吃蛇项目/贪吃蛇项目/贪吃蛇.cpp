#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include <iostream>

using namespace std;

#define SNAKESIZE 100
#define MAPWIDTH 78
#define MAPHEIGHT 24

#ifndef __cplusplus

typedef char bool;
#define false 0
#define true 1

#endif

class Food {
public:
	int x;
	int y;


};
Food foodl;
class Snake {
public:
	int speed;
	int len;
	int x[SNAKESIZE];
	int y[SNAKESIZE];
};
Snake snake;//可能有待斟酌

void gotoxy(int x, int y) {

	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawMap();
void createfood();
void keyDown();
bool status();

int key = 115;

int changeflag = 0;

int score = 0;

int i;

void drawMap() {

	gotoxy(0, 0);
	for (int i = 0; i < MAPWIDTH; i++) {
		printf("#");
	}
	gotoxy(0, MAPHEIGHT);
	for (int i = 0; i < MAPWIDTH; i++) {
		printf("#");
	}
	
	for (int i = 0; i < MAPHEIGHT; i++) {
		gotoxy(0, i);
		printf("#");
	}
	for (int i = 0; i < MAPHEIGHT; i++) {
		gotoxy(MAPWIDTH, i);
		printf("#");
	}
	//生成初试食物
	while (1) {
		srand((unsigned long)time(NULL));


		foodl.x = rand() % (MAPWIDTH - 4) + 2;//是不是要改成 MAPWIDTH-4  +1 
		foodl.y = rand() % (MAPHEIGHT - 2) + 1;
		if (foodl.x % 2 == 0) break;  //一定要使横坐标的奇偶和初试时蛇头所在的坐标一致
		//因为一个字符占两个字节宽度
	}
	
	gotoxy(foodl.x, foodl.y);
	printf("■");
	
	//初始化蛇
	snake.len = 3;
	snake.speed = 200;

	//在屏幕中间生成蛇头
	snake.x[0] = MAPWIDTH / 2 + 1;//x坐标是偶数
	snake.y[0] = MAPHEIGHT / 2;
	//打印蛇头
	gotoxy(snake.x[0], snake.y[0]);
	printf("■");
	//打印蛇身
	for (int i = 1; i < snake.len; i++) {
		snake.x[i] = snake.x[i - 1] - 2;
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf("■");
	}
	//初始化光标位置
	gotoxy(MAPWIDTH + 2, 0);
}

void keyDown() {
	int pre_key = key;
	if (_kbhit()) {
		fflush(stdin);//清空缓冲区的字符
		//第一次调用返回的0火星和244，第二次返回实际值
		key = _getch();
		key = _getch();

	}
	if (changeflag == 0) {
		//擦去蛇尾
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf("  ");
	}


	//移动蛇身
	for (int i = snake.len - 1; i > 0; i--) {
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}
	//判断是否按下了反方向键
	if(pre_key==119&&key==115) key=119;
	if (pre_key == 115 && key == 119) key = 115;
	if (pre_key == 97 && key == 100) key = 97;
	if (pre_key == 100 && key == 97) key = 100;

	//移动蛇头
	switch (key) {
		case 119:snake.y[0]-=2; break;
		case 115:snake.y[0]+=2; break;
		case 97:snake.x[0]-=2; break;
		case 100:snake.x[0]+=2; break;
	}
	


	//打印蛇头
	gotoxy(snake.x[0], snake.y[0]);
	printf("■");
	//打印蛇身
	for (int i = 1; i < snake.len; i++) {
		gotoxy(snake.x[i], snake.y[i]);
		printf("■");
	}
	gotoxy(MAPWIDTH + 2, 0);
	changeflag = 0;
}

void createfood() {
	if (snake.x[0] == foodl.x && snake.y[0] == foodl.y) {
		//擦去食物
		gotoxy(foodl.x, foodl.y);
		printf("  ");

		//生成新的食物
		int flag = 1;

		while (1) {
			
			flag = 1;
			//srand((unsigned long)time(NULL));
			foodl.x = rand() % (MAPWIDTH - 2) + 1;//是不是要改成 MAPWIDTH-4  +1
			foodl.y = rand() % (MAPHEIGHT - 2) + 1;
			//if (foodl.x % 2 == 0) break;

			//生成的食物不能在蛇身上
			for (int i = 0; i < snake.len; i++) {
				if (snake.x[i] == foodl.x && snake.y[i] == foodl.y) {
					flag = 0;
					break;
				}
			}

			if (flag && foodl.x % 2 == 0)break;
		}
		//打印新的食物
		gotoxy(foodl.x, foodl.y);
		printf("■");

		//蛇身增加
		snake.len++;
		score += 10;
		snake.speed -= 5;
		changeflag = 1;
	}

}

bool status() {
	//判断是否撞墙
	if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH || snake.y[0] == 0 || snake.y[0] == MAPHEIGHT) {
		return false;
	}
	//if(snake.y[0]==0||snake.y[0]==MAPHEIGHT)
	//判断是否撞到自己
	for (int i = 1; i < snake.len; i++) {
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	drawMap();
	char tt;
	while (1) {
		 tt = _getch();
		 if (tt == 's') break;
	 }

	srand((unsigned long)time(NULL));
	while (1) {
		
		createfood();
		if (!status()) {
			
			break;
		}
		keyDown();
		Sleep(snake.speed);
	}
	gotoxy(MAPWIDTH / 2 - 4, MAPHEIGHT / 2);
	printf("GAME OVER\n");
	gotoxy(MAPWIDTH / 2 - 4, MAPHEIGHT / 2 + 1);
	printf("YOUR SCORE:%d\n", score);
	//gotoxy(MAPWIDTH / 2 - 4, MAPHEIGHT / 2 + 2);
	Sleep(5000);

	return 0;
}	
