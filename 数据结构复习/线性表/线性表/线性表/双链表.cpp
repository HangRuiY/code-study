//#include <iostream>
//using namespace std;
//typedef struct DLNode
//{
//	int data;
//	struct DLNode* next;
//	struct DLNode* prev;
//}DLNode,*DLinkList;
//void InitList(DLinkList &L)
//{
//	L = (DLNode*)malloc(sizeof(DLNode));
//	if (L == NULL) return;
//	L->next = L->prev = NULL;
//}
//void Print(DLinkList L)
//{
//	DLNode* p = L->next;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
////在p结点之后插入s结点
//void InsertAfterP(DLNode* p, int x)
//{
//	DLNode* s = (DLNode*)malloc(sizeof(DLNode));
//	if (s == NULL) return;
//	s->data = x;
//	s->next = p->next;
//	s->prev = p;
//	if(p->next!=NULL)
//		p->next->prev = s;
//	p->next = s;
//}
//void Insert(DLinkList& L, int x)
//{
//	DLNode* s = (DLNode*)malloc(sizeof(DLNode));
//	if (s == NULL) return;
//	s->data = x;
//	DLNode* tail = L;//尾指针进行尾插
//	while (tail->next != NULL)
//		tail = tail->next;
//	tail->next = s;
//	s->prev = tail;
//	s->next = NULL;
//}
////删除P的后结点
//void Delete(DLNode* p)
//{
//	DLNode* s = p->next;
//	p->next = s->next;
//	if(s->next!=NULL)//如果s不是最后一个结点
//		s->next->prev = p;
//	free(s);//释放s
//}
//int main()
//{
//	DLinkList L;
//	InitList(L);
//	Insert(L, 1);
//	Insert(L, 2);
//	Insert(L, 4);
//	Insert(L, 5);
//	Print(L);
//	DLNode* p = L->next->next->next->next;
//	InsertAfterP(p, 3);
//	Print(L);
//	Delete(p);
//	Print(L);
//}