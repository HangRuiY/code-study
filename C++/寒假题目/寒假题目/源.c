#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//12.31
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=MpklFfn0hUyJKVbRFh8x522osOOc9tjRbDrimLxl2ec6Ot4JuvzlCvCqTqE3npHI&search_content=13%E5%B9%B412%E6%9C%88CCF
//出现最多的数
//int main()
//{
//    int n = 0; scanf("%d", &n);//6
//    int arr[10000] = { 0 };
//    
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d ", &arr[i]);
//    }
//    int arr2[10000] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        arr2[arr[i]]++;//arr2 10++ 1++ 10++ 20++ 30++ 20++
//    }
//    int min = 0;
//    for (int i = 0; i < 10000; i++)
//    {
//        if (arr2[i] > min)
//        {
//            min = arr2[i];
//        }
//    }
//    for (int i = 0; i < 10000; i++)
//    {
//        if (arr2[i] == min)
//        {
//            printf("%d", i);
//            break;
//        }
//    }
//    return 0;
//}
//最大的矩形
//int max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int n = 0; scanf("%d", &n);//6
//	int arr[1000] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);//3 1 6 5 2 3
//	}
//	int s = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int left = i, right = i, j = left;
//		while (j >= 0 && arr[j] >= arr[left])
//		{
//			j--;
//		}
//		left = j + 1;
//		j = i;
//		while (j < n && arr[j] >= arr[right])
//		{
//			j++;
//		}
//		right = j - 1;
//		s = max(s, (right - left + 1) * arr[i]);
//	}
//	printf("%d", s);
//	return 0;
//}

//1.1
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=yFllJd9DTuF7HxOUPhaJRinObIjW58rX3tJw26kPsIR2QLa4M8C71kder0WmtQj6&search_content=%E7%AC%AC%E4%B8%80%E6%AC%A1CCF
//窗口
//#define M 15
//int s[M][5];
//int tmp[5];
//int n, m;
//void get(int x, int y)
//{
//	for (int i = n; i > 0; i--) {
//		if (s[i][0] <= x && s[i][1] <= y && s[i][2] >= x && s[i][3] >= y) 
//		{
//			//必须从后往前判断是哪个窗口，因为他要选择顶层的那个 
//			printf("%d\n", s[i][4]);
//			//取出点击窗口中的数据 
//			for (int k = 0; k < 5; k++) 
//			{
//				tmp[k] = s[i][k];
//			}
//			//将上面的窗口都下降一层 
//			for (int j = i; j < n; j++) 
//			{
//				for (int k = 0; k < 5; k++) 
//				{
//					s[j][k] = s[j + 1][k];
//				}
//			}
//			//将点击的窗口置于顶层 
//			for (int k = 0; k < 5; k++) 
//			{
//				s[n][k] = tmp[k];
//			}
//			return;
//		}
//	}
//	printf("IGNORED\n");
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	//s[i][0-3]存坐标值，s[i][4]存的是id,是第几个窗口 
//	for (int i = 1; i <= n; i++) 
//	{
//		for (int j = 0; j < 4; j++) 
//		{
//			scanf("%d", &s[i][j]);
//		}
//		s[i][4] = i;
//	}
//	while (m--) 
//	{
//		int x, y;
//		scanf("%d%d", &x, &y);
//		get(x, y);
//	}
//	return 0;
//}

