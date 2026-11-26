#include <iostream>
#include <string>
#include <queue>
#include <assert.h>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;
//前缀和
//int main()
//{
//	int arr[100] = { 0 };
//	for (int i = 1; i <= 10; i++)
//		cin >> arr[i];
//	int sum[100] = { 0 };
//	for (int i = 1; i <= 10; i++)
//	{
//		sum[i] = sum[i - 1] + arr[i];
//	}
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << sum[i] << " ";
//	}
//	return 0;
//}

//差分
//int main()
//{
//	int arr[100] = { 0 };
//	int brr[100] = { 0 };
//	for (int i = 1; i <= 10; i++)
//		cin >> arr[i];
//	for (int i = 1; i <= 10; i++)
//	{
//		brr[i] = arr[i] - arr[i - 1];
//	}
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << brr[i] << " ";
//	}
//	return 0;
//}

//一种新型的激光炸弹，可以摧毁一个边长为 m 的正方形内的所有目标。现在地图上有 n 个目标，用整数 x, y
//表示的位置，每个目标有一个价值 v.算一颗炸弹最多能炸掉地图上总价值为多少的目标
//int n, m, s[5010][5010];
//int main()
//{
//	cin >> n >> m;//n是目标 m是区域边长
//	for (int i = 1; i <= n; i++)
//	{
//		int x, y, v;//x和y表示坐标 v表示价值
//		cin >> x >> y >> v;
//		s[x + 1][y + 1] += v;	// 将横纵坐标都加一，坐标范围变成 [1, 5001]，避免越界
//	}
//
//	int N = 5001; //坐标范围
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
//
//	int ans = 0;
//	for (int i = m; i <= N; i++)
//		for (int j = m; j <= N; j++)
//		{
//			int num = s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m];
//			// num为以(i, j)为右下角的边长为m的正方形区域中的目标价值之和
//			ans = max(ans, num);
//			// 用num更新答案
//		}
//	cout << ans << endl;
//	return 0;
//}

//长度为L的马路上有一排树，间隔1米，M个区域要建地铁，将这些树移走，还剩多少树
//int main()
//{
//	int v[100000];
//	int l = 0;//树的总数
//	int m = 0;//区域数量
//	cin >> l >> m;
//	for (int i = 0; i < l; i++)
//	{
//		v[i] = 0;
//	}
//	while (m--)
//	{
//		int q, z;//区域的起始点和终止点
//		cin >> q >> z;
//		for (int i = q; i <= z; i++)
//		{
//			if (v[i] == 0)
//			{
//				v[i] = 1;
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i < l; i++)
//	{
//		if (v[i] == 0)
//			cnt++;
//	}
//	cout << cnt+1;
//	return 0;
//}