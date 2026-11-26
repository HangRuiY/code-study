#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//链表的声明
typedef float SLTFloatType;
typedef int SLTDataType;
typedef struct SListNode
{
	SLTFloatType xi;
	SLTDataType zhi;
	struct SListNode* next;
}SLTNode;
//创建链表
SLTNode* SListCreat();
//创建新结点
SLTNode* CreatNewnode(SLTFloatType n, SLTDataType x);
//尾插法
SLTNode* SListPushBack(SLTNode** pphead, SLTFloatType n, SLTDataType x);
//打印链表
void SListPrint(SLTNode* pphead);
//输出多项式
void SListPrintf(SLTNode* pphead);
//多项式相加
SLTNode* SListAdd(SLTNode* phead1, SLTNode* phead2);
//多项式相减
SLTNode* SListJian(SLTNode* phead1, SLTNode* phead2);