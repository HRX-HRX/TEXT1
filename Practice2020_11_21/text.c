#include <stdio.h>
#include <windows.h>
int Findnum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;//找右上角进行对比

	while (x <= row - 1 && y >= 0)//找右上角对比，最后对比的情况一直向左下角收缩，
		//假设找的是7的话，3*3的矩阵就会收缩到第三行第一列，因为这是极端的情况
	{
		if (arr[x][y] > k)//说明右上角的数比想要找的数字大，应该继续向左找
		{
			y--;
		}
		else if (arr[x][y] < k)//右上角的数字比要找的数字小，继续向下找
		{
			x++;
		}
		else
		{
			return 1;
		}
	}
	//循环完之后找不到，直接返回0
	return 0;
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int k = 0;
	scanf_s("%d", &k);
	int ret = Findnum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
	system("pause");
	return 0;
}
