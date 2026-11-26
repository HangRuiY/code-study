#include <iostream>
#include <string>
using namespace std;
int model = 90; 
int v[] = { 1,2,3,4 }; 
int x; 
void f()
{
	model = 200; 
	v[2]++; 
}

//void sqr_it(int* i);
//int main()
//{
//	int x;
//	x = 10;
//	sqr_it(&x); 
//	cout << "The square of x is " << x << '\n';
//	return 0;
//}
//void sqr_it(int* i)
//{
//	*i = (*i) * (*i);
//}

//int max(int a, int b)
//{
//	if (a > b) return a;
//	else 
//		return b;
//}
//long long max(long long a, long long b)
//{
//	if (a > b) return a;
//	else
//		return b;
//}
//double max(double b, double a)
//{
//	if (b > a) return b;
//	else
//		return a;
//}
//int main()
//{
//	cout << "输入两个整数:";
//	int a, b; cin >> a >> b;
//	cout << "最大值为:" << max(a, b) << endl;
//	cout << "输入两个长整型:";
//	long long a1, b1; cin >> a1 >> b1;
//	cout << "最大值为:" << max(a1,b1) << endl;
//	cout << "输入两个浮点数:";
//	float a2, b2; cin >> a2 >> b2;
//	cout << "最大值为:" << max(a2, b2);
//}

//void f(int a[], int n, int& max, int& min)
//{
//	max = min = a[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (max < a[i]) max = a[i];
//		if (min > a[i]) min = a[i];
//	}
//}
//void main()
//{
//	int a[10] = { 2,5,3,9,0,8,1,7,6,4 };
//	int max, min;
//	f(a, 10, max, min);
//	cout << "Max: " << max << endl;
//	cout << "Min: " << min << endl;
//}

//int main()
//{
//	char* a = new char[20];
//	cout << "输入名字:";
//	cin >> a;
//	cout << "输出名字:" << a;
//	delete a;
//	return 0;
//}