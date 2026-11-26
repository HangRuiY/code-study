#include "链表.h"
//创建链表
SLTNode* SListCreat()
{
	SLTNode* head = (SLTNode*)malloc(sizeof(SLTNode));
	if (head == NULL)
	{
		return NULL;
	}
	head->num = 0;
	head->next = NULL;
	return head;
}
//创建新结点
SLTNode* CreatNewnode(SLTDataType x, SLTDataType n)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->data = x;
	newnode->num = n;
	newnode->next = NULL;
	return newnode;
}
//头删
SLTNode* SListPopFront(SLTNode** pphead)
{
	if ((*pphead)->next == NULL)
	{
		printf("链表为空\n");
		return NULL;
	}
	SLTNode* temp = (*pphead)->next->next;
	free((*pphead)->next);
	(*pphead)->next = temp;
	return *pphead;
}
//尾插
SLTNode* SListPushBack(SLTNode** pphead, SLTDataType n, SLTDataType x)
{
	SLTNode* newnode = CreatNewnode(x, n);
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