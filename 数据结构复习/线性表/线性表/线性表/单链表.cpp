//#include <iostream>
//using namespace std;
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode,*LinkList;
//void InitList(LinkList &L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	if (L == NULL) return;
//	L->next = NULL;
//}
//void Print(LinkList L)
//{
//	if (L->next == NULL)
//		return;
//	LNode* p = L->next;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
////头插
//void InsertHead(LinkList& L, int tmp)
//{
//	LNode* s = (LNode*)malloc(sizeof(LNode));//建立一个结点
//	if (s == NULL) return;
//	s->data = tmp; 
//	s->next = L->next;
//	L->next = s;
//}
////尾插
//void InsertBack(LinkList& L, int tmp)
//{
//	LNode* tail = L;//建立一个指针 等于L 进行遍历找到尾节点
//	LNode* s = (LNode*)malloc(sizeof(LNode));//建立一个结点
//	if (s == NULL) return;
//	s->data = tmp;
//	while (tail->next != NULL)
//		tail = tail->next;
//	tail->next = s;
//	s->next = NULL;
//}
////求表长
//int GetLength(LinkList L)
//{
//	int len = 0;
//	while (L != NULL)
//	{
//		L = L->next; len++;
//	}
//	return len;
//}
//LNode* GetElem(LinkList L, int i)//找第i个结点
//{
//	if (i < 1 || L->next==NULL) return NULL;
//	int j = 0;
//	while (L != NULL && j < i)
//	{
//		L = L->next; j++;//当j=i时，L所处的结点就是要找的
//	}
//	return L;
//}
////插入
//bool Insert(LinkList& L, int i, int tmp)
//{
//	LNode* p = L;
//	int j = 0;
//	while (p != NULL && j < i - 1)
//	{
//		p = p->next; j++;//最终j=i-1
//	}
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	if (s == NULL) return false;
//	if (p == NULL) return false;
//	s->data = tmp;
//	s->next = p->next;
//	p->next = s;
//	return true;
//}
////删除
//bool Delete(LinkList& L, int i)
//{
//	LNode* p = L;
//	int j = 0;
//	while (p != NULL && j < i - 1)
//	{
//		p = p->next; j++;//最终j=i-1
//	}
//	if (p == NULL) return false;
//	LNode* q = p->next;
//	p->next = q->next;
//	free(q);
//	return true;
//}
////逆置
//void Reverse(LinkList& L)
//{
//	LinkList H;
//	InitList(H);//新链表
//	//头插法逆置
//	LNode* p = L->next;
//	while (p!=NULL)
//	{
//		LNode* p_next = p->next;
//		p->next = H->next;
//		H->next = p;
//		p = p_next;
//	}
//	L = H;
//}
//int main()
//{
//	LinkList L;
//	InitList(L);
//	//头插
//	InsertHead(L, 3);
//	InsertHead(L, 2);
//	InsertHead(L, 1);
//	Print(L);
//	//尾插
//	InsertBack(L, 4);
//	InsertBack(L, 5);
//	InsertBack(L, 6);
//	Print(L);
//	cout << GetLength(L)<<endl;//表长
//	//找第4个结点
//	LNode* t = GetElem(L, 4);
//	cout << t->data<<endl;
//	//插入
//	Insert(L, 7, 7);
//	Print(L);
//	//删除
//	Delete(L, 7);
//	Print(L);
//	//逆置
//	Reverse(L);
//	Print(L);
//}