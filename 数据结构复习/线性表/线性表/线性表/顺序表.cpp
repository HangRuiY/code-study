#include <iostream>
using namespace std;
#define MaxSize 5
typedef struct SeqList
{
	int* data;
	int length;
}SeqList;
void InitList(SeqList& L)
{
	L.data = (int*)malloc(sizeof(int) * MaxSize);
	L.length = 0;
}
bool Insert(SeqList& L, int i, int tmp)
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = tmp;
	L.length++;
	return true;
}
void Print(SeqList L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}
bool Delete(SeqList& L, int i, int& t)
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length <= 0)
		return false;
	t = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
//int main()
//{
//	SeqList L;
//	//初始化顺序表
//	InitList(L);
//	//插入操作
//	Insert(L, 1, 1);
//	Insert(L, 2, 2);
//	Insert(L, 3, 3);
//	Insert(L, 4, 4);
//	Insert(L, 5, 5);
//	Print(L);
//	//删除
//	int t = 0;
//	Delete(L, 3, t);
//	Print(L);
//	return 0;
//}