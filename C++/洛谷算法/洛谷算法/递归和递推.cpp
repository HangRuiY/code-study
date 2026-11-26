#include <iostream>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
//P1044 [NOIP2003 普及组] 栈
//#define max 20
//typedef long long ll;
//ll f[max][max];//表示情况数
//ll dfs(int i, int j) //i表示待排 j表示栈内/
//{
//	if (f[i][j])
//		return f[i][j];
//	if (i == 0)
//		return 1;
//	//栈空：只能入数据 f[i][j]+=dfs(i-1,j+1)
//	//栈不空:1.入一个 出一个   2.出一个
//	if (j > 0)
//	{
//		f[i][j] += dfs(i, j - 1);
//	}
//	f[i][j] += dfs(i - 1, j + 1);
//	return f[i][j];
//}
//int main()
//{
//	int n = 0; cin >> n;
//	cout << dfs(n, 0);
//	return 0;
//}

//P1028 [NOIP2001 普及组] 数的计算
//int main() {
//    int n, cnt = 1, i, f[1010];
//    f[0] = f[1] = 1;
//    scanf("%d", &n);
//    for (i = 2; i <= n; i++) {
//        if (i % 2 == 0) {
//            f[i] = f[i - 1] + f[i / 2];
//        }
//        else {
//            f[i] = f[i - 1];//2n与2n+1(n为非负整数)的答案是一样的
//        }
//    }
//    printf("%d\n", f[n]);
//}

//P1464 Function
//typedef long long ll;
//ll ans[25][25][25];
//ll w(ll a, ll b, ll c)
//{
//    if (a <= 0 || b <= 0 || c <= 0) 
//        return 1;
//    else if (ans[a][b][c] != 0) 
//        return ans[a][b][c];
//    else if (a > 20 || b > 20 || c > 20) 
//        ans[a][b][c] = w(20, 20, 20);
//    else if (a < b && b < c) 
//        ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//    else ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
//    return ans[a][b][c];
//}
//int main()
//{
//    ll a, b, c;
//    while (scanf("%lld %lld %lld", &a, &b, &c)) 
//    {
//        if (a == -1 && b == -1 && c == -1) 
//            break;
//        memset(ans, 0, sizeof(ans));
//        printf("w(%lld, %lld, %lld) = ", a, b, c);
//        if (a > 20) 
//            a = 21;
//        if (b > 20) 
//            b = 21;
//        if (c > 20) 
//            c = 21;
//        printf("%lld\n", w(a, b, c));
//    }
//    return 0;
//}

//过河卒
//const int fx[] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
//const int fy[] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
//int bx, by, mx, my;
//long f[2][40];  
//bool s[40][40];
//int main()
//{
//    scanf("%d%d%d%d", &bx, &by, &mx, &my);
//    bx += 2; by += 2; mx += 2; my += 2;
//    f[1][2] = 1; 
//    s[mx][my] = 1;
//    for (int i = 1; i <= 8; i++) s[mx + fx[i]][my + fy[i]] = 1;
//    for (int i = 2; i <= bx; i++) 
//    {
//        for (int j = 2; j <= by; j++) 
//        {
//            if (s[i][j]) 
//            {
//                f[i & 1][j] = 0; //被马拦住了记住清零
//                continue;
//            }
//            f[i & 1][j] = f[(i - 1) & 1][j] + f[i & 1][j - 1];//新的状态转移方程
//        }
//    }
//    printf("%lld\n", f[bx & 1][by]);
//    return 0;
//}

//蜜蜂路线
//int n, m, len = 1;
//int f[1005][1005];
//void pl(int x)
//{
//	for (int i = 1; i <= len; i++)
//		f[x][i] = f[x - 1][i] + f[x - 2][i];
//	for (int i = 1; i <= len; i++)
//		if (f[x][i] > 9)
//		{
//			f[x][i + 1] += f[x][i] / 10;
//			f[x][i] %= 10;
//		}
//	if (f[x][len + 1]) 
//		len++;
//}
//int main()
//{
//	scanf("%d%d", &m, &n);
//	f[1][1] = 1, f[2][1] = 2;
//	for (int i = 3; i <= n - m; i++)
//		pl(i);
//	for (int i = len; i; i--) 
//		printf("%d", f[n - m][i]);
//	return 0;
//}

//P3612 [USACO17JAN]Secret Cow Code S
//char arr[40];
//long long n, ans;
//int main()
//{
//	char ch = 0;
//	while (scanf("%c", &ch),ch != ' ')
//	{
//		arr[++ans] = ch;
//	}
//	cin >> n;//第几位
//	while (ans < n)
//	{
//		long long t = ans;
//		while (n>t*2)
//		{
//			t *= 2;
//		}
//		n -= (t+1);
//		if (n == 0)
//			n = t;
//	}
//	cout << arr[n];
//	return 0;
//}

void f(int x)
{
	for (int i = 14; i >= 0; i--)
	{
		if (pow(2, i) <= x)
		{
			if (i == 1)
				cout << "2";
			else if (i == 0)
				cout << "2(0)";
			else
			{
				cout << "2(";
				f(i);
				cout << ")";
			}
			x -= pow(2, i);
			if (x != 0)
				cout << "+";
		}
	}
}
int main()
{
	int n = 0; cin >> n;
	f(n);
	return 0;
}