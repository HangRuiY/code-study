#include <iostream>
using namespace std;
#pragma region 2009_42题，即王道书 2.3.7_大题_17
//带表头的单链表，只给出一个头指针list，查找链表倒数第k个位置上的结点，输出data，返回1，否则只返回0
//思想：两个指针，从第一个有数据的结点开始，用count计数，当count<k时，仅移动q指针，当count>=k时，两个一起移动，直到q指针为空，此时p指针的位置就是倒数第k个
//算法性能：时间O(n),空间O(1)
typedef struct Node
{
	int data; struct Node* link;
}Node,*LinkList;
void Init(LinkList& list)
{
	list = (Node*)malloc(sizeof(Node));
	list->link = NULL;
}
void PushBack(LinkList& list, int x)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = x; p->link = NULL;
	Node* tail = list;
	while (tail->link != NULL)
	{
		tail = tail->link;
	}
	tail->link = p;
}
int Search_k(LinkList& list, int k)
{
	Node* p = list->link; Node* q = list->link;
	int cnt = 0;
	while (q != NULL)
	{
		if (cnt < k) cnt++;
		else p = p->link;
		q = q->link;
	}
	if (cnt < k)
		return 0;
	cout << p->data << endl;
	return 1;
}
int main()
{
	LinkList list; Init(list);
	PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PushBack(list, 5);
	cout << Search_k(list, 2);
}
#pragma endregion

#pragma region 2012_42题，即王道书 2.3.7_大题_18
//带头结点单链表，两个单词有相同后缀时，共享同一后缀空间，现在找出两个单词的后缀起始位置
//思想：假设str1长度为m，str2长度为n，m比n大，则让存放str1的单链表先走m-n个结点，之后两个共同走，如果str1->next==str2->next,则起始节点就是str1->next
//算法性能：时间O(n) 空间O(1)
//typedef struct Node
//{
//	char data; struct Node* next;
//}Node, * LinkList;
//int getLength(LinkList list)
//{
//	int cnt = 0; list = list->next;
//	while (list != NULL)
//	{
//		cnt++; list = list->next;
//	}
//	return cnt;
//}
//Node* SearchLast(LinkList str1, LinkList str2)
//{
//	int m = getLength(str1); int n = getLength(str2);//获取长度
//	Node* p = str1->next; Node* q = str2->next;//两个指针开始遍历
//	if (m > n)//第一个链表长，p先走m-n个
//	{
//		int i = 1;
//		while (i <= m - n)
//		{
//			i++; p = p->next;
//		}
//	}
//	else if (m < n)//第二个链表长，q先走n-m个
//	{
//		int i = 1;
//		while (i <= n-m)
//		{
//			i++; q = q->next;
//		}
//	}
//	while (p->next != NULL && q->next != NULL && p->next != q->next)//一样长或者已经同步 就一起走
//	{
//		p = p->next; q = q->next;
//	}
//	return p->next;
//}
#pragma endregion

#pragma region 2015_41题，即王道书 2.3.7_大题_19
//单链表保存m个数，对于链表中data的绝对值相同的结点，保留第一次出现的结点，删除其他
//思想：双指针，p和q一开始指向第一个节点，然后检查q->next的绝对值，如果和p的绝对值相同，则删除q指向的下一个结点。之后q循环往后走
//算法性能：时间O(n^2) 空间O(1)
//typedef struct Node
//{
//	int data; struct Node* link;
//}Node,*LinkList;
//void Init(LinkList& list)
//{
//	list = (Node*)malloc(sizeof(Node));
//	list->link = NULL;
//}
//void PushBack(LinkList& list, int x)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = x; p->link = NULL;
//	Node* tail = list;
//	while (tail->link != NULL)
//	{
//		tail = tail->link;
//	}
//	tail->link = p;
//}
//void Print(LinkList list)
//{
//	Node* p = list->link;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->link;
//	}
//}
//int abs(int x)
//{
//	if (x >= 0) return x;
//	else return -x;
//}
//void Delete(LinkList& list)
//{
//	Node* p = list->link; Node* q = p->link;
//	for (; p != NULL;p=p->link)
//	{
//		int cur = abs(p->data);//计算p结点的值的绝对值
//		for (q=p; q->link != NULL;)
//		{
//			if (cur == abs(q->link->data))//出现和p绝对值相等的结点了，删除q的下一个结点
//			{
//				Node* temp = q->link;
//				q->link = temp->link;
//				free(temp);
//				continue;
//			}
//			q = q->link;
//		}
//	}
//}
//int main()
//{
//	LinkList list; Init(list);
//	PushBack(list, 21);PushBack(list, -15);PushBack(list, -15);PushBack(list, -7);PushBack(list, 15);
//	Delete(list);
//	Print(list);
//}
#pragma endregion

