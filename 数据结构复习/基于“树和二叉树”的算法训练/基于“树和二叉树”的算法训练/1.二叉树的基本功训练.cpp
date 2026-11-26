#include <iostream>
using namespace std;
typedef struct NODE
{
	int data; int weight;
	struct NODE* left;
	struct NODE* right;
}NODE,*Tree;
#pragma region 求高度 宽度 带权WPL（先序遍历）
//求高度  递归从上到下传参
int height = 0;
void xianxu(Tree T,int n)//n从1开始  树高从1开始
{
	if (T != NULL)
	{
		height = max(height, n);
		xianxu(T->left,n+1);
		xianxu(T->right,n+1);
	}
}
//求高度 递归从下至上修改变量
int PreOrder(Tree T)
{
	if (T != NULL)
	{
		int l = PreOrder(T->left);
		int r = PreOrder(T->right);
		return l > r ? l + 1 : r + 1;
	}
	return 0;
}
//求宽度
int width[1010];//每一层有多少个结点 
void Xian(Tree T,int n)//n从0开始，树层从0开始
{
	if (T != NULL)
	{
		width[n]++;//第n层有几个结点
		Xian(T->left,n+1); Xian(T->right,n+1);
	}
}
int getWidth(Tree T)
{
	for (int i = 0; i < 1010; i++)	width[i] = 0;
	Xian(T, 0);//每一层几个结点
	int maxWidth = 0;
	for (int i = 0; i < 1010; i++)
	{
		maxWidth = max(maxWidth, width[i]);
	}
	return maxWidth;
}
//求WPL
int WPL = 0;
void getWPL(Tree T, int n)//路径长度和层数相同 从0开始
{
	if (T != NULL)
	{
		if (T->left == NULL && T->right == NULL)
			WPL += T->weight * n;
		Xian(T->left, n + 1); Xian(T->right, n + 1);
	}
}
#pragma endregion

#pragma region 判断是否为二叉排序树（中序遍历）
bool isBST = true;
int temp = 0;//temp为已访问过的最大的结点值
void Inorder(Tree T)
{
	if (T != NULL)
	{
		Inorder(T->left);//左子树
		if (T->data >= temp)//根>=左侧最大结点值
			temp = T->data;
		else
			isBST = false;//不满足 则不为排序树
		Inorder(T->right);//右子树
	}
}
#pragma endregion

#pragma region 判断是否为平衡二叉树（后序遍历）
bool isAVL = true;
int PostOrder(Tree T)
{
	if (T == NULL) return 0;
	int left = PostOrder(T->left);
	int right = PostOrder(T->right);
	if (abs(left - right) > 1) isAVL = false;
	return left > right ? left + 1 : right + 1;
}
#pragma endregion

#pragma region 判断是否为完全二叉树（层序遍历）
bool isCom = true;
bool flag = false;//flag为true 说明层序遍历时出现过叶子 或者 只有左孩子的结点
void visit(NODE* p)
{
	if (p->left == NULL && p->right == NULL) flag = true;
	if (p->left == NULL && p->right != NULL)	isCom = false;
	if (p->left != NULL && p->right == NULL)
	{
		if (flag) isCom = false;//已经出现过只有左孩子的结点，现在又出现一次 那么肯定不是完全二叉树
		flag = true;
	}
	if (p->left != NULL && p->right != NULL)
	{
		if (flag) isCom = false;//当前有左右右 但是前面已经出现过叶子或者只有左孩子结点
	}
}
void LevelOrder(Tree T)
{
	Queue Q; InitQueue(Q);
	Tree P;
	EnQueue(Q, T);
	while (!isEmpty(Q))
	{
		DeQueue(Q, P);
		visit(P);
		if (P->left != NULL)
			EnQueue(Q, P->left);
		if (P->right != NULL)
			EnQueue(Q, P->right);
	}
}
#pragma endregion

#pragma region 
int cnt = 0;
void leaf(Tree root)
{
	if (root)
	{
		if (root->left == NULL && root->right == NULL)
			cnt++;
		leaf(root->left);
		leaf(root->right);
	}
}
#pragma endregion

