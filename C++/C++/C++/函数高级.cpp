#include <iostream>
using namespace std;
//函数默认参数
//如果自己传入了数据，用自己的，否则用默认的
//注意：1.如果某个参数有了默认值，那么从这个参数以后的所有参数都必须有默认值
//int func(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
////注意：2.如果函数声明中包含默认参数，那么函数实现时不可以用默认参数,且声明和实现只能有一个有默认参数
//int func2(int a = 10, int b = 20);
//int func2(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	cout << func(10) << endl;//60
//	cout << func(10, 10) << endl;//50
//	cout << func2() << endl;//30
//	cout << func2(20) << endl;//40
//	return 0;
//}

//函数占位参数
//占位参数可以使用默认参数
//void func(int a, int=10)
//{
//	cout << "成功";
//}
//int main()
//{
//	func(10, 20);
//}

//函数重载
//作用：函数名可以相同，提高复用性
//注意：1.在同一个作用域下 2.名称相同 3.参数的类型不同，或者个数不同，或者顺序不同
//函数的返回值类型不能作为函数重载的条件
//void func1(int a)
//{
//	cout << "func(int a)" << endl;
//}
//void func1()
//{
//	cout << "func" << endl;
//}
////函数重载配合引用
////尽量不配合默认参数
//void func2(int& a)  //int& a=10; 不合法
//{
//	cout << "func(int& a)" << endl;
//}
//void func2(const int& a) //const int& a=10; 合法
//{
//	cout << "func(const int& a)"<< endl;
//}
//int main()
//{
//	//func1();
//	//func1(0);
//	int a = 10;
//	func2(a);
//	func2(10);
//	return 0;
//}


int main()
{
	char a;
	cin >> a;
	printf("%d", a);
}