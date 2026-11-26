//STL:标准模板库
//有 容器 算法 迭代器 仿函数 适配器 空间适配器 六类
#include <iostream>
#include <string>
using namespace std;
#include <vector>
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
void Print(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//vector容器存放内置数据类型
void test1()
{
	//创建一个vector容器，理解为数组 
	vector<int> v;  //<int>表示数据为int类型

	//插入数据 尾插
	v.push_back(10);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过迭代器访问
	//vector<int>::iterator Begin = v.begin(); //v.begin为起始迭代器，指向容器中第一个元素
	//vector<int>::iterator End = v.end(); //v.end指向容器中的最后一个元素的 下一个位置
    //遍历
	//while (Begin != End)
	//{
	//	cout << *Begin << endl;
	//	Begin++;
	//}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}
//vector存放自定义数据类型
void test2()
{
	vector<Person>v;
	Person p1("a", 10);
	Person p2("b", 11);
	Person p3("c", 12);
	Person p4("d", 13);
	//向容器中添加
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "姓名:"<< (*it).m_name << " " << "年龄:" << (*it).m_age << endl;
		cout << "姓名:" << it->m_name << " " << "年龄:" << it->m_age << endl;

	}
}
//存放自定义类型的指针
void test3()
{
	vector<Person*>v;
	Person p1("a", 10);
	Person p2("b", 11);
	Person p3("c", 12);
	Person p4("d", 13);
	//向容器中添加
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	//遍历
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		// *it 是一个Person类型的指针，再->访问元素
		cout << "姓名:" << (*it)->m_name << " " << "年龄:" << (*it)->m_age << endl;
	}
}
//容器嵌套容器
void test4()
{
	vector<vector<int>>v;
	//创建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	//给小容器添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 1 +1);
		v3.push_back(i + 1 +1 +1);
		v4.push_back(i + 1 +1 +1 +1);
	}
	//把小容器插入到大容器
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//通过大容器遍历
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it) 是小容器 要再用for循环
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//vector 容器构造
void test5()
{
	vector<int>v1;//默认构造 无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i+1);
	Print(v1);
	//区间方式构造
	vector<int>v2(v1.begin(), v1.end());
	Print(v2);
	//n个element
	vector<int>v3(10, 100);
	Print(v3);
	//拷贝构造
	vector<int>v4(v3);
	Print(v4);
}
//vector 赋值操作
void test6()
{
	vector<int>v1;//默认构造 无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i + 1);
	vector<int>v2;
	v2 = v1;
	Print(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	Print(v3);

}
//vector 容量和大小
void test7()
{
	vector<int>v1;//默认构造 无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i + 1);
	if (v1.empty())
		printf("v为空\n");
	else
	{
		printf("不为空\n");
		cout << "v1容量:" << v1.capacity() << endl;
		cout << "v1大小:" << v1.size() << endl;
	}
	//重新指定大小
	v1.resize(15);//如果比原来容量大，用0来填充   否则截断
	Print(v1);
}
//vector 插入和删除
void test8()
{
	vector<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	//尾删
	v1.pop_back();
	Print(v1);
	//插入
	v1.insert(v1.begin()+2,100);//第一个参数 是迭代器
	Print(v1);
	v1.insert(v1.begin(), 2, 1000);//插入2个1000
	Print(v1);
	//删除
	v1.erase(v1.begin());
	Print(v1);
	v1.erase(v1.begin(), v1.begin() + 3);//两个参数 从哪里到哪里全部删除
	Print(v1);
	//清空
	v1.clear();
}
//vector 数据存取
void test9()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	//利用[]访问元素
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	//用at访问元素
	for (int i = 0; i < v1.size(); i++)
		cout << v1.at(i) << " ";
	cout << endl;
	//第一个元素
	cout << "第一个元素：" << v1.front() << endl;
	//最后一个
	cout << "最后一个元素：" << v1.back() << endl;
}
//vector 容器互换
void test10()
{
	//vector<int>v1;
	//for (int i = 0; i < 10; i++)
	//	v1.push_back(i);
	//Print(v1);
	//vector<int>v2;
	//for (int i = 10; i > 0; i--)
	//	v2.push_back(i);
	//Print(v2);
	////互换
	//v1.swap(v2);
	//Print(v1);
	//Print(v2);
	//cout << endl;
	
	//用途
	//巧用swap收缩内存空间
	vector<int>v;
	for (int i = 0; i < 100000; i++)
		v.push_back(i);
	cout << "v的容量是：" << v.capacity() << endl;
	cout << "v的大小是：" << v.size() << endl;
	//重新指定大小
	v.resize(3);
	cout << "v的容量是：" << v.capacity() << endl; //容量不变 浪费了空间
	cout << "v的大小是：" << v.size() << endl;
	//收缩
	vector<int>(v).swap(v);
	cout << "v的容量是：" << v.capacity() << endl;
	cout << "v的大小是：" << v.size() << endl;
}
//vector 预留空间
void test11()
{
	vector<int>v;
	int cnt = 0;//开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			cnt++;
		}
	}
	cout << cnt << endl;
}
//int main()
//{
//	test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	//test7();
//	//test8();
//	//test9();
//	//test10();
//	//test11();
//}