#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//接受一个整型值，按照顺序打印每一位
//int print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

//求字符串长度
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//	
//}
//int main()
//{
//	char arr[] = "bit";
//	int x = my_strlen(arr);
//	printf("%d\n", x);
//}
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	printf("%d ", my_strlen(arr));
//	return 0;
//}

//交换两个数的位置
//
//void Swap(int* pa, int* pb)
//{
//	int z = 0;
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("打印前：a %d b %d", a, b);
//	Swap(&a, &b);
//	printf("交换后：a %d b %d", a, b);
//}

//函数打印100-200的素数
//int sushu(int n)
//{
//	int j = 0;
//	for (j = 2;j < n;j++)
//	{
//		if (n % j == 0)
//		{
//			return 1;
//		}
//
//	}
//	return 2;
//
//}
//int main()
//{
//
//
//	int i = 0;
//	int count = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		if (sushu(i) == 2)
//		{
//			printf("%d ", i);
//			count++;
//		}
//
//	}
//	printf("count=%d", count);
//	return 0;
//}

//三个数最大
//int ADD(int x, int y, int z)
//{
//	int max = 0;
//	max = (x > y) ? (x > z ? x : z) : (y > z ? y : z);
//	return max;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d,%d,%d", &a, &b, &c);
//	int big;
//	big = ADD(a, b, c);
//	printf("最大值是%d", big);
//	return 0;
//
//}

//void add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	add(&num);
//	printf("%d ", num);
//	add(&num);
//	printf("%d ", num);
//	add(&num);
//	printf("%d ", num);
//	add(&num);
//	printf("%d ", num);//传地址
//	return 0;
//}

//1000 - 2000闰年
//int diaomaomao(int x)
//{  x%4==0 && x%100!=0 || x%400 ==0
//	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
//		return 1;
//}
//int main()
//{
//	int y = 0;
//	int count = 0;
//	for (y = 1000;y <= 2000;y++)
//	{
//		if (diaomaomao(y) == 1)
//		{
//			printf("%d ", y);
//			count++;
//		}
//
//
//
//	}
//	printf("%d\n", count);
//	return 0;
//}
// 

//n的阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	for (i = 1;1 <= n;i++)
//	{
//		ret *= i;
//	}
//	printf("%d", ret);
//	return 0;
//}

//第N个斐波那契数
//int Fib(int n)
//{
//	int a = 1;int b = 1;int c = 1;
//	while (n > 2)
//	{  //1 1 2 3 5
//		c = a + b;
//		a = b;
//		b = c;
//		n--; 
//	}
//	return c;
//}
//int main()
//{
//	int n = 10;
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d ", Fib(i));
//
//	}
//	return 0;
//}

//斐波那契数列
//int main()
//{
//    double f[50];
//    int n, i;
//    f[0] = 0;
//    f[1] = 1;
//    f[2] = 1;   
//    scanf("%d", &n);
//    for (i = 3; i <= n; i++)
//        f[i] = f[i - 1] + f[i - 2];  
//    printf("%0.2lf", f[n]); 
//    return 0;
//}

//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//void reverse(char* arr)
//{
//	int left = 0;
//	int right = my_strlen(arr)- 1;
//	while (left < right)
//	{
//		char t = arr[left];
//		arr[left] = arr[right];
//		arr[right] = t;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	my_strlen(arr);
//	reverse(arr);
//	printf("%s\n", arr);
//}

//17290各位之和
//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//		return n;
//}
//int main()
//{
//	int num = 1729;
//	int sum = DigitSum(num);
//	printf("%d", sum);
//}
//DigitSum(1729)
//DigitSum(172)+9
//DigitSum(17)+2+9
//DigitSum(1)+7+2+9
//1+2+7+9=19

//逆序打印
//unsigned int reverse(unsigned int x)
//{
//	int he = 0; int ret = x;
//	while (ret)
//	{
//		he++; ret /= 10; //计算位数
//	}
//	if (x <= 9)
//		return x;
//	else
//		return reverse(x / 10) + (x % 10) * pow(10, he - 1);
//}
//int main()
//{
//	int n = 1720;
//	printf("%d", reverse(n));
//}

int main()
{
	char* abc = "yrh";
	char* name = "www";
	printf("my name is:%s\n", abc);
	printf("my name2 is:%s\n", name);
	return 0;
}