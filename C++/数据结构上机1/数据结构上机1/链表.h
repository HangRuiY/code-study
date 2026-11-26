#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//链表的声明
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	SLTDataType num;
	struct SListNode* next;
}SLTNode;

//创建链表
SLTNode* SListCreat();
//创建新结点
SLTNode* CreatNewnode(SLTDataType x, SLTDataType n);
//尾插法
SLTNode* SListPushBack(SLTNode** pphead, SLTDataType n, SLTDataType x);
//头删法
SLTNode* SListPopFront(SLTNode** pphead);