#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
//模拟-约瑟夫环
//int arr[100]; int n, k;
//int main()
//{
//	memset(arr, 0, sizeof(arr));
//	//arr[i]=0,人活着 ,arr[i]=-1，人死了
//	cin >> n >> k;
//	int cnt = 1; int cnt_n = n; int cnt_pos = 0;
//	while (cnt_n > 2)
//	{
//		cnt = 0;
//		while (cnt < k)
//		{
//			if (arr[cnt_pos] == 0)
//			{
//				cnt++;
//				if (cnt == k)
//					arr[cnt_pos] = -1;
//			}
//			cnt_pos++;
//			if (cnt_pos == n)
//				cnt_pos = 0;
//		}
//		cnt_n--;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] == 0)
//		{
//			cout << i + 1 << endl; 
//		}
//	}
//	return 0;
//}
 

//模拟-斐波那契数列
//int fib(int n)
//{
//	int a = 1; int b = 1; int c = 1;
//	while (n > 2)
//	{  //1 1 2 3 5
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 12;
//	cout << fib(n);
//}
//

//模拟-高精度 - 斐波那契
//char c[100001];
//void bigadd(char* a, char* b, char* d)
//{
//	int lena = strlen(a); int lenb = strlen(b);
//  int cura = lena - 1;//游标
//  int curb = lenb - 1;
//	int flag = 0; int p = 0;
//	while (cura >= 0 || curb >= 0)
//	{
//		int tmp = 0;
//		if (cura >= 0)
//		{                                                
//			tmp += a[cura] - '0';
//		}
//		if (curb >= 0)
//		{
//			tmp += b[curb] - '0';
//		}
//		tmp += flag;
//		if (tmp >= 10)
//		{
//			flag = 1;
//			tmp = tmp % 10;
//		}
//		else
//		{
//			flag = 0;
//		}
//		c[p++] = tmp + '0';
//		cura--; curb--;
//	}
//	if (flag == 1)
//		c[p++] = '1';
//	c[p] = 0;
//	int pd = 0;
//	for (int i = strlen(c) - 1; i >= 0; i--)
//	{
//		d[pd++] = c[i];
//	}
//	d[pd] = 0;
//}
//char f[1001][100001];
//int main()
//{
//	strcpy(f[1], "1");
//	strcpy(f[2], "1");
//	int n; cin >> n;
//	for (int i = 3; i <= n; i++)
//	{
//		bigadd(f[i - 1], f[i - 2], f[i]);
//	}
//	cout << f[n];
//	return 0;
//}

