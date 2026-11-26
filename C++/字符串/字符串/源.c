#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//大小写转换
//int main()
//{
//    char ch;
//    while ((ch = getchar()) != '#')
//    {
//        if (ch >= 'A' && ch <= 'Z')
//        {
//            ch += 32;
//            printf("%c", ch);
//        }
//        else if (ch >= 'a' && ch <= 'z')
//        {
//            ch -= 32;
//            printf("%c", ch);
//        }
//        else
//            printf("%c", ch);
//    }
//    return 0;
//}

//删除重复字符
//int main()
//{
//    char arr[80] = {0};
//    gets_s(arr);
//    int l = strlen(arr);
//    for (int i = 0;i < l;i++)
//    {
//        for (int j = i + 1;j < l;j++)
//        {
//            if (arr[i] == arr[j])
//            {
//                arr[j] = '@';
//            }
//        }
//    }
//    char t = 0;
//    for (int i = 0;i < l - 1;i++)
//    {
//        for (int j = 0;j < l - 1 - i;j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                char t = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = t;
//            }
//        }
//    }
//    for (int i = 0;arr[i] != '\0';i++)
//    {
//        if (arr[i] != '@')
//        {
//            printf("%c", arr[i]);
//        }
//    }
//    return 0;
//}

//找最长的字符串
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    char arr[100][81] = { 0 };
//    int i = 0;int j = 0;unsigned int max = 0;
//    for (i = 0;i < n;i++)
//    {
//        scanf("%s", &arr[i]);
//        if ((strlen(arr[i])) > max)
//        {
//            max = strlen(arr[i]);
//            j = i;
//        }
//    }
//    printf("The longest is: %s\n", arr[j]);
//    return 0;
//}

//i like beijing. -> beijing. like i
//三步翻转法
//void reverse(char* left, char* right)
//{
//	char tmp = 0;
//	while (left < right)
//	{
//		tmp = *left; *left = *right; *right = tmp;
//		left++;right--;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	gets_s(arr);
//	int len = strlen(arr);
//    //整体翻转
//	reverse(arr, arr + len - 1);  //传送下标
//	//单个单词逆序
//	char* start = arr;
//	while (*start) //start指到\0停止循环
//	{
//		char* end = start;
//		while (*end != ' ' && *end!='\0') //遇到空格或者\0停止 
//			end++;
//		reverse(start, end - 1); //逆序单词
//		if (*end != '\0')
//			start = end + 1;
//		else
//			start = end;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//打印星星
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0;i < line;i++)
//	{
//		int j = 0;
//		for (j = 0;j < line-1-i;j++)
//		{
//			printf(" ");
//		}
//		for (j = 0;j <2*i+1 ;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0;i < line - 1;i++)
//	{
//		int j = 0;
//		for (j = 0;j <= i;j++)
//			printf(" ");
//		for (j = 0;j < (line - 1 - i) * 2 - 1;j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//    char arr1[81] = { 0 };
//    char arr2[81] = { 0 };
//    gets_s(arr1);
//    int len1 = strlen(arr1);//arr1长度
//    int i = 0;int cnt = 0;//计算出现大写字母的多少
//    int j = 0;int flag = 0;//比较重复
//    for (i = 0;i < len1;i++)
//    {
//        if (arr1[i] >= 'A' && arr1[i] <= 'Z' && arr1[i]!='\0'&& arr1[i]!=' ')
//        {
//            arr2[cnt++] = arr1[i]; //大写字母放到arr2里面去
//            
//        }
//    }
//    if (cnt == 0)
//        printf("Not Found");
//    else
//        for (i = 0;i < cnt;i++)
//        {
//            flag = 0;
//            for (j = 0;j < i;j++)
//            {
//                if (arr2[i] == arr2[j])
//                    flag = 1;
//            }
//            if (flag == 0)
//                printf("%c", arr2[i]);
//
//        }
//    return 0;
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
char* my_strcpy(char* dest, const char* src)
{
	const char* start = src;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return start;
}
int main()
{
	char arr1[12] = "#########";
	char arr2[12] = "hello";
	//strcpy(arr1,arr2);
	printf("%s", my_strcpy(arr1, arr2));
	return 0;
}

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
//	char arr2[20] = "abcdef";
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
//	char arr2[20] = "abc";
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
//	ret = strtok(tmp, arr2);
//	printf("%s\n", ret);
//	ret = strtok(NULL, arr2);
//	printf("%s\n", ret);
//	ret = strtok(NULL, arr2);
//	printf("%s\n", ret);
//	//for (ret = strtok(tmp, arr2); ret != NULL; ret = strtok(NULL, arr2))
//	//	printf("%s\n", ret);
//	return 0;
//}

