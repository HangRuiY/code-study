#include <iostream>
using namespace std;
#pragma region 2019_41题，即王道书 2.3.7_大题_20
//带头结点单链表，空间复杂度O(1)，排列成1,n,2,n-1,3,n-2...这个顺序
//思想：p指向第一个元素，q指向倒数第二个元素，每次执行如下操作：把q->next插入到p结点之后，删除q->next,让q=q的前一个结点。然后p结点一次性走两个结点
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
//	cout << endl;
//}
//void pailie(LinkList& list)
//{
//	Node* p = list->link; Node* q = NULL;
//	if (p->link == NULL)//只有一个结点
//		return;
//	while (p!=q)//链表长度为奇数时的情况
//	{
//		q = list->link;
//		while (q->link->link != NULL)//找到倒数第二个结点，让q指向这个结点
//		{
//			q = q->link;
//		}
//		if (p == q) break;//链表长度为偶数时的情况
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = q->link->data;
//		temp->link = p->link;
//		p->link = temp;//把最后一个结点插入到p结点之后
//		Node* t = q->link;
//		q->link = NULL;
//		free(t);//删除最后一个结点
//		p = p->link->link;//p结点一次性走两次
//	}
//}
//int main()
//{
//	LinkList list; Init(list);
//	for (int i = 1; i <= 9; i++)
//		PushBack(list, i);
//	Print(list);
//	pailie(list);
//	Print(list);
//}
#pragma endregion

#pragma region 做王道书 2.3.7_大题_3
//带头结点 原地逆置 要求空间复杂度为O(1)
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
//	cout << endl;
//}
//void reverse(LinkList& list)
//{
//	Node* p = list->link; Node* next = NULL;
//	list->link = NULL;//把头结点摘下来 link域置为空
//	while (p != NULL)//用头插法插入
//	{
//		next = p->link;
//		p->link = list->link;
//		list->link = p;
//		p = next;
//	}
//}
//int main()
//{
//	LinkList list; Init(list);
//	for (int i = 1; i <= 6; i++)
//		PushBack(list, i);
//	reverse(list);
//	Print(list);
//}
#pragma endregion

#pragma region 做王道书 2.3.7_大题_6
//a[a1,b1,a2,b2...]用单链表存放，就地拆分其为两个线性表A[a1...an] B[bn...b1]
//思想：偶数的结点都往B放,头插形成逆置 然后再次遍历C，把偶数号结点删去
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
//	cout << endl;
//}
//LinkList chuli(LinkList& A)
//{
//	LinkList B = (Node*)malloc(sizeof(Node));//新建一个链表B
//	B->link = NULL;
//	Node* p = A->link;
//	while (p != NULL)
//	{
//		Node* t = (Node*)malloc(sizeof(Node));//建一个节点
//		t->data = p->link->data; t->link = NULL;
//		//头插到B
//		t->link = B->link;
//		B->link = t;
//		//移动p指针
//		p = p->link->link;
//	}
//	//删除A中多余结点
//	Node* q = A->link;
//	while (q != NULL)
//	{
//		Node* temp = q->link;//temp指向被删除的结点
//		q->link = temp->link;
//		free(temp);
//		q = q->link;//移动q
//	}
//	return B;
//}
//int main()
//{
//	LinkList A; Init(A);
//	for (int i = 1; i <= 10; i++)//1 2 3 4 5 6 7 8 9 10
//		PushBack(A, i);
//	LinkList B = chuli(A);//A:1 3 5 7 9   B:10 8 6 4 2逆置
//	Print(A);
//	Print(B);
//}
#pragma endregion

#pragma region 做王道书 2.3.7_大题_16
//不带头，偶数个元素的单链表，求最大孪生和：i号结点（从0开始）和n-i-1个结点之和
//思想：从0开始，实际上就是第1个和最后1个，第2个和倒数第2个以此类推，因此，可以先建立一个新链表，把原链表逆置，之后遍历到n/2停止就行
//typedef struct Node
//{
//	int data; struct Node* next;
//}Node,*LinkList;
//void PushBack(LinkList& head,int x)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = x; p->next = NULL;
//	if (head == NULL)
//	{
//		head = p; return;
//	}
//	Node* tail = head;
//	while (tail->next!=NULL)
//	{
//		tail = tail->next;
//	}
//	tail->next = p;
//}
//void Print(LinkList head)
//{
//	Node* p = head;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//LinkList reverse(LinkList head)
//{
//	LinkList head2 = NULL;//如果要生成新链表 必须要注意建立结点
//	Node* p = head; Node* next = NULL;
//	while (p != NULL)
//	{
//		next = p->next;
//		//头插
//		if (head2 == NULL)//当前为空
//		{
//			int x = p->data;
//			Node* t = (Node*)malloc(sizeof(Node));
//			t->data = x; t->next = NULL;
//			head2 = t;
//		}
//		else//当前不空
//		{
//			int x = p->data;
//			Node* t = (Node*)malloc(sizeof(Node));
//			t->data = x; t->next = NULL;
//			t->next = head2;
//			head2 = t;
//		}
//		p = next;//p往后走
//	}
//	return head2;
//}
//int getTwin(LinkList& head)
//{
//	int n = 0;//先求链表长度
//	Node* cur = head;
//	while (cur != NULL)
//	{
//		n++; cur = cur->next;
//	}
//	LinkList head2 = reverse(head);//建立一个新链表 存放A的逆置
//	Node* p = head; Node* q = head2;//两个指针 一个遍历A 一个遍历B
//	int cnt = 0;//当cnt>=n/2时，结束循环
//	int twin = 0;
//	while (cnt < n / 2)
//	{
//		cnt++;
//		int sum = p->data + q->data;
//		twin = max(twin,sum);
//		p = p->next;
//		q = q->next;
//	}
//	return twin;
//}
//int main()
//{
//	LinkList head = NULL;
//	PushBack(head, 2);
//	PushBack(head, 1);
//	PushBack(head, 3);
//	PushBack(head, 4);
//	PushBack(head, 5);
//	PushBack(head, 6);
//	cout << getTwin(head);
//}
#pragma endregion