#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	int a = 1;//00 00 00 01
	char* p = (char*)&a;
	if (*p == 1)//01 00 00 00
		printf("小端\n");
	else
		printf("大端");
}

//int main()
//{
//	unsigned int i = 0;
//	for (i = 9;i >= 0;i--)
//	{
//		printf("%u ", i);//死循环
//	}
//}

//int main()
//{
//	char a[1000];
//	int i = 0;
//	for (i = 0;i < 1000;i++)
//	{
//		a[i] = -1 - i;
//	}
//	//-1 -2 -3 ... -127 -128 127 126 ... 3 2 1 0
//	//128+127=255
//	printf("%d ", strlen(a)); // 找到\0 ->找到 0
//	return 0;
//}

//unsigned char i = 0;
//int main()
//{
//	for (i = 0;i <= 255;i++)
//	{
//		printf("hello");
//	}
//}

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	//00000000000000000000000000001001
//	//当成float类型: 0 00000000 00000000000000000001001
//	//0.00000000000000000001001 * 2^-126  E全为零 默认为1 还原的时候1-127 =126
//	//float类型保留后六位为 0.000000
//	printf("*pFloat的值为:%f\n", *pFloat);
//	*pFloat = 9.0;//1001.0   1.001*2^3
//	//S=0 E=3+127=130 10000010 M=00100000000000000000000
//	printf("num的值为：%d\n", n);// 01000001000100000000000000000000 
//	printf("*pFloat的值为：%f\n", *pFloat);// 9.0
//	return 0; 
//}