# include<stdio.h>
#include<windows.h>
void Menu()
{
	printf("*****************\n");
	printf("**1 add   2 sub**\n");
	printf("**3 mul   4 div**\n");
	printf("****  0 exit ****\n");
	printf("*****************\n");
	printf("plesae select:");
}
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a *b;
}
int Div(int a, int b)
{
	return a /b;
}
void Count1()//����switch���ѡ����㷽��
{
	int quit = 0;
	while (!quit)
	{
		int a, b;
		Menu();
		int select;
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("please input tow number:");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", Add(a, b));
			break;
		case 2:
			printf("please input tow number:");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", Sub(a, b));
			break;
		case 3:
			printf("please input tow number:");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", Mul(a, b));
			break;
		case 4:
			printf("please input tow number:");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", Div(a, b));
			break;
		case 0:
			quit = 1;
			break;
		default:
			printf("input error!please input again!\n");
			break;
		}
	}
}
void Count2()//����ת�Ʊ��±���ѡ����õĺ���
{
	int a,b;
	int(*p[5])(int x, int y) = { 0, Add, Sub, Mul, Div }; //ת�Ʊ�
	while (1)
	{
		Menu();
		int select;
		scanf_s("%d", &select);
		if (select == 0)
		{
			break;
		}
		if (select <= 4 && select > 0)
		{
			printf("please input tow number:");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", p[select](a, b));
		}
		else
		{
			printf("input error!please input again!\n");
			continue;
		}

	}
}
int main()
{
	printf("1 ����1  2 ����2\n");
	int s=0;
	scanf_s("%d", &s);
	switch (s)
	{
	case 1:
		Count1();//��ͨ����
		break;
	case 2:
		Count2();//ת�Ʊ����
		break;
	}
	system("pause");
	return 0;
}
