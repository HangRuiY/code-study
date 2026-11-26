#include <iostream>
using namespace std;
#define MAXSIZE 10
typedef struct Seqlist
{
	int data[MAXSIZE];
	int length;
}Seqlist;
void MovenotzeroFront(Seqlist& s)
{
	for (int i = 0; i < s.length; i++)
	{
		if (s.data[i] == 0)
		{
			for (int j = i; j < s.length; j++)
			{
				if (s.data[j] != 0)
				{
					int temp = s.data[i];
					s.data[i] = s.data[j];
					s.data[j] = temp;
					break;
				}
			}
		}
	}
}

void Delete(Seqlist& s, int index)
{
	for (int i = index; i < s.length-1; i++)
	{
		s.data[i] = s.data[i + 1];
	}
	s.length--;
}
void DeleteK1toK2(Seqlist& s, int k1, int k2)
{
	for (int i = 0; i < s.length; i++)
	{
		if (s.data[i] > k1 && s.data[i] < k2)
		{
			Delete(s, i);
			i--;
		}
	}
}

void reverse(Seqlist& s, int left, int right)
{
	while (left < right)
	{
		int temp = s.data[left];
		s.data[left] = s.data[right];
		s.data[right] = temp;
		left++; right--;
	}
}
void RightMoveK(Seqlist& s, int k)
{
	k = k % s.length;
	reverse(s, 0, s.length - 1);
	reverse(s, 0, k - 1);
	reverse(s, k, s.length - 1);
}

void DeleteMin(Seqlist& s)
{
	int min = s.data[0];
	int index = 0;
	for (int i = 1; i < s.length; i++)
	{
		if (s.data[i] <= min)
		{
			min = s.data[i]; index = i;
		}
	}
	for (int i = index; i < s.length; i++)
		s.data[i] = s.data[i + 1];
	s.length--;
}

typedef struct Lnode
{
	int data;
	int num; int price;
	struct Lnode* next;
}*Linklist,Lnode;
Linklist UpMergeAandB(Linklist LA, Linklist LB)
{
	Linklist LC = LA; Lnode* r = LC;
	Lnode* p = LA->next; Lnode* q = LB->next;
	while (p && q)
	{
		if (p->data <= q->data)
		{
			r->next = p; r = p; p = p->next;
		}
		else
		{
			r->next = q; r = q; q = q->next;
		}
	}
	r->next = (p != NULL) ? p : q;
	return LC;
}

void Addcommodity(Linklist H, int m, int h)
{
	Lnode* p = H;
	while (p->next != NULL)
	{
		Lnode* q = p->next;
		if (q->price < h)
			p = p->next;
		else if (q->price == h)
			q->num += m;
		else if (q->price > h)
		{
			Lnode* temp = (Lnode*)malloc(sizeof(Lnode));
			temp->num = m; temp->price = h;
			p->next = temp;
			temp->next = q;
		}
	}
	if (p->price < h)
	{
		Lnode* temp = (Lnode*)malloc(sizeof(Lnode));
		temp->num = m; temp->price = h;
		p->next = temp;
		temp->next = NULL;
	}
}

void DeleteJishu(Linklist& H)
{
	Lnode* p = H;
	while (p->next != NULL)
	{
		Lnode* q = p->next;
		if (q->data % 2 != 0)
		{
			p->next = q->next;
			free(q);
			continue;
		}
		p = p->next;
	}
}

Linklist MergeCircleAandB(Linklist& LA, Linklist& LB)
{
	Linklist LC = LA;
	Lnode* a = LA->next; Lnode* b = LB->next; Lnode* r = b;
	while (a->next != LA)
		a = a->next;
	while (r->next != LB)
		r = r->next;
	a->next = b;
	r->next = LA;
	LC = LA;
	free(LB);
	return LC;
}

void DeleteRepeat(Linklist& H)
{
	Lnode* p = H->next;
	while (p != NULL)
	{
		Lnode* q = p->next;
		while (q != NULL)
		{
			Lnode* temp = q;
			if (p->data == temp->data)
			{
				p->next = temp->next;
				free(temp);
				q = p->next;
			}
			else q = q->next;
		}
		p = p->next;
	}
}

