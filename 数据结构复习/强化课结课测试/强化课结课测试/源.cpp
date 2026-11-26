#include <iostream>
using namespace std;
#pragma region 多项式单链表
//一元多项式，用链表表示，系数为0的不用存储，返回两个多项式相加的结果存到A
//思想：p指针遍历A链表，q指针遍历B链表，比较p和q所指结点的次数，
//      如果次数相同，改变p结点的系数值，p和q一起往后走，
//      如果不同，如果p结点的次数高于q结点次数，需要把q结点插入到p结点之前,q往后走
//	    如果p结点的次数低于q结点次数，p结点往后走。p结点到尾时，把剩余的B链表元素接到A后面
//时间：O(n)，空间：O(1)
typedef struct Node
{
	int co; int ex;
	struct Node* next;
}Node,*Linklist;
void Init(Linklist &L)
{
	L = (Node*)malloc(sizeof(Node));L->next = NULL;
}
void PushBack(Linklist &L, int co, int ex)
{
	Node* p = (Node*)malloc(sizeof(Node)); p->next = NULL;
	p->co = co; p->ex = ex;
	Node* tail = L;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = p;
}
void Print(Linklist L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		cout << "(" << p->co << "," << p->ex << ")" << " ";
		p = p -> next;
	}
	cout << endl;
}
void Merge(Linklist& L1, Linklist& L2)
{
	Node* p = L1->next; Node* q = L2->next;
	Node* p_prev = L1;
	while (p != NULL && q != NULL)
	{
		if (p->ex == q->ex)
		{
			p->co += q->co;
			q = q->next; p_prev = p; p = p->next; 
		}
		else
		{
			if (p->ex > q->ex)
			{
				Node* t = (Node*)malloc(sizeof(Node));
				t->co = q->co; t->ex = q->ex; t->next = NULL;
				//插入到p_prev之后，p之前
				t->next = p_prev->next;
				p_prev->next = t;
				//移动q
				q = q->next;
			}
			if (p->ex < q->ex)
			{
				p_prev = p; p = p->next;
			}
		}
	}
	while (q != NULL)//L1已经遍历完，L2还有剩余
	{
		PushBack(L1, q->co, q->ex);
		q = q->next;
	}
}
int main()
{
	/*Linklist L1; Init(L1);
	Linklist L2; Init(L2);
	PushBack(L1, 2, 0);PushBack(L1, 4, 3);PushBack(L1, -1, 6);PushBack(L1, 5, 7);
	PushBack(L2, 1, 1);PushBack(L2, 2, 3);PushBack(L2, -2, 8);
	Merge(L1, L2);
	Print(L1);*/
	int ad = 9999; int ans1 = 0, ans2 = 0;
	for (int i = 1; i < 1022; i++)
	{
		for (int j = i; j < 1022; j++)
		{
			if (i * j == 1022)
			{
				if (ad > abs(i - j))
				{
					ad = abs(i - j); ans1 = i; ans2 = j;
				}
			}
		}
	}
	cout << ans1 << " " << ans2 << " " << ad;
}
#pragma endregion

#pragma region 多个升序链表合并成升序链表
//n个升序链表，每个都是升序 合并成一个新的链表
//思想：循环遍历各个链表数组的第一项，找到最小的，标记出这个结点所在的链表号，出循环后，把这个结点插入到新链表尾部
//typedef struct Node
//{
//	char airline[100]; char num[10];
//	int val;
//	struct Node* next;
//}Node,*Linklist;
//void Init(Linklist &L)
//{
//	L = (Node*)malloc(sizeof(Node));L->next = NULL;
//}
//void PushBack(Linklist& L, const char* airline,const char* num,int val)
//{
//	Node* p = (Node*)malloc(sizeof(Node)); p->next = NULL;
//	strcpy(p->airline, airline);
//	strcpy(p->num, num);
//	p->val = val; 
//	Node* tail = L;
//	while (tail->next != NULL)
//		tail = tail->next;
//	tail->next = p;
//}
//Linklist Merge(Linklist list[], int n)
//{
//	Linklist l; Init(l);//新建链表
//	while (1)
//	{
//		int minval = 999;
//		int linkflag = -1;
//		for (int i = 0; i < n; i++)//遍历n个链表
//		{
//			if (list[i]->next != NULL)//最小值大于i号链表的第一个结点 更新最小值 并保存好链表号
//			{
//				if (minval > list[i]->next->val)
//				{
//					minval = list[i]->next->val; linkflag = i;
//				}
//			}
//		}
//		if (linkflag == -1)//找完了
//			break;
//		//把这个结点尾插到新链表
//		PushBack(l, list[linkflag]->next->airline, list[linkflag]->next->num, minval);
//		//让被选链表往后走
//		list[linkflag]->next = list[linkflag]->next->next;
//	}
//	return l;
//}
//void Print(Linklist L)
//{
//	Node* p = L->next;
//	while (p != NULL)
//	{
//		printf("(%s,%s,%d)->", p->airline, p->num, p->val);
//		p = p -> next;
//	}
//	cout << endl;
//}
//#pragma endregion
//int main()
//{
//	Linklist list[2]; Init(list[0]); Init(list[1]);
//	PushBack(list[0], "one", "01", 100);
//	PushBack(list[0], "three", "03", 300);
//	PushBack(list[1], "tow", "02", 200);
//	PushBack(list[1], "four", "04", 400);
//	Linklist l = Merge(list, 2);
//	Print(l);
//}
#pragma endregion

#pragma region 求树结点的平衡因子
typedef struct TNode
{
	int data; int bf;
	struct TNode* left; struct TNode* right;
}TNode;
int getFactor(TNode* T)
{
	if (T == NULL) return 0;
	int left = getFactor(T->left);
	int right = getFactor(T->right);
	T->bf = left - right;
	return left > right ? left + 1 : right + 1;
}
void setBalanceFactor(TNode* T)
{
	getFactor(T);
}
#pragma endregion

