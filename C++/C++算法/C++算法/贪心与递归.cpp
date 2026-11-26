#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
//贪心：整体分为局部，接着局部进行到最优，且不考虑对后续步骤的影响，后续也不考虑前面的选择
//适用范围：1.最优子结构：一个问题最优解包含子问题的最优解
//          2.选择性质：全局的最优解可以从局部最优解得到
//方法：1.抽象成数学模型，选择贪心策略  2.分解大问题  3.子问题求最优解 4.整合为全局的解


//递归:通过 重复 将问题转换为同类的子问题
//适用范围：构成原问题的子问题，和原问题在结构上相似
//递推：从已知到未知    递归：从未知到已知（递推+回归）

//汉诺塔
//int cnt;
//void hanoi(int n, char src, char t, char tar)
//{
//	if (n == 1)
//	{
//		cout << "Move desk from" << " " << src << " to " << tar << endl;
//		cnt++;
//		return;
//	}
//
//	hanoi(n - 1, src, tar, t);
//	cout << "Move desk from" << " " << src << " to " << tar << endl;
//	cnt++;
//	hanoi(n - 1, t, src, tar);
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cnt = 0;
//		hanoi(n, 'A', 'B', 'C');
//		cout << cnt << endl;
//	}
//}