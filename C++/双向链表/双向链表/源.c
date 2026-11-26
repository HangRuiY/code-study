#include "DL.h"
void test1() //尾部
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);
}
void test2()//头部
{
	LTNode* plist = ListInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);
	
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}
void test3()//pos位置
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	LTNode* pos1=ListFind(plist, 3);
	ListInsert(pos1, 50);
	ListPrint(plist);

	LTNode* pos2 = ListFind(plist, 50);
	ListErase(pos2);
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;
}
int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}