#include<iostream>
#include<cstring>
#include<Windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

void Wind();

class Book
{
	char sumary[1000];
	char name[20];
	int price;
	char number[20];
	int state;
public:
	Book(char n[], int p, char num1[], char sum[]) {

		strcpy_s(name, n);
		price = p;
		strcpy_s(number, num1); strcpy_s(sumary, sum);
		state = 1;
	}
	Book() {
		strcpy_s(name, "  ");
		price = 0;
		strcpy_s(number, "  ");	strcpy_s(sumary, "  ");
		state = 1;
	}

	void set(char n[], int p, char num1[], char sum[]) {
		strcpy_s(name, n);
		price = p;
		strcpy_s(number, num1); strcpy_s(sumary, sum);
	}
	void show() {
		cout << "书名：" << name << endl;
		cout << "价格：" << price << endl;
		cout << "编号：" << number << endl;
		cout << "内容简介：" << sumary << endl;
	}
	char* getname() {
		return name;
	}
	int getprice() {
		return price;
	}
	char* getnumber() {
		return number;
	}
	char* getsumary() {
		return sumary;
	}
};
int main() {
	cout << "******************************" << endl;
	cout << "**********欢迎使用************" << endl;
	cout << "**********图书管理系统********" << endl;
	cout << "**********3.按名查找图书******" << endl;
	cout << "**********6.显示图书架********" << endl;
	cout << "**********7.退出系统**********" << endl;
	cout << "**********8.借书**********" << endl;
	cout << "**********10.管理员模式********" << endl;
	cout << "******************************" << endl;


	Book book[100] = {};
	int argc = 0;
	int i = 0;
	while (true) {
		cout << "请输入您的选择：";
		int n;
		cin >> n;
		switch (n) {

		case 3: {
			int t = 1;
			cout << "请输入要查找的书名：";
			char name[20]; cin >> name;
			for (int k = 0; k < 100; k++) {
				if (strcmp(book[k].getname(), name) == 0 && book[k].getname()[0] == name[0]) {
					t = 1;
					book[k].show(); break;
					
				}
				else { t = 0;  }
			}
			if (t == 0) {
				cout << "查无此书！" << endl;
			}
		}break;


		case 6: {
			for (int k = 0; k < i; k++) {
				if (book[k].getname()[0] != ' ' && book[k].getname()[1] != ' ') {
					book[k].show();
					cout << endl;
				}
			}
		}break;

		case 10:
		{

			int code;
			cout << "请输入密码" << endl;
			cin >> code;
			if (code == 123456)
			{
				cout << "亲爱的管理员，欢迎进入系统" << endl;
				cout << "**********1.加入书名**********" << endl;
				cout << "**********2.按名删除图书******" << endl; cout << "**********4.清空图书架********" << endl; cout << "**********5.修改图书名********" << endl;
				cout << "**********0.退管理员**********" << endl;



				int k;
				int temp = 0;

				while (true) {
					cout << "请输入您的选择：";
					cin >> k;



					switch (k) {

					case 1: {
						cout << "请输入书名：";
						char name[20]; cin >> name;
						cout << "请输入价格：";
						int price; cin >> price;
						cout << "请输入编号：";
						char number[20]; cin >> number;
						cout << "请输入内容简介：";
						char sumary[10000]; cin >> sumary;

						book[i].set(name, price, number, sumary);
						cout << "加入成功！" << endl;
						i++;//也许后面要改一下
					}break;

					case 2: {
						cout << "请输入要删除的书名：";
						int t = 1;
						char name[20]; cin >> name;
						for (int k = 0; k < 100; k++) {
							char a1[] = " "; char c1[] = " ";
							char b1[] = " ";
							if (strcmp(book[k].getname(), name) == 0 && book[k].getname()[0] == name[0]) {
								book[k].set(a1, 0, b1, c1);
								cout << "删除成功！" << endl;
								t = 1;
							}
							else { t = 0; break; }
						}
						if (t == 0) {
							cout << "查无此书！" << endl;
						}
					}break;

					case 4: {
						for (int k = 0; k < 100; k++) {
							char a1[] = " "; char c1[] = " ";
							char b1[] = " ";
							book[k].set(a1, 0, b1, c1);
						}
						cout << "清空成功！" << endl;
					}break;

					case 5: {
						cout << "请输入要修改的书名：";
						char name[20]; cin >> name;
						cout << "请输入新的书名：";
						char name1[20]; cin >> name1;
						cout << "请输入新的价格：";
						int price; cin >> price;
						cout << "请输入新的编号：";
						char number[20]; cin >> number;
						cout << "请输入新的内容简介：";
						char sumary[10000]; cin >> sumary;
						int t = 1;
						for (int k = 0; k < 100; k++) {
							if (strcmp(book[k].getname(), name) == 0 && book[k].getname()[0] == name[0]) {
								book[k].set(name1, price, number, sumary);
								cout << "修改成功！" << endl; t = 1;
							}
							else { t = 0; break; }
						}
						if (t == 0) {
							cout << "查无此书！" << endl;
						}
					}break;

					case 0:
					{cout << "退出管理员系统成功" << endl; temp = 1;
					cout << "**********回到了用户系统******" << endl;
					cout << "**********3.按名查找图书******" << endl;
					cout << "**********6.显示图书架********" << endl;
					cout << "**********7.退出系统**********" << endl;
					cout << "**********8.借书**********" << endl;
					cout << "**********10.管理员模式********" << endl;
					cout << "******************************" << endl;
					}//退出系统



					}
					if (temp == 1)break;

				}




			}
			else { cout << "密码错误" << endl;     break; }

		}break;





		case 7: {
			cout << "谢谢使用！" << endl; argc = 1;

			break;
		}

		case 8: {
			cout << "该功能尚未开发，尽情期待" << endl;
		}break;

			//default: {break;}
		}

		if (argc == 1)break;

	}
	Wind();

	return 0;
}


