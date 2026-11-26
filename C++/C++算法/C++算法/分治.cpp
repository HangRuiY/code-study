#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
//把一个问题，分解为若干相似的子问题（相互独立），再把子问题分解为更小的子问题，直到可以简单求解
//特征：问题的规模缩小到一定程度可以很容易的解决,具有最优子结构的性质，子问题的解可以合并为问题的解
//1.怎么分解成子问题 2.子问题怎么求解 3.怎么合并

//归并排序：把N个无序整数数组排序
void merge_operate(int* a, int s, int mid, int t)
{
	int b[10000];
	int i = s; int j = mid + 1;
	int p = 0;
	while (i <= mid || j <= t)
	{
		int ai = 99999999;
		int aj = 99999999;
		if (i <= mid)
			ai = a[i];
		if (j <= t)
			aj = a[j];
		int tmp = 0;//记录较小的数字
		if (ai>aj)
		{
			tmp = aj; j++;
		}
		else
		{
			tmp = ai; i++;
		}
		b[s + p] = tmp;
		p++;
	}
	for (int i = s; i <= t; i++)
		a[i] = b[i];
}
void merge_sort(int* a, int s, int t)
{
	if (s == t)
		return;
	int mid = (s + t) / 2;
	merge_sort(a, s, mid);
	merge_sort(a, mid + 1, t);
	merge_operate(a, s,mid,t);
}
//int main()
//{
//  int a[10000];
//  int n;
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		merge_sort(a, 0, n - 1);
//
//		for (int i = 0; i < n; i++)
//			cout << a[i] << " ";
//	}
//	return 0;
//}