//1.2
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=tKGnmjpoEN6ZxG5Ll7v4XQtc6783hvvTswVl721jjsK5dkwdbCMsdTVL6f4SrDGI&search_content=%E7%AC%AC%E4%BA%8C%E6%AC%A1ccf
//画图
//struct S
//{
//    int x1, y1, x2, y2;
//}arr[100];
//int main()
//{
//    int n = 0; scanf("%d", &n);//2
//    int arr2[100] = { 0 }; int sum = 0;
//    int arr3[100] = { 0 }; int cnt = 0;
//    int m = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
//        arr2[i] = (arr[i].x2 - arr[i].x1) * (arr[i].y2 - arr[i].y1);
//        sum += arr2[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (!((arr[j].x1 > arr[i].x2) || (arr[j].y1 > arr[i].y2) || (arr[i].x1 > arr[j].x2) || (arr[i].y1 > arr[i].y2)))
//            {
//                if (arr[i].x1 < arr[j].x1)
//                {
//
//                    arr3[cnt] = (arr[j].x1 - arr[i].x2) * (arr[j].y1 - arr[i].y2);
//                    m += arr3[cnt];
//                    cnt++;
//                }
//                else
//                {
//                    arr3[cnt] = (arr[i].x1 - arr[j].x2) * (arr[i].y1 - arr[j].y2);
//                    m += arr3[cnt];
//                    cnt++;
//                }
//            }
//        }
//    }
//    printf("%d", sum - m);
//    return 0;
//}
//字符串大小写
//int main()
//{
//	char s[100] = { 0 };
//	char arr[100] = { 0 };
//	int n = 0;
//	gets(s);
//	int input = 0; 
//	scanf("%d", &input);
//	switch (input)
//	{
//	case 1:
//	{
//		scanf("%d", &n);//5
//		while (n > 0)
//		{
//			scanf("%s", arr);
//			if (strstr(arr,s))
//			{
//				printf("%s\n", arr);
//			}
//			n--;
//		}
//	}
//	case 0:
//	{
//		scanf("%d", &n);
//		{
//			while (n > 0)
//			{
//				scanf("%s", arr);;//变成小写
//				char arr2[100] = { 0 };
//				strcpy(arr2, arr);
//				for (int i = 0; arr[i] != '\0'; i++) 
//				{
//					if (arr[i] < 97) 
//					{
//						arr[i] = arr[i] + 32;
//					}
//				}
//				for (int i = 0; s[i] != '\0'; i++)
//				{
//					if (s[i] < 97)
//					{
//						s[i] = s[i] + 32;
//					}
//				}
//				if (strstr(arr,s))
//				{
//					printf("%s\n", arr2);
//				}
//				n--;
//			}
//		}
//	}
//	}
//	return 0;
//}

//1.3
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=q15vBC2gVuD6uoOWkzNSnsn2qSN1GAKkVPtGUvdsuIP1DCa6hqfgxudsGaqr4iCt&search_content=%E7%AC%AC%E4%B8%89%E6%AC%A1CCF
//Z形扫描
//#define N 510
//int n;
//int a[N][N];
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			scanf("%d", &a[i][j]);
//	}
//	for (int i = 1; i <= 2 * n - 1; i++)//枚举1~2n-1行
//	{
//		if (i % 2 == 0)
//		{
//			for (int j = 1; j <= i; j++)//如果为偶数行那么从第一行开始往下走
//			{
//				if (j <= n && i - j + 1 <= n)//坐标在范围内则输出
//					printf("%d ", a[j][i - j + 1]);
//				else;
//			}
//		}
//		else
//		{
//			for (int j = i; j; j--)//如果为奇数行那么从第i行开始往上走
//			{
//				if (j <= n && i - j + 1 <= n)//坐标在范围内则输出
//					printf("%d ", a[j][i - j + 1]);
//				else;
//			}
//		}
//	}
//	return 0;
//}