int getLength(Linklist& H)
{
	Lnode* p = H->next; int cnt = 0;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
Linklist MergeAandB(Linklist& A, Linklist& B)
{
	int m = getLength(A); int n = getLength(B);
	Linklist C = A; Lnode* r = C;
	Lnode* p = A->next; Lnode* q = B->next;
	if (m <= n)
	{
		int flagp = 1; int flagq = 0;
		while (p && q)
		{
			if (flagp == 1)
			{
				r->next = p; r = p; p = p->next; flagp = 0; flagq = 1;
			}
			else if (flagq == 1)
			{
				r->next = q; r = q; q = q->next; flagp = 1; flagq = 0;
			}
		}
		r->next = q;
	}
	else
	{
		int flagp = 0; int flagq = 1;
		while (p && q)
		{
			if (flagp == 1)
			{
				r->next = p; r = p; p = p->next; flagp = 0; flagq = 1;
			}
			else if (flagq == 1)
			{
				r->next = q; r = q; q = q->next; flagp = 1; flagq = 0;
			}
		}
		r->next = p;
	}
	return C;
}

void DeleteLen(Linklist& H, int i,int len)
{
	Lnode* p = H; int cnt = 0;
	while (p->next != NULL)
	{
		cnt++;
		if (cnt == i)
		{
			while (len > 0&&p->next)
			{
				Lnode* q = p->next;
				p->next = q->next;
				free(q);
				len--;
			}
			break;
		}
		p = p->next;
	}
}

typedef struct Stack
{
	int data[MAXSIZE];
	int top = -1;
}Stack;
void Push(Stack& s, int x)
{
	if (s.top+1 == MAXSIZE) return;
	s.top++;
	s.data[s.top] = x;
	return;
}
void Pop(Stack& s, int& x)
{
	if (s.top == -1)return;
	x = s.data[s.top];
	s.top -= 1;
	return;
}

typedef struct Queue
{
	int data[MAXSIZE];
	int rear; int quelen; int front;
}Queue;
void EnQueue(Queue& q, int x)
{
	if ((q.rear+1)%MAXSIZE==(q.rear-q.quelen+MAXSIZE)%MAXSIZE)
		return;
	q.rear = (q.rear + 1) % MAXSIZE;
	q.data[q.rear] = x;
	q.quelen++;
}
void DeQueue(Queue& q, int& x)
{
	int front = (q.rear - q.quelen + MAXSIZE) % MAXSIZE;
	if (front == q.rear) return;
	front = (front + 1) % MAXSIZE;
	x = q.data[front];
	q.quelen--;
}

void EnQueue2(Queue& q, int x)
{
	if (q.quelen == MAXSIZE)
		return;
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MAXSIZE;
	q.quelen++;
}
void DeQueue(Queue& q, int& x)
{
	if (q.quelen == 0)return;
	x = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	q.quelen--;
}

typedef struct String
{
	char ch[MAXSIZE];
	int length;
}String;
bool isCircle(String s)
{
	int left = 0; int right = s.length - 1;
	while (left <= right)
	{
		if (s.ch[left] == s.ch[right])
		{
			left++; right--;
		}
		else
			return false;
	}
	return true;
}

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;
int cnt = 0;
void soleChild(Tree* root)
{
	if (!root)return;
	if ((root->left == NULL && root->right) || (root->left && root->right == NULL))cnt++;
	soleChild(root->left);
	soleChild(root->right);
}

int getHeight(Tree* root)
{
	if (!root)return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

void PrintHouxuReverse(Tree* root)
{
	if (root)
	{
		printf("%d ", root->data);
	}
	PrintHouxuReverse(root->right);
	PrintHouxuReverse(root->left);
}

int Degree2(Tree* root)
{
	if (!root) return 0;
	int cnt = (root->left && root->right) ? 1 : 0;
	int left = Degree2(root->left);
	int right = Degree2(root->right);
	return cnt + left + right;
}

int CountX(Tree* root,int x)
{
	if (!root)return 0;
	int cnt = (root->data == x) ? 1 : 0;
	int left = CountX(root->left, x);
	int right = CountX(root->right, x);
	return cnt + left + right;
}

int Leaf(Tree* root)
{
	if (!root)return 0;
	int cnt = (root->left == NULL && root->right == NULL) ? 1 : 0;
	int left = Leaf(root->left);
	int right = Leaf(root->right);
	return cnt + left + right;
}

int Deep(Tree* root)
{
	if (!root) return 0;
	int left = Deep(root->left);
	int right = Deep(root->right);
	return left > right ? left + 1 : right + 1;
}

void PrintK(Tree* root,int k)
{
	if (!root)return;
	if (k == 1)printf("%d ", root->data);
	PrintK(root->left,k-1);
	PrintK(root->right,k-1);
}

int temp = 0;
bool isBinTree(Tree* root)
{
	if (root)
	{
		isBinTree(root->left);
		if (temp <= root->data)
			temp = root->data;
		else
			return false;
		isBinTree(root->right);
	}
	return true;
}

Tree* FindXParent(Tree* root, int x)
{
	if (!root) return NULL;
	if (root->left->data == x || root->right->data==x)
		return root;
	Tree* left = FindXParent(root->left,x);
	if (left != NULL) return left;
	Tree* right = FindXParent(root->right, x);
	if (right != NULL) return right;
}

int PrintXlevel(Tree* root,int x,int level)
{
	if (!root)return 0;
	if (root->data == x)return level;
	int left = PrintXlevel(root->left, x, level + 1);
	if (left != 0)return left;
	int right = PrintXlevel(root->right, x, level + 1);
	if (right != 0)return right;
}

bool isCom = true;
bool flag = false;//flag为true 说明层序遍历时出现过叶子 或者 只有左孩子的结点
//void visit(NODE* p)
//{
//	if (p->left == NULL && p->right == NULL) flag = true;
//	if (p->left == NULL && p->right != NULL)	isCom = false;
//	if (p->left != NULL && p->right == NULL)
//	{
//		if (flag) isCom = false;//已经出现过只有左孩子的结点，现在又出现一次 那么肯定不是完全二叉树
//		flag = true;
//	}
//	if (p->left != NULL && p->right != NULL)
//	{
//		if (flag) isCom = false;//当前有左右右 但是前面已经出现过叶子或者只有左孩子结点
//	}
//}

//void LevelOrder(Tree T)
//{
//	Queue Q; InitQueue(Q);
//	Tree P;
//	EnQueue(Q, T);
//	while (!isEmpty(Q))
//	{
//		DeQueue(Q, P);
//		visit(P);
//		if (P->left != NULL)
//			EnQueue(Q, P->left);
//		if (P->right != NULL)
//			EnQueue(Q, P->right);
//	}
//}

typedef struct Arcnode
{
	int adjvex;
	Arcnode* nextarc;
}Arcnode;
typedef struct Vexnode
{
	int data;
	Arcnode* firstarc;
}Vexnode;
typedef struct Graph
{
	Vexnode vextices[MAXSIZE];
	int vexnum; int edgenum;
}Graph;
int visited[MAXSIZE];
void DFS(Graph g,int i)
{
	visited[i] = 1;
	for (Arcnode* p = g.vextices[i].firstarc; p != NULL; p = p->nextarc)
	{
		int w = p->adjvex;
		if (!visited[w])
		{
			DFS(g, w);
		}
	}
}
int Count_connection(Graph g)
{
	int cnt = 0;
	for (int i = 0; i < g.vexnum; i++)visited[i] = 0;
	for (int i = 0; i < g.vexnum; i++)
	{
		if (!visited[i])
		{
			DFS(g, i);
			cnt++;
		}
	}
	return cnt;
}

int visited[MAXSIZE];
void DFS(Graph g, int i, int& VNUM, int& ENUM)
{
	visited[i] = 1;
	VNUM++;
	for (Arcnode* p = g.vextices[i].firstarc; p != NULL; p = p->nextarc)
	{
		int w = p->adjvex;
		ENUM++;
		if (!visited[w])
		{
			DFS(g, w, VNUM, ENUM);
		}
	}
}
bool isTree(Graph g)
{
	for (int i = 0; i < g.vexnum; i++)visited[i] = 0;
	int VNUM = 0; int ENUM = 0;
	DFS(g, 0, VNUM, ENUM);
	if (VNUM == g.vexnum && ENUM == 2*(g.vexnum - 1))
		return true;
	return false;
}

int out[MAXSIZE]; int in[MAXSIZE];
void DFS(Graph g)
{
	for (int i=0;i<g.vexnum;i++)
	{
		for (Arcnode* p = g.vextices[i].firstarc; p != NULL; p = p->nextarc)
		{
			int w = p->adjvex;
			out[i]++;
			in[w]++;
		}
	}
}
void PrintDegree3(Graph g)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		out[i] = in[i] = 0;
	}
	DFS(g);
	for (int i = 0; i < g.vexnum; i++)
	{
		if (out[i] == 3)
			printf("%d ", g.vextices[i].data);
	}
}

