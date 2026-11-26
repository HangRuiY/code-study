#include "AVL.h"
AT* MakeEmpty(AT* T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
	}
	return NULL;
}
void TPrint(AT* p)
{
	if (p == NULL)
	{
		printf("树为空\n");
		return;
	}
	//左子树
	if (p->left != NULL)
	{
		TPrint(p->left);
	}
	//根节点
	printf("数据的值为:%d\n", p->data);
	//右子树
	if (p->right != NULL)
	{
		TPrint(p->right);
	}
}
AT* Find(int x, AT* T)
{
	if (T == NULL)
		return NULL;
	if (x > T->data)
	{
		return Find(x, T->right);
	}
	else if (x < T->data)
	{
		return Find(x, T->left);
	}
	else
		return T;
}
AT* FindMin(AT* T)
{
	if (T == NULL)
		return NULL;
	else if (T->left == NULL) //左子树为空 
	{
		return T;
	}
	else//左子树不为空
	{
		return FindMin(T->left);
	}
}
AT* FindMax(AT* T)
{
	if (T == NULL)
		return NULL;
	else if (T->right == NULL) //右子树为空 
	{
		return T;
	}
	else//右子树不为空
	{
		return FindMin(T->right);
	}
}
AT* Insert(int x, AT* T)
{
	if (T == NULL)
	{
		T = (AT*)malloc(sizeof(AT));
		assert(T != NULL);
		T->data = x; T->height = 0; T->left = T->right = NULL;
	}
	else if (x < T->data)
	{
		T->left = Insert(x, T->left);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (x < T->left->data)
				T = SingleLeft(T);
			else
				T = DoubleLeft(T);
		}
	}
	else if (x > T->data)
	{
		T->right = Insert(x, T->right);
		if (Height(T->right) - Height(T->left) == 2)
		{
			if (x > T->right->data)
				T = SingleRight(T);
			else
				T = DoubleRight(T);
		}
	}
	T->height = max(Height(T->right), Height(T->left)) + 1;
	return T;
}
int Height(AT* T)
{
	if (T == NULL)
		return -1;
	else
		return T->height;
}
AT* SingleLeft(AT* k2)
{
	AT* k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = max(Height(k1->left), Height(k1->right)) + 1;
	return k1;

}
AT* SingleRight(AT* k2)
{
	AT* k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = max(Height(k1->left), Height(k1->right)) + 1;
	return k1;
}
AT* DoubleLeft(AT* k3)
{
	k3->left = SingleRight(k3->left);
	return SingleLeft(k3);
}
AT* DoubleRight(AT* k3)
{
	k3->right = SingleLeft(k3->right);
	return SingleRight(k3);
}