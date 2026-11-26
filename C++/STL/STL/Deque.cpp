#include <iostream>
#include <algorithm>
using namespace std;
#include <deque>
void PrintD(deque<int>&d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//deque 构造函数 + 赋值函数
void t1()
{
	deque<int>d1;//默认
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	PrintD(d1);
	deque<int>d2(d1.begin(),d1.end()); //区间
	PrintD(d2);
	deque<int>d3(10, 100);//n个elem
	PrintD(d3);
	deque<int>d4(d3);//拷贝
	PrintD(d4);

	deque<int>d5;
	d5.assign(10, 100);
	PrintD(d5);
	deque<int>d6;
	d6.assign(d1.begin(),d1.end());
	PrintD(d6);
}
//deque 大小 没有容量限制
void t2()
{
	deque<int>d1;//默认
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	if (d1.empty())//为真 说明为空
		printf("为空\n");
	else
	{
		printf("不为空\n");
		PrintD(d1);
		cout << "d1的大小：" << d1.size() << endl;
	}
	//修改大小
	d1.resize(20); //比原来大 用0填充 否则截断
	PrintD(d1);
}
//deque 插入删除
void t3()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
    //头插
	d1.push_front(100);
	d1.push_front(200);
	PrintD(d1);
	//尾删
	d1.pop_back();
	//头删
	d1.pop_front();
	PrintD(d1);   //100 10

	//insert插入
	d1.insert(d1.begin(), 1000);//第一个参数：位置 第二个参数：值
	PrintD(d1);   //1000 100 10
	d1.insert(d1.begin(), 2, 2000); //2个2000;
	PrintD(d1);//2000 2000 1000 100 10

	//区间插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.end(), d2.begin(), d2.end());//在d1的end位置 插入d2的begin到end区间内的元素
	PrintD(d1);//2000 2000 1000 100 10 1 2 3 

	//删除
	d1.erase(d1.begin() + 2);
	PrintD(d1);//2000 2000 100 10 1 2 3
	
	d1.erase(d1.begin(), d1.begin() + 2);
	PrintD(d1);//100 10 1 2 3

	//清空
	d1.clear();
}
//deque 数据存取
void t4()
{
	deque<int>d1;//默认
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	//通过[]访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	//通过at访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

}
//deque 排序
void t5()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	sort(d.begin(), d.end());
	//vector 也可以用sort
	PrintD(d);
}
//int main()
//{
//	t1();
//	t2();
//  t3();
//	t4();
//	t5();
//}