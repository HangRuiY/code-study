#include <iostream>
#include <queue>
using namespace std;
typedef struct
{
	int* elem;
	int length;
}SSTable;
void InitTable(SSTable &st)
{
	st.elem = (int*)malloc(sizeof(int) * 11);
	if (st.elem != NULL)
	{
		st.elem[0] = 1;
		st.elem[1] = 5;
		st.elem[2] = 10;
		st.elem[3] = 13;
		st.elem[4] = 4;
		st.elem[5] = 50;
		st.elem[6] = 30;
		st.elem[7] = 12;
		st.elem[8] = 55;
		st.elem[9] = 44;
		st.elem[10] = 32;
		st.length = 11;
	}
}
//顺序查找
int Search_Seq(SSTable st, int key)
{
	st.elem[0] = key;
	for (int i = 1; i <= st.length; i++)
	{
		if (st.elem[i] == st.elem[0])
			return i;
	}
}
//二分查找 只能找有序表
int Binary_Search(SSTable st, int key)
{
	int low = 0; int right = st.length - 1;
	int mid = 0;
	while (low <= right)
	{
		mid = (low + right) / 2;
		if (st.elem[mid] == key) return mid;
		else if (st.elem[mid] < key) low = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
void Print(SSTable st)
{
	for (int i = 0; i < st.length; i++)
	{
		cout << st.elem[i] << " ";
	}
	cout << endl;
}
void InsertSort(SSTable st)
{
	int i, j;
	for (i = 1; i < st.length; i++)
	{
		if (st.elem[i] < st.elem[i - 1])
		{
			int temp = st.elem[i];
			for (j = i - 1; temp< st.elem[j]; j--)
			{
				st.elem[j + 1] = st.elem[j];
			}
			st.elem[j + 1] = temp;
		}
	}
}
void Binary_Sort(SSTable st)
{
	int i, j, low, mid, right,temp;
	for (i = 1; i < st.length; i++)
	{
		temp = st.elem[i];
		low = 0; right = i - 1;
		while (low <= right)
		{
			mid = (low + right) / 2;
			if (st.elem[mid] > temp) right = mid - 1;
			else low = mid + 1;
		}
		for (j = i - 1; j >= low; j--)
			st.elem[j + 1] = st.elem[j];
		st.elem[low] = temp;
	}
}
void Bubble_Sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = true;
			}
		}
		if (flag == false) return;
	}
}
int Part(int a[], int low, int high)
{
	int pos = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= pos)
			high--;
		a[low] = a[high];
		while (low < high && a[low] <= pos)
			low++;
		a[high] = a[low];
	}
	a[low] = pos;
	return low;
}
void Quick_Sort(int a[], int low, int high)
{
	if (low < high)
	{
		int pos = Part(a, low, high);
		Quick_Sort(a, low, pos - 1);
		Quick_Sort(a, pos + 1, high);
	}
}
void Select_Sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (min != i)
		{
			int t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
}
void Head(int a[], int k, int len)
{
	a[0] = a[k];
	for (int i = 2 * k; i <= len; i*=2)
	{
		if (i < len && a[i] < a[i + 1]) i++;//挑出来左右孩子更大的一个
		if (a[0] >= a[i]) //根最大 不用调整
			break;
		else
		{
			a[k] = a[i];//大的那个孩子来当父结点
			k = i;//下坠 继续调整
		}
	}
	a[k] = a[0];
}
void Build(int a[], int len)
{
	for(int i=len/2;i>0;i--)
	{
		Head(a, i, len);
	}
}
void HeapSort(int a[], int len)
{
	Build(a, len);
	for (int i = len; i > 1; i--)
	{
		int t = a[i];
		a[i] = a[1];//最大的放到最后面
		a[1] = t;
		Head(a, 1, i - 1);//调整剩下的元素
	}
}
void pri(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int* b = (int*)malloc(sizeof(int) * 10);
void Merge(int a[], int low, int mid, int high)
{
	int i, j, k;
	for (k = low; k <= high; k++)
		b[k] = a[k];//把a的复制一份到b
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)//i为左列起点，j为右列起点,k为拷贝起点
	{
		if (b[i] <= b[j])//左列的比右列的小 把左列的放进去
			a[k] = b[i++];
		else//右列的比左列的小 把右列的放进去
			a[k] = b[j++];
	}
	while (i <= mid) a[k++] = b[i++];//左列还有剩余
	while (j <= high)a[k++] = b[j++];//右列还有剩余
}
void MergeSort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);//分割左边
		MergeSort(a, mid + 1, high);//分割右边
		Merge(a, low, mid, high);//合并
	}
}
int main()
{
	//SSTable st;
	//InitTable(st);
	//cout << Search_Seq(st, 55) << endl;
	//InsertSort(a);
	//Print(a);
	//Binary_Sort(a);
	//Print(st);
	int a[10] = { 1,5,3,4,78,6,2,11,13,34 };
	//Bubble_Sort(a, 10);
	//Quick_Sort(a, 0, 9);
	//Select_Sort(a, 10);
	//int a[11] = { 0,1,5,3,4,78,6,2,11,13,34 };
	//HeapSort(a, 10);
	MergeSort(a, 0, 9);
	pri(a, 10);
}