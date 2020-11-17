#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
int Minecmp(const void *_p1, const void *_p2)//比较函数
{
	int *p1 = (int*)_p1;
	int *p2 = (int*)_p2;

	if (*p1 > *p2)
	{
		return 1;
	}
	else if (*p1 < *p2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void print(int *arr, int n)//打印函数
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void Minechange(char *src, char *dst, int size)//交换函数
{
	while (size){
		char temp = *src;
		*src = *dst;
		*dst = temp;
		size--;
		src++;
		dst++;
	}
}

void Mineqsort(void *arr, int num, int size, int(*comp)(const void*, const void*))//模拟qsort函数
{
	assert(arr != NULL);
	assert(comp != NULL);
	char *e = (char*)arr;
	for (int i = 0; i < num - 1; i++){
		int flag = 0;//判断这次排序是否有交换
		for (int j = 0; j < num - 1 - i; j++){
			if (Minecmp(e + j*size, e + (j + 1)*size) > 0){
				flag = 1;
				Minechange(e + j*size, e + (j + 1)*size, size);
			}
		}
		if (flag == 0){
			break;
		}
	}
}
int main()
{

	int arr[] = { 1, 5, 7, 4, 89, 54, 44 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print(arr, len);
	Mineqsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), Minecmp);
	print(arr, len);
	system("pause");
	return 0;
}
