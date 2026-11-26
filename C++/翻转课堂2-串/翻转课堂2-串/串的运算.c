#include "串.h"
int main()
{
	char s[50] = { 0 };
	char str[50] = { 0 };
	gets(s);
	StrAssign(str, s);//生成串
	printf("%s\n", str);
	printf("%d\n\n", StrLength(str));//长度

	char arr[12] = "hello";
	char* s2 = StrCopy(str, arr);
	printf("%s\n",s2);
	char arr2[12] = "hello";
	SteCmp(s2, arr2);
	printf("\n");

	char arr3[12] = " world";
	printf("%s\n", StrCat(arr, arr3));
	char t[50] = { 0 };
	char arr4[12] = "hello world";
	printf("%s\n", SubStr(t, arr4, 7, 5));
	char arr5[30] = "hello world";
	printf("%s\n", StrInsert(arr5, 6, t));
	printf("%s\n", StrDelete(arr5, 6, 5));

	char arr6[12] = "hello world";
	char tmp[50] = "ll";
	printf("%d\n", StrIndex(arr6, 1, "abc"));
	char p[50] = "3";
	printf("%s\n", StrReplace(arr6, tmp, p));
}
