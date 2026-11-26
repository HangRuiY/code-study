#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//20. 有效的括号
//bool isValid(char* s)
//{
//    ST st;
//    StackInit(&st);
//    while (*s)
//    {
//        if (*s == '{' || *s == '(' || *s == '[')
//        {
//            StackPush(&st, *s);
//            s++;
//        }
//        else
//        {
//            //遇到右括号 但是栈中没有左括号匹配
//            if (StackEmpty(&st) == 0)
//            {
//                return false;
//            }
//            STDataType top = StackTop(&st);
//            StackPop(&st);
//            if ((*s == '}' && top != '{')
//                || (*s == ')' && top != '(')
//                || (*s == ']' && top != '['))
//            {
//                StackDestroy(&st);
//                return false;
//            }
//            else
//            {
//                s++;
//            }
//        }
//    }
//    //如果栈不是空，说明还有左括号没有匹配
//    int ret = StackEmpty(&st);
//    StackDestroy(&st);
//    if (ret == 1)
//    {
//        return false;
//    }
//    else
//    {
//        return true;
//    }
//}

//232. 用栈实现队列
//入数据 第一个栈 出数据 第二个栈
//typedef struct
//{
//    ST pushst;
//    ST popst;
//} MyQueue;
//
//
//MyQueue* myQueueCreate()
//{
//    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
//    StackInit(&q->pushst);
//    StackInit(&q->popst);
//    return q;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//    StackPush(&obj->pushst, x);
//}
//
//int myQueuePop(MyQueue* obj)
//{
//    if (StackEmpty(&obj->popst) == 0)
//    {
//        while (StackSize(&obj->pushst) != 0)
//        {
//            StackPush(&obj->popst, StackTop(&obj->pushst));
//            StackPop(&obj->pushst);
//        }
//    }
//    int front = StackTop(&obj->popst);
//    StackPop(&obj->popst);
//    return front;
//}
//
//int myQueuePeek(MyQueue* obj)
//{
//    if (StackEmpty(&obj->popst) == 0)
//    {
//        while (StackEmpty(&obj->pushst) != 0)
//        {
//            StackPush(&obj->popst, StackTop(&obj->pushst));
//            StackPop(&obj->pushst);
//        }
//    }
//    return StackTop(&obj->popst);
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//    return StackEmpty(&obj->pushst) == 0 && StackEmpty(&obj->popst) == 0;
//}
//
//void myQueueFree(MyQueue* obj)
//{
//    StackDestroy(&obj->pushst);
//    StackDestroy(&obj->popst);
//    free(obj);
//}