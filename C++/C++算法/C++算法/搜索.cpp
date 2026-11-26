#include <iostream>
#include <string>
#include <queue>
#include <assert.h>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;
//搜索：通过穷举所有可能的 解的 状态，来得到最后的答案    构造一颗解答树来找到合适的节点。
//状态：某一系统在某一时刻的数学描述 可以进行状态转移。
//几乎所有问题都可以进行 搜索

//广度优先搜索 BFS
//优先遍历当前节点的所有子节点，依赖于队列实现
//解决的“最快到达”问题，主要在于状态的表示和转移
//例题1.求x到y的最少计算次数
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	queue<int>q;
//	q.push(n);
//	int flag = 0; int cnt = 0;
//	while (!q.empty())
//	{
//		int len = q.size();
//		for (int i = 0; i < len; i++)
//		{
//			int tmp = q.front();
//			q.pop();
//			if (tmp == k)
//			{
//				flag = 1; 
//				break;
//			}
//			else
//			{
//				q.push(tmp + 1);
//				q.push(tmp - 1);
//				q.push(tmp * 2);
//			}
//		}
//		
//		if (flag == 1)
//			break;
//		cnt++;
//	}
//	cout << cnt;
//	return 0;
//}
//
//例题2.迷宫问题
//struct Node
//{
//	int x, y;
//	int step;
//};
//queue<Node>Q;
//int visit[1000][1000];
//int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
//int main()
//{
//	int t; cin >> t;
//	char c[1000][1000];
//	while (t--)
//	{
//		int n, m;
//		cin >> n >> m;
//		memset(visit, 0, sizeof(visit));
//		while (!Q.empty())
//		{
//			Q.pop();
//		}
//		for (int i = 0; i < n; i++)
//		{
//			cin >> c[i];
//		}
//		int sx = 0, sy=0;//记录当前位置
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (c[i][j] == 'S')
//				{
//					sx = i; sy = j;
//					break;
//				}
//			}
//		}
//
//		Node start;
//		start.x = sx; start.y = sy; start.step = 0;
//
//		Q.push(start);
//		visit[sx][sy] = 1;
//		int ans = -1;
//		while (!Q.empty())
//		{
//			Node head = Q.front();
//			Q.pop();
//
//			if (c[head.x][head.y] == 'T')
//			{
//				ans = head.step; break;
//			}
//			for (int i = 0; i < 4; i++)  //走4个方向
//			{
//				int nx, ny;
//				nx = head.x + dir[i][0];
//				ny = head.y + dir[i][1];
//
//				if (c[nx][ny] == '.' || c[nx][ny] == 'T' || c[nx][ny] == 'S')
//				{
//					visit[nx][ny] = 1;
//					Node newnode;
//					newnode.x = nx; newnode.y = ny; newnode.step = head.step + 1;
//					Q.push(newnode);
//				}
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

//深度优先DFS
//优先进行深部遍历，利用 栈或者递归实现 可以用visit数组来标记访问过的点
//乔治的木棍问题
//int used[100], len[100], sum, n, Min;
//int find(int p, int rest, int trest)
//{
//	int i;
//	if (trest == Min)
//		return 1;
//	for (i = p; i <= n; i++)
//	{
//		if (!used[i] && len[i] <= rest)
//		{
//			used[i] = 1;
//			if (len[i] == rest)
//			{
//				if (find(1, Min, trest - len[i]))
//					return 1;
//			}
//			else if (find(i + 1, rest - len[i], trest - len[i]))
//				return 1;
//			used[i] = 0;
//			if (len[i] == rest)
//				return 0;
//			if (rest == Min)
//				return 0;
//			while (len[i + 1] == len[i])
//				i++;
//		}
//	}
//	return 0;
//}
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int i = 0;
//	while (cin >> n)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> len[i];
//		}
//		memset(used, 0, sizeof(used));
//		sort(len + 1, len + 1 + n,cmp);
//		sum = 0;
//		for (int i = 1; i <= n; i++)
//			sum += len[i];
//		Min = len[i];
//
//		while(sum % Min != 0)
//			Min++;
//		while (find(1, Min, sum) == 0)
//		{
//			Min++;
//			while (sum % Min != 0)
//				Min++;
//		}
//		cout << Min << endl;
//	}
//	return 0;
//}