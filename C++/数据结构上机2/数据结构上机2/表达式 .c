#include "栈.h"
//算术表达式
int youxian(char c)
{
	if (c == '*' || c == '/')
		return 1;
	if (c == '+' || c == '-')
		return 0;
}
ST s;
ST2 c;
void work()
{
	char op = StackTop2(&c);
	int a = StackTop(&s);
	StackPop(&s);
	int b = StackTop(&s);
	StackPop(&s);
	int tmp = 0;
	if (op == '+')
		tmp = a + b;
	else if (op == '-')
		tmp = b - a;
	else if (op == '/')
		tmp = b / a;
	else
		tmp = a * b;
	StackPush(&s, tmp);
	StackPop2(&c);
}
//int main()
//{
//	StackInit(&s);
//	StackInit2(&c);
//	char ch[100010];
//	while (scanf("%s", &ch))
//	{
//		while (!StackEmpty(&s))
//			StackPop(&s);
//		while (!StackEmpty2(&c))
//			StackPop2(&c);
//		int l = strlen(ch);
//		for (int i = 0; i < l; i++)
//		{
//			if (ch[i] >= '0' && ch[i] <= '9')
//			{
//				int tmp = 0;
//				while (ch[i] >= '0' && ch[i] <= '9')
//				{
//					tmp = tmp * 10 + ch[i] - '0';
//					i++;
//				}
//				StackPush(&s, tmp);
//				i--;
//			}
//			else
//			{
//				if (StackEmpty2(&c) || StackTop2(&c) == '(' || ch[i] == '(')
//					StackPush2(&c, ch[i]);
//				else if (ch[i] == ')')
//				{
//					if (StackTop2(&c) != '(')
//						work();
//					if (StackTop2(&c) != '(')
//						work();
//					StackPop2(&c);
//				}
//				else
//				{
//					while (!StackEmpty2(&c) && StackTop2(&c) != '(' && youxian(StackTop2(&c)))
//					{
//						work();
//					}
//					StackPush2(&c, ch[i]);
//				}
//			}
//		}
//		while (!StackEmpty2(&c))
//			work();
//		printf("%d", StackTop(&s));
//	}
//	return 0;
//}
//
