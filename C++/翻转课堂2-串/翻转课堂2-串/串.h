#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

char* StrAssign(char* str, char* s);
char* StrCopy(char* str, char* t);
int StrLength(char* str);
char* StrInsert(char* str, int pos, char* t);
char* StrDelete(char* str, int pos, int len);
void SteCmp(char* str, char* t);
char* StrCat(char* str, char* t);
char* SubStr(char* t, char* str, int pos, int len);
int StrIndex(char* str, int pos, char* t);
char* StrReplace(char* str, char* t, char* p);

bool StrEmpty(char* str);
char* StrClear(char* str);

typedef struct
{
	char* arr;
	int len;
}HString;
HString* HStrInit(HString** s);
HString* HStrAssign(HString** s,const char* t);
HString* HStrInsert(HString* s, int pos, int len);
HString* HStrDelete(HString* s, const HString t);
HString* HStrCat(HString* t, HString* s, int pos, int len);
//
//int Index(SString S, SString T, int pos)
//{ //返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数值为0。 
//    int i, j;
//    if (1 <= pos && pos <= S[0])
//    {
//        i = pos;j = 1;
//        while (i <= S[0] && j <= T[0])/*S[0],T[0]中存放的为串长*/
//            if (S[i] == T[j]) /* 继续比较后继字符 */
//            {
//                ++i;++j;
//            }
//            else /* 指针后退重新开始匹配 */
//            {
//                i = i - j + 2;
//                j = 1;
//            }
//        if (j > T[0])
//            return i - T[0];
//        else
//            return 0;
//    }
//    else
//        return 0;
//}