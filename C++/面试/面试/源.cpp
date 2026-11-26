#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//int main()
//{
//	int a = 1, b = 1, c = 1, d = 1;
//	printf("%d\n", a++);
//	if (b++ == a) printf("%d\n", b);//1
//	if (++c || ++b==++a) printf("%d\n", c);//1
//	return 0;
//}

//int main()
//{
//	int b = 0;
//	printf("%d %d %d %d %d", b, b++, ++b, b++,++b);
//}

//int main()
//{
//	char a = -1;
//	//10000000 00000000 00000000 00000001 原码
//	//11111111 11111111 11111111 11111111 补码
//	//存 11111111 8个bit
//	signed char b = -1;
//	//11111111
//	unsigned char c = -1;
//	//11111111 高位不是符号位
//	//无符号位 整型提升 补0  有符号位 补符号位
//	//00000000 00000000 00000000 11111111 也是原码
//	printf("%d %d %d", a, b, c);
//}
//
//int main()
//{
//	unsigned char i = -255;// 11111111
//	printf("i=%u\n", i); //00000000 00000000 00000000 11111111
//	i++;  //00000000 00000000 00000001 00000000
//	printf("i=%u\n", i);    
//	unsigned char p = -255; //00000001 11111111-原码  00000001-补码  00000000 00000000 00000000 00000001-高位不是符号位 补0进行整形提升
//	printf("i=%u\n", p);
//	//for (i = 0; i <= 255; i++) printf("*");//死循环
//	//无符号 不可能有负数，并且最大就是255,255+1变成0 死循环
//	return 0;
//}

//int main()
//{
//	int a = 0x11223344;
//	char b; //11 22 33 44 
//	b = a;
//	if (b == 0x11) //大端存储
//		printf("1");
//	else //小端存储
//		printf("2");
//	return 0;
//}

//typedef int* u8;
//#define u8_ int*
//int main()
//{
//    //指针在64位x64 8字节 在32位x86 4字节
//    u8 a, b;
//    u8_ c,d;
//    printf("sizeof a:%d\n", sizeof(a));//8  4
//    printf("sizeof d:%d\n", sizeof(b));//8  4
//    printf("sizeof b:%d\n", sizeof(c));//8  4
//    printf("sizeof c:%d\n", sizeof(d));//4  4
//    return 0;
//}

//int main() 
//{
//	float a = 0.5, b = 0.3;
//	if (a + b == 0.8) 
//	{
//		printf("yes");
//	}
//	else 
//	{
//		printf("no");
//	}
//}

//int main()
//{              //0 1 2  3  4
//	int a[5] = { 1,4,7,11,14 };
//	printf("%d\n", *(a + 2));//7
//	printf("%d\n", *a + 2);//3
//	printf("%p\n", &a);
//	printf("%p\n", a);
//	return 0;
//}

//#include <stdbool.h>
//#define true 0
//#define false 1
//struct ZDJD
//{
//	bool O(bool x)
//	{
//		return x ? true : false;
//	}
//}o;
//int main()
//{
//	int cnt = 0;
//	int a[] = { 1,2,3,4,5 };
//	for (int i = 0; i < 5; ++i)
//	{
//		if (o.O(*&(i - 1)[a + 1] % 2))
//			cnt++;
//	}
//	cout << cnt;
//}

//strlen模拟实现
//int my_strlen(const char* str)
//{
//	int cnt = 0;
//	assert(str != NULL);
//	while (*str != '\0' )
//	{
//		cnt++; str++;
//    }
//	return cnt;
//}
//int main()
//{
//	char arr[10] = { 'a','b','c' };
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

//strcpy模拟实现
//char* my_strcpy(char* dest, const char* src)
//{
//	const char* start = src;
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	return start;
//}
//int main()
//{
//	char arr1[12] = "#########";
//	char arr2[12] = "he\0llo";
//	strcpy(arr1,arr2);
//	printf("%s", arr1);
//	return 0;
//}

//strcat模拟实现
//char* my_strcat (char* dest, char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest != '\0')
//		dest++;  //先找到目标字符串中的\0
//	while (*dest = *src)
//	{
//		dest++; src++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[20] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//strcmp模拟实现
//int my_strcmp(char* s1, char* s2)
//{
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++; s2++;
//	}
//	return *s1 - *s2;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[20] = "cdefs";
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}

//strstr模拟实现
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = NULL; //abcdeabcde
//	const char* s2 = NULL; //bbc
//	const char* cp = str1;
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	while (*cp!='\0')
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
//		{
//			s1++; s2++;
//		}
//		if (*s2 == '\0')
//			return (char*)cp;
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[20] = "abcdeabcde";
//	char arr2[20] = "xxwes";
//	printf("%s", my_strstr(arr1, arr2));
//	return 0;
//}

//strtok
//int main()
//{
//	char arr1[20] = "abc@acg.acg";
//	char arr2[20] = "@.";
//	char tmp[20] = { 0 };
//	char* ret = NULL;
//	strcpy(tmp, arr1);//尽量不在原字符串上修改
//	/*ret = strtok(tmp, arr2);
//	printf("%s\n", ret);
//	ret = strtok(NULL, arr2);
//	printf("%s\n", ret);
//	ret = strtok(NULL, arr2);
//	printf("%s\n", ret);*/
//	for (ret = strtok(tmp, arr2); ret != NULL; ret = strtok(NULL, arr2))
//		printf("%s\n", ret);
//	return 0;
//}

//int main()
//{
//    int t, m, hour;
//    scanf("%d %d", &t, &m);
//    hour = (t / 100 + (m + t % 100) / 60) * 100;
//    m = (m + t % 100) % 60;
//    if (m < 0) 
//    {
//        hour = hour + 60 + m - 100;
//    }
//    else 
//    {
//        hour += m;
//    }
//    if (hour < 100) 
//    {
//        printf("0%d", hour);
//    }
//    else 
//    {
//        printf("%d", hour);
//    }
//    return 0;
//}

//int main()
//{
//    //动态规划算法
//	//int x = 15;
//	//int dp[4040] = { 0 };
//	//dp[1] = 1;
//	//for (int i = 2; i <= x; i++)
//	//{
//	//	dp[i] = dp[i - 1] + 1;              //dp[4] = dp[3]+1;
//	//	if (i % 2 == 0)
//	//	{
//	//		dp[i] = min(dp[i], dp[i/2] + 1);//dp[4] = min( dp[4],dp[2]+1);
//	//	}
//	//}
//	//printf("%d",dp[x]);
//
//	//int x = 31415926;
//	//int ans = 0;
//	//for (int i = x; i > 0;)
//	//{
//	//	if (i % 2 == 0)
//	//	{
//	//		i /= 2;
//	//		ans++;
//	//	}
//	//	else
//	//	{
//	//		i--;
//	//		ans++;
//	//	}
//	//}
//	//cout << ans;
//	//return 0;
//}