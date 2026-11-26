#include <iostream>
using namespace std;
//加号运算符重载
//对于内置的数据类型（int等）不可以进行重载
//1.成员函数重载
//class person
//{
//public:
//	int m_a; int m_b;
//	person(int a=10, int b=10) :m_a(a), m_b(b){}
//	person operator+(const person& p)
//	{
//		person temp;
//		temp.m_a = p.m_a+this->m_a;
//		temp.m_b = p.m_b+this->m_b;
//		return temp;
//	}
//};
//int main()
//{
//	person p1;
//	person p2;
//	person p3 = p1 + p2;
//	cout << p3.m_a;
//}
//2.全局函数
//class person
//{
//public:
//	int m_a; int m_b;
//	person(int a=10, int b=10) :m_a(a), m_b(b){}
//};
//person operator+(person p1,person p2)
//{
//	person temp;
//	temp.m_a = p1.m_a+p2.m_a;
//	temp.m_b = p1.m_b+p2.m_b;
//	return temp;
//}
//int main()
//{
//	person p1;
//	person p2;
//	person p3 = p1 + p2;
//	cout << p3.m_a;
//}

//左移运算符重载
//只能在全局
//class person
//{
//public:
//	int m_a; int m_b;
//	person(int a = 10, int b = 10) :m_a(a), m_b(b) {}
//	friend ostream& operator<<(ostream& cout, const person& p);
//};
////void operator<<(ostream& cout, person p)//cout对象只有一个，要用引用 本质是cout<<p;
////{
////	cout << p.m_a;
////}
//ostream& operator<<(ostream& cout, const person& p)//cout对象只有一个，要用引用 本质是cout<<p;
//{
//	cout << p.m_a;
//	return cout;
//}
//int main()
//{
//	person p;
//	cout << p <<endl;
//}

//带cout的，用值传递 或者const 引用传递

//递增运算符重载++
//class MyInt
//{
//private:
//	int num;
//public:
//	MyInt()
//	{
//		num = 0;
//	}
//	friend ostream& operator<<(ostream& cout, const MyInt& myint);
//	//friend MyInt& operator++(MyInt& p);
//	//前置++在内部 返回引用
//	MyInt& operator++()//返回引用是为了对一个数据进行递增
//	{
//		num++; return *this;
//	}
//	//后置++在内部 返回值
//	MyInt operator++(int)//int是占位参数，区分前置和后置++
//	{
//		//先 记录当前结果
//		MyInt temp = *this;
//		//后 递增
//		num++;
//		//返回
//		return temp;
//	}
//};
//ostream& operator<<(ostream& cout, const MyInt& myint)
//{
//	cout << myint.num;
//	return cout; 
//}
////前置++在全局
////MyInt& operator++(MyInt& p)
////{
////	p.num++;
////	return p;
////}
//int main()
//{
//	MyInt myint;
//	cout << myint++ << endl;//0
//	cout << ++myint << endl;//2
//}

