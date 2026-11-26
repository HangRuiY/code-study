#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;
void print(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
		cout << a[i] << " ";
	cout << endl;
}
//≤Â»Î≈≈–Ú
void insertsort(int* a, int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int k = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
		print(a, sz);
	}
}
//√∞≈›≈≈–Ú
void bubblesort(int* a, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (a[j] >= a[j + 1])
			{
				int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
		}
		print(a, sz);
	}
}
//—°‘Ò≈≈–Ú 
void choosesort(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		for (int k = i + 1; k < sz; k++)
		{
			if (a[i] >= a[k])
			{
				int t = a[i]; a[i] = a[k]; a[k] = t;
			}
		}
		print(a, sz);
	}
}
//øÏÀŸ≈≈–Ú
void quicksort(int* a, int s, int t)
{
	if (s >= t)
		return;
	int tag = s;
	int i = s, j = t;
	while (i < j)
	{
		while (a[j] > a[tag] && j > tag)
		{
			j--;
		}
		int tmp = a[j];
		a[j] = a[tag];
		a[tag] = tmp;
		
		tag = j;
		while (a[i] <= a[tag] && i < tag)
		{
			i++;
		}
		tmp = a[i];
		a[i] = a[tag];
		a[tag] = tmp;

		tag = i;
	}
	if (s <= tag - 1)
		quicksort(a, s, tag - 1);
	if (tag + 1 <= t)
		quicksort(a, tag + 1, t);
}

#include<iostream>
using namespace std;
int m, t;
int c[1010], v[1010];
int dp[1010];
//int main()
//{
//	cin >> t >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> c[i] >> v[i];
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = t; j >= c[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
//		}
//	}
//	cout << dp[t];
//	return 0;
//}
