#include <iostream>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cstdio>
#include <algorithm>
using namespace std;
//P1803 凌乱的yyy / 线段覆盖
//struct Match//使用结构体将比赛的开始时间和结束时间保存下来
//{
//	int start;//开始时间
//	int end;//结束时间
//}M[1000000];
//bool compare(Match x, Match y)//以结束时间从小到大排序
//{
//	return x.end < y.end;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> M[i].start >> M[i].end;
//	sort(M, M + n, compare);
//	int pos = 0; //上一场比赛的结束时间
//	int num = 0;//能够参加比赛的次数
//	for (int i = 0; i < n; i++)
//	{
//		if (pos <= M[i].start)
//		{
//			pos = M[i].end;
//			num++;
//		}
//	}
//	cout << num;
//	return 0;
//}

//糖果
//int main()
//{
//	long long ans = 0;
//	vector<int>v;
//	int n, x,m;
//	cin >> n >> x;
//	for (int i = 0; i < n; i++)
//	{                             //x=1
//		cin >> m; v.push_back(m); //1 6 1 2 0 4
//	}
//	for (int i = 0; i < n-1; i++)
//	{
//		if (v[i] + v[i + 1] > x)
//		{
//			ans += v[i + 1] - x + v[i]; 
//			v[i + 1] = x - v[i];
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//金币堆
//struct node 
//{
//    double w;//重量 
//    double v;//价值 
//    double p;//性价比 
//}a[105];
//int n;
//double sum, c;
//inline bool cmp(node a, node b)
//{
//    return a.p > b.p;//性价比从大到小排序 
//}
//int main() 
//{
//    cin >> n >> c;
//    for (int i = 1; i <= n; ++i) 
//    {
//        cin >> a[i].w >> a[i].v;
//        a[i].p = a[i].v / a[i].w; 
//    }
//    sort(a + 1, a + n + 1, cmp);//将性价比排序 
//    for (int i = 1; i <= n; ++i) 
//    {
//        if (c >= a[i].w) 
//        {
//            c -= a[i].w;
//            sum += a[i].v;
//        }
//        else 
//        {
//            sum += c * a[i].p;
//            break;
//        }
//    }
//    printf("%.2f", sum);
//    return 0;
//}
//
