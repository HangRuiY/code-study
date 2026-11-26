#include <iostream>
using namespace std;
#pragma region 2010_42题，即王道书 2.2.3_大题_10
//n个整数存在数组内，循环左移p个位置
//思想：找循环前后的数组下标之间的关系，用一个新的数组存放循环后的数据。可以知道，数组下标从0开始时，如果a数组元素下标i大于等于循环量p，则
//      b[i-p]=a[i]，否则b[n-p+i]=a[i]
//算法性能：时间复杂度O(n)，空间复杂度O(n)
//#define N 100
//void test(int a[], int n, int p)
//{
//	int b[1010];
//	for (int i = 0; i < n; i++)
//	{
//		int temp = a[i];
//		if (i < p)
//		{
//			b[n - p + i] = temp;
//		}
//		else if (i >= p)
//		{
//			b[i - p] = temp;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << b[i] << " ";
//	}
//}
//int main()
//{
//	int n,p; cin >> n;//0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
//	int a[100];
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = i;
//	}
//	cin >> p;
//	test(a, n, p);
//	return 0;
//}
#pragma endregion

#pragma region 2011_42题，即王道书 2.2.3_大题_11
//长度L的生序序列S，处于L/2上取整的是中位数。现在有两个等长序列A和B，求出A和B合并后升序序列的中位数
//思想：双指针循环比较A和B数组各个元素，将整合后的升序序列存到C数组，访问到第L个元素就是中位数
//算法性能：时间复杂度O(n)，空间复杂度O(n)
//int getMid(int a[], int b[],int n)
//{
//	int c[5], index = 0;;
//	for (int i = 0,j = 0; i < n && j<n;)
//	{
//		if (a[i] >= b[j])
//		{
//			c[index++] = b[j]; j++;
//		}
//		else if (a[i] < b[j])
//		{
//			c[index++] = a[i]; i++;
//		}
//		if (index >= n)
//			break;
//	}
//	for (int i = 0; i < index; i++)
//		cout << c[i] << " ";
//	return c[n-1];
//}
//int main()
//{
//	int a[5] = { 2,4,6,8,11};
//	int b[5] = { 8,13,15,17,19};
//	int mid = getMid(a, b,5);
//	cout << mid;
//}
#pragma endregion

#pragma region 2013_41题，即王道书 2.2.3_大题_12
//序列A，如果ap1=ap2=...=apm=x，且m>n/2，则x为A的主元素，求A的主元素
//思想：遍历整个数组，由于每个元素都在0到（n-1）这个范围内，则可以给每个值出现的次数做一个标记，之后标记次数m>n/2的就是主元素
//算法性能：时间O(n)，空间O(n)
//int getMain(int a[], int n)
//{
//	int m[8] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		m[a[i]]++;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (m[i] > n / 2)
//			return m[i];
//	}
//	return -1;
//}
//int main()
//{
//	int a[8] = { 0,5,5,3,5,1,5,7 };//0,5,5,3,5,1,5,7
//	int main = getMain(a, 8);
//	cout << main;
//}
#pragma endregion

#pragma region 2018_41题，即王道书 2.2.3_大题_13
//找出数组中 未出现的最小正整数
//思想：设置一个标记数组vis[1010]，遍历当前数组，如果出现当前数则置vis为1，之后遍历vis数组，输出第一个正整数且vis为0的vis下标
//算法性能：时间O(n)，空间O(n)
//int getMin(int a[], int n)
//{
//	int vis[1010] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] >= 0)
//			vis[a[i]] = 1;
//	}
//	for (int i = 1;; i++)//从1开始即可，因为0不是正整数
//	{
//		if (!vis[i])
//		{
//			return i;
//			break;
//		}
//	}
//}
//int main()
//{
//	int a[4] = { 1,2,3,4};
//	cout << getMin(a, 4);
//}
#pragma endregion

