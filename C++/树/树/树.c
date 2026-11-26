//树：平均时间复杂度是O(logN)
//每一棵树是由一个根节点(root)和0个或者若干个非空的子树组成
//每一个树由N个节点和N-1个边组成，没有儿子的节点称之为叶节点,具有相同父亲的节点称之为兄弟节点
#include "tree.h"
int main()
{
	T* root;//根节点
	root = TInsert(6, NULL);
	TInsert(4, root);
	TInsert(1, root);
	TInsert(8, root);
	TInsert(3, root);
	TInsert(2, root);
	TPrint(root);

	////查找某一个节点
	//T* node = Find(4, root);
	//printf("找到的是:%d\n", node->data);

	////找最小
	//T* Min = FindMin(root);
	//printf("最小的是:%d\n", Min->data);
	////找最大
	//T* Max = FindMax(root);
	//printf("最大的是:%d\n", Max->data);

	////删除一个节点
	//TDelete(6, root);
	//TPrint(root);
	////清空
	//root=MakeEmpty(root);
	//TPrint(root);
}