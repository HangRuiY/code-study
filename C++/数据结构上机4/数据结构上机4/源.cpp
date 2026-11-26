//#include <iostream>
//using namespace std;
//#include <queue>
//typedef struct
//{
//	char c[100];
//	int vex[100][100];
//	int n;
//}Graph;
//int vis[1010];
//void bfs(Graph* g, int v)
//{
//	queue<int> q;
//	vis[v] = 1;
//	cout << g->c[v] << " ";
//	q.push(v);
//	while (!q.empty())
//	{
//		int v1 = q.front();
//		q.pop();
//		for (int i = 1; i <= g->n; i++)
//		{
//			if (!vis[i] && g->vex[v1][i])
//			{
//				vis[i] = 1;
//				cout << g->c[i] << " ";
//				q.push(i);
//			}
//		}
//	}
//}
//int visit[1010];
//void dfs(Graph* g, int v)
//{
//	cout << g->c[v] << " ";
//	visit[v] = 1;
//	for (int i = 1; i <= g->n; i++)
//	{
//		if (!visit[i] && g->vex[v][i])
//			dfs(g, i);
//	}
//}
//int id[100];
//int od[100];
//void degree(Graph* g)
//{
//	for (int i = 1; i <= g->n; i++)
//	{
//		for (int j = 1; j <= g->n; j++)
//		{
//			if (g->vex[i][j])
//			{
//				od[i]++;
//			}
//			if (g->vex[j][i])
//			{
//				id[i]++;
//			}
//		}
//	}
//	cout << "顶点" << " " << "出度" << " " << "入度" << " "<<"度"<<endl;
//	for (int i = 1; i <= g->n; i++)
//	{
//		cout <<" " << g->c[i] << "    " << od[i] << "    " << id[i] << "   " << od[i] + id[i] << endl;
//	}
//}
//int main()
//{
//	Graph g = { 0 };
//	int n = 0, m = 0; cout << "请输入顶点数和边数:>"; cin >> n >> m;
//	//初始化图
//	g.n = n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			g.vex[i][j] = 0;
//	}
//	cout << "输入顶点序列:>";
//	for (int i = 1; i <= n; i++)
//	{
//		char c;
//		cin >> c;
//		g.c[i] = c;
//	}
//	int x = 0, y = 0;
//	cout << "输入每条边的两个顶点序号:>" << endl;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> x >> y;
//		g.vex[x][y] = 1;
//	}
//	//输出邻接矩阵
//	cout << "邻接矩阵为:>" << endl;
//	cout << "  " << "A B C D E" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cout << g.c[i] << " ";
//		for (int j = 1; j <= n; j++)
//			cout << g.vex[i][j] << " ";
//		cout << endl;
//	}
//	//度
//	degree(&g);
//	//深度优先遍历
//	cout << "深度优先遍历结果为:>" << endl; 
//	dfs(&g, 1); cout << endl;
//	//广度优先遍历
//	int v = 0;
//	cout << "输入广度优先遍历的起点序号:>"; cin >> v;
//	cout << "广度优先遍历结果为:>" << endl;
//	bfs(&g, v); cout << endl;
//	return 0;
//}

#include<stdio.h>
int main()
{
	int g[10][10];
	int dis[10] = { 0 };
	int vis[10];
	int n, m;
	int t1, t2, t3;
	int inf = 99999999;
	printf("请输入顶点个数与边的条数:>");
	scanf("%d %d", &n, &m);//n表示顶点个数，m表示边的条数
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) 
				g[i][j] = 0;
			else  
				g[i][j] = inf;
		}
	}
	printf("请输入顶点之间的连通关系以及边的权值:>\n");
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		g[t1][t2] = t3;//顶点 t1 到顶点 t2 的路程 
	}
	for (int i = 1; i <= n; i++)//源点到各个顶点的初始路程 
		dis[i] = g[1][i];
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	vis[1] = 1;//源点访问过，标记1
	int u, min;
	for (int i = 1; i <= n - 1; i++)
	{
		min = inf;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		vis[u] = 1;
		for (int v = 1; v <= n; v++)
		{
			if (g[u][v] < inf)
			{
				if (dis[v] > g[u][v] + dis[u])
				{
					dis[v] = g[u][v] + dis[u];
				}
			}
		}
	}
	int k = 0;
	/*printf("请输入所求最短路径的终点序号:>"); scanf("%d", &k);
    printf("源点到该点的最短路径为:>%d", dis[k]);*/
	for (k = 1; k <= n; k++)
		printf("%d ", dis[k]);
	return 0;
}