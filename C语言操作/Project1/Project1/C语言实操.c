#include <stdio.h>
#include <math.h>

void iszhishu(int n) {
	int i,flag=0;
	for ( i = 2; i < sqrt(n); i++) {
		if (n % i == 0) { printf("%d不是质数", n); break; }
		else flag = 1;
	}

	if(flag==1)printf("%d是质数", n);

}

int main() 
{
	//int a = 3,b=4;
	printf("a=%d, c=%d\n这是什么东西\t第一次进入C语言", 12.0, 24);
	//printf(a, b);
	//printf(14, 20);
	int x = 0117;
	printf("%d\n", x);
	printf("%o\n", x);
	printf("%#o\n", x);
	printf("%x\n", x);
	printf("%#x\n", x);
	printf("%f\n", x);

	//int year;
	//scanf_s("%d", &year);
	//if(year%4==0&&year%100!=0||year%400==0)
	//	printf("%d是闰年\n", year);
	//else
	//	printf("%d不是闰年\n", year);

	int i = 123;
	while (i != 0) {
		printf("%d", i % 10);
		i /= 10;
	}
	printf("\n");
	//long int a=2, b, t=0;
	//int temp;
	//scanf_s("%ld", &a);
	//scanf_s("%d", &b);
	//temp = a;
	//while (a != 0) {
	//	if (b == a % 10)t++;
	//	a = a / 10;
	//}
	//a = temp;
	//printf("%d中有%d个%d", a, t, b);
	iszhishu(i);

	//1.输出九九乘法口诀表
	//2.feibonaqi数列  四个数据换一行
	//3.判断看100-200之间有多少个素数，并输出所有素数
	//4.求出n以内所有完全数
	//s5.倒置数组
	//6.变成打印直角杨辉三角形
	//7.实现输入的字符串反序输出  可以用指针法
	//8.删除一段自发串中指定的元素或者子串，寻找子串
	//9.排序数组将结果输出到文件P91.out中
	//10.将一个数字插入到一个一个有序的数组中，使得插入后的数组仍然有序
	//11.实现字符串的替换
	//12.建立一个有简单节点的有序链表
	//13.判断是否为回文字符串
	//14.计算PI的近似值



	return 0;

}
