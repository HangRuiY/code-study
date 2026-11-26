#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct SListNode* next;
	struct SListNode* prev;
}LTNode;

LTNode* ListInit();
void ListPushBack(LTNode* phead,LTDataType x);
void ListPrint(LTNode* phead);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);
LTNode* Buynode(LTDataType x);
LTNode* ListFind(LTNode* phead, LTDataType x);
LTNode* ListInsert(LTNode* pos, LTDataType x);
LTNode* ListErase(LTNode* pos);
void ListDestroy(LTNode* phead);