#include "链表.h"
//创建链表
SLTNode* SListCreat()
{
	SLTNode* head = (SLTNode*)malloc(sizeof(SLTNode));
	if (head == NULL)
	{
		return NULL;
	}
	head->zhi = -1;
	head->next = NULL;
	return head;
}
//创建新节点
SLTNode* CreatNewnode(SLTFloatType n, SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->xi = n;
	newnode->zhi = x;
	newnode->next = NULL;
	return newnode;
}
//尾插法
SLTNode* SListPushBack(SLTNode** pphead, SLTFloatType n, SLTDataType x)
{
	SLTNode* newnode = CreatNewnode(n, x);
	if ((*pphead)->next == NULL)
	{
		(*pphead)->next = newnode;
		return *pphead;
	}
	SLTNode* tail = (*pphead)->next;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
	return *pphead;
}
//打印链表
void SListPrint(SLTNode* pphead)
{
	if (pphead->next == NULL)
	{
		printf("链表为空\n");
		return;
	}
	SLTNode* cur = pphead->next;
	while (cur != NULL)
	{
		printf("(%f,%d)->", cur->xi,cur->zhi);
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("NULL\n");
	}
}
//输出多项式
void SListPrintf(SLTNode* pphead)
{
	SLTNode* cur = pphead->next;
	int flag = 1;
	if (cur == NULL)
	{
		printf("0\n");
		return;
	}
	while (cur)
	{
		if (cur->xi > 0 && flag != 1)
		{
			printf("+");
		}
		if (cur->xi != 1 && cur->xi != -1)
		{
			printf("%.0f", cur->xi);
			if (cur->zhi == 1)
				printf("x");
			else if (cur->zhi)
				printf("x^%d", cur->zhi);
		}
		else
		{
			if (cur->xi == 1)
			{
				if (!cur->zhi)
					printf("1");
				else if (cur->zhi == 1)
					printf("x");
				else
					printf("x^%d", cur->zhi);
			}
			if (cur->xi == -1)
			{
				if (!cur->zhi)
					printf("-1");
				else if (cur->zhi == 1)
				{
					printf("-x");
				}
				else
					printf("-x^%d", cur->zhi);
			}
		}
		cur = cur->next;
		flag++;
	}
	printf("\n");
}
//多项式相加
SLTNode* SListAdd(SLTNode* phead1, SLTNode* phead2)
{
	SLTNode* pa = phead1->next;
	SLTNode* pb = phead2->next;
	SLTNode* head3, *phead3, *newnode;
	phead3 = (SLTNode*)malloc(sizeof(SLTNode));
	phead3->next = NULL;
	head3 = phead3;
	while (pa != NULL && pb != NULL)
	{
		newnode = (SLTNode*)malloc(sizeof(SLTNode));
		if (pa->zhi < pb->zhi)
		{
			newnode->xi = pa->xi;
			newnode->zhi = pa->zhi;
			pa = pa->next;
		}
		else if (pa->zhi == pb->zhi)
		{
			newnode->xi = pa->xi + pb->xi;
			newnode->zhi = pa->zhi;
			pa = pa->next;
			pb = pb->next;
		}
		else
		{
			newnode->xi = pb->xi;
			newnode->zhi = pb->zhi;
			pb = pb->next;
		}
		if (newnode->xi != 0)
		{
			newnode->next = phead3->next;
			phead3->next = newnode;
			phead3 = newnode;
		}
		else
			free(newnode);
	}
	while (pa != NULL)
	{
		newnode = (SLTNode*)malloc(sizeof(SLTNode));
		newnode->xi = pa->xi;
		newnode->zhi = pa->zhi;
		pa = pa->next;
		newnode->next = phead3->next;
		phead3->next = newnode;
		phead3 = newnode;
	}
	while (pb != NULL)
	{
		newnode = (SLTNode*)malloc(sizeof(SLTNode));
		newnode->xi = pb->xi;
		newnode->zhi = pb->zhi;
		pb = pb->next;
		newnode->next = phead3->next;
		phead3->next = newnode;
		phead3 = newnode;
	}
	return head3;
}
//多项式相减
SLTNode* SListJian(SLTNode* phead1, SLTNode* phead2)
{
	SLTNode* head4 = phead2;
	SLTNode* cur = phead2->next;
	SLTNode* pc;
	while (cur)
	{
		cur->xi *= -1;
		cur = cur->next;
	}
	pc = SListAdd(phead1, head4);
	for (cur = head4->next; cur != NULL; cur = cur->next)
	{
		cur->xi *= -1;
	}
	return pc;
}