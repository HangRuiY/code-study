#include "单链表.h"
//打印链表
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}
//建立新的节点函数
SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) //判断是否为空指针
		return NULL;
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	return newnode;
}
//尾插法
void SListPushBack(SLTNode** phead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);

	if (*phead == NULL)   //如果*phead为空指针，则让新的节点当作起始
	{
		*phead = newnode;
	}
	else
	{
		//找到尾节点
		SLTNode* tail = *phead;  //从头开始找尾
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

//头插法
void SListPushFront(SLTNode** phead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	if (newnode == NULL)
		return;
	else
	{
		newnode->next = *phead;
		*phead = newnode;//把一个结构体指针的地址(节点) 存放到*phead这个指针变量去
	}
}

//尾删法
void SListPopBack(SLTNode** phead)
{
	assert(*phead != NULL);
	if ((*phead)->next == NULL) //*phead就是第一个
	{
		free(*phead);
		*phead = NULL;

	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *phead; //从头开始找尾
		/*while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail); 
		tail = NULL;
		prev->next = NULL;*/
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
	

}

//头删法
void SListPopFront(SLTNode** phead)
{
	assert(*phead != NULL);
	SLTNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}

//查找并修改
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead; //遍历链表
	while (cur)
	{
		if (cur->data == x)  //找到了，返回这个节点
			return cur; 
		else
			cur = cur->next; //没找到，赋值为next;
	}
	return NULL; //没找到返回NULL
}

//在pos位置之前插入一个节点
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
	assert(*phead != NULL);
	SLTNode* newnode = BuyListNode(x);
	if (pos == *phead)//查找到的节点就是头节点
	{
		//头插
		newnode->next = pos;
		*phead = newnode;
	}
	else
	{
		//找到pos的前一个节点
		SLTNode* posprev = *phead;
		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}
		posprev->next = newnode;
		newnode->next = pos;
	}
}

//在pos位置之后插入一个节点 不需要考虑头为pos  更为常用!!!!!!!!!
void SlistInsertAfter(SLTNode* pos, SLTDataType x)//插入的数字
{
	SLTNode* newnode = BuyListNode(x);
	/*newnode->next = pos->next;
	pos->next = newnode;*/
	SLTNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}

//删除pos位置
void SListErase(SLTNode** phead, SLTNode* pos)
{
	if (pos == *phead)
	{
		//头删
		*phead = pos->next;
		free(pos);
		pos = *phead;
	}
	else
	{
		SLTNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next; //往后走
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos的后一个位置
void SListEraseAfter(SLTNode* pos)
{
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SListDestroy(SLTNode** phead)
{
	assert(phead!=NULL);
	SLTNode* cur = *phead;
	while(cur!= NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	*phead = NULL;
	printf("销毁成功");
}