#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
//测试数据:
//ABC##DE#G##F###
typedef struct Tree
{
	char data;
	struct Tree* left;
	struct Tree* right;
}T;
void Creat(T** t) 
{
	char c;
	cin >> c;
	if (c == '#')
		(*t) = NULL;
	else
	{
		if (*t = (T*)malloc(sizeof(T)))
		{
			(*t)->data = c;
			Creat(&(*t)->left);
			Creat(&(*t)->right);
		}
	}
}
void Preorder(T* T) //先序打印
{
	if (T)
	{
		printf("%c", T->data);
		Preorder(T->left);
		Preorder(T->right);
	}
}
void Inorder(T* T) //中序遍历
{
	if (T) 
	{
		Inorder(T->left);
		printf("%c", T->data);
		Inorder(T->right);
	}
}
void Postorder(T* T) //后序遍历
{
	if (T) 
	{
		Postorder(T->left);
		Postorder(T->right);
		printf("%c", T->data);
	}
}
int depth = 0;
void Depth(T* T,int h)//求高度
{
	if (T)
	{
		if (h > depth)
			depth = h;
		Depth(T->left, h + 1);
		Depth(T->right, h + 1);
	}
}
void PrintTree(T* T, int h)
{
	if(!T)
		return;
	PrintTree(T->right, h + 1);//打印右子树
	for (int i = 1; i <= h; i++)
	{
		cout << " ";
	}
	cout << T->data << endl;
	PrintTree(T->left, h + 1);
}
int cnt = 0;
void Leaf(T* T)
{
	if (T)
	{
		Leaf(T->left);
		if (T->left == NULL && T->right == NULL)
		{
			cnt++;
		}
		Leaf(T->right);
	}
}
int main()
{
	T* tree = NULL;
    Creat(&tree);
	Depth(tree, 1);//只有一个根结点，只有一层
	cout << "树的高度为:>" << depth << endl;
	cout << "树状打印为:>" << endl;
	PrintTree(tree, 1);
	cout << "先序序列为:>"; Preorder(tree); cout << endl;
	cout << "中序序列为:>"; Inorder(tree); cout << endl;
	cout << "后序序列为:>"; Postorder(tree); cout << endl;
	Leaf(tree);
	cout << "树中叶子结点的个数为:>" << cnt << endl;

}

//由后序和中序生成先序序列
//typedef struct Node 
//{
//    int data; 
//    struct Node* left; 
//    struct Node* right; 
//} Node;
//Node* buildTree(int* postOrder, int* inOrder, int len)
//{
//    if (postOrder == NULL || inOrder == NULL || len <= 0) 
//    {
//        return NULL;
//    }
//    //将后序遍历的最后一个元素赋值
//    Node* root = (Node*)malloc(sizeof(Node));
//    root->data = postOrder[len - 1];
//    //在中序遍历中找到根节点的位置
//    int pos = 0;
//    while (inOrder[pos] != root->data) 
//    {
//        pos++;
//    }
//    //传入后序遍历和中序遍历的左子树部分和右子树部分
//    root->left = buildTree(postOrder, inOrder, pos);
//    root->right = buildTree(postOrder + pos, inOrder + pos + 1, len - pos - 1);
//    return root;
//}
//void preOrder(Node* root) 
//{
//    if (root == NULL) 
//    {
//        return;
//    }
//    printf("%d ", root->data);
//    preOrder(root->left);
//    preOrder(root->right);
//}
//void PrintTree(Node* T, int h)
//{
//    if (!T)
//        return;
//    PrintTree(T->right, h + 1);//打印右子树
//    for (int i = 1; i <= h; i++)
//    {
//        cout << " ";
//    }
//    cout << T->data << endl;
//    PrintTree(T->left, h + 1);
//}
//int main() 
//{
//    int postOrder[] = { 4, 5, 2, 3, 1 };
//    int inOrder[] = { 4, 2, 5, 1, 3 };
//    Node* root = buildTree(postOrder, inOrder, sizeof(postOrder) / sizeof(int));
//    printf("先序遍历结果为:>\n");
//    preOrder(root);
//    printf("\n");
//    printf("树状打印为:>\n");
//    PrintTree(root, 1);
//    return 0;
//}