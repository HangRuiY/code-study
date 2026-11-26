#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//225 队列实现栈
//1.入数据 往不为空的队列入 保证另一个队列为空
//2.出数据 一次出队头的数据，转移到另一个队列 只剩队尾的数据 删除
//typedef struct
//{
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//MyStack* myStackCreate()
//{
//    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&st->q1);
//    QueueInit(&st->q2);
//    return st;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//    if (!QueueEmpty(&obj->q1)) //q1队列不为空 q2为空
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
//int myStackPop(MyStack* obj)
//{
//    Queue* emptyQ = &obj->q1;
//    Queue* noemptyQ = &obj->q2;//默认q1为空 q2不为空
//    if (!QueueEmpty(&obj->q1)) //q1不为空
//    {
//        emptyQ = &obj->q2;
//        noemptyQ = &obj->q1;
//    }
//    while (QueueSize(noemptyQ) > 1)
//    {
//        QueuePush(emptyQ, QueueFront(noemptyQ)); //非空的数据入到空队列
//        QueuePop(noemptyQ);
//    }
//    int top = QueueFront(noemptyQ);
//    QueuePop(noemptyQ);
//    return top;
//}
//
//int myStackTop(MyStack* obj)
//{
//    if (!QueueEmpty(&obj->q1))
//    {
//        return obj->q1.tail->data;
//    }
//    else
//    {
//        return obj->q2.tail->data;
//    }
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);
//}