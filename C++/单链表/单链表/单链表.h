#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//链表的声明
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//打印链表
void SListPrint (SLTNode* phead);
//尾插法
void SListPushBack(SLTNode** phead,SLTDataType x);
//头插法
void SListPushFront(SLTNode** phead, SLTDataType x);
//尾删法
void SListPopBack(SLTNode** phead);
//头删法
void SListPopFront(SLTNode** phead);

//查找并且修改数据
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos位置之后插入一个节点
void SlistInsertAfter(SLTNode* pos, SLTDataType x);

//在pos位置之前插入一个节点
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);

//删除pos位置
void SListErase(SLTNode** phead, SLTNode* pos);

//删除pos的下一个位置
void SListEraseAfter(SLTNode* pos);

//销毁并且制空链表
void SListDestroy(SLTNode** phead);
