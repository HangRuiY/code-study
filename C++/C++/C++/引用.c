#include <stdio.h>
#include <string.h>
//引用-
//作用：给变量起别名
//用法：数据类型+&别名=原名
//引用必须初始化，且引用只能作用于一个
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int c = 30;//a和b本质一样 b改变 a改变
//	b = c;
//	cout << b << " " << a;
//	return 0;
//}

//引用传参
//void swap(int &a, int &b)
//{
//	int tmp = 0;
//	tmp = a; a = b; b = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap(a, b);
//	cout << a << " " << b;
//}

//引用作函数返回值
//int& test1()
//{
//	int a = 100;
//	return a;
//}
//int main()
//{
//	int& ret = test1();//ret是a的别名
//	cout << ret << endl;
//	test1() = 200;//引用作返回值可以当左值
//	cout << ret << endl;
//	return 0;
//}

//引用本质是一个指针常量
//void func(int& ret)
//{
//	ret = 100; //*ret=100;
//}
//int main()
//{
//	int a = 10;
//	int& ret = a;// int* const ret=&a;
//	ret = 20;
//	cout << ret << " " << a << endl;
//	func(a);
//	cout << ret << " " << a << endl;
//	ret = 200;
//	cout << ret << " " << a << endl;
//	func(ret);
//	cout << ret << " " << a << endl;
//	return 0;
//}

//常量引用
//void print(const int& ret)
//{
//	cout << ret << endl;
//}
//int main()
//{
//	int a = 10;
//	print(a);
//	cout << a << endl;
//}