#pragma region 2020_41题，即王道书 2.2.3_大题_14
//三元组abc距离D=|a-b|+|b-c|+|c-a|,3个非空升序序列，存在3个数组s1,s2,s3内，(a,b,c)分别从s1,s2,s3这三个数组内取，求所有三元组最小的距离d
//思想：d由三项构成，第一项的值遍历s1和s2，找到第一项最小值后锁定这两个值，后续不再修改。第二项遍历s3，找到c，第三项自然就确定好了
//性能:时间O(n^2) 空间O(1)
//int abs(int a)
//{
//	if (a < 0) return -a;
//	else return a;
//}
//int getDis(int s1[], int s2[], int s3[], int n1, int n2, int n3)
//{
//	int d1=999, d2=999, d3 = 999;
//	int flag1 = 0; int flag2 = 0; int flag3 = 0;//a b c的下标，锁定作用
//	for (int i = 0; i < n1; i++)//第一项
//	{
//		for (int j = 0; j < n2; j++)
//		{
//			if (d1 > abs(s1[i] - s2[j]))//如果d1小于绝对值函数的返回值，则更新
//			{
//				d1 = abs(s1[i] - s2[j]);
//				flag1 = i; flag2 = j;//每次修改flag的值
//			}
//		}
//	}
//	for (int i = 0; i < n3; i++)//第二项
//	{
//		if (d2 > abs(s2[flag2] - s3[i]))//b已经确定，现在只需要确定c
//		{
//			d2 = abs(s2[flag2] - s3[i]);
//			flag3 = i;
//		}
//	}
//	d3 = abs(s3[flag3] - s1[flag1]);
//	cout << s1[flag1] << " " << s2[flag2] << " " << s3[flag3] << endl;
//	return d1 + d2 + d3;
//}
//int main() 
//{
//	int s1[3] = { -1,0,9 };
//	int s2[4] = { -25,-10,10,11 };
//	int s3[5] = { 2,9,17,30,41 };
//	cout << getDis(s1, s2, s3,3,4,5);
//}
#pragma endregion

#pragma region 2016_43题，即王道书 8.3.3_大题_4
//集合A，划分为不想交的子集A1,A2，元素个数为n1,n2，元素之和为s1,s2，满足|n1-n2|最小，|s1-s2|最大
//思想：用快速排序排出升序序列，之后把前n/2(下取整)个放到A1,把剩余的放到A2即可
//算法性能：时间O(nlog2n) 空间O(n)
//int Partion(int a[], int low, int high)
//{
//	int index = a[low];//子集第一个元素为关键字
//	while (low < high)
//	{
//		while (low < high && a[high] >= index) high--;//从右往左 找小于index的插入到左边
//		a[low] = a[high];
//		while (low < high && a[low] <= index) low++;//从左往右 找大于index的插入到右边
//		a[high] = a[low];
//	}
//	a[low] = index;//剩下的空位插入index
//	return low;
//}
//void QuickSort(int a[], int low, int high)
//{
//	if (low < high)
//	{
//		int p = Partion(a, low, high);//划分数组
//		QuickSort(a, low, p - 1);//一次划分后 就确定了p下标元素的位置
//		QuickSort(a, p + 1, high);
//	}
//}
//int getAns(int a[], int a1[], int a2[],int n)
//{
//	int s1 = 0; int s2 = 0;
//	for (int i = 0; i < n / 2; i++)
//	{
//		a1[i] = a[i]; s1 += a1[i];
//	}
//	for (int i = n / 2,j=0; i < n; i++,j++)
//	{
//		a2[j] = a[i]; s2 +=a2[j];
//	}
//	return s2 - s1;
//}
//int main()
//{
//	int a[15] = { 1,8,6,7,5,9,3,4,2,11,13,14,10,15,12 };//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15  28
//	QuickSort(a, 0, 14);
//	int a1[7] = { 0 }; int a2[8] = { 0 };
//	cout << getAns(a, a1, a2,15);
//}
#pragma endregion
