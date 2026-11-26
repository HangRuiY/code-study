#pragma once
#include "list.h"
void SeqListInit(SeqList* p)
{
	p->data = NULL;
	p->sz = 0;
	p->capacity = 0;
}
void SeqListCheck(SeqList* p)
{
	if (p->sz == p->capacity)  //考虑增容
	{
		int newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		SeqList* str = realloc(p->data, newcapacity * sizeof(SLDatatype));
		if (str == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		else
		{
			p->data = str;
			p->capacity = newcapacity;
		}
	}
}

//打印
void SeqListPrint(SeqList* p)
{
	for (int i = 0; i < p->sz; i++)
	{
		printf("%d ", p->data[i]);
	}
	printf("\n");
}
//销毁
void SeqListDestroy(SeqList* p)
{
	free(p->data);
	p->data = NULL;
	p->sz = p->capacity = 0;
}
//尾插
void SeqListPushBack(SeqList* p, SLDatatype x)
{
	SeqListCheck(p);
	*(p->data+(p->sz)) = x;
	p->sz++;
}
//尾删
void SeqListPopBack(SeqList* p)
{
	assert(p->sz > 0);
	p->sz--;
}
//头插
void SeqListPushFront(SeqList* p, SLDatatype x)
{
	SeqListCheck(p);
	int end = p->sz - 1;
	while (end >= 0)
	{
		p->data[end + 1] = p->data[end];
		end--;
	}
	p->data[0] = x;
	p->sz++;
}
//头删
void SeqListPopFront(SeqList* p)
{
	assert(p->sz > 0);
	int begin = 1;
	while (begin < p->sz)
	{
		p->data[begin - 1] = p->data[begin];
		begin++;
	}
	p->sz--;
}
//查找
void SeqListFind(SeqList* p, SLDatatype x)
{
	int i = 0; int flag = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (p->data[i] == x)
		{
			printf("这个数据的下标是%d\n", i);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("没有找到此数据\n");
}
//在pos位置添加
void SeqListInsert(SeqList* p, int pos, SLDatatype x)
{
	assert(pos >= 0 || pos <= p->sz);
	SeqListCheck(p);
	int end = p->sz - 1;
	while (end >= pos)
	{
		p->data[end + 1] = p->data[end];
		end--;
	}
	p->data[pos] = x;
	p->sz++;
}
//删除pos位置
void SeqListErase(SeqList* p, int pos)
{
	assert(pos >= 0 || pos <= p->sz);
	int begin = pos + 1;
	while (begin < p->sz) // 1 1 1 2 3 5
	{
		p->data[begin - 1] = p->data[begin];
		begin++;
	}
	p->sz--;
}
