#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <cstdio>
#include <algorithm>
using namespace std;
//求正方形和长方形个数
//int main()
//{
//	long long n, m;
//	cin >> n >> m;
//	long long count1 = 0;
//	long long count2 = 0;
//	long long num1 = n < m ? n : m;
//	long long num2 = n > m ? n : m;
//	for (long long i = 0; i < num1; i++)//数学问题
//	{
//		for (long long j = 0; j < num2; j++)
//		{
//			count2 += (long long)(num1 - i) * (num2 - j); //矩形
//		}
//		count1 += (n - i) * (m - i);//正方形
//	}
//	cout << count1 << endl; cout << count2 - count1;
//}

//A:B:C
//int ans[10];
//void go(int x)
//{
//	ans[x % 10] = 1;
//	ans[x / 10 % 10] = 1;
//	ans[x / 100] = 1;
//}
//bool check(int x, int y, int z)
//{
//	memset(ans, 0, sizeof(ans));
//	if (y > 999 || z > 999)
//		return false;
//	go(x), go(y), go(z);
//	for (int i = 1; i <= 9; i++)
//	{
//		if (ans[i] != 1)
//			return false;
//	}
//	return true;
//}
//int x, y, z, cnt;
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	assert(a, b, c);
//	for (x = 123; x <= 987; x++)
//	{
//		if (x * b % a || x * c % a)
//			continue;
//		y = x * b / a; z = x * c / a;
//		if (check(x, y, z))
//		{
//			cout << x << " " << y << " " << z << endl;
//			cnt++;
//		}
//	}
//	if (cnt == 0)
//		cout << "No!!!" << endl;
//	return 0;
//}

//选数
//long long int a[30], b[30], n, m, we = 0, v = 0, g[30], w7, g1 = 1;
//bool sushu(int x)
//{
//    int i, t = 1;
//    if (x == 1) { return false; }
//    else if (x == 2 || x == 3) { return true; }
//    for (i = 2; i * i <= x; i++)
//    {
//        if (x % i == 0)
//        {
//            t = 0;
//            break;
//        }
//    }
//    if (t) { return true; }
//    else { return false; }
//}
//void dfs(int x, int y)
//{
//    if (y == 0)
//    {
//        if (sushu(v))
//        {
//            we++;
//        }
//        return;
//    }
//    else
//    {
//        for (int w1 = 0; w1 < x; w1++)
//        {
//            if (b[w1] == 0)
//            {
//                b[w1] = 1;
//                v += a[w1];
//                dfs(x, y - 1);
//                b[w1] = 0;
//                v -= a[w1];
//            }
//        }
//    }
//}
//int main()
//{
//    for (w7 = 1; w7 < 21; w7++)
//    {
//        g1 *= w7;
//        g[w7] = g1;
//    }
//    scanf("%lld %lld", &n, &m);
//    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }
//    dfs(n, m);
//    printf("%lld", we / g[m]);
//    return 0;
//}

//组合的输出
//int n, m;//n为数的个数，m为位置的个数 
//int a[22], b[22];//a数组标记位置是否被占，b数组储存对应数值 
//void print() 
//{
//	for (int i = 1; i <= m; i++)
//		printf("%3d", b[i]);//域宽为3，输出数值 
//	printf("\n");//换行别忘了 
//}
//void dfs(int i) 
//{//搜索与回溯 
//	if (i > m) 
//	{
//		print();//打印出结果 
//		return;
//	}
//	for (int j = b[i - 1] + 1; j <= n; j++) 
//	{
//		if (!a[j])
//		{
//			a[j] = 1;
//			b[i] = j;
//			dfs(i + 1);//下一层递归 
//			a[j] = 0;
//		}
//	}
//	return;//回溯 
//}
//int main() 
//{
//	scanf("%d%d", &n, &m);
//	dfs(1);//从1开搜 
//	return 0;
//}

//全排列问题
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

//火星人的手指数字
//int n,m;
//int a[10000];
//int main()
//{
//	cin >> n;
//	cin >> m;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1; i <= m; ++i) 
//		next_permutation(a + 1, a + n + 1);
//	for (int i = 1; i <= n; ++i) 
//		printf("%d ", a[i]);
//	return 0;
//}

//涂国旗
//int mi = 10000;
//int main()
//{
//	int n, m,k,g;
//	cin >> n >> m;//4 5 
//	char a[100][100];
//	int cnt = 0;
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//		cin >> a[i][j];
	//}
//	for (int i = 1; i <= n-2; i++)//白色部分与蓝色部分的边界
//	{
//		for (int j = i+1; j <= n-1; j++) //蓝色部分与红色部分的边界
//		{
//			cnt = 0;
//			for ( k = 1; k <= i; k++)//白色
//				for ( g = 1; g <= m; g++)
//				{
//					if (a[k][g] != 'W')
//						cnt++;
//				}
//			for ( k = i + 1; k <= j; k++) //蓝色
//				for (g = 1; g <= m; g++)
//				{
//					if (a[k][g] != 'B')
//						cnt++;
//				}
//			for (k = j + 1; k <= n; k++)//红色
//				for (g = 1; g <= m; g++)
//				{
//					if (a[k][g] != 'R')
//						cnt++;
//				}
//			mi = min(cnt, mi);
//		}
//	}
//	cout << mi << endl;
//	return 0;
//}

//PERKET酸苦度
//int s[20], b[20], f[20];	//s表示酸度，b表示甜度，f记录是否查找
//int n, j, c = 1, y = 0, ans = 99999999999;		
//void dfs(int x)
//{
//	if (x > n)
//	{
//		return;
//	}
//	else
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if (f[i] == 0)		
//			{
//				c *= s[i];
//				y += b[i];
//				ans = min(ans, abs(c - y));	//取最小值
//				f[i] = 1;		//记录
//				dfs(x + 1);
//				f[i] = 0;		//取消记录
//				c /= s[i];
//				y -= b[i];
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> s[i] >> b[i];
//	}
//	dfs(1);
//	cout << ans;
//}

//临时抱佛脚
//int Left, Right, minn, ans;
//int s[5];
//int a[21][5];
//void search(int x, int y)
//{
//	if (x > s[y]) 
//	{
//		minn = min(minn, max(Left, Right));
//		return;
//	}
//	Left += a[x][y];
//	search(x + 1, y);
//	Left -= a[x][y];
//	Right += a[x][y];
//	search(x + 1, y);
//	Right -= a[x][y];
//}
//int main() 
//{
//	cin >> s[1] >> s[2] >> s[3] >> s[4];
//	for (int i = 1; i <= 4; i++) 
//	{//减少码量
//		Left = Right = 0;
//		minn = 19260817;
//		for (int j = 1; j <= s[i]; j++)
//			cin >> a[j][i];
//		search(1, i);
//		ans += minn;
//	}
//	cout << ans;
//	return 0;
//}

//P2615 [NOIP2015 提高组] 神奇的幻方
//int arr[40][40] = { 0 };
//int n = 0;//行列
//int main()
//{
//	cin >> n;
//	assert(n % 2 == 1);
//	int x, y;
//	x = 1; y = (n + 1) / 2;//1的位置
//	for (int i = 1; i <= n * n; i++)
//	{
//		arr[x][y] = i;
//		if (arr[(x - 2 + n) % n + 1][y % n + 1] == 0) 
//			x = (x - 2 + n) % n + 1, y = y % n + 1;
//		else 
//			x = x % n + 1;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}