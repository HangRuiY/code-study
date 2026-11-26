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
}HFTree,HFTREE[2000];

char a[1010] = { 0 };//输入的字符串
char t[1010] = { 0 };//存放叶子结点
int b[1010];//访问过的字符的权值
int weight[1010] = { 0 };
int code[1010] = { 0 };//存放0 1符号
int top = 0,k=0;

int* Select(HFTREE ht,int n)
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
void Creat(HFTREE ht,int n)
{
	int* res;
	int min1, min2;
	int lenth = n * 2 - 1;
	for (int i = n+1; i <= lenth; i++)
	{
		res = Select(ht,i-1);
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
		printf("%d", code[i]);
	printf("\n");
}
bool vis[1010];
void HFBCODE(HFTREE ht, int n)
{
	k = 0;
	int m = 2 * n - 1;
	int s[1010] = { 0 };
	s[++top] = m;
	int now = m;
	vis[m] = true;
	while (top!=0)
	{
		now = s[top];
		while (ht[now].left && !vis[ht[now].left])
		{
			code[++k] = 0;
			now = ht[now].left;
			if (ht[now].c != '\0')
			{
				printf("%c\n", ht[now].c);
				PRINT2();
			}
			vis[now] = true;
			s[++top] = now;
		}
		if (ht[now].right && !vis[ht[now].right])
		{
			code[++k] = 1;
			now = ht[now].right;
			if (ht[now].c != '\0')
			{
				printf("%c\n", ht[now].c);
				PRINT2();
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
	Creat(ht, n);
	PRINT(ht, 2 * n - 1);
	printf("\n");
	HFBCODE(ht, n);
	return 0;
}

//typedef struct T
//{
//	int w;//权值
//	int p;//父结点的下标
//	int left, right;
//}TreeNode;
//typedef struct HFTree
//{
//	TreeNode* data;
//	int len;//结点个数
//}HFTree;
////初始化
//HFTree* InitTree(int* weight,int len)
//{
	//HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	//T->data = (TreeNode*)malloc(sizeof(TreeNode) * (2 * len - 1));//动态数组
	//T->len = len;
	//for (int i = 0; i < len; i++)	
	//{
		//T->data[i].w = weight[i];
		//T->data[i].p = 0;
		//T->data[i].left = -1;
		//T->data[i].right = -1;
	//}
	//return T;
//}
//int* Select(HFTree* T)
//{
//	int min1 = 10000;
//	int min2 = 10000;
//	int s1 = 0, s2 = 0;
//	for (int i = 0; i < T->len; i++)//找最小的
//	{
//		if (T->data[i].p == 0)//必须没有父节点
//		{
//			if (T->data[i].w < min1)
//			{
//				min1 = T->data[i].w;
//				s1 = i;
//			}
//		}
//	}
//	for (int i = 0; i < T->len; i++)//找第二小
//	{
//		if (T->data[i].p == 0 && i != s1)//必须没有父节点
//		{
//			if (T->data[i].w < min2)
//			{
//				min2 = T->data[i].w;
//				s2 = i;
//			}
//		}
//	}
//	int* res = (int*)malloc(sizeof(int) * 2);
//	res[0] = s1; 
//	res[1] = s2;
//	return res;
//}
//void Creat(HFTree* T)
//{
//	int* res;
//	int min1, min2;
//	int lenth = T->len * 2 - 1;
//	for (int i = T->len; i < lenth; i++)
//	{
//		res = Select(T);
//		min1 = res[0]; min2 = res[1];
//		T->data[i].w = T->data[min1].w + T->data[min2].w;//父节点权值 = 子节点之和
//		T->data[i].left = min1;
//		T->data[i].right = min2;
//		T->data[i].p = 0;//新结点放入列表里。
//		T->data[min1].p = i;
//		T->data[min2].p = i;
//		T->len++;
//	}
//}
//void PRINT(HFTree* T, int index)
//{
//	if (index != -1)//说明不是空结点
//	{
//		printf("%d ", T->data[index].w);
//		PRINT(T, T->data[index].left);
//		PRINT(T, T->data[index].right);
//	}
//}
//int main()
//{
//	int weight[4] = { 1,2,3,4 };
//	HFTree* T = InitTree(weight,4);
//	int* res = Select(T);
//	printf("res[0] = %d\n", res[0]);
//	printf("res[1] = %d\n", res[1]);
//	Creat(T);
//	PRINT(T, T->len - 1);
//	return 0;
//}