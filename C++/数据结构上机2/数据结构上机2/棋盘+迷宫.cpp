//马踏棋盘
#include <iostream>
#include<stdio.h>
using namespace std;
int map[10][10];
int dir[8][2] = { {1,2} ,{-1,2},{1,-2},{-1,-2},
				  {2,1},{2,-1},{-2,1},{-2,-1} };
int vis[10][10];
bool flag;
bool only = false;
void print()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%4d", map[i][j]);
		}
		printf("\n\n");
	}
	return;
}
void dfs(int x, int y, int step)
{
	if (flag && only)
		return;
	map[x][y] = step;
	if (step == 64)
	{
		print();
		printf("\n");
		flag = true;
		return;
	}
	vis[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int tx = dir[i][0] + x;
		int ty = dir[i][1] + y;
		if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && !vis[tx][ty])
		{
			dfs(tx, ty, step + 1);
		}

	}
	vis[x][y] = 0;
	map[x][y] = 0;
}
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	dfs(x, y, 1);
//	return 0;
//}

//迷宫
//#include <iostream>
//using namespace std;
//int n, m, t, ans = 0;
//int sx, sy, fx, fy;
//int x, y;
//int a[1010][1010];
//bool vis[1010][1010];
//int xx[4] = { 1,0,-1,0 };
//int yy[4] = { 0,-1,0,1 };
//void dfs(int h, int l)
//{
//	cout << "(" << h << "," << l << ")";
//	if (h == fx && l == fy)
//	{
//		ans++;
//		return;
//	}
//	cout << "->";
//	for (int i = 0; i < 4; i++)
//	{
//		int dx = xx[i] + h;
//		int dy = yy[i] + l;
//		if (dx >= 1 && dy >= 1 && dx <= n && dy <= m && !vis[dx][dy] && !a[dx][dy])
//		{
//			vis[dx][dy] = 1;
//			dfs(dx, dy);
//			vis[dx][dy] = 0;
//		
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m >> t;//迷宫规模n*m 障碍物t个
//	cin >> sx >> sy >> fx >> fy;//起点坐标  终点坐标
//	while (t--)
//	{
//		cin >> x >> y;
//		a[x][y] = 1;//标记障碍物
//	}
//	vis[sx][sy] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cout << a[i][j]<<"   ";
//		}
//		cout << endl;
//	}
//	dfs(sx, sy);
//	cout << endl;
//	cout << ans;
//	return 0;
//}
