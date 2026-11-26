#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <queue>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void Te1()
{
	//创建队列
	queue<Person>q;
	//准备数据
	Person p1("唐僧", 10);
	Person p2("唐僧2", 2000);
	Person p3("唐僧3", 100);
	Person p4("唐僧4", 500);
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	while (!q.empty())
	{
		cout << "队头元素：" << "姓名：" << q.front().m_name << "年龄：" << q.front().m_age << endl;
		cout << "队尾元素：" << "姓名：" << q.back().m_name << "年龄：" << q.back().m_age << endl;
		//出队
		q.pop();
	}
	cout << "队列大小：" << q.size();
}
//int main()
//{
//	Te1();
//}