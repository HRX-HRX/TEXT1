#include <stdio.h>
#include <windows.h>
int Findnum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;//�����Ͻǽ��жԱ�

	while (x <= row - 1 && y >= 0)//�����ϽǶԱȣ����Աȵ����һֱ�����½�������
		//�����ҵ���7�Ļ���3*3�ľ���ͻ������������е�һ�У���Ϊ���Ǽ��˵����
	{
		if (arr[x][y] > k)//˵�����Ͻǵ�������Ҫ�ҵ����ִ�Ӧ�ü���������
		{
			y--;
		}
		else if (arr[x][y] < k)//���Ͻǵ����ֱ�Ҫ�ҵ�����С������������
		{
			x++;
		}
		else
		{
			return 1;
		}
	}
	//ѭ����֮���Ҳ�����ֱ�ӷ���0
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
		printf("�ҵ���\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}
	system("pause");
	return 0;
}
