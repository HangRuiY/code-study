#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//int main()
//{
//	char arr1[] = "helo";
//	char arr2[] = "helo";
//	const char* arr3 = "helo";
//	const char* arr4 = "helo";
//	if (arr1 == arr2)
//		printf("1");
//	else
//		printf("2");
//	if (arr3 == arr4)
//		printf("3");
//	else
//		printf("4");
//	return 0;
//}

//指针数组
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int b[] = { 6,7,8,9,10 };
//	int c[] = { 11,12,13,14,15 };
//	int* arr[] = { a,b,c };
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 5;j++)
//		{
//			printf("%d ", *(arr[i] + j));
//		}
//		printf("\n");
//	}
//}

//数组指针
//int main()
//{
//	//int arr1[10] = { 0 };
//	//int(*parr1)[10] = &arr1;
//	//int* arr2[5];
//	//int* (*parr2)[5] = &arr2;
//	int arr[10] = { 0 };
//	int* p1 = arr;;
//	int(*p2)[10] = &arr;
//	printf("%p\n", p1);printf("%p\n", p1 + 1);
//	printf("%p\n", p2);printf("%p\n", p2 + 1);
//	return 0;
//}

//void print(int arr[3][5], int a, int b)
//{
//	int i = 0;int j = 0;
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 5;j++)
//			printf("%d ", arr[i][j]);
//		printf("\n");
//	}
//}
//void print(int(*p)[5], int x, int y)
//{
//	int i = 0;int j = 0;
//	for (i = 0;i < x;i++)
//	{
//		for (j = 0;j < y;j++)
//			printf("%d ", *(*(p + i) + j));
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	/*print(arr, 3, 5);*/
//	print(arr, 3, 5);
//	return 0;
//}

//int(*parr[10])[5]
//parr是一个存放数组指针的数组，数组内有10个元素，每个元素是一个数组指针，每个数组指针指向一个数组，数组里面5个元素
//int(*p) = &a; //类型为int p为指针变量 
