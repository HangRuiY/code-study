#include <iostream>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cstdio>
#include <algorithm>
using namespace std;
//int n, m, s[5010][5010];
//P2280 激光炸弹
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		int x, y, v;
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
//
//			ans = max(ans, num);
//		}
//	cout << ans << endl;
//	return 0;
//}

//校门外的树
//int L, M;
//int cnt = 0;
//int vis[10000 + 10];
//int main()
//{
//    memset(vis, 0, sizeof(vis));
//    cin >> L >> M;
//    for (int i = 0; i <= L; i++)
//        vis[i] = 0;//从0这个树开始，将这条路上所有的树标记为未访问过
//    for (int i = 1; i <= M; i++)
//    {
//        int head, tail;//定义区间的头和尾
//        cin >> head >> tail;
//        for (int j = head; j <= tail; j++)
//            if (vis[j] == 0)
//                vis[j] = 1;
//    }
//    for (int i = 0; i <= L; i++)
//    {
//        if (vis[i] == 0)
//            cnt++;//计算未被访问过的树的数
//    }
//    cout << cnt << endl;
//    return 0;
//}