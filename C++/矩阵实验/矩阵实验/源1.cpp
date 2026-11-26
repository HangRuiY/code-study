#include "三元组.h"
void M_Add(Matrix A, Matrix B)
{
	if (A.r != B.r || A.c != B.c)
	{
		printf("不满足相加条件\n");
		return;
	}
	int map[10][10];
	int map1[10][10];
	int map2[10][10];
	memset(map, 0, sizeof(map));
	memset(map1, 0, sizeof(map1));
	memset(map2, 0, sizeof(map2));
	for (int i = 1; i <= A.num; i++)
	{
		map1[A.data[i].row][A.data[i].col] = A.data[i].value;
	}
	for (int i = 1; i <= B.num; i++)
	{
		map2[B.data[i].row][B.data[i].col] = B.data[i].value;
	}
	for (int i = 1; i <= A.r; i++)
	{
		for (int j = 1; j <= A.c; j++)
			map[i][j] = map1[i][j] + map2[i][j];
	}
	printf("A+B矩阵：\n");
	for (int i = 1; i <= A.r; i++)
	{
		for (int j = 1; j <= A.c; j++)
			printf("\t%d", map[i][j]);
		cout << endl;
	}
	cout << endl;
}
void M_Sup(Matrix A, Matrix B)
{
	if (A.r != B.r || A.c != B.c)
	{
		printf("不满足相减条件\n");
		return;
	}
	int map[10][10];
	int map1[10][10];
	int map2[10][10];
	memset(map, 0, sizeof(map));
	memset(map1, 0, sizeof(map1));
	memset(map2, 0, sizeof(map2));
	for (int i = 1; i <= A.num; i++)
	{
		map1[A.data[i].row][A.data[i].col] = A.data[i].value;
	}
	for (int i = 1; i <= B.num; i++)
	{
		map2[B.data[i].row][B.data[i].col] = B.data[i].value;
	}
	for (int i = 1; i <= A.r; i++)
	{
		for (int j = 1; j <= A.c; j++)
			map[i][j] = map1[i][j] - map2[i][j];
	}
	printf("A-B矩阵：\n");
	for (int i = 1; i <= A.r; i++)
	{
		for (int j = 1; j <= A.c; j++)
			printf("\t%d", map[i][j]);
		cout << endl;
	}
	cout << endl;
}
void M_Mul(Matrix A, Matrix B)
{
	if (A.r != B.c || A.c != B.r)
	{
		printf("不满足相乘条件\n");
		return;
	}
	int map[10][10];
	int map1[10][10];
	int map2[10][10];
	memset(map, 0, sizeof(map));
	memset(map1, 0, sizeof(map1));
	memset(map2, 0, sizeof(map2));
	for (int i = 1; i <= A.num; i++)
	{
		map1[A.data[i].row][A.data[i].col] = A.data[i].value;
	}
	for (int i = 1; i <= B.num; i++)
	{
		map2[B.data[i].row][B.data[i].col] = B.data[i].value;
	}
	for (int i = 1; i <= A.r; i++)
	{
		for (int j = 1; j <= B.c; j++)
		{
			for (int k = 1; k <= A.c; k++)
			{
				map[i][j] += map1[i][k] * map2[k][j];
			}
		}
	}
	printf("A*B矩阵：\n");
	for (int i = 1; i <= A.r; i++)
	{
		for (int j = 1; j <= B.c; j++)
			printf("\t%d", map[i][j]);
		cout << endl;
	}
}