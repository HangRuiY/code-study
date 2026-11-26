#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef  int SLDatatype;
typedef struct SeqList
{
	SLDatatype* data;
	SLDatatype sz;//表示存储多少个有效数据
	int capacity; //记录当前通讯录最大容量

}SeqList;
void SeqListInit(SeqList* p); //初始化
void SeqListCheck(SeqList* p);
void SeqListPrint(SeqList* p);//打印 
void SeqListDestroy(SeqList* p);//销毁
void SeqListPushBack(SeqList* p, SLDatatype x); //尾插
void SeqListPopBack(SeqList* p);//尾删
void SeqListPushFront(SeqList* p, SLDatatype x);//头插
void SeqListPopFront(SeqList* p);//头删
void SeqListFind(SeqList* p,SLDatatype x);//查找位置 返回下标
void SeqListInsert(SeqList* p, int pos, SLDatatype x);
void SeqListErase(SeqList* p, int pos);