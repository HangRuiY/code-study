#include <iostream>
using namespace std;
#include <set>
#include <string>
void PrintS(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//set 构造与赋值
void ts1()
{
	set<int>s1;
	//插入数据只有.insert
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	PrintS(s1); //set容器不能有重复的数据 并且 自动升序排序

	//拷贝构造
	set<int>s2(s1);
	PrintS(s2);
}
//set 大小和交换
void ts2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	if (s1.empty())
		cout << "为空" << endl;
	else
	{
		cout << "不为空" << endl;
		cout << "大小为：" << s1.size() << endl;
	}
	//交换
	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(400);

	s1.swap(s2);
	PrintS(s1);
	PrintS(s2);
	s2.swap(s1);
	PrintS(s1);
	PrintS(s2);
}
//set 插入和删除
void ts3()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	//删除
	s1.erase(s1.begin());
	PrintS(s1);//30 40
	s1.erase(30);
	PrintS(s1);//40

	//清空
	s1.clear();
}
//set 查找和统计
void ts4()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	//查找 返回一个迭代器 
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "找到了:" << *pos << endl;
	}
	else
		cout << "没找到" << endl;
	//统计
	int cnt = s1.count(30);
	cout << cnt; //对于set而言 要么0 要么1
}
//set 排序
class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void ts5()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	PrintS(s1);
	set<int, MyCompare>s2;//降序
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(500);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << *it << " ";
}
//set 排序自定义数据
//自定义数据排序 要用到仿函数
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
class PC
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		//年龄降序
		return p1.m_age > p2.m_age;
	}
};
void ts6()
{
	set<Person,PC>s;
	Person p1("A", 20);
	Person p2("B", 22);
	Person p3("C", 24);
	Person p4("D", 19);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person,PC>::iterator it = s.begin(); it != s.end(); it++)
		cout << "姓名：" << it->m_name << " " << "年龄：" << it->m_age << endl;

}
//set 和 multiset 的区别
void ts7()
{
	set<int>s;
	pair<set<int>::iterator,bool> ret = s.insert(10);
	if (ret.second)//bool类型以为真
		cout << "第一次插入成功" << endl;
	else
		cout << "第一次插入失败" << endl;
	ret = s.insert(10);
	if (ret.second)//bool类型以为真
		cout << "第二次插入成功" << endl;
	else
		cout << "第二次插入失败" << endl;
	//multiset 可以 重复插入
}
//pair 对组创建
void ts8()
{
	//第一种
	pair<string, int> p("tom", 10);
	cout << "姓名：" << p.first << "  " << "年龄：" << p.second << endl;
	//第二种
	pair<string, int> p2 = make_pair("jerry", 20);
	cout << "姓名：" << p2.first << "  " << "年龄：" << p2.second << endl;
}
//int main()
//{
//	//ts1();
//	//ts2();
//	//ts3();
//	//ts4();
//	//ts5();
//	//ts6();
//	//ts7();
//	//ts8();
//
//}