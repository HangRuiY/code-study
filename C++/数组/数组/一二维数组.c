#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//int main()
//{
//	char arr1[] = { 'b','i','t' };
//	char arr2[] = "bit";
//	printf("%d\n", strlen(arr1));
//	printf("%d", strlen(arr2));
//
//}

//int main() //修改某一个值
//{
//	int arr[10] = { 0 };
//	arr[3] = 5;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0;i < sz;i++)
//		printf("%d ", arr[i]);
//}

//int main() //内存存储
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//}

//int main()
//{
//	int arr[][4] = { {1,2,3,4},{5,6},{7,8} };
//	int i = 0; //行数
//	int j = 0; //列数
//	for (i = 0;i <=2;i++)
//	{
//		for (j = 0;j <= 3;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//选择排序
//void Print(int* arr)
//{
//	for (int i = 0; i < 9; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//int main()
//{
//	int arr[9] = { 14,7,23,31,40,56,78,9,2 };
//	int i = 0; int k = 0;
//	for (i = 0; i < 9; i++)
//	{
//		for (k = i + 1; k < 9; k++)
//		{
//			if (arr[i] > arr[k])
//			{
//				int t = 0;
//				t = arr[k];
//				arr[k] = arr[i];
//				arr[i] = t;
//				Print(arr);
//			}
//		}
//	}
//	return 0;
//}

//冒泡排序 升序
void Print(int* arr,int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void bubble_sort (int *arr, int sz)
{
	
	int i = 0;//趟数
	for (i = 0;i < sz - 1;i++)
	{
		int j = 0;//下标从0开始
		for (j = 0;j < sz - i -1;j++)
		{
			if (arr[j] >= arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
			}
		}
		Print(arr, sz);
     }
}
int main()
{
	int arr[] = { 2,5,3,4,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	return 0;
}

//插入排序
//void Print(int* arr, int sz)
//{
//	for (int i = 0; i < 9; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//void insertsort(int* arr,int sz)
//{
//	int i = 0; int j = 0;
//	int value = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		value = arr[i + 1];
//		for (j = i + 1; j >= 0 && value < arr[j - 1]; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[j] = value;
//		Print(arr, sz);
//	}
//}
//int main()
//{
//	int arr[] = {14 ,  7 ,  23  , 31 ,  40  , 56   ,78  , 9  , 2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	insertsort(arr, sz);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", &arr); //整个数组的地址
//	printf("%p\n", &arr+1); //加40字节
//  printf("%p\n", arr);  //首元素
//	printf("%p\n", arr+1); //第二个元素
//
//}

//逆序，初始化0
//void init(int arr[], int sz)
//{
//	int j = 0;
//	for (j = 0;j < sz;j++)
//	{
//		arr[j] = 0;
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int t = arr[left];
//		arr[left] = arr[right];
//		arr[right] = t;
//		left++;right--;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//    init(arr, sz);
//	print(arr, sz);
//
//}

//交换两个数组的内容 等大
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//    int arr2[] = { 2,4,6,8,10 };
//	int sz=sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0;i < sz;i++)
//	{
//		int t = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = t;
//	}
//	int * p = arr1;
//	int* q = arr2;
//	int j = 0;
//	for (j = 0;j < sz;j++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	
//}

//二分查找
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int high = 9; int low = 0;
//	int x = 6;
//	int mid = (high + low) / 2;
//	while (low != high)
//	{
//		if (arr[mid] > x)
//		{
//			high = mid;
//			mid = (high + low) / 2;
//		}
//		else if (arr[mid] < x)
//		{
//			low = mid;
//			mid = (high + low) / 2;
//		}
//		else if (arr[mid] == x)
//		{
//			printf("%d是在数组的%d下标处", x, mid);
//			break;
//		}
//		else
//		{
//			printf("查无此数");
//		}
//	}
//	return 0;
//}

//苹果分盘
//#define MAX 1000
//int arr[MAX][MAX];
//int main()
//{
//	int n = 0; int m = 0;
//	scanf("%d %d", &n, &m);//n个苹果 m个盘子
//	//1种排法
//	for (int i = 0; i <= m; i++)
//	{
//		arr[0][i] = 1;//没有苹果
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		arr[i][1] = 1;//1个盘子
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (i >= j) //苹果比盘子多
//			{
//				arr[i][j] = arr[i][j - 1] + arr[i - j][j];
//			}
//			if(i<j) //盘子比苹果多
//				arr[i][j] = arr[i][i];
//		}
//	}
//	printf("%d", arr[n][m]);
//	return 0;
//}

