#include "链表.h"
int main()
{
	SLTNode* phead = SListCreat();
	int x, y;
	while (1)
	{
		scanf("%d %d", &x, &y);//输入系数和指数
		if (x == 0)
		{
			break;
		}
		//尾插
		phead = SListPushBack(&phead, x, y);
	}
	SLTNode* phead2 = SListCreat();
	int x2, y2;
	while (1)
	{
		scanf("%d %d", &x2, &y2);//输入系数和指数
		if (x2 == 0)
		{
			break;
		}
		//尾插
		phead2 = SListPushBack(&phead2, x2, y2);
	}
	//输出多项式
	SListPrintf(phead); SListPrintf(phead2);
	//多项式相加
	SLTNode* phead3 = SListAdd(phead, phead2);
	SListPrintf(phead3);
	//多项式相减
	SLTNode* phead4 = SListJian(phead, phead2);
	SListPrintf(phead4);
}