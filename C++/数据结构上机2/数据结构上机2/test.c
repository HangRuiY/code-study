#include "栈.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0; //top给0 指向栈顶数据下一个,先放再++,top给-1 指向栈顶数据 先++再放
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)  //考虑增容
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* str = realloc(ps->a, newcapacity * sizeof(STDataType));
		if (str == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		else
		{
			ps->a = str;
			ps->capacity = newcapacity;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	if (StackEmpty(ps) == 1)
		return;
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	if (StackEmpty(ps) == 1)
		return;
	assert(ps);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
int StackEmpty(ST* ps)
{
	assert(ps);
	if (ps->top == 0)
		return 1;
	else
		return 0;
}

void StackInit2(ST2* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0; //top给0 指向栈顶数据下一个,先放再++,top给-1 指向栈顶数据 先++再放
	ps->capacity = 0;
}
void StackDestroy2(ST2* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackPush2(ST2* ps, char x)
{
	assert(ps);
	if (ps->top == ps->capacity)  //考虑增容
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		char* str = realloc(ps->a, newcapacity * sizeof(char));
		if (str == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		else
		{
			ps->a = str;
			ps->capacity = newcapacity;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop2(ST2* ps)
{
	assert(ps);
	if (StackEmpty2(ps) == 1)
		return;
	ps->top--;
}
char StackTop2(ST2* ps)
{
	if (StackEmpty2(ps) == 1)
		return;
	assert(ps);
	return ps->a[ps->top - 1];
}
int StackSize2(ST2* ps)
{
	assert(ps);
	return ps->top;
}
int StackEmpty2(ST2* ps)
{
	assert(ps);
	if (ps->top == 0)
		return 1;
	else
		return 0;
}