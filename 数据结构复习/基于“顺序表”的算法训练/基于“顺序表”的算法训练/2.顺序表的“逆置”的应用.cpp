#include <iostream>
using namespace std;
#pragma region 做王道书 2.2.3_大题_2
//顺序表L的所有元素逆置，空间复杂度为O(1)
//思想：双指针，一个从左到右 一个从右到左，左>=右时结束循环，交换位置即可
//void reverse(int a[], int n)
//{
//	int left = 0; int right = n - 1;
//	while (left < right)
//	{
//		int t = a[left];
//		a[left] = a[right];
//		a[right] = t;
//		left++; right--;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//}
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	reverse(a,10);
//}
#pragma endregion

#pragma region 做王道书 2.2.3_大题_7
//一维数组中存放两个线性表(a1-am),(b1-bn)，将两个顺序表位置互换
//思想：开辟新数组，先存放后面n个，再存放前面m个即可
//void reverse(int a[], int length,int m, int n)
//{
//	int b[15] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		b[i] = a[m++];
//	}
//	for (int i = n, j = 0; i < length && j < m; i++, j++)
//	{
//		b[i] = a[j];
//	}
//	for (int i = 0; i < length; i++)
//		cout << b[i] << " ";
//}
//int main()
//{
//	int a[15] = { 1,3,4,5,6,7, 8,2,10,15,16,17,22,13,11 };//m=6,n=9
//	reverse(a, 15,6, 9);
//}
#pragma endregion
