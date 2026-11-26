#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//int main()
//{
//	string user_name;
//	cout << "Please enter your first name: ";
//	cin >> user_name;
//	cout << '\n' << "Hello, " << user_name << " ... and goodbye!\n";
//	return 0;
//}

//int max(int x, int y) 
//{
//	int z;
//	if (x > y) z = x;
//	else z = y;
//	return (z);
//}
//int main()
//{
//	int a, b, c;
//	cin >> a >> b;
//	c = max(a, b);
//	cout << "max= " << c << '\n';
//}

//int main()
//{
//	int i; float f;
//	char s[80];
//	cout << "Enter an integer,float,and string:";
//	cin >> i >> f >> s;
//	cout << "Here's your data:" << i << ' ' << f << endl << s << '\n';
//	return 0;
//}

//int main() 
//{
//	int a, b, c;
//	cin >> a >> b;
//	if (b == 0) return -1;
//	c = a / b;
//	cout << "c= " << c <<endl;
//	return 0;  
//}

//两个数求和
//int main()
//{
//	int a, b;
//	cout << "输入两个数:";
//	cin >> a >> b;
//	cout << "两个数的和为:" << a + b;
//	return 0;
//}

//计算三角形面积
//double sum(int a, int b, int c)
//{
//	double f, t;
//	f = (a + b + c) / 2.0;
//	t = sqrt(f * (f - a) * (f - b) * (f - c));
//	return t;
//}
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		cout << "三角形的面积为:" << sum(a, b, c);
//	}
//	else
//		cout << "无法构成三角形";
//	return 0;
//}

//1-100的和
//int main()
//{
//	int sum = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += i;
//	}
//	cout << "1-100的和为:" << sum;
//	return 0;
//}

//求n的阶乘
//int main()
//{
//	cout << "输入一个数:";
//	int n; cin >> n;
//	int sum = 1;
//	for (int i = n; i >= 1; i--)
//	{
//		sum *= i;
//	}
//	cout << "此数的阶乘为:" << sum;
//	return 0;
//}

//九九乘法表
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cout << i << "*" << j << "=" << i * j << " ";
//		}
//		cout << endl;
//	}
//}

//定义一个具有五个数据的数组，求数组元素中的最大值。
//int main()
//{
//	int a[5];
//	int max = 0;
//	cout << "输入5个数:";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> a[i];
//		if (a[i] >= max)
//			max = a[i];
//	}
//	cout << "最大值为:" << max;
//}