#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	char* pa = arr;
//	for (i = 0;i < 10;i++)
//	{
//		*(pa + i) = 1;   //pa+i是下标为i的地址;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(pa + i));
//	}
//	return 0;
//}

//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p = arr;
//	for (p = &arr[0];p < &arr[5];)
//	{
//         *p++ = 0;
//	}
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int* q = arr+9;
//	while (p <= q)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//}

//int main()
//{
//	char ch[5] = { 'b','i','t','\0'};
//	char dh[5] = "bit";
//	printf("%d\n", sizeof(ch));
//	printf("%d\n", sizeof(dh));
//	printf("%d\n", strlen(ch));
//	printf("%d", strlen(dh));
//}
//

//实现strlen函数
//int my_strlen(char* p)
//{
//	int* q = p;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return p-q;
//}
//int main()
//{
//	char arr[] = "abc"; // a b c \0
//	int len = my_strlen(arr);
//	printf("%d", len);
//}

//int main()
//{
//	int i = 0;
//	//前置返回本身 后置返回缓存区
//	printf("%d %d %d", i++,++i,i++);//i++ I=1.缓冲区 0  //++i i=2,缓存区2 //i++ i=3，缓存区 2
//	// 从左开始打印: 2 3 3
//}

//计算a+aa+aaa+aaaa
//int main()
//{
//	int a = 0;int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;int j = 0;int ret = 0;int sum = 0;
//	for (i = 0;i < n;i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;//2 + 2*10+2 + 22*10+2
//	}
//	printf("%d", sum);
//	return 0;
//}

//计算0-10000的水仙花数
//n位数 各位数字的n次方之和等于本身
//int pow(int x, int y)
//{
//	if (y == 0)
//		return 1;
//	else
//		return pow(x, y - 1) * x;
//}
//int main()
//{
//	int i = 0;
//	for (i = 0;i <= 10000;i++)
//	{
//		int n = 0; //位数
//		int t = i;
//		while (t)
//		{
//			n++;
//			t = t / 10;
//		}
//		t = i;
//		int sum = 0;
//		while (t)
//		{
//			sum += pow(t%10, n);
//			t = t / 10;
//		}
//		if (sum == i)
//			printf("%d ", sum);
//	}
//	return 0;
//}

//逆序字符串
//void reverse(char* str)
//{
//	assert(str != NULL);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;right--;
//	}
//}
//int main()
//{
//	char arr[10] = "abcdef";
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char t = *left;
//		*left = *right;
//		*right = t;
//		left++;right--;
//	}
//}
//int main()
//{
//	char arr[10] = "abcdef";
//	int len = strlen(arr);
//	reverse(arr, arr + len - 1);
//	printf("%s", arr);
//}

//一瓶汽水1元，2个空瓶可以换一瓶，给20元买了20瓶，问：总共能喝多少瓶
//int main()
//{
//	int money = 0;scanf("%d", &money);
//	int total = 0;
//	//total = money;
//	//int empty = 0;
//	//empty = money;
//	//int huan = 0;
//	//while (empty >= 2)
//	//{
//	//	total += empty / 2;
//	//	empty = empty / 2 + empty % 2;  // 除以2得到换掉的瓶子 %2得到没有换出去的瓶子 
// //   }
//	if(money>0)
//	     total = 2 * money - 1;
//	printf("%d", total);
//	return 0;
//}