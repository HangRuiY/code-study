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
		printf("%d->", cur->data);
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("NULL\n");
	}
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
//头插
SLTNode* SListPushFront(SLTNode** pphead, SLTDataType x)
{
    SLTNode* newnode = CreatNewnode(x,0);
	newnode->next = (*pphead)->next;
	(*pphead)->next = newnode;
	return *pphead;
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
	SLTNode* newnode = CreatNewnode(x,n);
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
//尾删
SLTNode* SListPopBack(SLTNode** pphead)
{
	if ((*pphead)->next == NULL)
	{
		printf("链表为空\n");
		return NULL;
	}
	SLTNode* prev = NULL;
	SLTNode* tail = (*pphead)->next;
	while (tail->next->next != NULL)
	{
		tail = tail->next;
	}
	prev = tail;
	free(tail->next);
	prev->next = NULL;
	return *pphead;
}
//按值查找
SLTNode* SListFind(SLTNode* pphead, SLTDataType x)
{
	SLTNode* cur = pphead->next;
	while (cur!=NULL && cur->data!=x)
	{
		cur = cur->next;
	}
	return cur;
}
//在pos位置之后插入一个节点
SLTNode* SlistInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos != NULL);
	SLTNode* newnode = CreatNewnode(x,0);
	SLTNode* tail = pos->next;
	pos->next = newnode;
	newnode->next = tail;
	return *pphead;
}
//在pos位置之前插入一个节点
SLTNode* SlistInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos != NULL);
	SLTNode* newnode = CreatNewnode(x,0);
	if (pos == (*pphead)->next)
	{
		newnode->next = (*pphead)->next;
		(*pphead)->next = newnode;
		return *pphead;
	}
	//找到pos的前一个节点
	SLTNode* posprev = (*pphead)->next;
	while (posprev->next != pos)
	{
		posprev = posprev->next;
	}
	posprev->next = newnode;
	newnode->next = pos;
	return *pphead;
}
//删除pos位置
SLTNode* SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos != NULL);
	if (pos == (*pphead)->next)
	{
		SLTNode* temp = (*pphead)->next->next;
		free((*pphead)->next);
		(*pphead)->next = temp;
		return *pphead;
	}
	SLTNode* prev = (*pphead)->next;
	while (prev->next != pos)
	{
		prev = prev->next; //往后走
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
	return *pphead;
}
//链表逆置
SLTNode* ReverseList(SLTNode* head)
{
	SLTNode* cur = head->next;
	SLTNode* newhead = NULL;
	while (cur!=NULL)
	{
		SLTNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	head->next = newhead;
	return head;
}
//创建循环单链表
SLTNode* LoopSListCreat()
{
	SLTNode* head = (SLTNode*)malloc(sizeof(SLTNode));
	head->next = head;
	return head;
}
//头插
SLTNode* Head_Insert(SLTNode* head, int x)
{
	SLTNode* p = (SLTNode*)malloc(sizeof(SLTNode));
	p->data = x;
	p->next = head->next;
	head->next = p;
	return p;
}
//尾插
void Tail_Insert(SLTNode* tail, int x, SLTNode* head)
{
	SLTNode* p = (SLTNode*)malloc(sizeof(SLTNode));
	p->data = x;
	p->next = head;
	tail->next = p;
	tail = p;
}
//拼接
void Merge_LoopList(SLTNode* ta, SLTNode* tb)
{
	SLTNode* p = ta->next;
	ta->next = tb->next->next;
	free(tb->next);
	tb->next = p;
}
//打印
void LoopListPrint(SLTNode* head, int n)
{
	SLTNode* p = head;
	for (int i = 1; i <= 2 * (n + 1); i++, p = p->next)
	{
		if (p != head)
		{
			printf("%d", p->data);
			if (i != 2 * n + 2)
			{
				printf("->");
			}
		}

	}
}