#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
//遍历算法 
////1.for_each
////普通函数
//void print1(int val)
//{
//	cout << val << " ";
//}
////仿函数
//class print2
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//void test1()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i + 1);
//	for_each(v.begin(), v.end(), print1);   //两个迭代器 + 一个函数名
//	cout << endl;
//	for_each(v.begin(), v.end(), print2());   //两个迭代器 + 一个函数名
//	cout << endl;
//}
//int main()
//{
//	test1();
//}
//
// 
//2.transform
//class Transform
//{
//public:
//	int operator()(int val)
//	{
//		return val+100;
//	}
//};
//class Print
//{
//public:
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//};
//void test1()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i);
//	vector<int>v1;//目标容器
//	//开辟空间
//	v1.resize(v.size());
//	transform(v.begin(), v.end(), v1.begin(), Transform());  //第一个容器的迭代器，第一个容器的迭代器。第二个容器的迭代器，仿函数
//	for_each(v1.begin(), v1.end(), Print());
//}
//int main()
//{
//	test1();
//}
//全排列算法
//next _ permutation
//int n, m;
//int a[100];
//int main()
//{
//    scanf("%d", &n);
//    int tot = 1;
//    for (int i = 1; i <= n; ++i)
//    {
//        a[i] = i;
//        tot *= i;
//    }
//    for (int i = 1; i <= tot; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//            printf("    %d", a[j]);    //输出格式注意
//        next_permutation(a + 1, a + n + 1);
//        printf("\n");
//    }
//    return 0;
//}

//查找算法
////1.find
////(1)查找内置数据类型
//void test1()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i);
//	//是否有'50'
//	vector<int>::iterator it = find(v.begin(), v.end(), 50);
	//if (it == v.end())
	//	cout << "没有找到" << endl;
	//else
	//	cout << "找到了：" << " " << *it << endl;
//}
////(2)查找自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	//重载 == 让底层find学会查找
//	bool operator==(const Person& p)
//	{
//		if (this->m_name == p.m_name && this->m_age == p.m_age)
//			return true;
//		else
//			return false;
//	}
//	string m_name; int m_age;
//};
//void test2()
//{
//	vector<Person>v;
//	Person p1("A", 1);
//	Person p2("B", 2);
//	Person p3("C", 3);
//	Person p4("D", 4);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//	Person ppp("D", 4);
//	vector<Person>::iterator it = find(v.begin(), v.end(), ppp);
//	if (v.end() == it)
//		cout << "没有找到" << endl;
//	else
//		cout << "找到了：" << "姓名：" << it->m_name << " " << "年龄：" << it->m_age << endl;
//}
//int main()
//{
//	test1(); test2();
//}
//
// 
//2.find_if
////(1)内置数据类型
//class creative
//{
//public:
//	bool operator()(int val)
//	{
//		return val > 5;
//	}
//};
//void test1()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i + 1);
//	vector<int>::iterator it = find_if(v.begin(), v.end(), creative());
//	if (it == v.end())
//		cout << "没找到" << endl;
//	else
//		cout << "找到了:" << *it << endl;
//
//}
////(2)自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	string m_name; int m_age;
//};
//class creative2
//{
//public:
//	bool operator()(Person &p)
//	{
//		return p.m_age > 10;
//	}
//};
//void test2()
//{
	//vector<Person>v;
	//Person p1("a", 10);
	//Person p2("b", 20);
	//Person p3("c", 30);
	//v.push_back(p1);
	//v.push_back(p2);
	//v.push_back(p3);
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), creative2());
//	if (it == v.end())
//		cout << "没找到" << endl;
//	else
//		cout << "找到了:" << "姓名："<< it->m_name << " " << "年龄："<< it->m_age << endl;
//}
//int main()
//{
//	test1(); test2();
//}
//
// 
//3.adjacent_find  
////查找是否存在 相邻且重复的元素
//void test1()
//{
//	vector<int>v;
//	v.push_back(2);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(3);
//	v.push_back(5);
//	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
//	if (it == v.end())
//		cout << "没有找到" << endl;
//	else
//		cout << "找到了：" << " " << *it << endl;
//}
//int main()
//{
//	test1();
//}
//
// 
//4.二分查找 binary_search
//void test1()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i);
//	//必须有序
//	sort(v.begin(), v.end());
//	bool a = binary_search(v.begin(), v.end(),9);
//	if (a == true)
//		cout << "找到了：" << endl;
//	else
//		cout << "没找到" << endl;
//}
//int main()
//{
//	test1();
//}
//
// 
//5.count 
//(1)统计内置数据类型
//void test1()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i);
//	int cnt = count(v.begin(), v.end(), 5);
//	cout << cnt << endl;
//}
////(2)统计自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	bool operator==(const Person& p)
//	{
//		if (this->m_age == p.m_age)
//			return true;
//		else
//			return false;
//	}
//	string m_name; int m_age;
//};
//void test2()
//{
//	vector<Person>v;
//	Person p1("a", 10);
//	Person p2("b", 10);
//	Person p3("c", 30);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	Person p4("d", 10);
//	int cnt = count(v.begin(), v.end(), p4);
//	cout << "与d同岁的人的数量：" << cnt << endl;
//}
//int main()
//{
//	test1(); test2();
//}
//
// 
//6.count_if
//(1)统计内置数据类型
//class creat1
//{
//public:
//	bool operator()(int val)
//	{
//		return val > 10;
//	}
//};
//void test1()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	int cnt = count_if(v.begin(), v.end(), creat1());
//	cout << "大于10的数字有：" << cnt << endl;
//
//}
////(2)统计自定义数据类型
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	string m_name; int m_age;
//};
//class creat2
//{
//public:
//	bool operator()(Person &p)
//	{
//		return p.m_age > 10;
//	}
//};
//void test2()
//{
//	vector<Person>v;
//	Person p1("a", 10);
//	Person p2("b", 20);
//	Person p3("c", 30);
//	Person p4("d", 40);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	int cnt = count_if(v.begin(), v.end(), creat2());
//	cout << "大于10的人有：" << cnt << endl;
//}
//int main()
//{
//	test1(); test2();
//}

