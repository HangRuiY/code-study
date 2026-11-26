#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;
int aaa[10000], aa[10000];
int max = 10000;
//二分查找
bool binary(int a[], int k, int l, int r)
{
	if (l > r)
		return false;
	int mid = (l + r) / 2;
	if (a[mid] > k)
	{
		return binary(a, k, l, mid - 1);
	}
	else if (a[mid] < k)
	{
		return binary(a, k, mid + 1, r);
	}
	else
		return true;
}

//二分答案
//适用范围：1.问题具有单调性 2.要求找到符合条件的最大（小）值
//例题:对于一个序列A，改变其数字，让形成的序列B可以单调递增，并打印出调整代价的最优值
//bool check(int* aa,int mid)
//{
//	for (int i = 0; i < 5; i++)
//		aaa[i] = aa[i];
//	for (int i = 0; i < 5; i++)
//	{
//		if (i == 0)
//			aaa[i] -= mid;
//		if (aaa[i] <= aaa[i - 1])
//		{
//			if (aaa[i] + mid >= aaa[i - 1] + 1)
//			{
//				aaa[i] = aaa[i - 1] + 1;
//			}
//			else
//				return false;
//		}
//		else
//		{
//			if (aaa[i - 1] + 1 + mid >= aaa[i])
//				aaa[i] = aaa[i - 1] + 1;
//			else
//				aaa[i] -= mid;
//		}
//	}
//	return true;
//}
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> aa[i];
//	}
//	int l = 1; int r = 10000;
//	int mid = 0; int ans = 0;
//	while(l < r)
//	{
//		mid = (r + l) / 2;
//		if (check(aa, mid))
//		{
//			r = mid - 1;
//			ans = mid;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}