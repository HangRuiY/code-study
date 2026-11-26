#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <list>
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name; this->m_age = age;
	}
	string m_name; int m_age;
};
//list 遍历
void PRint(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//list 构造
person push(string m, int a)
{
	cin >> m; cin >> a;
	person p(m, a);
	return p;
}
void TES1()
{
	list<int>l1;
	//默认构造 尾插
	l1.push_back(10);
	l1.push_back(30);
	l1.push_back(20);
	l1.push_back(40); PRint(l1);
	//区间构造
	list<int>l2(l1.begin(), l1.end()); PRint(l2);
	string name; int age= 0;
	list<person>l3;
	person p = push(name, age);
	l3.push_back(p);
}
//list 交换和赋值
void TES2()
{
	list<int>l1;
	//默认构造 尾插
	l1.push_back(10);
	l1.push_back(30);
	l1.push_back(20);
	l1.push_back(40); PRint(l1);
	list<int>l2;
	l2 = l1; PRint(l2);
	list<int>l3;
	l3.assign(l1.begin(), l1.end());
	PRint(l3);

	list<int>l4;
	l4.push_back(1);
	l4.swap(l1);
	PRint(l1); PRint(l4);
}
//大小
void TES3()
{
	list<int>l1;
	if (l1.empty())
		cout << "为空" << endl;
	l1.push_back(10);
	l1.push_back(30);
	l1.push_back(20);
	l1.push_back(40);
	cout << "大小：" << l1.size() << endl;
	//重新指定大小
	l1.resize(10); PRint(l1);
}
//插入删除
void TES4()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);
	PRint(l1);
	//尾删
	l1.pop_back();//300 200 100 10 20 
	//头删
	l1.pop_front();//200 100 10 20
	//插入
	list<int>::iterator it = l1.begin();
	l1.insert(++it, 1000);//200 1000 100 10 20
	PRint(l1);
	//删除
	it = l1.begin();
	l1.erase(++it);//200 100 10 20
	PRint(l1);
	//移除
	l1.remove(200);
	PRint(l1);
	//情空
	l1.clear();
 }
//数据存取
void TES5()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	cout << "第一个元素：" << l1.front() << endl;
	cout << "最后一个元素：" << l1.back() << endl;
	//迭代器不支持随机访问  it+1 不可以
}
//反转 排序
bool Compare(int v1,int v2)
{
	return v1 > v2;
}
void TES6()
{
	//反转
	list<int>l1;
	l1.push_back(10);
	l1.push_back(15);
	l1.push_back(9);
	l1.push_back(50);
	l1.push_back(40);
	l1.push_back(130);
	cout << "反转前："; PRint(l1);
	l1.reverse();
	cout << "反转后："; PRint(l1);
	//排序

	//所有不支持随机访问的迭代器，不能用sort算法
	//直接用成员函数
	l1.sort();//升序
	PRint(l1);
	l1.sort(Compare);
	PRint(l1);
}
//int main()
//{
//	//TES1();
//	//TES2();
//	//TES3();
//	//TES4();
//	//TES5();
//	//TES6();
//}