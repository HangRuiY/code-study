#include "Á´±í.h"
//Ô¼Éª·ò»·
int main()
{
	int n, m;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	SLTNode* p = SListCreat();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		p = SListPushBack(&p, i, x);
	}
	while (p->next != NULL)
	{
		int k = p->next->data;
		int pn = p->next->num;
		p = SListPopFront(&p);
		cnt++;
		if (cnt == m)
		{
			printf("%d ", pn);
			m = k;
			cnt = 0;
		}
		else
		{
			p = SListPushBack(&p, pn, k);
		}
	}
	return 0;
}

