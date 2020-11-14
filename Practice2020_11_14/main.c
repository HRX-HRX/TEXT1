#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
void Minechange(char *p, char*q)
{

	while (p < q)
	{
		char temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}
void Minereverse(char*t,int s)
{
	Minechange(t, t + s);
	char *begin = t;
	while (*t)
	{
		while (*t&&(*t!= ' '))
		{
			t++;
		}
		Minechange(begin,t- 1);
		t++;
		begin = t;
	}
}
int main()
{
	char arr[100];
	fgets(arr, 100, stdin);
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == '\n')
		{
			arr[i] = '\0';
			break;
		}
	}
	int s= strlen(arr);
	Minereverse(arr,s-1);
	printf("%s\n", arr);
	system("pause");
	return 0;

}