int visited[MAXSIZE];
bool Existitojwithk(Graph g, int i, int j, int k)
{
	if (i == j && k == 0) return true;
	if (k > 0)
	{
		visited[i] = 1;
		for (Arcnode* p = g.vextices[i].firstarc; p != NULL; p = p->nextarc)
		{
			int w = p->adjvex;
			if (!visited[w])
			{
				if (Existitojwithk(g, w, j, k - 1))
					return true;
			}
		}
		visited[i] = 0;
	}
	return false;
}

int visited[MAXSIZE];
bool Existitoj(Graph g, int i, int j)
{
	if (i == j)return true;
	visited[i] = 1;
	for (Arcnode* p = g.vextices[i].firstarc; p != NULL; p = p->nextarc)
	{
		int w = p->adjvex;
		if (!visited[w])
		{
			if (Existitoj(g, w, j))
				return true;
		}
	}
	visited[i] = 0;
	return false;
}

typedef struct G
{
	int vex[MAXSIZE];
	int edge[MAXSIZE][MAXSIZE];
	int vexnum; int edgenum;
}G;
int out[MAXSIZE]; int in[MAXSIZE];
void DFS(G g)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			if (g.edge[i][j] != 0)
			{
				out[i]++; in[j]++;
			}
		}
	}
}
void PrintDegree3(G g)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		out[i] = in[i] = 0;
	}
	DFS(g);
	for (int i = 0; i < g.vexnum; i++)
	{
		if (out[i] == 3)
			printf("%d ", g.vex[i]);
	}
}