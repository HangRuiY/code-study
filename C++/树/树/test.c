#include "tree.h"
T* MakeEmpty(T* p)
{
	if (p != NULL)
	{
		MakeEmpty(p->left);
		MakeEmpty(p->right);
	}
	return NULL;
}
T* Find(int x, T* p)
{
	if (p == NULL)
		return NULL;
	if (x > p->data)
	{
		return Find(x, p->right);
	}
	else if (x < p->data)
	{
		return Find(x, p->left);
	}
	else
		return p;
}
T* FindMin(T* p)
{
	if (p == NULL)
		return NULL;
	else if (p->left==NULL) //左子树为空 
	{
		return p;
	}
	else//左子树不为空
	{
		return FindMin(p->left);
	}
}
T* FindMax(T* p)
{
	if (p == NULL)
		return NULL;
	else if (p->right == NULL) //右子树为空 
	{
		return p;
	}
	else//右子树不为空
	{
		return FindMin(p->right);
	}
}
T* TInsert(int x,T* p)
{
	if (p == NULL) //根节点
	{
		p = (T*)malloc(sizeof(T));
		assert(p);
		p->data = x;
		p->left = p->right = NULL;
	}
	else if (p->data > x)
	{
		p->left = TInsert(x, p->left);
	}
	else if (p->data < x)
	{
		p->right = TInsert(x, p->right);
	}
	return p;
}
T* TDelete(int x, T* p)
{
	T* tmp;
	if (p == NULL)
	{
		printf("树为空\n");
	}
	else if (x < p->data)
	{
		p->left = TDelete(x, p->left);
	}
	else if (x > p->data)
	{
		p->right = TDelete(x, p->right);
	}
	else if (p->left && p->right)//两个儿子
	{
		tmp = FindMin(p->right);
		p->data = tmp->data;
		p->right = TDelete(p->data, p->right);
	}
	else //没有或只有一个儿子
	{
		tmp = p;
		if (p->left == NULL)
		{
			p = p->right;
		}
		else if (p->right == NULL)
		{
			p = p->left;
		}
		free(tmp);
	}
	return p;
}
void TPrint(T* p)//中序打印
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