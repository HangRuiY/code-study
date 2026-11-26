#include <iostream>
using namespace std;
#pragma region 2014_41题，即26王道书 5.3.3_大题_15
//求二叉树带权路径长度WPL 根为root
//思想：采用先序遍历，全局变量WPL，传入层数参数n，n从0开始，每个叶子结点是路径长就是结点的层数
typedef struct NODE
{
	int data; int weight;
	struct NODE* left;
	struct NODE* right;
}NODE, * Tree;
int WPL = 0;
void PreOrder(Tree root, int n)
{
	if (root == NULL) return;
	//访问结点
	if (root->left == root->left == NULL)//是叶子结点
		WPL += root->weight * n;
	PreOrder(root->left, n + 1);
	PreOrder(root->right, n + 1);
}
#pragma endregion

#pragma region 2017_41题，即26王道书 5.3.3_大题_16
//给定表达式二叉树，转换为等价的中缀式，通过括号反应计算次序
//思想：采用中序遍历，叶子结点是操作数，非叶是操作符，对于叶子结点，直接输出操作数。 注意到 各个根节点都是操作符
//      对于深度大于1（不是主根）的那些非叶结点，输出左括号，之后递归遍历左子树，然后输出操作符，之后遍历右子树。在结尾输出右括号
typedef struct node
{
	char data[10];
	struct node* left;
	struct node* right;
}node, * BTree;
void BTreeToExp(BTree T, int deep)//传入deep初始为1
{
	if (T == NULL) return;
	if (T->left == T->right == NULL) cout << T->data;//叶子结点 直接输出操作数
	else
	{
		if (deep > 1)//是非根的分支节点
			cout << "(";
		BTreeToExp(T->left, deep + 1);
		cout << T->data;
		BTreeToExp(T->right, deep + 1);
		if(deep > 1)//是非根的分支节点
			cout << ")";
	}
}
#pragma endregion

#pragma region 2022_41题，即26王道书5.3.3_大题_17
//结点值都是正整数，不存在用-1表示   判定是否为二叉搜索树
//思想：数组下标从0开始，i号结点 左孩子2i+1 右孩子2i+2  父结点为(i-1)/2
//		数组下标从1开始，i号结点 左孩子2i 右孩子2i+1 父结点i/2
//      二叉搜索树：结点i大于左子树全部 小于右子树全部 则需要中序遍历
//		用temp变量标记当前访问过的最大结点值 如果遍历到根结点时，发现temp大于等于根的值 则一定不是，否则更新temp的值
typedef struct
{
	int SqBiTNode[1010];//二叉树结点值数组
	int ElemNum;//实际占用的数组元素个数
}SeqTree;
bool isSearch = true;
int temp = 0;
bool Search(SeqTree t,int i)//i从0开始 即从根开始
{
	if (t.SqBiTNode[i] == -1) return false;//空结点 直接返回
	if (i >= t.ElemNum) return false;//过界 直接返回
	if (!Search(t, 2 * i + 1))//判断左子树
		return false;
	if (t.SqBiTNode[i] > temp)	temp = t.SqBiTNode[i];//如果当前结点值比已经访问过的都要大 则符合搜索树条件 更新temp的值
	else return false;//反之 不符合
	if (!Search(t, 2 * i + 2))//判断右子树
		return false;
	return true;
}
#pragma endregion

