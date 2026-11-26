#include <iostream>
using namespace std;
#pragma region 在你的笔记本上整理快速排序算法代码
//int Partion(int a[], int low, int high)
//{
//	int k = a[low];
//	while (low < high)
//	{
//		while (low < high && a[high] >= k) high--;
//		a[low] = a[high];
//		while (low < high && a[low] <= k) low++;
//		a[high] = a[low];
//	}
//	a[low] = k;
//	return low;
//}
//void QuickSort(int a[], int low, int high)
//{
//	if (low < high)
//	{
//		int p = Partion(a, low, high);
//		QuickSort(a, low, p-1);
//		QuickSort(a, p + 1, high);
//	}
//}
//int main()
//{
//	int a[10] = { 10,9,8,7,6,5,4,3,2,1};
//	QuickSort(a, 0, 9);
//	for (int i = 0; i < 10; i++)
//		cout << a[i] << " ";
//}
#pragma endregion

#pragma region 二刷408真题_2011_42题，即王道书 2.2.3_大题_11
//长度L的生序序列S，处于L/2上取整的是中位数。现在有两个等长序列A和B，求出A和B合并后升序序列的中位数
//思想：双指针循环比较A和B数组各个元素，将整合后的升序序列存到C数组，访问到第L个元素就是中位数
//算法性能：时间复杂度O(n)，空间复杂度O(n)
#pragma endregion

#pragma region 二刷408真题_2013_41题，即王道书 2.2.3_大题_12
//序列A，如果ap1=ap2=...=apm=x，且m>n/2，则x为A的主元素，求A的主元素
//思想：遍历整个数组，由于每个元素都在0到（n-1）这个范围内，则可以给每个值出现的次数做一个标记，之后标记次数m>n/2的就是主元素
//算法性能：时间O(n)，空间O(n)
#pragma endregion

#pragma region 二刷408真题_2018_41题，即王道书 2.2.3_大题_13
//找出数组中 未出现的最小正整数
//思想：设置一个标记数组vis[1010]，遍历当前数组，如果出现当前数则置vis为1，之后遍历vis数组，输出第一个正整数且vis为0的vis下标
//算法性能：时间O(n)，空间O(n)
#pragma endregion

#pragma region 二刷408真题_2016_43题，即王道书 8.3.3_大题_4
//集合A，划分为不想交的子集A1,A2，元素个数为n1,n2，元素之和为s1,s2，满足|n1-n2|最小，|s1-s2|最大
//思想：用快速排序排出升序序列，之后把前n/2(下取整)个放到A1,把剩余的放到A2即可
//算法性能：时间O(nlog2n) 空间O(n)
#pragma endregion

#pragma region 在你的笔记本上整理快速排序算法代码
//int b[10] = { 0 };//辅助数组
//void Merge(int a[], int low, int mid, int high)
//{
//	for (int i = low; i <= high; i++)
//		b[i] = a[i];
//	int i, j, k;
//	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)//i指针检查左侧序列，j指针检查右侧序列,i,j作用于b数组，k指针给a数组更新数据
//	{
//		if (b[i] <= b[j])//将小值放到a数组
//			a[k] = b[i++];
//		else a[k] = b[j++];
//	}
//	while (i <= mid) a[k++] = b[i++];//左侧有剩余，直接添加
//	while (j <= high) a[k++] = b[j++];//右侧有剩余，直接添加
//}
//void MergeSort(int a[], int low, int high)
//{
//	if (low < high)
//	{
//		int mid = (low + high) / 2;//从中间划分两个序列
//		MergeSort(a, low, mid);//左侧递归
//		MergeSort(a, mid + 1, high);//右侧递归
//		Merge(a, low, mid, high);//合并
//	}
//}
//int main()
//{
//	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	MergeSort(a, 0, 9);
//	for (int i = 0; i < 10; i++)
//		cout << a[i] << " ";
//}
#pragma endregion

#pragma region 三刷408真题_2011_42题，即王道书 2.2.3_大题_11
//长度L的生序序列S，处于L/2上取整的是中位数。现在有两个等长序列A和B，求出A和B合并后升序序列的中位数
//思想：双指针循环比较A和B数组各个元素，将整合后的升序序列存到C数组，访问到第L个元素就是中位数
//算法性能：时间复杂度O(n)，空间复杂度O(n)
#pragma endregion
