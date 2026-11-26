#include <iostream>
#include <queue>
using namespace std;
//typedef struct Graph
//{
//	int vex[5] = { 1,2,3,4,5 };
//	int edge[5][5] = { {0,1,1,0,1},{1,0,0,1,1},{1,0,0,1,0},{0,1,1,0,1},{1,1,0,1,0} };
//	int vexnum = 5;
//}Graph;
//bool visited[5];
//void visit(int i)
//{
//	cout << i << " ";
//}
//void BFS(Graph g, int i, queue<int>& q)
//{
//	visit(i);
//	visited[i] = true;
//	q.push(i);
//	while (!q.empty())
//	{
//		int v = q.front();
//		q.pop();
//		for (int w = 0; w < g.vexnum; w++)
//		{
//			if (visited[w] == false && g.edge[v][w] == 1)
//			{
//				visit(w);
//				visited[w] = true;
//				q.push(w);
//			}
//		}
//	}
//}
//void bfsStart(Graph g)
//{
//	for (int i = 0; i < g.vexnum; i++)
//		visited[i] = false;
//	queue<int> q;
//	for (int i = 0; i < g.vexnum; i++)
//	{
//		if (!visited[i])
//			BFS(g, i, q);
//	}
//}
//void DFS(Graph g, int i)
//{
//	visit(i);
//	visited[i] = true;
//	for (int j = 0; j < g.vexnum; j++)
//	{
//		if (visited[j] == false && g.edge[i][j] == 1)
//			DFS(g, j);
//	}
//}
//void dfsStart(Graph g)
//{
//	for (int i = 0; i < g.vexnum; i++)
//		visited[i] = false;
//	for (int i = 0; i < g.vexnum; i++)
//	{
//		if (!visited[i])
//			DFS(g, i);
//	}
//}
//int main()
//{
//	Graph g;
//	bfsStart(g); cout << endl;
//	dfsStart(g);
//}