//1.4
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=MVaxZ2NPGp9sN9bPjtpdZf0hs140rKGrhJyIiVY1fDlnWnxZgkRB9hQHIjHqPsyA&search_content=%E7%AC%AC%E5%9B%9B%E6%AC%A1CCF
//图形旋转
//#define N 1000
//int arr[N][N];
//int n, m;
//int i, j;
//int main()
//{
//	scanf("%d %d", &n, &m);//2 3 两行三列
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < m; i++) //3
//	{ //三行两列
//		for (j = 0; j < n; j++)  //2
//		{
//			printf("%d ", arr[j][m - i - 1]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//数字排序
//int n;
//int arr[1000];
//int i, j;
//int main()
//{
//	scanf("%d", &n);//12
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);//5 2 3 3 1 3 4 2 5 2 3 5
//	}
//	int tmp = 0;
//	//冒泡排序 升序
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] >= arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	//1 2 2 2 3 3 3 3 4 5 5 5 
//	int sum[1000] = { 0 }; int sum1[1000] = { 0 };
//	for (int i = 0; i < n; i++) //检索每一个元素在他后面出现次数
//	{
//		sum[i] = 1;
//		for (int j = 1; j < n - i; j++)
//		{
//			if (arr[i] == arr[i + j])
//				sum[i]++;
//		}
//	}
//	int k = 0; int arr2[1000] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		arr2[k] = arr[i];
//		sum1[k] = sum[i];
//		i = i + sum[i] - 1;
//		k++;
//	}//保存每个数字出现的最大次数
//	int temp = 0; int x = 0;
//	for (int i = 0; i < k - 1; i++)
//	{
//		for (int j = 0; j < k - 1 - i; j++)
//		{
//			if (sum1[j] < sum1[j + 1])
//			{
//				temp = sum1[j];
//				sum1[j] = sum1[j + 1];
//				sum1[j + 1] = temp;
//				x = arr2[j];
//				arr2[j] = arr2[j + 1];
//				arr2[j + 1] = x;
//			}//按照出现次数进行排序，同时对应的数字也对应改变位置
//		}
//	}
//	for (int i = 0; i < k; i++)
//		printf("%d %d\n", arr2[i], sum1[i]);
//	return 0;
//}
//节日
//#include <iostream>
//#include <cstring>
//using namespace std;
//int a, b, c, y1, y2;
//const int mo[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//int check(int y) {
//    return ((y % 400 == 0) || ((y % 4 == 0) && (y % 100)));
//}
//
//int f(int y, int a, int b, int c) {
//    int res = 0;
//    for (int i = 1850; i < y; i++)
//        res += 365 + check(i);
//
//    for (int i = 1; i < a; i++)
//        if (i == 2) res += mo[i] + check(y);
//        else res += mo[i];
//
//    int t = (2 + res % 7) % 8;//现在计算出了a月1日是星期几
//    if (!t) t = 1;
//
//    res = 1;
//    while (t != c) {
//        t = (t + 1) % 8;
//        if (!t) t = 1;
//        res++;
//    }
//    res += 7 * (b - 1);
//    if (res <= mo[a] + (check(y) && a == 2))  return res;
//    return -1;
//}
//
//int main(void) {
//    cin >> a >> b >> c >> y1 >> y2;
//
//    for (int i = y1; i <= y2; i++) {
//        int res = f(i, a, b, c);
//        if (res == -1) printf("none\n");
//        else printf("%d/%02d/%02d\n", i, a, res);
//    }
//    return 0;
//}

