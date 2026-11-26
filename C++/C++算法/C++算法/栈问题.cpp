#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <stack>
using namespace std;
int youxian(char c)
{
	if (c == '*' || c == '/')
		return 1;
	if (c == '+' || c == '-')
		return 0;
}
stack<int>s;
stack<char>c;
void work()
{
	char op = c.top();
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	int tmp = 0;
	if (op == '+')
		tmp = a + b;
	else if (op == '-')
		tmp = b - a;
	else if (op == '/')
		tmp = b / a;
	else
		tmp = a * b;
	s.push(tmp);
	c.pop();
}
//int main()
//{
//	char ch[100010];
//	while (cin >> ch)
//	{
//		while (!s.empty())
//			s.pop();
//		while (!c.empty())
//			c.pop();
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
//				s.push(tmp);
//				i--;
//			}
//			else
//			{
//				if (c.empty() || c.top() == '(' || ch[i] == '(')
//					c.push(ch[i]);
//				else if (ch[i] == ')')
//				{
//					if (c.top() != '(')
//						work();
//					if (c.top() != '(')
//						work();
//					c.pop();
//				}
//				else
//				{
//					while(!c.empty() && c.top() != '(' && youxian(c.top()))
//					{
//						work();
//					}
//					c.push(ch[i]);
//				}
//			}
//		}
//		while (!c.empty())
//			work();
//		cout << s.top() << endl;
//	}
//	return 0;
//}