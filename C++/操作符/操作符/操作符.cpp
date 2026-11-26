#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//交换a,b 并且不用第三变量
//int main()
//{
//	int a = -3;     
//	int b = 5;                
//	a= a ^ b;                  
//	b = a ^ b;                 
//	a = a ^ b;  
//	printf("%d %d", a,b);
//	 
//}

//计算一个二进制补码有多少个1
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int count = 0;
//	for (i = 0;i < 32;i++)
//	{
//		if ((n >> i & 1) == 1)
//		{
//			count++;
//		}
//		
//	}
//	printf("%d ", count);
//}

//int main()
//{
//	int a = 13;
//	//把a的二进制位第五位改成1
//	//00000000 00000000 00000000 00001101
//	//00000000 00000000 00000000 00010000  按位或 
//	//00000000 00000000 00000000 00011101
//	a = a | (1 << 4);
//	printf("%d\n", a);
//	//把a二进制位的第五位改成0
//	//00000000 00000000 00000000 00011101
//	//00000000 00000000 00000000 00010000 按位异或
//	a = a ^ (1 << 4);
//	printf("%d", a);
//	return 0;
//}

//计算二进制序列;
int main()
{
	int n = 3;
	int arr[33] = { 0 };//int 型有32个字节
	int i = 0;
	while (n > 0)
	{
		arr[i] = n % 2;
		++i;
		n /= 2;
	}
	int k = 0;
	for (k = 31; k >= 0; k--) //逆序输出
	{
		printf("%d", arr[k]);
	}
	return 0;
}

//计算二进制补码有几个1
//方法一:int Num(unsigned int n) //无符号整型
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n /= 2;
//	}
//	return count;
//}
//方法二：int Num(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0;i < 32;i++)
//	{
//		if (((n >> i) & 1)== 1)   //-1  11111111111111111111111111111111
//			                      //    11111111111111111111111111111111
//		{                        
//			count++;
//		}
//	}
//	return count;
//}
//方法三：int Num(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = Num(n);
//	printf("%d", sum);
//	return 0;
//}
//判断一个数是不是2的倍数
//k&(k-1)==0

//求两个数 二进制位不同位的个数
//方法一：int main()
//{  
	//int a = 0;int b = 0;int count = 0;
	//scanf("%d %d", &a, &b);
	//int i = 0;
	//for (i = 0;i < 32;i++)
//	{
//		if (((a >> i) & 1) != ((b >> i) & 1))
//			count++;
//    }
//	printf("%d", count);
//	return 0;
//}
//方法二：int main()
//{
//	int a = 0;int b = 0;int count = 0;
//	scanf("%d %d", &a, &b);
//	int i = 0;
//	int ret = a ^ b;
//	for (i = 0;i < 32;i++)
//	{
//		if (((ret >> i) & 1) == 1)
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}

//获得一个二进制数的所有的偶数位和奇数位，并打印二进制位
//int main()
//{
//	int a = 0;int i = 0;
//	scanf("%d", &a);
//	//00000000 00000000 00000000 00001010
//	//00000000 00000000 00000000 00000001
//	//打印偶数位:
//	for (i = 31;i >= 1;i = i - 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30;i >= 0;i = i - 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	return 0;
//}

//交换两个数 不使用第三变量
//int main()
//{
//	int a = 1;
//	int b = 2;
//	a = a ^ b;   
//	b = a ^ b; //a^b^b  b^b=0     
//	a = a ^ b; //a^b^a(原来的a)
//	printf("%d %d", a, b);
//}

