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
//打印链表
void SListPrint(SLTNode* pphead);
////尾插法
SLTNode* SListPushBack(SLTNode** pphead, SLTDataType n, SLTDataType x);
//头插法
SLTNode* SListPushFront(SLTNode** pphead, SLTDataType x);
//尾删法
SLTNode* SListPopBack(SLTNode** pphead);
//头删法
SLTNode* SListPopFront(SLTNode** pphead);
//按值查找
SLTNode* SListFind(SLTNode* pphead, SLTDataType x);
//在pos位置之后插入一个节点
SLTNode* SlistInsertAfter(SLTNode** pphead,SLTNode* pos, SLTDataType x);
//在pos位置之前插入一个节点
SLTNode* SlistInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删除pos位置
SLTNode* SListErase(SLTNode** pphead, SLTNode* pos);
//链表逆置
SLTNode* ReverseList(struct ListNode** head);

//循环单链表
//创建
SLTNode* LoopSListCreat();
//头插
SLTNode* Head_Insert(SLTNode* head, int x);
//尾插
void Tail_Insert(SLTNode* tail, int x, SLTNode* head);
//合并两个循环链表
void Merge_LoopList(SLTNode* ta, SLTNode* tb);
//打印
void LoopListPrint(SLTNode* head, int n);
