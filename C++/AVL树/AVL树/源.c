#include "AVL.h"
int main()
{
	AT* root;
	root = Insert(6, NULL);
	Insert(4, root);
	Insert(5, root);
	Insert(3, root);
	Insert(7, root);
	TPrint(root);

	//查找某一个节点
	AT* node = Find(3, root);
	printf("找到的是:%d\n", node->data);

	//找最小
	AT* Min = FindMin(root);
	printf("最小的是:%d\n", Min->data);
	//找最大
	AT* Max = FindMax(root);
	printf("最大的是:%d\n", Max->data);

	root = MakeEmpty(root);
	TPrint(root);
	return 0;
}