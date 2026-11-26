#include <iostream>
using namespace std;
#define MaxSize 5
typedef struct Stack
{
	int data[MaxSize];
	int top;
}Stack;
void InitStack(Stack &s)
{
	s.top = -1;
}
bool Empty(Stack s)
{
	if (s.top == -1)
		return true;
	return false;
}
void Insert(Stack& s,int x)
{
	if (s.top == MaxSize - 1)
		return;
	s.data[++s.top] = x;
}
void Out(Stack &s)
{
	cout << s.data[s.top--]<<" ";
}
int GetTop(Stack s)
{
	return s.data[s.top];
}
//int main()
//{
//	Stack s;
//	InitStack(s);
//	Insert(s, 1);
//	Insert(s, 2);
//	Insert(s, 3);
//	Insert(s, 4);
//	Insert(s, 5);
//	cout << GetTop(s)<<endl;
//	for (int i = s.top; i >=0 ; i--)
//		Out(s);
//}