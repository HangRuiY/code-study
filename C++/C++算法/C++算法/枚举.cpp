#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
//枚举 打印出1-100的勾股数
//int flag[10010];
//int main()
//{
//	flag[10010] = { 0 };
//	//用空间换时间
//	for (int i = 1; i <= 100; i++)
//	{
//		flag[i * i] = i;
//	}
//	//flag[3]==0
//	for (int i = 1; i <= 100; i++)
//	{
//		for (int j = i; j <= 100; j++)
//		{
//			if (i * i + j * j >= 100 * 100)
//				break;
//			if (flag[i * i + j * j] != 0)
//				cout << i << " " << j << " " << flag[i * i + j * j] << endl;
//		}
//	}
//	return 0;
//}

//一个n*n的表，第i行第j列的元素是i*j,现在给一个x，求x在表中出现的次数
//int main()
//{
//	int n, t;
//	while (scanf("%d %d", &n, &t) != EOF)
//	{
//		int sum = 0;
//		int i;
//		//每一行最多出现一次x，且x必定是行数的整数倍，那么验证这个行数是不是x的因数（x % 行数 == 0），如果是因数，并且
//		//这个数的列数<=n （列数 == x除以行数）
//		for (i = 1; i <= n; i++)
//		{
//			if (t % i == 0 && t / i <= n)
//				sum++;
//		}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//计算机随机产生一个四位数，玩家每次猜一个四位数，计算机会告诉猜对了几个数字，有几个在正确的位置上面。
//现在有多组数组，给我们每一次对话的过程，要求猜出这个数字
//const int maxn = 1e5;
//int vis[maxn];
//int cmp1(int x, int y)
//{
//	int a[4];//存计算机给的数字的各个位 
//	int b[4];//存遍历到的数字的各个位
//	int cnt = 0;//计算对的位有几个
//	int i = 0; int j = 0;
//	while (x)
//	{
//		a[i++] = x % 10;
//		x /= 10;
//	}
//	while (y)
//	{
//		b[j++] = y % 10;
//		y /= 10;
//	}
//	for (int k = 0; k < 4; k++)
//	{
//		for (int p = 0; p < 4; p++)
//		{
//			if (a[k] == b[p])
//			{
//				b[p] = -1;
//				cnt++;
//				break;
//			}
//		}
//	}
//	return cnt;
//}
//int cmp2(int x, int y)
//{
//	int cnt = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		if (x % 10 == y % 10)
//		{
//			cnt++;
//		}
//		x /= 10;
//		y /= 10;
//	}
//	return cnt;
//}
//int main()
//{
//	int n = 0;//对话数量 
//	cin >> n;
//	while (n--)
//	{
//		int x;//计算机给的数字
//		int dui;//对的数字
//		int ni;//在正确的位置上面
//		scanf("%d %d %d", &x, &dui, &ni);
//		for (int i = 1000; i <= 9999; i++)//遍历所有的四位数字
//		{
//			if (vis[i] == 1)
//			{
//				continue;
//			}
//			if (cmp1(x, i) != dui)//遍历到的数字跟给出的x不匹配
//			{
//				vis[i] = 1; //给不匹配的数字标1
//			}
//			if (cmp2(x, i) != ni)
//			{
//				vis[i] = 1;
//			}
//		}
//	}
//	//求正确的数字
//	int ans = 0; int num = 0;
//	for (int i = 1000; i <= 9999; i++)
//	{
//		if (vis[i] == 0)//满足条件
//		{
//			num++;//数量加1
//			ans = i;//记录当前遍历的数字
//		}
//		if (num >= 2)
//		{
//			break;//剔除多余的
//		}
//	}
//	if (num == 1)
//	{
//		cout << "数字是:" << ans;
//	}
//	else
//		cout << "查无此数" << endl;
//	return 0;
//}