//1.5
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=1gHC4ZByBmT9SsddC2c5kxtldFoPcjkxw45NnSMKaA541GznzTEtuzjLtX1fA1cG&search_content=%E7%AC%AC%E4%BA%94%E6%AC%A1CCF
//数列分段
//int arr[1000];
//int n, i, j;
//int main()
//{
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);//8 8 8 0 12 12 8 0
//    }
//    int cnt = 0; int flag = -1;
//    for (i = 0; i < n; i++)
//    {
//        if (flag != arr[i])
//        {
//            flag = arr[i];
//            cnt++;
//        }
//    }
//    printf("%d", cnt);
//    return 0;
//}
//日期
//int main()
//{
//	int y, d;
//	scanf("%d %d", &y, &d);
//	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
//	{
//		if (d <= 31)
//			printf("%d\n%d", 1, d);
//		else if (d <= 60)
//			printf("%d\n%d", 2, d - 31);
//		else if (d <= 91)
//			printf("%d\n%d", 3, d - 60);
//		else if (d <= 121)
//			printf("%d\n%d", 4, d - 91);
//		else if (d <= 152)
//			printf("%d\n%d", 5, d - 121);
//		else if (d <= 182)
//			printf("%d\n%d", 6, d - 152);
//		else if (d <= 213)
//			printf("%d\n%d", 7, d - 182);
//		else if (d <= 244)
//			printf("%d\n%d", 8, d - 213);
//		else if (d <= 274)
//			printf("%d\n%d", 9, d - 244);
//		else if (d <= 305)
//			printf("%d\n%d", 10, d - 274);
//		else if (d <= 335)
//			printf("%d\n%d", 11, d - 305);
//		else if (d <= 366)
//			printf("%d\n%d", 12, d - 335);
//	}
//	else
//	{
//		if (d <= 31)
//			printf("%d\n%d", 1, d);
//		else if (d <= 59)
//			printf("%d\n%d", 2, d - 31);
//		else if (d <= 90)
//			printf("%d\n%d", 3, d - 59);
//		else if (d <= 120)
//			printf("%d\n%d", 4, d - 90);
//		else if (d <= 151)
//			printf("%d\n%d", 5, d - 120);
//		else if (d <= 181)
//			printf("%d\n%d", 6, d - 151);
//		else if (d <= 212)
//			printf("%d\n%d", 7, d - 181);
//		else if (d <= 243)
//			printf("%d\n%d", 8, d - 212);
//		else if (d <= 273)
//			printf("%d\n%d", 9, d - 243);
//		else if (d <= 304)
//			printf("%d\n%d", 10, d - 273);
//		else if (d <= 334)
//			printf("%d\n%d", 11, d - 304);
//		else if (d <= 365)
//			printf("%d\n%d", 12, d - 334);
//
//	}
//	return 0;
//}

