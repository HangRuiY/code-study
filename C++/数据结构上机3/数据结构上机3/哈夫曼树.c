#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
typedef struct Tree
{
	char c;
	int w;
	int p;
	int left; int right;
}HFTree, HFTREE[2000];

char a[1010] = { 0 };//输入的字符串
char t[1010] = { 0 };//存放叶子结点
int b[1010];//访问过的字符的权值
int weight[1010] = { 0 };
char code[1010] = { 0 };//存放0 1符号
int top = 0, k = 0;

int* Select(HFTREE ht, int n)
{
	int min1 = 10000;
	int min2 = 10000;
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++)//找最小的
	{
		if (ht[i].p == 0)//必须没有父节点
		{
			if (ht[i].w < min1)
			{
				min1 = ht[i].w;
				s1 = i;
			}
		}
	}
	for (int i = 1; i <= n; i++)//找第二小
	{
		if (ht[i].p == 0 && i != s1)//必须没有父节点
		{
			if (ht[i].w < min2)
			{
				min2 = ht[i].w;
				s2 = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = s1;
	res[1] = s2;
	return res;
}
void Creat(HFTREE ht, int n)
{
	int* res;
	int min1, min2;
	int lenth = n * 2 - 1;
	for (int i = n + 1; i <= lenth; i++)
	{
		res = Select(ht, i - 1);
		min1 = res[0]; min2 = res[1];
		ht[i].w = ht[min1].w + ht[min2].w;//父节点权值 = 子节点之和
		ht[i].left = min1;
		ht[i].right = min2;
		ht[i].p = 0;//新结点放入列表里。
		ht[min1].p = i;
		ht[min2].p = i;

	}
}
void PRINT(HFTREE ht, int index)
{
	if (index != 0)//说明不是空结点
	{
		printf("%d ", ht[index].w);
		PRINT(ht, ht[index].left);
		PRINT(ht, ht[index].right);
	}
}
void Cal(char* a)
{
	int cnt = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (!b[a[i] - '!'])
		{

			t[++cnt] = a[i];
			printf("%c ", t[cnt]);
		}
		b[a[i] - '!']++;
	}
	printf("\n");
	for (int i = 1; i <= cnt; i++)
	{
		weight[i] = b[t[i] - '!'];
		printf("%d ", weight[i]);
	}
	printf("\n");
}
void PRINT2()
{
	for (int i = 1; i <= top; i++)
		printf("%c", code[i]);
	printf("\n");
}
bool vis[1010];
char v[1010][1010];
void HFBCODE(HFTREE ht, int n)
{
	k = 0;
	int m = 2 * n - 1;
	int s[1010] = { 0 };
	s[++top] = m;
	int now = m;
	vis[m] = true;
	while (top != 0)
	{
		now = s[top];
		while (ht[now].left && !vis[ht[now].left])
		{
			code[++k] = '0';
			now = ht[now].left;
			if (ht[now].c != '\0')
			{
				printf("%c:", ht[now].c);
				PRINT2();
				for (int u = 1; u <= k; u++)
				{
					v[ht[now].c - '!'][u] = code[u];
				}
			}
			vis[now] = true;
			s[++top] = now;
		}
		if (ht[now].right && !vis[ht[now].right])
		{
			code[++k] = '1';
			now = ht[now].right;
			if (ht[now].c != '\0')
			{
				printf("%c:", ht[now].c);
				PRINT2();
				for (int u = 1; u <= k; u++)
				{
					v[ht[now].c - '!'][u] = code[u];
				}
			}
			vis[now] = true;
			s[++top] = now;
		}
		else
		{
			top--;
			k--;
		}
	}
}
int main()
{
	//初始化
	HFTREE ht;
	printf("请输入需要编码的字符串:>");
	scanf("%s", a);//sssssadadaf
	Cal(a);//计算列表内结点数量
	int n = strlen(t + 1);
	printf("列表内结点的数量一共为:%d个\n", n);
	for (int i = 1; i <= n; i++)
	{
		ht[i].c = t[i];
		ht[i].w = weight[i];
		ht[i].p = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}
	int m = 2 * n - 1;
	for (int i = n + 1; i <= m; i++)
	{
		ht[i].c = '\0';
		ht[i].w = 0;
		ht[i].p = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}
	int* res = Select(ht, n);
	printf("res[0] = %d\n", res[0]);
	printf("res[1] = %d\n", res[1]);
	Creat(ht, n);
	printf("生成哈夫曼树的先序序列为:");
	PRINT(ht, 2 * n - 1);
	printf("\n");
	HFBCODE(ht, n);
	printf("该字符串的哈夫曼编码为:>");
	for (int i = 0; i < strlen(a); i++)
	{
		int k = 1;
		while (v[a[i] - '!'][k] != '\0')
		{
			printf("%c", v[a[i] - '!'][k]);
			k++;
		}
	}
	return 0;
}