#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1.int main()
//{
//	int j = 6;
//	printf("%D\r\n", j);
//}

//2.int fun3(int x)
//{
//	static int a = 2;
//	a += x;
//	return a;
//}
//int main()
//{
//	int k = 2, m = 1, n;
//	n = fun3(k);
//	n += fun3(m);
//	printf("%d", n);
//}

//int main()
//{
//	int a = 10, b = 9;
//	b = (a + b) - (a = b);
//	printf("%d %d", a, b);
//}

//struct s2
//{
//	char c1;
//	double b;
//	int a;
//};
//struct s3
//{
//	int d;
//	char c;
//	int i;
//	struct s2 t;
//};
//int main()
//{
//	printf("%d", sizeof(struct s2));
//	printf("%d", sizeof(struct s3));
//}

//回文数  1221
//int main()
//{
//	int n = 0;int weishu = 0;
//	scanf("%d", &n);
//	int p = n;
//	while (p)
//	{
//		weishu++;
//		p /= 10;
//	}
//	int arr[100] = { 0 };
//	int i = 0;
//	for (i = 0;i < weishu;i++)
//	{
//		arr[i] = (n % 10);
//		n /= 10;
//	}
//	int left = 0;int right = weishu - 1;int flag = 0;
//	while (left < right)
//	{
//		if (arr[left] == arr[right])
//		{
//			flag++;
//		}
//		left++;right--;
//	}
//	if (flag ==weishu/2)
//		printf("true");
//	else
//		printf("no");
//	return 0;
//	
//}

//n的次方 递归实现
//double po(double x, int y)
//{
//	if (y == 0)
//		return 1;
//	else
//		return po(x, y - 1) * x;
//}
//int main()
//{
//	double m = 0.0; int n = 0;
//	scanf("%lf %d", &m, &n); //2的次方
//	printf("%lf", po(m, n));
//	return 0;
//}

