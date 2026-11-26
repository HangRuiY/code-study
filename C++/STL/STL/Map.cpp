#include <iostream>
using namespace std;
#include <map>
void PrintM(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key = " << (*it).first << "  " << "value = " << it->second << endl;
	cout << endl;
}
//map 构造和赋值
void te1()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 50));
	PrintM(m); //按照key排序
	map<int, int>m2(m); //拷贝构造
	map<int, int>m3;
	m3 = m; //赋值
}
//map 大小和交换
void te2()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 50));
	if (m.empty())
		cout << "为空" << endl;
	else
	{
		cout << "不为空" << endl;
		cout << "m的大小：" << m.size() << endl;
	}
	//交换
	map<int, int>m2;
	m2.insert(pair<int, int>(5, 20));
	m2.insert(pair<int, int>(3, 10));
	m2.insert(pair<int, int>(2, 40));
	PrintM(m2);
	m.swap(m2);
	PrintM(m);
	PrintM(m2);
}
//map 插入和删除
void te3()
{
	map<int, int>m;
	//第一种插入
	m.insert(pair<int, int>(1, 30));
	//第二种插入
	m.insert(make_pair(2, 20));
	//第三种
	m[3] = 40;
	PrintM(m);
	//[]不建议用于插入，但是可以用key访问value

	//删除
	m.erase(m.begin());
	PrintM(m);
	m.erase(3);//把key为3的数据删除
	PrintM(m);
	//清空
	m.clear();
}
//map 查找和统计
void te4()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 50));
	//查找 返回一个迭代器
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "找到了key = " << pos->first << "  " << "value = " << pos->second << endl;
	}
	else
		cout << "没有找到" << endl;
	//统计
	int cnt = m.count(3);
	cout << cnt << endl;//map容器 统计要么0要么1
}
//map 排序
class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void te5()
{
	map<int, int,MyCompare>m;
	m.insert(pair<int, int>(1, 30));
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(2, 50));
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key = " << it->first << "  " << "value = " << it->second << endl;
}
//int main()
//{
//	//te1();
//	//te2();
//	//te3();
//	//te4();
//	te5();
//
//}