#include <iostream>
using namespace std;
#pragma region 2021_41题，即王道书 6.2.6_大题_7
//当G中度为奇数的顶点个数为不大于2的偶数时，G存在包含所有边且长度为|E|的路径，判断一个图是否存在EL路径
//思想：邻接矩阵存储无向图，i号结点的度等于第i行非零元素个数，遍历整个图，把度为奇数的顶点个数用变量保存下来，最后判断即可
//时间：O(n^2) 空间O(1)
//typedef struct
//{
//	int numV, numE;
//	int V[5];
//	int Edge[5][5];
//}Graph;
//int isExistEL(Graph g)
//{
//	int count = 0;
//	for (int i = 0; i < g.numV; i++)
//	{
//		int i_degree = 0;
//		for (int j = 0; j < g.numV; j++)
//		{
//			if (g.Edge[i][j] != 0)
//				i_degree++;
//		}
//		if (i_degree % 2 != 0)
//			count++;
//	}
//	if (count <= 2 && count % 2 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	Graph g;
//	g.numV = 5; g.numE = 6;
//	for (int i = 0; i <= 4; i++)
//		g.V[i] = i;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//			g.Edge[i][j] = 0;
//	}
//	int m, n = 0;
//	for (int i = 0; i < g.numE; i++)
//	{
//		cin >> m >> n;
//		g.Edge[m][n] = g.Edge[n][m] = 1;
//	}
//	cout << isExistEL(g);
//}
#pragma endregion
//typedef struct Node//边表结点
//{
//	int adjvex; struct Node* nextarc;
//}Node;
//typedef struct VNode//顶表结点
//{
//	int data; Node* firstarc;
//}VNode,AdjList;//声明顶表数组名称
//typedef struct Graph
//{
//	AdjList vt[5];
//	int vexnum, edgenum;
//}Graph;
//void create(AdjList &v,int n)
//{
//	int t = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> t;
//		Node* p = (Node*)malloc(sizeof(Node));
//		p->adjvex = t; p->next = NULL;
//		//尾插
//		if (v.next == NULL)
//		{
//			v.next = p;
//		}
//		else
//		{
//			Node* tail = v.next;
//			while (tail->next != NULL)
//				tail = tail->next;
//			tail->next = p;
//		}
//	}
//}
//void Print(AdjList v)
//{
//	cout << v.data << " ";
//	Node* tail = v.next;
//	while (tail != NULL)
//	{
//		cout << tail->adjvex<<" ";
//		tail = tail->next;
//	}
//	cout << endl;
//}
//int isExistEL(Graph g)
//{
//	int count = 0;
//	for (int i = 0; i < g.vexnum; i++)
//	{
//		Node* p = g.vt[i].next;
//		int degree = 0;
//		while (p != NULL)
//		{
//			degree++; p = p -> next;
//		}
//		if (degree % 2 != 0)
//			count++;
//	}
//	if (count <= 2 && count % 2 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//	Graph g; g.vexnum = 5; g.edgenum = 6;
//	int n = 0;
//	for (int i = 0; i < g.vexnum; i++)//先初始化顶表的顶点
//	{
//		g.vt[i].data = i;
//		g.vt[i].next = NULL;
//	}
//	for (int i = 0; i < g.vexnum; i++)
//	{
//		cin >> n;//第i个顶点连接n个边点
//		create(g.vt[i],n);//再处理边表
//	}
//	cout << isExistEL(g);
//}

#pragma region 2023_41题，即王道书 6.2.6_大题_8
//邻接矩阵存有向图 出度大于入度的顶点称为K顶点，输出图中所有的K结点 返回K结点个数 
//思想：i结点 出度是i行 入度是i列，遍历图即可
typedef struct
{
	int numV, numE;
	int V[5];
	int Edge[5][5];
}Graph;
int printk(Graph g)
{
	int count = 0;
	for (int i = 0; i < g.numV; i++)
	{
		int indegree = 0; int outdegree = 0;
		for (int j = 0; j < g.numV; j++)//i号结点 第i行之和为出度
		{
			if (g.Edge[i][j] != 0)
				outdegree++;
		}
		for (int j = 0; j < g.numV; j++)////i号结点 第i列之和为入度
		{
			if (g.Edge[j][i] != 0)
				indegree++;
		}
		if (outdegree > indegree)
		{
			cout << g.V[i] << " ";
			count++;
		}
	}
	return count;
}
int main()
{
	Graph g;
	g.numV = 5; g.numE = 7;
	for (int i = 0; i <= 4; i++)
		g.V[i] = i;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			g.Edge[i][j] = 0;
	}
	int m, n = 0;
	for (int i = 0; i < g.numE; i++)
	{
		cin >> m >> n;
		g.Edge[m][n] = 1;
	}
	cout << printk(g);
}
#pragma endregion
