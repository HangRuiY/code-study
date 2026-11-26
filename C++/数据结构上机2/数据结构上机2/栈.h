#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
typedef struct STack
{
	char* a;
	int top;
	int capacity;
}ST2;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
int StackEmpty(ST* ps);

void StackInit2(ST2* ps);
void StackDestroy2(ST2* ps);
void StackPush2(ST2* ps, char x);
void StackPop2(ST2* ps);
char StackTop2(ST2* ps);
int StackSize2(ST2* ps);
int StackEmpty2(ST2* ps);

