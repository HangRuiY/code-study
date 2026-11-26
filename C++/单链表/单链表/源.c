#include "单链表.h"
//头指针
//尾插
void test1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	
	SListPopBack(&plist);
	
	SListPrint(plist);
}
//头插
void test2()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);


	SListPrint(plist);
}
//头删
void test3()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist); 
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
}
//查找 并且 修改
void test4()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);

	//查找
	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个pos节点：%p %d\n", i++, pos, pos->data); //可以计算有几个'x'
		pos = SListFind(pos->next, 2);
	}
	//修改 
	pos = SListFind(plist, 3);
	if (pos != NULL)
	{
		pos->data = 30;
	}
	SListPrint(plist);
}
//在pos位置之前插入
void test5()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPrint(plist);
	 
	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist,pos,30);
	}
	SListPrint(plist);
	pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsert(&plist, pos, 50);
	}
	SListPrint(plist);
}
//在pos位置之后插入
void test6()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SlistInsertAfter(pos, 40);
	SListPrint(plist);
}
//删除pos节点
void test7()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode*pos=SListFind(plist, 3);
	SListErase(&plist, pos);
	SListPrint(plist);
}
//删除pos位置之后的节点
void test8()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);
	SListEraseAfter(pos);
	SListPrint(plist);
}
//摧毁链表
void test9()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListDestroy(&plist);
	SListPrint(plist);
}
int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	return 0;
}

//无哨兵位的尾插
//int main()
//{
//	SLTNode* p = NULL;
//	int n = 3;
//	for (int i = 0; i < 3; i++)
//	{
//		SLTNode* new = (SLTNode*)malloc(sizeof(SLTNode));
//		scanf("%d", &new->data);
//		new->next = NULL;
//		if (p == NULL)
//		{
//			p = new;
//		}
//		else
//		{
//			SLTNode* rear = p;
//			while (rear->next != NULL)
//			{
//				rear = rear->next;
//			}
//			rear->next = new;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d->", p->data);
//		p = p->next;
//	}
//	printf("NULL");
//	return 0;
//}


