#include <stdio.h>
#include <math.h>

void iszhishu(int n) {
	int i,flag=0;
	for ( i = 2; i < sqrt(n); i++) {
		if (n % i == 0) { printf("%d��������", n); break; }
		else flag = 1;
	}

	if(flag==1)printf("%d������", n);

}

int main() 
{
	//int a = 3,b=4;
	printf("a=%d, c=%d\n����ʲô����\t��һ�ν���C����", 12.0, 24);
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
	//	printf("%d������\n", year);
	//else
	//	printf("%d��������\n", year);

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
	//printf("%d����%d��%d", a, t, b);
	iszhishu(i);

	//1.����žų˷��ھ���
	//2.feibonaqi����  �ĸ����ݻ�һ��
	//3.�жϿ�100-200֮���ж��ٸ��������������������
	//4.���n����������ȫ��
	//s5.��������
	//6.��ɴ�ӡֱ�����������
	//7.ʵ��������ַ����������  ������ָ�뷨
	//8.ɾ��һ���Է�����ָ����Ԫ�ػ����Ӵ���Ѱ���Ӵ�
	//9.�������齫���������ļ�P91.out��
	//10.��һ�����ֲ��뵽һ��һ������������У�ʹ�ò�����������Ȼ����
	//11.ʵ���ַ������滻
	//12.����һ���м򵥽ڵ����������
	//13.�ж��Ƿ�Ϊ�����ַ���
	//14.����PI�Ľ���ֵ



	return 0;

}
