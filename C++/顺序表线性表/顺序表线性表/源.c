#include "list.h"
void TestSeqList1()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);

	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPrint(&sl);

	SeqListPushBack(&sl, 1); 
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);

	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}
void TestSeqList2()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);

	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);

	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);

	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}
void TestSeqList3()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);

	SeqListPrint(&sl);

	SeqListFind(&sl, 3); //打印3数据的位置

	SeqListInsert(&sl, 2, 40);//在下标2位置之后写入40
	SeqListPrint(&sl);

	SeqListErase(&sl,4);//删除4下标的元素
	SeqListPrint(&sl);
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}