//1.6
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=nCP9vqLO97YnHgRI2g9ZCUUnpdHvQcZfSqdkOjW0IlaiQudSZ7BnMWKNFvkVeURo&search_content=%E7%AC%AC%E5%85%AD%E6%AC%A1CCF
//消除棋子
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int a[30][30] = { 0 };
//	int b[30][30] = { 0 };
//	int c[30][30] = { 0 };
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &a[i][j]);
//	// 计算横向的重复三次及以上的数字 
//	for (int i = 0; i < n; i++)
//	{
//		int p = 1;
//		int k = a[i][0];
//		for (int j = 1; j < m; j++)
//		{
//			if (a[i][j] == k)
//			{
//				p++;
//			}
//			else if (p >= 3)
//			{
//				int q = j;
//				for (int l = 0; l < p; l++)
//				{
//					b[i][q - 1] = 1;
//					q--;
//				}
//				k = a[i][j];
//				p = 1;
//			}
//			else
//			{
//				k = a[i][j];
//				p = 1;
//			}
//			if (j == m - 1 && p >= 3)
//			{
//				int q = j;
//				for (int l = 0; l < p; l++)
//				{
//					b[i][q] = 1;
//					q--;
//				}
//			}
//		}
//	}
//	// 计算纵向的重复三次及以上的数字，因其计算方式一样，所以先进行转置，再用之前方法进行计算，
//	// 最后再转置回来，相当于对纵向计算重复三次以上的数字。 
//	//对矩阵进行转置 
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			c[j][i] = a[i][j];
//		}
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		int p = 1;
//		int k = c[i][0];
//		for (int j = 1; j < n; j++)
//		{
//			if (c[i][j] == k)
//			{
//				p++;
//			}
//			else if (p >= 3)
//			{
//				int q = j;
//				for (int l = 0; l < p; l++)
//				{
//					c[i][q - 1] = 0;
//					q--;
//				}
//				k = c[i][j];
//				p = 1;
//			}
//			else
//			{
//				k = c[i][j];
//				p = 1;
//			}
//			if (j == n - 1 && p >= 3)
//			{
//				int q = j;
//				for (int l = 0; l < p; l++)
//				{
//					c[i][q] = 0;
//					q--;
//				}
//			}
//		}
//	}
//	// 再进行转置 
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			a[j][i] = c[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (b[i][j] == 1)
//				a[i][j] = 0;
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//画图
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//char g[N][N];
//int n, m, q;
//bool st[N][N];
//
//const int dx[] = { -1,0,+1,0 };
//const int dy[] = { 0,+1,0,-1 };
//
//void dfs(int x, int y, char c) {
//    st[x][y] = 1;
//    g[x][y] = c;
//
//    for (int i = 0; i < 4; i++) {
//        int a = x + dx[i], b = y + dy[i];
//        if (a < 0 || a >= n || b < 0 || b >= m) continue;
//        if (st[a][b] || g[a][b] == '-' || g[a][b] == '|' || g[a][b] == '+') continue;
//        dfs(a, b, c);
//    }
//    return;
//}
//
//int main(void) {
//    scanf("%d%d%d", &m, &n, &q);
//
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            g[i][j] = '.';
//
//    int op, x1, y1, x2, y2;
//    char s[5];
//
//    while (q--) {
//        scanf("%d", &op);
//
//        if (!op) {
//            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
//            if (x1 == x2) {
//                if (y1 > y2) swap(y1, y2);
//                for (int i = y1; i <= y2; i++)
//                    if (g[x1][i] == '|' || g[x1][i] == '+') g[x1][i] = '+';
//                    else g[x1][i] = '-';
//            }
//            else {
//                if (x1 > x2) swap(x1, x2);
//                for (int i = x1; i <= x2; i++)
//                    if (g[i][y1] == '-' || g[i][y1] == '+') g[i][y1] = '+';
//                    else g[i][y1] = '|';
//            }
//        }
//        else {
//            memset(st, 0, sizeof st);
//            scanf("%d%d%s", &y1, &x1, s);
//            dfs(x1, y1, *s);
//        }
//    }
//
//    for (int i = n - 1; i >= 0; i--)
//        printf("%s\n", g[i]);
//
//    return 0;
//}

//1.7
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=1p7vjiYFv0cMLKdWsZL8oOjucsn0Gf4qtRzKEUg6NURJtJIwRfVixliRIzetgN5O&search_content=%E7%AC%AC%E4%B8%83%E6%AC%A1ccf
//俄罗斯方块
//#include <iostream>
//using namespace std;
//
//int main() {
//	short A[15][10], B[4][4], local[4][2];
//	int n, i, j, flag = 0, row = 0, l = 0;
//	for (i = 0; i < 15; i++) {
//		for (j = 0; j < 10; j++) {
//			cin >> A[i][j];
//		}
//	}
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			cin >> B[i][j];
//		}
//	}
//	cin >> n;
//	n--;
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			if (B[i][j] == 1) {
//				local[l][0] = i;
//				local[l][1] = n + j;
//				l++;
//			}
//		}
//	}
//	//在保证四个位置的下一行该列都不为1时 行自增 直到出现一个为1的为止
//	while (local[0][0] + 1 != 15 && local[1][0] + 1 != 15 && local[2][0] + 1 != 15 && local[3][0] + 1 != 15 &&
//		A[local[0][0] + 1][local[0][1]] != 1 && A[local[1][0] + 1][local[1][1]] != 1 &&
//		A[local[2][0] + 1][local[2][1]] != 1 && A[local[3][0] + 1][local[3][1]] != 1) {
//		local[0][0]++;
//		local[1][0]++;
//		local[2][0]++;
//		local[3][0]++;
//	}
//	for (i = 0; i < 4; i++) {
//		A[local[i][0]][local[i][1]] = 1;
//	}
//	for (i = 0; i < 15; i++) {
//		for (j = 0; j < 10; j++) {
//			cout << A[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//1.9
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=yyYRx3uo4RxmDmcZwYArv4CI6anwvtnw0mJFZIAgxANzAzFeCw0pZc9MQxeo5Dfa&search_content=%E7%AC%AC%E5%85%AB%E6%AC%A1ccf
//火车购票				//应当设立一个结构体  其中变量m表示该排是否满了 ,A[i]表示i坐位是否已经被占 
//struct sit 
//{
//    int A[5];
//    int m;
//};
//int main() 
//{
//    int n, i = 0, a, c, j = 0, k = 0, key = 0, A[100];
//    struct sit B[20];                       //设置20个结构体数组,在100中的序号用i*5表示 
//    scanf("%d", &n);                        //n中存放买票人的数量 
//    while (i < n) 
//    {                        // A[i]表示第i个人买了多少 票   注:区别结构体中的A[i] 
//        scanf("%d", &A[i]);
//        i++;
//    }
//    for (i = 0; i < 20; i++) 
//    {                //对结构体数组进行初始化 
//        B[i].m = 5;
//        for (j = 0; j < 5; j++) 
//        {
//            B[i].A[j] = 0;       //表示第i排的第j个坐位未被购买 
//        }
//    }
//    a = 0;
//    while (a < 100) 
//    {       //关键步骤:每次循环都代表一个人已经找够了坐位,若所有人都找够了坐位,退出循环 
//        i = 0;
//        while (i < 20 && k < n) 
//        {                 //开始找坐位   用key表示第一次找是否能找到 
//            key = 0;
//            if (B[i].m >= A[k]) 
//            {         //如果某一排有足够多的坐位 
//                for (j = 0; j < 5 && A[k]>0; j++) 
//                {                           //开始占座 
//                    if (B[i].A[j] == 0) 
//                    {
//                        B[i].A[j] = 1;
//                        printf("%d ", i * 5 + j + 1);
//                        A[k]--;
//                        B[i].m--;
//                    }
//                }
//                printf("\n");
//                k++;
//                key = 1;
//                i = 0;     //已经找到了坐位换下一个人从头开始遍历 
//            }
//            if (key == 0) 
//            {
//                i++;
//            }
//        }
//        if (i == 20 && key == 0 && k < n) 
//        {  //如果遍历结束还没找到坐位 
//            for (i = 0; i < 20; i++) 
//            {     //从头按顺序坐 
//                for (j = 0; j < 5 && B[i].m>0; j++) 
//                {
//                    if (B[i].A[j] == 0) 
//                    {
//                        B[i].A[j] = 1;
//                        B[i].m--;
//
//                        c = i * 5 + j + 1;
//                        printf("%d ", i * 5 + j + 1);
//                        A[k]--;
//                        if (A[k] == 0) break;
//                    }
//                }
//                if (A[k] == 0) 
//                {    //票如果买够了 
//                    key = 1;
//                    printf("\n");
//                    break;
//                }
//            }
//            k++;
//        }
//        if (k >= n) 
//        {
//            break;
//        }
//        else 
//        {
//            a++;
//        }
//
//    }
//    return 0;
//}
//炉石传说
//#include<iostream>
//#include<cstring>
//#include<string>
//
//using namespace std;
//const int N = 10;
//struct Node {
//    int X, Y;
//}tr[2][N];
//int n;
//
//int main(void) {
//    cin >> n;
//    string s;
//    int a, b, c;
//    int player = 0;
//    tr[0][0].X = tr[1][0].X = 30;
//
//    while (n--) {
//        cin >> s;
//        if (s == "summon") {
//            cin >> a >> b >> c;
//            for (int i = 7; i >= a; i--)
//                if (tr[player][i].X <= 0) continue;
//                else tr[player][i + 1] = tr[player][i];
//            tr[player][a] = { c,b };
//        }
//        else if (s == "attack") {
//            cin >> a >> b;
//            tr[player][a].X -= tr[player ^ 1][b].Y;
//            tr[player ^ 1][b].X -= tr[player][a].Y;
//
//            for (int i = 1; i <= 7; i++)
//                if (tr[0][i].X > 0) continue;
//                else {
//                    tr[0][i] = tr[0][i + 1];
//                    tr[0][i + 1].X = 0;
//                }
//
//            for (int i = 1; i <= 7; i++)
//                if (tr[1][i].X > 0) continue;
//                else {
//                    tr[1][i] = tr[1][i + 1];
//                    tr[1][i + 1].X = 0;
//                }
//        }
//        else player ^= 1;
//    }
//
//    if (tr[0][0].X > 0 && tr[1][0].X > 0) printf("0\n");
//    else if (tr[0][0].X > 0) printf("1\n");
//    else printf("-1\n");
//
//    printf("%d\n", tr[0][0].X);
//
//    for (int i = 1; i <= 8; i++)
//        if (tr[0][i].X <= 0) {
//            printf("%d ", i - 1);
//            break;
//        }
//
//    for (int i = 1; i <= 7; i++)
//        if (tr[0][i].X > 0) printf("%d ", tr[0][i].X);
//        else break;
//
//    printf("\n%d\n", tr[1][0].X);
//
//    for (int i = 1; i <= 8; i++)
//        if (tr[1][i].X <= 0) {
//            printf("%d ", i - 1);
//            break;
//        }
//
//    for (int i = 1; i <= 7; i++)
//        if (tr[1][i].X > 0) printf("%d ", tr[1][i].X);
//        else break;
//    return 0;
//}

//1.11
//https://www.acwing.com/problem/search/1/?csrfmiddlewaretoken=tTpqJ6nvOpIJY1GSFHU8IvQwcAiuFJwsYHNB2ZyHnDUE7f22CymwSxGWsSVU3roB&search_content=%E7%AC%AC%E5%8D%81%E6%AC%A1CCF
//3230 游戏
//#include<iostream>
//#include<cstring>
//#include<map>
//
//#define x first
//#define y second
//
//using namespace std;
//typedef pair<int, int> PII;
//typedef pair<PII, int> PIII;
//
//const int N = 110, INF = 0x3f3f3f3f;
//bool d[N][N][N];
//int n, m, q, maxv;
//map<PII, PII> mem;
//
//int bfs() {
//    const int dx[] = { -1,0,+1,0 }, dy[] = { 0,+1,0,-1 };
//
//    PIII q[N * N * N];
//    int hh, tt = -1;
//    q[++tt] = { {1,1},0 };
//    d[1][1][0] = 1;
//
//    while (hh <= tt) {
//        PIII t = q[hh++];
//        for (int i = 0; i < 4; i++) {
//            int a = t.x.x + dx[i], b = t.x.y + dy[i], p = t.y + 1;
//            if (a<1 || a>n || b<1 || b>m) continue;
//            if (d[a][b][p]) continue;
//            if (mem.count({ a,b }) && (mem[{a, b}].x <= p && mem[{a, b}].y >= p)) continue;
//            d[a][b][p] = 1;
//            if (a == n && b == m) return p;
//            q[++tt] = { {a,b},p };
//        }
//    }
//
//    return INF;
//}
//
//int main(void) {
//    scanf("%d%d%d", &n, &m, &q);
//
//    while (q--) {
//        int a, b, c, d;
//        scanf("%d%d%d%d", &a, &b, &c, &d);
//        mem[{a, b}] = { c,d };
//        maxv = max(maxv, d);
//    }
//
//    int res = bfs();
//    if (res != INF) printf("%d\n", res);
//    else {
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++)
//                if (d[i][j][maxv]) res = min(res, n - i + m - j + maxv);
//    }
//
//    return 0;
//}
//学生排队 
//int Move(int a[], int n, int p, int q) {
//    int i, j, direction;
//    for (i = 1; i <= n; i++) {
//        if (a[i] == p) {
//            direction = q / abs(q);//-1前移，1后移
//            for (j = 0; j < abs(q); j++) {
//                a[j * direction + i] = a[(j + 1) * direction + i];
//            }
//            a[j * direction + i] = p;
//            break;
//        }
//    }
//
//}
//
//int main() {
//    int n, m, i, p, q;
//    scanf("%d%d", &n, &m);
//    int* a;
//    a = (int*)calloc(n + 1, sizeof(int));
//    for (i = 1; i <= n; i++) {
//        a[i] = i;
//    }
//    for (i = 0; i < m; i++) {
//        scanf("%d%d", &p, &q);
//        Move(a, n, p, q);
//    }
//    for (i = 1; i <= n; i++)
//        printf("%d ", a[i]);
//    return 0;
//}
