#include "queue.h"
void test1()
{
	Queue p;
	QueueInit(&p);
	QueuePush(&p, 1);
	QueuePush(&p, 2);
	QueuePush(&p, 3);
	QueuePush(&p, 4);
	while (!QueueEmpty(&p))
	{
		printf("%d->", QueueFront(&p));
		QueuePop(&p);
	}
}
int main()
{
	test1();
	return 0;
}		