enum Scale
{
	Rest = 0, C8 = 108, B7 = 107, A7s = 106, A7 = 105, G7s = 104, G7 = 103, F7s = 102, F7 = 101, E7 = 100,
	D7s = 99, D7 = 98, C7s = 97, C7 = 96, B6 = 95, A6s = 94, A6 = 93, G6s = 92, G6 = 91, F6s = 90, F6 = 89,
	E6 = 88, D6s = 87, D6 = 86, C6s = 85, C6 = 84, B5 = 83, A5s = 82, A5 = 81, G5s = 80, G5 = 79, F5s = 78,
	F5 = 77, E5 = 76, D5s = 75, D5 = 74, C5s = 73, C5 = 72, B4 = 71, A4s = 70, A4 = 69, G4s = 68, G4 = 67,
	F4s = 66, F4 = 65, E4 = 64, D4s = 63, D4 = 62, C4s = 61, C4 = 60, B3 = 59, A3s = 58, A3 = 57, G3s = 56,
	G3 = 55, F3s = 54, F3 = 53, E3 = 52, D3s = 51, D3 = 50, C3s = 49, C3 = 48, B2 = 47, A2s = 46, A2 = 45,
	G2s = 44, G2 = 43, F2s = 42, F2 = 41, E2 = 40, D2s = 39, D2 = 38, C2s = 37, C2 = 36, B1 = 35, A1s = 34,
	A1 = 33, G1s = 32, G1 = 31, F1s = 30, F1 = 29, E1 = 28, D1s = 27, D1 = 26, C1s = 25, C1 = 24, B0 = 23,
	A0s = 22, A0 = 21
};
enum Voice
{
	X1 = C2, X2 = D2, X3 = E2, X4 = F2, X5 = G2, X6 = A2, X7 = B2,
	L1 = C3, L2 = D3, L3 = E3, L4 = F3, L5 = G3, L6 = A3, L7 = B3,
	M1 = C4, M2 = D4, M3 = E4, M4 = F4, M5 = G4, M6 = A4, M7 = B4,
	H1 = C5, H2 = D5, H3 = E5, H4 = F5, H5 = G5, H6 = A5, H7 = B5,
	LOW_SPEED = 500, MIDDLE_SPEED = 400, HIGH_SPEED = 300,
	_ = 0XFF
};
void Wind()
{
	HMIDIOUT handle;
	midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
	// midiOutShortMsg(handle, 2 << 8 | 0xC0);
	int volume = 0x7f;
	int voice = 0x0;
	int sleep = 350;
	int wind[] =
	{
	 400,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,
	 0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,
	 0,M6,M3,M2,L6,M3,L6,M2,M3,L6,_,_,_,
	 M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M1,300,M2,700,0,M1,M2,M3,M2,M1,300,L5,_,
	 M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,M2,_,_,_,
	 M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,L6,_,
	 0,M3,M2,M1,M2,300,M1,_,0,M3,M2,M1,M2,300,M1,700,0,L5,M3,M2,M1,M2,300,M1,_,_,_,
	 M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,M5,M6,_,M5,M6,M5,300,M6,0,M5,M2,300,_,0,M5,700,300,M3,_,_,_,
	 M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,H3,H3,300,_,M5,M6,0,H3,H3,300,_,0,M5,700,300,M6,_,_,_,_,_,
	 H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
	 H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
	 H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
	 0,M6,300,H3,700,H2,0,H1,M6,700,300,H3,H2,700,300,0,H1,M6,300,700,H1,H1,_,_,
	 0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,
	 0,M6,M3,M2,L6,M3,L6,M2,M3,L6,_,_,_,
	 M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M1,300,M2,700,0,M1,M2,M3,M2,M1,300,L5,_,
	 M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,M2,_,_,_,
	 M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,L6,_,
	 0,M3,M2,M1,M2,300,M1,_,0,M3,M2,M1,M2,300,M1,700,0,L5,M3,M2,M1,M2,300,M1,_,_,_,
	 M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,M5,M6,_,M5,M6,M5,300,M6,0,M5,M2,300,_,0,M5,700,300,M3,_,_,_,
	 M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,H3,H3,300,_,M5,M6,0,H3,H3,300,_,0,M5,700,300,M6,_,_,_,_,_,
	 H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
	 H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
	 H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
	 H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
	 H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
	 H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
	 H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
	 H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
	 H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
	 0,M6,300,H3,700,H2,0,H1,M6,700,300,H3,H2,700,300,0,H1,M6,300,700,H1,H1,_,_,_,_,_,_,_,
	};

	for (auto i : wind) {
		if (i == 0) { sleep = 175; continue; }
		if (i == 700) { Sleep(175); continue; }
		if (i == 300) { sleep = 350; continue; }
		if (i == _) {
			Sleep(350);
			continue;
		}
		// if (i == 900) volume += 100;
		voice = (volume << 16) + ((i) << 8) + 0x90;
		midiOutShortMsg(handle, voice);
		//cout << voice << endl;
		//fflush(stdin);
		//system("cls");
		Sleep(sleep);// midiOutShortMsg(handle, 0x7BB0);
	}
	midiOutClose(handle);
}
