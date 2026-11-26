#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
	QueueNode* head; //队头 删除
	QueueNode* tail; //队尾 插入
}Queue;
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq,QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);//取队头的数据
QDataType QueueBack(Queue* pq);//取队尾的数据
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
