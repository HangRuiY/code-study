#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>
void T1()
{
	//先进后出
	stack<int>s;
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	//查看
	while (!s.empty())
	{
		cout << "栈顶元素为：" << s.top() << endl;
		//出栈
		s.pop();
	}
	cout << "栈的大小：" << s.size() << endl;
}
//int main()
//{
//	T1();
//}