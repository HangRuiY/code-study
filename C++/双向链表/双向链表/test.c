#include "DL.h"
//初始化
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
    phead->next = phead;
	phead->prev = phead;
	return phead;
}
//节点
LTNode* Buynode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//打印
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while(cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = Buynode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
//	ListInsert(phead, x);
}
//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);//链表为空 不能删除
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	//ListErase(phead->prev);
}
//头插
void ListPushFront(LTNode* phead, LTDataType x)
{
	LTNode* newnode = Buynode(x);
	LTNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
	//ListInsert(phead->next, x);
}
//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next;
	LTNode* nextNext = next->next;
	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
	//ListErase(phead->next);
}
//查找
LTNode* ListFind(LTNode* phead,LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
			cur = cur->next;
	}
	return NULL;
}
//在pos位置之前插入
LTNode* ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* newnode = Buynode(x);
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除pos位置
LTNode* ListErase(LTNode* pos)
{
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}
//销毁
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead);
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
	printf("已制空");
}