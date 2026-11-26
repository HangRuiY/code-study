//#include "链表.h"
//void test1()
//{
//	SLTNode* phead = SListCreat();
//	//头插
//	phead = SListPushFront(&phead, 1);
//	phead = SListPushFront(&phead, 2);
//	phead = SListPushFront(&phead, 3);
//	phead = SListPushFront(&phead, 1);
//	phead = SListPushFront(&phead, 2);
//	phead = SListPushFront(&phead, 3);
//	//打印
//	SListPrint(phead);
//	printf("\n");
//	//头删
//	phead = SListPopFront(&phead);
//	SListPrint(phead);
//	printf("\n");
//	//按值查找
//	//phead = SListFind(phead, 1);
//}
//void test2()
//{
//	SLTNode* phead = SListCreat();
//	//尾插
//	phead = SListPushBack(&phead, 1);
//	phead = SListPushBack(&phead, 2);
//	phead = SListPushBack(&phead, 3);
//	phead = SListPushBack(&phead, 1);
//	phead = SListPushBack(&phead, 2);
//	phead = SListPushBack(&phead, 3);
//	//打印
//	SListPrint(phead);
//	printf("\n");
//	//尾删
//	phead = SListPopBack(&phead);
//	SListPrint(phead);
//	printf("\n");
//}
//void test3()
//{
//	SLTNode* phead = SListCreat();
//	//尾插
//	phead = SListPushBack(&phead, 1);
//	phead = SListPushBack(&phead, 2);
//	phead = SListPushBack(&phead, 3);
//	phead = SListPushBack(&phead, 1);
//	phead = SListPushBack(&phead, 2);
//	phead = SListPushBack(&phead, 3);
//	//查找
//	SLTNode* pos = SListFind(phead, 2);
//	int i = 1;
//	while (pos!=NULL)
//	{
//		printf("第%d个pos节点：%p %d\n", i++, pos, pos->data); //可以计算有几个'x'
//		pos = SListFind(pos->next, 2);
//	}
//	SListPrint(phead);
//}
//void test4()
//{
//	SLTNode* phead = SListCreat();
//	//尾插
//	phead = SListPushBack(&phead, 1);
//	phead = SListPushBack(&phead, 2);
//	phead = SListPushBack(&phead, 3);
//	phead = SListPushBack(&phead, 4);
//	phead = SListPushBack(&phead, 5);
//	phead = SListPushBack(&phead, 6);
//	//在pos之后插入一个
//	SLTNode* pos = SListFind(phead, 4);
//	phead = SlistInsertAfter(&phead, pos, 9);
//	SListPrint(phead);
//	//在pos之前插入一个
//	phead = SlistInsert(&phead, pos, 10);
//	SListPrint(phead);
//	//删除pos位置
//	phead = SListErase(&phead, pos);
//	SListPrint(phead);
//}
//void test5()
//{
//	SLTNode* phead = SListCreat();
//	//尾插
//	phead = SListPushBack(&phead, 1);
//	phead = SListPushBack(&phead, 2);
//	phead = SListPushBack(&phead, 3);
//	phead = SListPushBack(&phead, 4);
//	phead = SListPushBack(&phead, 5);
//	phead = SListPushBack(&phead, 6);
//	SListPrint(phead);
//	//单链表逆置
//	phead = ReverseList(phead);
//	SListPrint(phead);
//}
//void test6()
//{
//	SLTNode* ahead, * bhead, * atail, * btail;
//	ahead = atail = LoopSListCreat();
//	bhead = btail = LoopSListCreat();
//	atail = Head_Insert(ahead, 1);
//	Head_Insert(ahead, 2);
//	Head_Insert(ahead, 3);
//	Head_Insert(ahead, 4);
//	LoopListPrint(ahead, 4);
//	puts("\n");
//	btail = Head_Insert(bhead, 5);
//	Head_Insert(bhead, 6);
//	Head_Insert(bhead, 7);
//	Head_Insert(bhead, 8);
//	LoopListPrint(bhead, 4);
//	Merge_LoopList(atail, btail);
//	puts("\n");
//	LoopListPrint(ahead, 8);
//}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	test6();
//}

//#include "链表.h"
//int main()
//{
//	int n, m;
//	int cnt = 0;
//	scanf("%d %d", &n, &m);
//	SLTNode* p = SListCreat();
//	for (int i = 1; i <= n; i++)
//	{
//		int x;
//		scanf("%d", &x);
//		p = SListPushBack(&p,i,x);
//	}
//	while (p->next != NULL)
//	{
//		int k = p->next->data;
//		int pn = p->next->num;
//		p = SListPopFront(&p);
//		cnt++;
//		if (cnt == m)
//		{
//			printf("%d ", pn);
//			m = k;
//			cnt = 0;
//		}
//		else
//		{
//			p = SListPushBack(&p, pn, k);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int n, m;
//int a[1010];
//int b[1010];
//int main()
//{
//	int cnt = 0; int k = 1;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (++cnt > n)
//			{
//				cnt = 1;
//			}
//			if (a[cnt] == 1)
//			{
//				j--;
//			}
//		}
//		printf("%d ", cnt);
//		a[cnt] = 1;
//	}
//}