//排序算法
//1.sort
//class compare
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//void PRINT(int v)
//{
//	cout << v << " ";
//}
//int main()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	sort(v.begin(), v.end(), compare());
//	for_each(v.begin(), v.end(), PRINT);
//}
//
//
//2.random_shuffle 洗牌
//void PRINT(int v)
//{
//	cout << v << " ";
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	//打乱顺序
//	random_shuffle(v.begin(), v.end());
//	for_each(v.begin(), v.end(), PRINT);
//}
//
//
//3.merge 合并两个有序容器
//void PRINT(int v)
//{
//	cout << v << " ";
//}
//int main()
//{
//	vector<int>v1; vector<int>v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 10);
//	}
//	vector<int>v;
//	//开辟空间
//	v.resize(v1.size() + v2.size());
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(),v.begin());
//	for_each(v.begin(), v.end(), PRINT);
//}
//
//
//4.reverse 反转

//拷贝和替换算法
//1.replace
//class PRINT
//{
//public:
//	void operator()(int v)
//	{
//		cout << v << " ";
//	}
//};
//int main()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(0);
//	v.push_back(100);
//	replace(v.begin(), v.end(), 10, 500);//区间+替换的数据+替换后的数据
//	for_each(v.begin(), v.end(), PRINT());
//}
//
//
//2.replace if
//class PRINT
//{
//public:
//	void operator()(int v)
//	{
//		cout << v << " ";
//	}
//};
//class creator
//{
//public:
//	bool operator()(int v)
//	{
//		return v >= 30;
//	}
//};
//int main()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(60);
//	replace_if(v.begin(), v.end(), creator(), 500);
//	for_each(v.begin(), v.end(), PRINT());
//}

//算术生成算法
//1.accumulate
//int main()
//{
//	vector<int>v;
//	for (int i = 1; i <= 100; i++)
//		v.push_back(i);
//	int total = accumulate(v.begin(), v.end(), 1000);  //从1000开始累加vector的内容 
//	cout << total << endl;
//}
//
//
//2.fill
//class PRINT
//{
//public:
//	void operator()(int v)
//	{
//		cout << v << " ";
//	}
//};
//int main()
//{
//	vector<int>v;
//	v.resize(10);
//	fill(v.begin(), v.end(), 100);
//	for_each(v.begin(), v.end(), PRINT());
//}

//集合算法
//1.set_intersection 交集
//int main()
//{
//	vector<int>v1, v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);//0-9
//		v2.push_back(i + 5);//5-14
//	}
//	vector<int>v;
//	v.resize(min(v1.size(), v2.size()));
//	vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
//	for (vector<int>::iterator it2 = v.begin(); it2 != it; it2++)
//		cout << *it2 << " ";
//	cout << endl;
//}
//
//
//2.set_union 并集 且两个子集都要有序
//int main()
//{
//	vector<int>v1, v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);//0-9
//		v2.push_back(i + 5);//5-14
//	}
//	vector<int>v;
//	v.resize((v1.size() + v2.size()));
//	vector<int>::iterator it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
//	for (vector<int>::iterator it2 = v.begin(); it2 != it; it2++)
//		cout << *it2 << " ";
//	cout << endl;
//}
//
//
//3.set_difference 差集
//class PRINT
//{
//public:
//	void operator()(int x)
//	{
//		cout << x << " ";
//	}
//};
//int main()
//{
//	vector<int>v1, v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);//0-9
//		v2.push_back(i + 5);//5-14
//	}
//	vector<int>v;
//	v.resize(max(v1.size(), v2.size()));
//	vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
//	for_each(v.begin(), it, PRINT());
//}
