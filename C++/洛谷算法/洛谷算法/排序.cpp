#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <assert.h>
using namespace std;
//奖学金
//class person
//{
//public:
//	person(int num,int C, int M, int E,int sum)
//	{
//		this->mnum = num;
//		this->mC = C;
//		this->mM = M;
//		this->mE = E;
//		this->msum = sum;
//	} 
//	int mnum,mC, mM, mE,msum;
//};
//bool cmp(person &a, person &b)
//{
//	if (a.msum > b.msum)
//		return 1;
//	else if (a.msum < b.msum)
//		return 0;
//	else
//	{
//		if (a.mC > b.mC)
//			return 1;
//		else if (a.mC < b.mC)
//			return 0;
//		else
//		{
//			if (a.mnum > b.mnum)
//				return 0;
//			else
//				return 1;
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int num,C, M, E,sum;
//	vector<person>v;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> C >> M >> E;
//		num = i;
//		sum = C + M + E;
//		person p(i,C,M,E,sum);
//		v.push_back(p);
//	}
//	sort(v.begin(), v.begin()+n, cmp);
//	for (int i = 0; i < 5; i++)
//	{
//		cout << v[i].mnum << " " << v[i].msum << endl;
//	}
//	return 0;
//}
//
//
//

//分数线划定
//class member
//{
//public:
//	member(int num, int score)
//	{
//		this->mnum = num; this->msc = score;
//	}
//	int mnum; int msc;
//};
//bool compare(member& p1,member& p2)
//{
//	if (p1.msc != p2.msc)
//		return p1.msc >= p2.msc;
//	else
//		return p1.mnum <= p2.mnum;
//}
//int main()
//{
//	vector<member>v;
//	int n = 0; int m = 0;
//	cin >> n >> m; //6 3
//	for (int i = 0; i < n; i++)
//	{
//		int num; int sc;
//		cin >> num >> sc;
//		member p(num, sc);
//		v.push_back(p);
//	}
//	sort(v.begin(), v.end(), compare);
//	int p = m * 1.5;
//	int ksc = v[p - 1].msc;
//	cout << ksc<<" ";
//	int cnt = 0;
//	for (vector<member>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		if (it->msc >= ksc)
//			cnt++;
//	}
//	cout << cnt << endl;
//	int i = 0;
//	for (vector<member>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << it->mnum << " " << it->msc << endl;
//		i++;
//		if (i == cnt)
//			break;
//	}
//	return 0;
//}

//拼数
//int main()
//{
//	string a[25];
//	int n; cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (a[j] + a[j + 1] < a[j + 1] + a[j])
//				swap(a[j], a[j + 1]);
//		}
//	}
//	for (int i = 0; i < n; i++)
//		cout << a[i];
//	return 0;
//}